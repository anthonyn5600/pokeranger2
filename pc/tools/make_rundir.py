#!/usr/bin/env python3
"""Lay out the PC port's run directory (the game opens its files by ROM path from the current directory).

Links every file of ranger2.us/filesys.csv to its ROM path, writes header.bin (the first 0x160 bytes of the built
ROM) and copies the placeholder firmware.bin (user settings + WiFi slots only, from the pokeplatinum PC port).
save.bin and sim_config.ini are created by the game on first run and kept across runs.

usage: make_rundir.py [RUNDIR]   (default pc/run; run from anywhere)
"""
import csv
import os
import shutil
import sys

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ROM = os.path.join(REPO, "build", "pokeranger2.us.nds")
HEADER_SIZE = 0x160


def main():
    run = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, "pc", "run"))
    os.makedirs(run, exist_ok=True)

    count = 0
    with open(os.path.join(REPO, "ranger2.us", "filesys.csv"), newline="") as f:
        for row in csv.DictReader(f):
            src = os.path.join(REPO, row["Source File"])
            dst = os.path.join(run, row["Target File"].lstrip("/"))
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            if os.path.lexists(dst):
                os.remove(dst)
            os.symlink(src, dst)
            count += 1

    with open(ROM, "rb") as f:
        header = f.read(HEADER_SIZE)
    with open(os.path.join(run, "header.bin"), "wb") as f:
        f.write(header)

    firmware = os.path.join(run, "firmware.bin")
    if not os.path.exists(firmware):  # the game writes WiFi settings into it
        shutil.copyfile(os.path.join(REPO, "pc", "res", "firmware.bin"), firmware)

    print(f"{run}: {count} files, header.bin, firmware.bin")


if __name__ == "__main__":
    main()
