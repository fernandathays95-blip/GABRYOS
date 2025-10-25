// sys/bionic/gabryos/main-repo/src/droid/bionic-gabryos/kernel/kernl/kernl_memory.cc
#include "kernl_log.h"
#include <cstdint>
#include <vector>
#include <mutex>

using namespace kernl_log;

struct MemBlock {
    uintptr_t addr;
    size_t size;
    bool free;
};

static std::vector<MemBlock> heap;
static std::mutex heap_mtx;
static size_t total_simulated_memory = 64 * 1024 * 1024; // 64MB simulado

extern "C" {

// inicializa o gerenciador de memória simulado
void kernl_memory_init() {
    std::lock_guard<std::mutex> lk(heap_mtx);
    heap.clear();
    heap.push_back(MemBlock{0x10000000, total_simulated_memory, true});
    log(INFO, "Memory manager initialized with %zu bytes.", total_simulated_memory);
}

// aloca um bloco (simulado) e retorna endereço (0 = falha)
uintptr_t kernl_malloc(size_t size) {
    std::lock_guard<std::mutex> lk(heap_mtx);
    for (auto &b : heap) {
        if (b.free && b.size >= size) {
            uintptr_t addr = b.addr;
            if (b.size > size) {
                // split
                uintptr_t newAddr = b.addr + size;
                heap.push_back(MemBlock{ newAddr, b.size - size, true });
            }
            b.size = size;
            b.free = false;
            log(DEBUG, "Alloc %zu bytes at 0x%08x", size, (unsigned)addr);
            return addr;
        }
    }
    log(ERROR, "Alloc failed for %zu bytes", size);
    return 0;
}

// libera (simulado)
void kernl_free(uintptr_t addr) {
    std::lock_guard<std::mutex> lk(heap_mtx);
    for (auto &b : heap) {
        if (b.addr == addr) {
            b.free = true;
            log(INFO, "Freed block at 0x%08x", (unsigned)addr);
            return;
        }
    }
    log(WARN, "Attempted to free unknown addr 0x%08x", (unsigned)addr);
}

// estatísticas simples
size_t kernl_get_free_memory() {
    std::lock_guard<std::mutex> lk(heap_mtx);
    size_t freeBytes = 0;
    for (auto &b : heap) if (b.free) freeBytes += b.size;
    return freeBytes;
}

} // extern "C"
