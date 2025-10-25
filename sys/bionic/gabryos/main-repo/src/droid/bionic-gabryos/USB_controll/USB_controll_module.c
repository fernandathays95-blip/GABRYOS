// USB_controll_module.c
// GABRYOS - Inicializa o módulo USB incorporado

#include "USB_controll_module.h"
#include <stdio.h>

// Função que "carrega" o módulo USB no kernel
void init_usb_module() {
    printf("[GABRYOS/USB] Carregando módulo USB_controll...\n");
    // Função fictícia de kernel que aceita array de bytes
    kernel_load_module(USB_CONTROLL_KO, USB_CONTROLL_KO_SIZE);
    printf("[GABRYOS/USB] Módulo USB carregado com sucesso!\n\n");
}
