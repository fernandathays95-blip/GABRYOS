#ifndef GABRYOS_SENTRY_H
#define GABRYOS_SENTRY_H

#include <stdint.h>
#include <stddef.h>

// Estrutura básica de erro
typedef struct {
    const char* message;
    const char* file;
    int line;
    const char* level; // "INFO", "WARN", "ERROR"
} SentryEvent;

// Funções principais
void sentry_init(const char* dsn);
void sentry_capture_event(const char* message, const char* level, const char* file, int line);
void sentry_shutdown(void);

#endif // GABRYOS_SENTRY_H
