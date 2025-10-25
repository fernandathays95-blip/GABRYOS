#ifndef GABRYOS_BUNDLE_H
#define GABRYOS_BUNDLE_H

#include <stdint.h>
#include <stddef.h>

// Estrutura real de bundle APK
typedef struct {
    const char* path;          // caminho do arquivo APK
    const char* package_name;  // extraído do AndroidManifest.xml
    const char* version;       // extraído do AndroidManifest.xml
    size_t size;               // tamanho real do arquivo
} GabryosBundleAPK;

// Funções principais
GabryosBundleAPK* bundle_load(const char* apk_path);
void bundle_unload(GabryosBundleAPK* bundle);
void bundle_print_info(GabryosBundleAPK* bundle);

#endif // GABRYOS_BUNDLE_H
