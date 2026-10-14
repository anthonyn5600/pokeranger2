#!/usr/bin/env python3
"""Rename symbols of an mwcc ELF object in place: elfrename.py IN OUT OLD=NEW [OLD=NEW ...]

Only the symbol's name bytes in .strtab change (NEW must not be longer than OLD), so bindings (mwcc's binding 13 for
weak copies, which objcopy turns into LOCAL), sections and relocations stay as they are. Used to give an overlay its
own copy of a weak function that another overlay also emits (mwld keeps one copy of a weak function per link).
"""

import struct
import sys


def main():
    if len(sys.argv) < 4:
        sys.exit(__doc__)
    data = bytearray(open(sys.argv[1], 'rb').read())
    if data[:4] != b'\x7fELF' or data[4] != 1 or data[5] != 1:
        sys.exit(f'{sys.argv[1]}: not a 32-bit little-endian ELF file')
    shoff, = struct.unpack_from('<I', data, 0x20)
    shentsize, shnum = struct.unpack_from('<HH', data, 0x2E)
    sections = [struct.unpack_from('<10I', data, shoff + i * shentsize) for i in range(shnum)]
    symtabs = [s for s in sections if s[1] == 2]  # SHT_SYMTAB
    if len(symtabs) != 1:
        sys.exit(f'{sys.argv[1]}: expected one symbol table')
    symtab = symtabs[0]
    strtab = sections[symtab[6]]
    str_base, str_size = strtab[4], strtab[5]
    names = [struct.unpack_from('<I', data, symtab[4] + k * 16)[0] for k in range(symtab[5] // 16)]

    def name_at(offset):
        start = str_base + offset
        return bytes(data[start:data.index(b'\0', start, str_base + str_size)])

    for pair in sys.argv[3:]:
        old, new = (part.encode() for part in pair.split('=', 1))
        if len(new) > len(old):
            sys.exit(f'{pair}: the new name must not be longer than the old one')
        offsets = {offset for offset in names if name_at(offset) == old}
        if len(offsets) != 1:
            sys.exit(f'{sys.argv[1]}: {old.decode()}: found {len(offsets)} names, expected 1')
        offset = offsets.pop()
        # Another symbol whose name is a suffix of this one (shared string) would be renamed too.
        if any(offset < other < offset + len(old) for other in names):
            sys.exit(f'{sys.argv[1]}: {old.decode()}: its name string is shared with another symbol')
        start = str_base + offset
        data[start:start + len(old)] = new + b'\0' * (len(old) - len(new))
    open(sys.argv[2], 'wb').write(data)


if __name__ == '__main__':
    main()
