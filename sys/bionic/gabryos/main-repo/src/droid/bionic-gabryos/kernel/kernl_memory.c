#include "kernl_memory.h"
#include "kernl_log.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static size_t total_allocated = 0;
static size_t allocation_count = 0;

void kmem_init() {
    total_allocated = 0;
    allocation_count = 0;
    kernl_log(LOG_INFO, "MEM", "Subsistema de memória inicializado.");
}

void* kmalloc(size_t size) {
    if (size == 0) {
        kernl_log(LOG_WARN, "MEM", "Tentativa de alocar 0 bytes.");
        return NULL;
    }

    void* ptr = malloc(size);
    if (ptr == NULL) {
        kernl_log(LOG_ERROR, "MEM", "Falha ao alocar memória!");
        return NULL;
    }

    total_allocated += size;
    allocation_count++;

    char msg[128];
    snprintf(msg, sizeof(msg), "Alocado %zu bytes (total: %zu bytes, %zu blocos).", size, total_allocated, allocation_count);
    kernl_log(LOG_INFO, "MEM", msg);

    return ptr;
}

void kfree(void* ptr) {
    if (ptr == NULL) {
        kernl_log(LOG_WARN, "MEM", "Tentativa de liberar ponteiro nulo.");
        return;
    }

    free(ptr);
    allocation_count--;

    char msg[128];
    snprintf(msg, sizeof(msg), "Bloco liberado (restam %zu blocos).", allocation_count);
    kernl_log(LOG_DEBUG, "MEM", msg);
}

void kmem_usage() {
    char msg[128];
    snprintf(msg, sizeof(msg), "Uso atual: %zu bytes alocados em %zu blocos.", total_allocated, allocation_count);
    kernl_log(LOG_INFO, "MEM", msg);
}
