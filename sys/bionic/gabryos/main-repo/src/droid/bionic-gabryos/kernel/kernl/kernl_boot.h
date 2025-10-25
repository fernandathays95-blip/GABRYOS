// sys/bionic/gabryos/main-repo/src/droid/bionic-gabryos/kernel/kernl/kernl_boot.h
#ifndef KERNL_BOOT_H
#define KERNL_BOOT_H

#include <cstdint>

// Estruturas básicas do kernel
typedef struct KernelInfo {
    const char* name;
    uint32_t versionMajor;
    uint32_t versionMinor;
    uint64_t uptimeSeconds;
} KernelInfo;

// Prototipos
extern "C" {
    void kernl_init();                       // inicia kernel
    void kernl_shutdown();                   // desliga kernel
    const KernelInfo* kernl_get_info();      // retorna info do kernel
    void kernl_tick(uint32_t seconds);       // incrementa uptime
}

#endif // KERNL_BOOT_H
