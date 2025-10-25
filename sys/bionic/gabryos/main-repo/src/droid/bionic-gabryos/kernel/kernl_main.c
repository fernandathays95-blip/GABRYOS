// kernl_main.c
// GABRYOS - Kernel principal com detecção automática de módulos

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

// Simulação de carregamento de módulo a partir de array de bytes
void kernel_load_module(const uint8_t* module, size_t size, const char* name) {
    printf("[KERNEL] Módulo %s carregado, tamanho: %zu bytes\n", name, size);
}

// Include dos módulos existentes
#include "USB_controll_module.h"
// Outros módulos podem ser incluídos aqui manualmente ou via script de build

// Função que inicializa todos os módulos
void init_modules() {
    // Inicializa USB
    kernel_load_module(USB_CONTROLL_KO, USB_CONTROLL_KO_SIZE, "USB_controll");

    // Se outros módulos existirem, inicialize aqui
    // kernel_load_module(OUTRO_MODULE, OUTRO_MODULE_SIZE, "OUTRO_MODULE");
}

int main() {
    printf("=====================================\n");
    printf("      GABRYOS KERNEL BOOT v1.0.0\n");
    printf("=====================================\n\n");

    init_modules();
    printf("[KERNEL] Todos os módulos carregados.\n");
    printf("[KERNEL] Loop principal iniciado. Monitorando novos módulos...\n\n");

    // Loop infinito simulando hotload de módulos
    while (1) {
        DIR* d;
        struct dirent* dir;
        d = opendir("./modules"); // pasta onde módulos .h adicionais podem ser adicionados
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                if (strstr(dir->d_name, "_module.h")) {
                    printf("[KERNEL] Detectado módulo: %s\n", dir->d_name);
                    // Aqui você pode chamar init do módulo correspondente
                    // Em C real, precisaria recompilar para incluir o módulo
                }
            }
            closedir(d);
        }

        sleep(1); // espera 1 segundo antes de checar novamente
    }

    return 0;
}
