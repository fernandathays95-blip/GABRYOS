#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

// Função de kernel para carregar módulo
void kernel_load_module(const uint8_t* module, size_t size, const char* name) {
    printf("[KERNEL] Módulo %s carregado, tamanho: %zu bytes\n", name, size);
}

// Inclui os módulos
#include "modules/USB_controll_module.h"
#include "modules/USB_controll_module.c"
#include "modules/TEST_module.h"
#include "modules/TEST_module.c"

// Inicializa todos os módulos conhecidos
void init_modules() {
    init_usb_module();
    init_test_module();
}

int main() {
    printf("=====================================\n");
    printf("      GABRYOS KERNEL BOOT v1.0.0\n");
    printf("=====================================\n\n");

    init_modules();
    printf("[KERNEL] Todos os módulos carregados.\n");
    printf("[KERNEL] Loop principal iniciado. Monitorando novos módulos...\n\n");

    while (1) {
        DIR* d;
        struct dirent* dir;
        d = opendir("./modules");
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                if (strstr(dir->d_name, "_module.h")) {
                    printf("[KERNEL] Detectado módulo: %s\n", dir->d_name);
                    // Aqui você pode simular hotload
                }
            }
            closedir(d);
        }
        sleep(1);
    }

    return 0;
}
