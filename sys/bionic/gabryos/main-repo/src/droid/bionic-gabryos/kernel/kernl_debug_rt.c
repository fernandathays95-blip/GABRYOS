#include "kernl_debug_rt.h"
#include "kernl_log.h"
#include "kernl_memory.h"
#include "kernl_cpu.h"
#include "../NDKs/AndroidX/include/androidx_core.h"
#include "../NDKs/AndroidX/include/androidx_ui.h"
#include "../NDKs/AndroidX/include/androidx_system.h"
#include <stdio.h>
#include <unistd.h>  // sleep

void gabryos_debug_panel_rt() {
    kernl_log(LOG_INFO, "DEBUG", "========== GABRYOS DEBUG PANEL (RT) ==========");

    // Inicializa módulos
    gabryos_init_memory();
    gabryos_init_cpu();

    // Verifica NDK e UI no início
    kernl_log(LOG_INFO, "NDK", "Verificando NDK AndroidX...");
    androidx_checkNDK();
    kernl_log(LOG_INFO, "NDK", "NDK verificado com sucesso.");

    kernl_log(LOG_INFO, "UI", "Renderizando UI de teste inicial...");
    androidx_renderWindow("Painel de Debug RT");
    kernl_log(LOG_INFO, "UI", "UI renderizada com sucesso.");

    kernl_log(LOG_INFO, "DEBUG", "Iniciando loop de monitoramento...");

    while (1) {
        // Atualiza memória
        gabryos_log_meminfo();

        // Atualiza CPU
        gabryos_log_cpu_info();

        // Pequena pausa para não travar o terminal
        sleep(1);
    }
}
