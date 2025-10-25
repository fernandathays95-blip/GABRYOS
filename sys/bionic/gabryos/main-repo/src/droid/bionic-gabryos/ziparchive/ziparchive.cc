#include "ziparchive.h"
#include <zip.h>
#include <iostream>
#include <fstream>

ZipArchive::ZipArchive(const std::string& path) : zipPath(path) {}

ZipArchive::~ZipArchive() {
    close();
}

bool ZipArchive::open() {
    int err = 0;
    zip* za = zip_open(zipPath.c_str(), ZIP_RDONLY, &err);
    if (!za) {
        std::cerr << "[ZIP] Erro ao abrir ZIP: " << zipPath << std::endl;
        return false;
    }

    zip_int64_t num_entries = zip_get_num_entries(za, 0);
    for (zip_int64_t i = 0; i < num_entries; ++i) {
        struct zip_stat st;
        zip_stat_index(za, i, 0, &st);
        ZipEntry entry;
        entry.name = st.name;
        entry.size = st.size;
        entries.push_back(entry);
    }

    zip_close(za);
    std::cout << "[ZIP] ZIP aberto com sucesso: " << zipPath << std::endl;
    return true;
}

void ZipArchive::close() {
    entries.clear();
}

const std::vector<ZipEntry>& ZipArchive::list() {
    return entries;
}

bool ZipArchive::extract(const std::string& entryName, const std::string& outputPath) {
    int err = 0;
    zip* za = zip_open(zipPath.c_str(), ZIP_RDONLY, &err);
    if (!za) {
        std::cerr << "[ZIP] Erro ao abrir ZIP para extração: " << zipPath << std::endl;
        return false;
    }

    struct zip_stat st;
    if (zip_stat(za, entryName.c_str(), 0, &st) != 0) {
        std::cerr << "[ZIP] Arquivo não encontrado: " << entryName << std::endl;
        zip_close(za);
        return false;
    }

    zip_file* zf = zip_fopen(za, entryName.c_str(), 0);
    if (!zf) {
        std::cerr << "[ZIP] Falha ao abrir arquivo: " << entryName << std::endl;
        zip_close(za);
        return false;
    }

    std::ofstream out(outputPath, std::ios::binary);
    char* buffer = new char[st.size];
    zip_fread(zf, buffer, st.size);
    out.write(buffer, st.size);
    delete[] buffer;
    out.close();
    zip_fclose(zf);
    zip_close(za);

    std::cout << "[ZIP] Arquivo extraído: " << entryName << " -> " << outputPath << std::endl;
    return true;
}
