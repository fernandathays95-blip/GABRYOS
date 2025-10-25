#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kernl_memory.h"
#include "kernl_log.h"
#include "../NDKs/AndroidX/include/androidx_core.h"
#include "../NDKs/AndroidX/include/androidx_ui.h"
#include "../NDKs/AndroidX/include/androidx_system.h"

#define GABRYOS_VERSION "1.0.0-alpha"
#define GABRYOS_CODENAME "BIONIC-KERNEL"

// Exibição do logo de boot
void gabryos_boot_logo() {
    printf("\n=====================================\n");
    printf("      GABRYOS SYSTEM BOOT v%s\n", GABRYOS_VERSION);
    printf("      Codename: %s\n", GABRYOS_CODENAME);
    printf("=====================================\n\n");
}

// Inicialização de drivers
void gabryos_init_drivers() {
    kernl_log(LOG_INFO,  "BOOT",   "Iniciando GABRYOS...");
    kernl_log(LOG_INFO,  "DRIVER", "Drivers carregados com sucesso.");
    kernl_log(LOG_WARN,  "NDK",    "Algumas APIs podem estar indisponíveis.");
    kernl_log(LOG_ERROR, "CORE",   "Falha ao inicializar componente gráfico!");
    kernl_log(LOG_DEBUG, "KERNEL", "Thread principal aguardando tarefas...");
}

// Checagem do NDK AndroidX
void gabryos_check_ndk() {
    kernl_log(LOG_INFO, "NDK", "Verificando NDK AndroidX...");
    androidx_checkNDK();
    kernl_log(LOG_INFO, "NDK", "Verificação concluída.");
}

// Inicialização do sistema AndroidX
void gabryos_init_system() {
    kernl_log(LOG_INFO, "CORE", "Inicializando sistema AndroidX...");
    androidx_initCore();

    const char* os_name = androidx_getSystemProperty("os.name");
    const char* os_version = androidx_getSystemProperty("os.version");

    char msg[128];
    snprintf(msg, sizeof(msg), "Sistema: %s v%s", os_name, os_version);
    kernl_log(LOG_INFO, "CORE", msg);
    kernl_log(LOG_INFO, "CORE", "Inicialização concluída.");
}

// Renderização da interface
void gabryos_render_ui() {
    kernl_log(LOG_INFO, "UI", "Renderizando ambiente gráfico principal...");
    androidx_renderWindow("Painel principal do GABRYOS");
    kernl_log(LOG_INFO, "UI", "Interface pronta.");
}

int main() {
    gabryos_boot_logo();
    gabryos_init_drivers();
    gabryos_check_ndk();
    gabryos_init_system();
    gabryos_render_ui();
    gabryos_init_memory();
    kernl_log(LOG_INFO, "KERNEL", "Sistema inicializado com sucesso.");
    kernl_log(LOG_DEBUG, "KERNEL", "Aguardando tarefas do usuário...");

    return 0;
}
