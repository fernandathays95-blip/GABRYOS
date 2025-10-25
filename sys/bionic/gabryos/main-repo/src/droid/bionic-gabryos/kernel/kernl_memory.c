#include <stdio.h>
#include <stdlib.h>
#include "kernl_log.h"
#include "kernl_memory.h"

static gabryos_meminfo_t meminfo;

void gabryos_init_memory() {
    kernl_log(LOG_INFO, "MEM", "Inicializando gerenciador de memória...");

    // Simulação inicial (poderia vir de hardware real)
    meminfo.total = 4096;  // 4 GB
    meminfo.used  = 512;   // 512 MB usados
    meminfo.free  = meminfo.total - meminfo.used;
    meminfo.usage_percent = (float)meminfo.used / meminfo.total * 100.0f;

    kernl_log(LOG_INFO, "MEM", "Gerenciador de memória ativo.");
    gabryos_log_meminfo();
}

gabryos_meminfo_t gabryos_get_meminfo() {
    return meminfo;
}

void gabryos_log_meminfo() {
    char msg[128];
    snprintf(msg, sizeof(msg),
             "Memória Total: %lu MB | Usada: %lu MB | Livre: %lu MB (%.2f%%)",
             meminfo.total, meminfo.used, meminfo.free, meminfo.usage_percent);
    kernl_log(LOG_INFO, "MEM", msg);
}
