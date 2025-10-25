// sys/bionic/gabryos/main-repo/src/droid/bionic-gabryos/kernel/kernl/kernl_main.cc
#include "kernl_boot.h"
#include "kernl_log.h"
#include <atomic>

using namespace kernl_log;

// estado global (simulado)
static KernelInfo g_info = { "GABRYOS_KERNEL", 0, 1, 0 };
static std::atomic<bool> g_running(false);

extern "C" {

void kernl_init() {
    g_running.store(true);
    log(INFO, "Kernel %s v%u.%u initializing...", g_info.name, g_info.versionMajor, g_info.versionMinor);
    // inicializações ordernadas
    log(DEBUG, "Initializing core subsystems...");
    // (drivers, memória, scheduler) -> chamados por outras unidades
    log(INFO, "Kernel initialized.");
}

void kernl_shutdown() {
    log(WARN, "Kernel shutting down...");
    g_running.store(false);
    log(INFO, "Kernel stopped.");
}

const KernelInfo* kernl_get_info() {
    return &g_info;
}

void kernl_tick(uint32_t seconds) {
    g_info.uptimeSeconds += seconds;
    log(DEBUG, "Tick: uptime=%llu", (unsigned long long)g_info.uptimeSeconds);
}

} // extern "C"
