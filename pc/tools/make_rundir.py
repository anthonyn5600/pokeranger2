#!/usr/bin/env python3
"""Lay out the PC port's run directory.

files/ gets a link to every file of ranger2.us/filesys.csv at its ROM path (files/data/..., files/dwc/...): the game
reads its files from there (ntros builds the ROM's file tables from that folder; no ROM image is used). Also copies
the placeholder firmware.bin (user settings + WiFi slots only, from the pokeplatinum PC port). The save,
pokeranger2.sav (raw backup memory, as melonDS / DeSmuME write it), and sim_config.ini are created by the game and
kept across runs. Removes what older versions laid out (data/ links, header.bin, the ROM link).

usage: make_rundir.py [RUNDIR]   (default pc/run; run from anywhere)
"""
import csv
import os
import shutil
import sys

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def remove_links(top):
    for root, dirs, files in os.walk(top, topdown=False):
        for name in files:
            path = os.path.join(root, name)
            if os.path.islink(path):
                os.remove(path)
        if not os.listdir(root):
            os.rmdir(root)


def main():
    run = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, "pc", "run"))
    os.makedirs(run, exist_ok=True)
    remove_links(os.path.join(run, "data"))
    for old in ("header.bin", "pokeranger2.us.nds"):
        if os.path.lexists(os.path.join(run, old)):
            os.remove(os.path.join(run, old))

    files = os.path.join(run, "files")
    remove_links(files)  # files removed from the list since the last run
    count = 0
    with open(os.path.join(REPO, "ranger2.us", "filesys.csv"), newline="") as f:
        for row in csv.DictReader(f):
            src = os.path.join(REPO, row["Source File"])
            dst = os.path.join(files, row["Target File"].lstrip("/"))
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            os.symlink(src, dst)
            count += 1

    firmware = os.path.join(run, "firmware.bin")
    if not os.path.exists(firmware):  # the game writes WiFi settings into it
        shutil.copyfile(os.path.join(REPO, "pc", "res", "firmware.bin"), firmware)

    print(f"{run}: files/ ({count} files), firmware.bin")


if __name__ == "__main__":
    main()
