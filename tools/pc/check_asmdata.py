#!/usr/bin/env python3
"""Check src/pc/AsmData.cpp against the data-only asm files it replaces in the PC port.

Compiles AsmData.cpp with the DS build's mwccarm command (32-bit layout, so the bytes are comparable) and compares
every object it defines with the asm object holding the label of the same name: same section kind, same bytes
(.bss: same size). Asm bytes between the end of one C++ object and the next defined label must be zero (padding);
anything else is listed as data the C++ file leaves out. Needs a configured build (ninja -C build).

usage: tools/pc/check_asmdata.py [--repo DIR]
"""
import argparse, json, os, re, shlex, subprocess, sys, tempfile

ASM_FILES = ['arm9_02084288', 'arm9_0208A840', 'arm9_0208AC1C', 'arm9_0210CA30', 'arm9_0210CAB0',
             'overlay_11_02169B40']
READELF, OBJCOPY = 'arm-none-eabi-readelf', 'arm-none-eabi-objcopy'


def run(*args):
    return subprocess.run(args, capture_output=True, text=True, check=True).stdout


def kind(sec):
    return '.bss' if sec.startswith('.bss') or sec.startswith('.sbss') else \
        '.rodata' if sec.startswith('.rodata') else '.data' if sec.startswith('.data') else sec


def load(obj):
    """{name: (section kind, offset, size or None)}, {section: bytes or None (nobits)}"""
    secs = {}
    for l in run(READELF, '-SW', obj).splitlines():
        m = re.match(r'\s*\[\s*(\d+)\]\s+(\S+)\s+(\S+)\s+\S+\s+\S+\s+(\S+)', l)
        if m and m.group(3) in ('PROGBITS', 'NOBITS'):
            secs[m.group(1)] = (m.group(2), int(m.group(4), 16), m.group(3))
    data = {}  # mwcc emits one section per object, several with the same name: key by index
    raw = open(obj, 'rb').read()
    for l in run(READELF, '-SW', obj).splitlines():
        m = re.match(r'\s*\[\s*(\d+)\]\s+\S+\s+(\S+)\s+\S+\s+(\S+)\s+(\S+)', l)
        if m and m.group(1) in secs:
            off, size = int(m.group(3), 16), int(m.group(4), 16)
            data[m.group(1)] = None if m.group(2) == 'NOBITS' else raw[off:off + size]
    syms = {}
    for l in run(READELF, '-sW', obj).splitlines():
        p = l.split()
        if len(p) >= 8 and p[0].endswith(':') and p[6] in secs and p[3] in ('NOTYPE', 'OBJECT') \
                and not p[7].startswith('$') and not p[7].startswith('.'):
            syms[p[7]] = (p[6], int(p[1], 16), int(p[2], 0))
    return syms, data, secs


def relocs(obj):
    out, cur = {}, None
    for l in run(READELF, '-rW', obj).splitlines():
        m = re.match(r"Relocation section '\.rela?(\S+)'", l)
        if m:
            cur = m.group(1)
            continue
        p = l.split()
        if cur and len(p) >= 5 and re.match(r'[0-9a-f]{8}$', p[0]):
            out.setdefault(cur, set()).add(int(p[0], 16))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--repo', default=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
    repo = ap.parse_args().repo
    build = os.path.join(repo, 'build')
    cc = json.load(open(os.path.join(build, 'compile_commands.json')))
    cmd = shlex.split(next(e['command'] for e in cc if e['file'].endswith('src/Camera2D.cpp')))
    out = tempfile.mkdtemp()
    obj = os.path.join(out, 'AsmData.o')
    i = cmd.index('-o')
    cmd[i + 1] = obj
    cmd[cmd.index('-c') + 1] = os.path.join(repo, 'src/pc/AsmData.cpp')
    cmd = [a for a in cmd if a not in ('-gccdep', '-MD')]
    r = subprocess.run(cmd, cwd=build, capture_output=True, text=True)
    if r.returncode:
        sys.exit('compile failed:\n' + r.stdout + r.stderr)

    cpp, cdata, csecs = load(obj)
    asm = {}  # name -> (file, section, offset)
    adata, asize, arel = {}, {}, {}
    for f in ASM_FILES:
        aobj = os.path.join(build, 'main.nef.p', f'asm_{f}.s.o')
        syms, data, sizes = load(aobj)
        adata[f], asize[f], arel[f] = data, sizes, relocs(aobj)
        for name, (sec, off, _) in syms.items():
            asm[name] = (f, sec, off)

    bad = 0
    covered = {}  # (file, section) -> [(start, end)]
    for name, (sec, off, size) in sorted(cpp.items(), key=lambda s: s[0]):
        if name not in asm:
            continue
        f, asec, aoff = asm[name]
        if kind(csecs[sec][0]) != kind(asize[f][asec][0]):
            print(f'SECTION {name}: C++ {csecs[sec][0]}, asm {asize[f][asec][0]}')
            bad += 1
        covered.setdefault((f, asec), []).append((aoff, aoff + size, name))
        if adata[f][asec] is None:
            continue
        a = adata[f][asec][aoff:aoff + size]
        c = cdata[sec][off:off + size] if cdata.get(sec) is not None else b'\0' * size
        if any(aoff <= o < aoff + size for o in arel[f].get(asize[f][asec][0], ())):
            print(f'RELOC {name}: the asm item holds a relocation, compare by hand')
        if a != c:
            print(f'DIFFER {name}: asm {a.hex()} / C++ {c.hex()}')
            bad += 1
    def zero_gap(f, sec, off):  # padding label: only zero bytes up to the next label
        nxt = min([o for (g, s2, o) in asm.values() if (g, s2) == (f, sec) and o > off] + [asize[f][sec][1]])
        return adata[f][sec] is not None and not any(adata[f][sec][off:nxt])

    missing = sorted(n for n in asm if n not in cpp and not zero_gap(*asm[n]) and not any(
        s <= asm[n][2] < e for s, e, _ in covered.get(asm[n][:2], [])))
    gaps = []
    for (f, sec), spans in covered.items():
        spans.sort()
        for (s, e, n), nxt in zip(spans, spans[1:] + [(asize[f][sec][1], 0, None)]):
            if adata[f][sec] is not None and nxt[0] > e and any(adata[f][sec][e:nxt[0]]):
                gaps.append(f'{f} {asize[f][sec][0]} +{e:#x}..{nxt[0]:#x} after {n}: {adata[f][sec][e:nxt[0]].hex()}')
    for g in gaps:
        print('LEFT OUT', g)
    for n in missing:
        print('NO DEFINITION', n, asm[n])
    print(f'{sum(len(v) for v in covered.values())} objects compared, {bad} differ, '
          f'{len(gaps)} non-zero gaps, {len(missing)} asm labels not covered')
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
