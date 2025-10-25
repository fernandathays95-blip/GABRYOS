#include "sentry.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char* SENTRY_DSN = NULL;

void sentry_init(const char* dsn) {
    SENTRY_DSN = strdup(dsn);
    printf("[SENTRY] Inicializado com DSN: %s\n", SENTRY_DSN);
}

void sentry_capture_event(const char* message, const char* level, const char* file, int line) {
    printf("[SENTRY][%s] %s (%s:%d)\n", level, message, file, line);
    // Aqui você poderia enviar o evento real via HTTP para o DSN configurado
}

void sentry_shutdown(void) {
    if (SENTRY_DSN) {
        free((void*)SENTRY_DSN);
        SENTRY_DSN = NULL;
        printf("[SENTRY] Shutdown concluído.\n");
    }
}
