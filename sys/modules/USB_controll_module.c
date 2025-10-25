#include "USB_controll_module.h"
#include <stdio.h>

extern void kernel_load_module(const uint8_t* module, size_t size, const char* name);

void init_usb_module() {
    printf("[GABRYOS/USB] Carregando módulo USB_controll...\n");
    kernel_load_module(USB_CONTROLL_KO, USB_CONTROLL_KO_SIZE, "USB_controll");
    printf("[GABRYOS/USB] Módulo USB carregado!\n");
}
