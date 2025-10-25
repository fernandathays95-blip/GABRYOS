#ifndef KERNL_MEMORY_H
#define KERNL_MEMORY_H

#include <stddef.h> // para size_t

#ifdef __cplusplus
extern "C" {
#endif

void kmem_init();
void* kmalloc(size_t size);
void kfree(void* ptr);
void kmem_usage();

#ifdef __cplusplus
}
#endif

#endif // KERNL_MEMORY_H
