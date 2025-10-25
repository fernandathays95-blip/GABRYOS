#ifndef GABRYOS_ZIPARCHIVE_H
#define GABRYOS_ZIPARCHIVE_H

#include <string>
#include <vector>

struct ZipEntry {
    std::string name;
    size_t size;
};

class ZipArchive {
private:
    std::string zipPath;
    std::vector<ZipEntry> entries;

public:
    ZipArchive(const std::string& path);
    ~ZipArchive();

    bool open();                         // Abre o arquivo ZIP
    void close();                         // Fecha o arquivo ZIP
    const std::vector<ZipEntry>& list();  // Lista arquivos dentro do ZIP
    bool extract(const std::string& entryName, const std::string& outputPath); // Extrai arquivo específico
};

#endif // GABRYOS_ZIPARCHIVE_H
