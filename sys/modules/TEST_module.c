#include "TEST_module.h"
#include <stdio.h>

extern void kernel_load_module(const uint8_t* module, size_t size, const char* name);

void init_test_module() {
    printf("[GABRYOS/TEST] Carregando módulo TEST_module...\n");
    kernel_load_module(TEST_MODULE_DATA, TEST_MODULE_SIZE, "TEST_module");
    printf("[GABRYOS/TEST] TEST_module carregado!\n");
}
