// The card's ROM, made from a folder: the game's files lie in a folder laid out like the ROM's file system
// ($NTR_FILES, else "files" in the current directory; e.g. files/data/Script/area/m000.fsb). At start this builds
// what the ROM holds in front of them: the header, the file name table (FNT) and the file allocation table (FAT),
// numbering files and folders exactly as the ROM builder does (nitrorom, packer.c: paths sorted folder by folder
// ignoring case, files before subfolders; overlays take the first file IDs). Each file gets a range of a virtual ROM;
// a ROM read in a file's range reads that file. The SDK's file system code runs unchanged on top.
#include <algorithm>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <vector>

#include "ntros.h"

#include "internal.hpp"

namespace ntros {
namespace {

    constexpr u32 kHeaderSize = 0x4000;
    constexpr u32 kAlign = 0x200; // the ROM builder's alignment

    struct File {
        std::vector<std::string> parts; // path below the root folder, one name per level
        std::string hostPath;
        u32 size;
        u32 top; // range in the virtual ROM
    };

    struct Region {
        u32 top;
        std::vector<u8> data;
    };

    std::string sRoot;
    std::vector<File> sFiles; // in file ID order (minus the overlays)
    Region sHeader;
    Region sFnt;
    Region sFat;

    void Scan(const std::string &host, std::vector<std::string> &parts)
    {
        DIR *dir = opendir(host.c_str());
        if (dir == NULL) {
            return;
        }
        while (dirent *entry = readdir(dir)) {
            if (entry->d_name[0] == '.') {
                continue;
            }
            std::string path = host + "/" + entry->d_name;
            struct stat st;
            if (stat(path.c_str(), &st) != 0) {
                continue; // broken link
            }
            parts.push_back(entry->d_name);
            if (S_ISDIR(st.st_mode)) {
                Scan(path, parts);
            } else if (S_ISREG(st.st_mode)) {
                sFiles.push_back({ parts, path, (u32)st.st_size, 0 });
            }
            parts.pop_back();
        }
        closedir(dir);
    }

    // nitrorom's stricmp on path components: compares the character after the shorter name too, which is '/' for a
    // folder and the end of the path for a file
    int CompareNames(const std::string &a, const std::string &b, char end)
    {
        size_t n = std::min(a.size(), b.size());
        size_t i = 0;
        auto lower = [](unsigned char c) { return (unsigned char)(c >= 'A' && c <= 'Z' ? c + 0x20 : c); };
        while (i < n && lower(a[i]) == lower(b[i])) {
            i++;
        }
        unsigned char ac = lower(i < a.size() ? a[i] : end);
        unsigned char bc = lower(i < b.size() ? b[i] : end);
        return ac == bc ? 0 : ac < bc ? -1
                                      : 1;
    }

    // nitrorom's comparefnames: level by level; at one level a file sorts before a folder
    bool FileBefore(const File &x, const File &y)
    {
        const auto &a = x.parts;
        const auto &b = y.parts;
        int result = 0;
        size_t i = 0;
        do {
            bool aDir = i + 1 < a.size();
            bool bDir = i + 1 < b.size();
            result = aDir == bDir ? CompareNames(a[i], b[i], aDir ? '/' : '\0') : !aDir ? -1
                                                                                        : 1;
            i++;
        } while (i < a.size() && i < b.size() && result == 0);
        return result < 0;
    }

    void Put16(std::vector<u8> &v, size_t at, u32 value)
    {
        v[at] = (u8)value;
        v[at + 1] = (u8)(value >> 8);
    }

    void Put32(std::vector<u8> &v, size_t at, u32 value)
    {
        Put16(v, at, value);
        Put16(v, at + 2, value >> 16);
    }

    // nitrorom's buildfntb / sealfntb
    void BuildFnt(u32 firstFileId)
    {
        struct Child {
            std::string name;
            u16 dirId; // 0: a file
        };
        struct Dir {
            std::vector<std::string> path;
            u16 file0;
            u16 parent;
            std::vector<Child> children;
        };
        std::vector<Dir> dirs(1);
        dirs[0].file0 = (u16)firstFileId;
        std::vector<size_t> open = { 0 }; // the folders of the previous file's path, from the root
        u32 fileId = firstFileId;
        for (const File &file : sFiles) {
            size_t depth = 1;
            while (depth < open.size() && depth < file.parts.size()
                && dirs[open[depth]].path.back() == file.parts[depth - 1]) {
                depth++;
            }
            open.resize(depth);
            for (; depth < file.parts.size(); depth++) {
                Dir dir;
                dir.path.assign(file.parts.begin(), file.parts.begin() + depth);
                dir.file0 = (u16)fileId;
                dir.parent = (u16)(0xF000 | open.back());
                dirs[open.back()].children.push_back({ file.parts[depth - 1], (u16)(0xF000 | dirs.size()) });
                open.push_back(dirs.size());
                dirs.push_back(dir);
            }
            dirs[open.back()].children.push_back({ file.parts.back(), 0 });
            fileId++;
        }
        dirs[0].parent = (u16)dirs.size(); // the root holds the number of folders

        std::vector<u8> &fnt = sFnt.data;
        fnt.assign(8 * dirs.size(), 0);
        for (size_t i = 0; i < dirs.size(); i++) {
            Put32(fnt, 8 * i, (u32)fnt.size());
            Put16(fnt, 8 * i + 4, dirs[i].file0);
            Put16(fnt, 8 * i + 6, dirs[i].parent);
            for (const Child &child : dirs[i].children) {
                if (child.name.size() > 127) {
                    OS_Panic("files: name longer than 127 characters: '%s'", child.name.c_str());
                }
                fnt.push_back((u8)(child.name.size() | (child.dirId != 0 ? 0x80 : 0)));
                fnt.insert(fnt.end(), child.name.begin(), child.name.end());
                if (child.dirId != 0) {
                    fnt.push_back((u8)child.dirId);
                    fnt.push_back((u8)(child.dirId >> 8));
                }
            }
            fnt.push_back(0);
        }
    }

    u32 AlignUp(u32 value)
    {
        return (value + kAlign - 1) & ~(kAlign - 1);
    }

    void CopyText(std::vector<u8> &v, size_t at, const char *text, size_t max)
    {
        if (text != NULL) {
            memcpy(&v[at], text, std::min(strlen(text), max));
        }
    }

} // namespace

void RomFs_Init()
{
    const NtrOsCartridge &cart = NtrOs_Cartridge;
    const char *env = getenv("NTR_FILES");
    sRoot = env != NULL ? env : "files";
    struct stat st;
    if (stat(sRoot.c_str(), &st) != 0 || !S_ISDIR(st.st_mode)) {
        OS_Panic("files: no folder '%s' with the game's files; set NTR_FILES", sRoot.c_str());
    }
    std::vector<std::string> parts;
    Scan(sRoot, parts);
    std::sort(sFiles.begin(), sFiles.end(), FileBefore);

    u32 overlays = (u32)cart.overlays;
    BuildFnt(overlays);

    // Layout: header, FNT, FAT, then the files
    sHeader.top = 0;
    sFnt.top = kHeaderSize;
    sFat.top = AlignUp(sFnt.top + (u32)sFnt.data.size());
    sFat.data.assign(8 * (overlays + sFiles.size()), 0);
    u32 next = AlignUp(sFat.top + (u32)sFat.data.size());
    for (size_t i = 0; i < overlays; i++) {
        Put32(sFat.data, 8 * i, next); // no overlay files: the code is linked into the executable
        Put32(sFat.data, 8 * i + 4, next);
    }
    for (size_t i = 0; i < sFiles.size(); i++) {
        File &file = sFiles[i];
        file.top = next;
        Put32(sFat.data, 8 * (overlays + i), next);
        Put32(sFat.data, 8 * (overlays + i) + 4, next + file.size);
        next = AlignUp(next + file.size);
    }

    // The header fields the SDK and the game read (CARDRomHeader)
    std::vector<u8> &h = sHeader.data;
    h.assign(kHeaderSize, 0);
    CopyText(h, 0x00, cart.title, 12);
    CopyText(h, 0x0C, cart.gameCode, 4);
    CopyText(h, 0x10, cart.makerCode, 2);
    h[0x1E] = cart.revision;
    Put32(h, 0x40, sFnt.top);
    Put32(h, 0x44, (u32)sFnt.data.size());
    Put32(h, 0x48, sFat.top);
    Put32(h, 0x4C, (u32)sFat.data.size());
    Put32(h, 0x80, next);
    Put32(h, 0x84, kHeaderSize);
}

void RomFs_Read(u32 offset, void *dst, u32 len)
{
    u8 *out = (u8 *)dst;
    memset(out, 0xFF, len); // gaps read as the ROM's fill
    u64 end = (u64)offset + len;
    for (const Region *region : { &sHeader, &sFnt, &sFat }) {
        u64 top = region->top;
        u64 bottom = top + region->data.size();
        if (offset < bottom && end > top) {
            u64 from = std::max<u64>(offset, top);
            u64 to = std::min<u64>(end, bottom);
            memcpy(out + (from - offset), region->data.data() + (from - top), to - from);
        }
    }
    // First file whose range ends after offset, then on while the files start before the end of the read
    auto it = std::upper_bound(sFiles.begin(), sFiles.end(), offset, [](u32 value, const File &file) { return value < file.top + file.size; });
    for (; it != sFiles.end() && it->top < end; ++it) {
        u64 from = std::max<u64>(offset, it->top);
        u64 to = std::min<u64>(end, (u64)it->top + it->size);
        if (from >= to) {
            continue;
        }
        FILE *f = fopen(it->hostPath.c_str(), "rb");
        if (f == NULL || fseek(f, (long)(from - it->top), SEEK_SET) != 0
            || fread(out + (from - offset), 1, to - from, f) != to - from) {
            OS_Panic("files: cannot read '%s'", it->hostPath.c_str());
        }
        fclose(f);
    }
}

} // namespace ntros
