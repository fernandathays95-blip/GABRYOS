#include "kernl_debug.h"
#include "kernl_log.h"
#include "kernl_memory.h"
#include "kernl_cpu.h"
#include "../NDKs/AndroidX/include/androidx_core.h"
#include "../NDKs/AndroidX/include/androidx_ui.h"
#include "../NDKs/AndroidX/include/androidx_system.h"
#include <stdio.h>

void gabryos_debug_panel() {
    kernl_log(LOG_INFO, "DEBUG", "========== GABRYOS DEBUG PANEL ==========");

    // 1️⃣ Informações da memória
    gabryos_log_meminfo();

    // 2️⃣ Informações da CPU
    gabryos_log_cpu_info();

    // 3️⃣ Informações do NDK AndroidX
    kernl_log(LOG_INFO, "NDK", "Verificando NDK AndroidX no painel...");
    androidx_checkNDK();
    kernl_log(LOG_INFO, "NDK", "NDK verificado com sucesso.");

    // 4️⃣ Teste de renderização UI
    kernl_log(LOG_INFO, "UI", "Renderizando UI de teste no painel...");
    androidx_renderWindow("Painel de Debug do GABRYOS");
    kernl_log(LOG_INFO, "UI", "UI de teste renderizada com sucesso.");

    kernl_log(LOG_INFO, "DEBUG", "========== FIM DO PAINEL DE DEBUG ==========");
}
