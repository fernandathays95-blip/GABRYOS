#include "kernl_cpu.h"
#include "kernl_log.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/sysinfo.h>

static int cpu_cores = 0;
static float cpu_usage = 0.0f;

// Inicializa dados da CPU
void gabryos_init_cpu() {
    cpu_cores = sysconf(_SC_NPROCESSORS_ONLN);
    cpu_usage = 0.0f; // começa zerado

    char msg[128];
    snprintf(msg, sizeof(msg), "CPU detectada: %d núcleos", cpu_cores);
    kernl_log(LOG_INFO, "CPU", msg);

    gabryos_log_cpu_info();
}

// Função de log da CPU
void gabryos_log_cpu_info() {
    // Aqui podemos colocar leitura real de uso se disponível
    // Por enquanto, apenas exibe núcleos e uso inicial
    char msg[128];
    snprintf(msg, sizeof(msg), "Núcleos ativos: %d | Carga atual: %.2f%%", cpu_cores, cpu_usage);
    kernl_log(LOG_INFO, "CPU", msg);
}
