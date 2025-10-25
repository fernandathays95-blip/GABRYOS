#include "bundle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <zip.h> // libzip para abrir APK real

// Função auxiliar para extrair package e version do AndroidManifest.xml
static void parse_android_manifest(const char* manifest_content, char** package, char** version) {
    // Procura por package="..." e android:versionName="..."
    const char* pkg_ptr = strstr(manifest_content, "package=\"");
    const char* ver_ptr = strstr(manifest_content, "android:versionName=\"");

    if (pkg_ptr) {
        pkg_ptr += 9;
        const char* end = strchr(pkg_ptr, '"');
        size_t len = end - pkg_ptr;
        *package = (char*)malloc(len + 1);
        strncpy(*package, pkg_ptr, len);
        (*package)[len] = '\0';
    } else {
        *package = strdup("unknown");
    }

    if (ver_ptr) {
        ver_ptr += 20;
        const char* end = strchr(ver_ptr, '"');
        size_t len = end - ver_ptr;
        *version = (char*)malloc(len + 1);
        strncpy(*version, ver_ptr, len);
        (*version)[len] = '\0';
    } else {
        *version = strdup("1.0.0");
    }
}

GabryosBundleAPK* bundle_load(const char* apk_path) {
    struct stat st;
    if (stat(apk_path, &st) != 0) {
        printf("[BUNDLE] Erro: arquivo não encontrado: %s\n", apk_path);
        return NULL;
    }

    GabryosBundleAPK* bundle = (GabryosBundleAPK*)malloc(sizeof(GabryosBundleAPK));
    bundle->path = strdup(apk_path);
    bundle->size = st.st_size;

    // Abrir APK (ZIP) e ler AndroidManifest.xml
    int err = 0;
    zip_t* za = zip_open(apk_path, 0, &err);
    if (!za) {
        printf("[BUNDLE] Erro: não foi possível abrir APK.\n");
        bundle->package_name = strdup("unknown");
        bundle->version = strdup("1.0.0");
        return bundle;
    }

    struct zip_stat stz;
    zip_stat_init(&stz);
    if (zip_stat(za, "AndroidManifest.xml", 0, &stz) == 0) {
        zip_file_t* zf = zip_fopen(za, "AndroidManifest.xml", 0);
        if (zf) {
            char* content = (char*)malloc(stz.size + 1);
            zip_fread(zf, content, stz.size);
            content[stz.size] = '\0';
            parse_android_manifest(content, (char**)&bundle->package_name, (char**)&bundle->version);
            free(content);
            zip_fclose(zf);
        } else {
            bundle->package_name = strdup("unknown");
            bundle->version = strdup("1.0.0");
        }
    } else {
        bundle->package_name = strdup("unknown");
        bundle->version = strdup("1.0.0");
    }

    zip_close(za);

    printf("[BUNDLE] APK carregado: %s (Pacote: %s, Versão: %s, Tamanho: %zu bytes)\n",
           bundle->path, bundle->package_name, bundle->version, bundle->size);
    return bundle;
}

void bundle_unload(GabryosBundleAPK* bundle) {
    if (bundle) {
        free((void*)bundle->path);
        free((void*)bundle->package_name);
        free((void*)bundle->version);
        free(bundle);
        printf("[BUNDLE] Bundle descarregado.\n");
    }
}

void bundle_print_info(GabryosBundleAPK* bundle) {
    if (bundle) {
        printf("[BUNDLE] Pacote: %s\n", bundle->package_name);
        printf("[BUNDLE] Versão: %s\n", bundle->version);
        printf("[BUNDLE] Tamanho: %zu bytes\n", bundle->size);
    }
}
