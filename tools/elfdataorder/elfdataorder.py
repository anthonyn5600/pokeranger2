#!/usr/bin/env python3
"""Reorder data objects of an mwcc ELF object: elfdataorder.py IN OUT SPEC

mwcc emits every data object in its own section (".data", ".rodata", ...) and mwld lays an object's sections out in
section-index order. SPEC lists symbol names, one per line ('#' starts a comment); blank lines separate groups. Within
a group, the sections holding those symbols keep their index slots, but their contents are permuted so that the
symbols come out in the listed order. Symbols (section symbols included) and relocation sections follow their
contents, so every reference stays valid. Used where the original TU's size sort placed equal-size objects in an order
our source can't reproduce (objects the linker later dropped took part in the sort).
"""

import struct
import sys


def main():
    if len(sys.argv) != 4:
        sys.exit(__doc__)
    data = bytearray(open(sys.argv[1], 'rb').read())
    if data[:4] != b'\x7fELF' or data[4] != 1 or data[5] != 1:
        sys.exit(f'{sys.argv[1]}: not a 32-bit little-endian ELF file')
    groups, cur = [], []
    for line in open(sys.argv[3]).read().split('\n'):
        line = line.split('#', 1)[0].strip()
        if line:
            cur.append(line)
        elif cur:
            groups.append(cur)
            cur = []
    if cur:
        groups.append(cur)

    shoff, = struct.unpack_from('<I', data, 0x20)
    shentsize, shnum = struct.unpack_from('<HH', data, 0x2E)
    def sh(i):
        return list(struct.unpack_from('<10I', data, shoff + i * shentsize))
    sections = [sh(i) for i in range(shnum)]
    symtab_idx = [i for i, s in enumerate(sections) if s[1] == 2]  # SHT_SYMTAB
    if len(symtab_idx) != 1:
        sys.exit(f'{sys.argv[1]}: expected one symbol table')
    symtab = sections[symtab_idx[0]]
    strtab = sections[symtab[6]]
    nsyms = symtab[5] // 16

    def sym(k):
        return list(struct.unpack_from('<IIIBBH', data, symtab[4] + k * 16))

    def name(off):
        end = data.index(0, strtab[4] + off)
        return data[strtab[4] + off:end].decode()

    where = {}
    for k in range(nsyms):
        s = sym(k)
        if s[0] and 0 < s[5] < shnum:
            where.setdefault(name(s[0]), s[5])

    perm = {}  # old section index -> new section index (content moves from old to new)
    for g in groups:
        missing = [n for n in g if n not in where]
        if missing:
            sys.exit(f'{sys.argv[1]}: symbols not found: {missing}')
        idx = [where[n] for n in g]
        if len(set(idx)) != len(idx):
            sys.exit(f'{sys.argv[1]}: two symbols of {g} share a section')
        for old, new in zip(idx, sorted(idx)):
            if old != new:
                perm[old] = new

    # Move section contents: header fields other than the name follow the content.
    new_sections = [list(s) for s in sections]
    for old, new in perm.items():
        new_sections[new][1:] = sections[old][1:]
    # Relocation sections: retarget sh_info.
    for i, s in enumerate(new_sections):
        if s[1] in (4, 9) and s[7] in perm:  # SHT_RELA / SHT_REL
            s[7] = perm[s[7]]
    for i, s in enumerate(new_sections):
        struct.pack_into('<10I', data, shoff + i * shentsize, *s)
    # Symbols follow their sections.
    for k in range(nsyms):
        s = sym(k)
        if s[5] in perm:
            struct.pack_into('<H', data, symtab[4] + k * 16 + 14, perm[s[5]])
    open(sys.argv[2], 'wb').write(data)


if __name__ == '__main__':
    main()
