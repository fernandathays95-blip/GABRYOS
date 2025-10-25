#ifndef KERNL_MEMORY_H
#define KERNL_MEMORY_H

#include <stddef.h>

typedef struct {
    unsigned long total;
    unsigned long used;
    unsigned long free;
    float usage_percent;
} gabryos_meminfo_t;

void gabryos_init_memory();
gabryos_meminfo_t gabryos_get_meminfo();
void gabryos_log_meminfo();

#endif // KERNL_MEMORY_H
