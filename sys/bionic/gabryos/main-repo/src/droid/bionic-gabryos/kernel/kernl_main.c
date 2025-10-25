#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kernl_log.h"
#include "../NDKs/AndroidX/include/androidx_core.h"
#include "../NDKs/AndroidX/include/androidx_ui.h"
#include "../NDKs/AndroidX/include/androidx_system.h"

#define GABRYOS_VERSION "1.0.0-alpha"
#define GABRYOS_CODENAME "BIONIC-KERNEL"

void gabryos_boot_logo() {
    printf("\n=====================================\n");
    printf("      GABRYOS SYSTEM BOOT v%s\n", GABRYOS_VERSION);
    printf("      Codename: %s\n", GABRYOS_CODENAME);
    printf("=====================================\n\n");
}

void gabryos_init_drivers() {
    kernl_log(LOG_INFO, "BOOT", "Iniciando GABRYOS...");
kernl_log(LOG_INFO, "DRIVER", "Drivers carregados com sucesso.");
kernl_log(LOG_WARN, "NDK", "Algumas APIs podem estar indisponíveis.");
kernl_log(LOG_ERROR, "CORE", "Falha ao inicializar componente gráfico!");
kernl_log(LOG_DEBUG, "KERNEL", "Thread principal aguardando tarefas...");
}

void gabryos_check_ndk() {
    printf("[GABRYOS/NDK] Verificando NDK AndroidX...\n");
    androidx_checkNDK();
    printf("[GABRYOS/NDK] Verificação concluída.\n\n");
}

void gabryos_init_system() {
    printf("[GABRYOS/CORE] Inicializando sistema AndroidX...\n");
    androidx_initCore();

    const char* os_name = androidx_getSystemProperty("os.name");
    const char* os_version = androidx_getSystemProperty("os.version");

    printf("[GABRYOS/CORE] Sistema: %s v%s\n", os_name, os_version);
    printf("[GABRYOS/CORE] Inicialização concluída.\n\n");
}

void gabryos_render_ui() {
    printf("[GABRYOS/UI] Renderizando ambiente gráfico principal...\n");
    androidx_renderWindow("Painel principal do GABRYOS");
    printf("[GABRYOS/UI] Interface pronta.\n\n");
}

int main() {
    gabryos_boot_logo();
    gabryos_init_drivers();
    gabryos_check_ndk();
    gabryos_init_system();
    gabryos_render_ui();

    printf("[GABRYOS/KERNEL] Sistema inicializado com sucesso.\n");
    printf("[GABRYOS/KERNEL] Aguardando tarefas do usuário...\n\n");

    return 0;
}
