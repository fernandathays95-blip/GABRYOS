#ifndef KERNL_LOG_H
#define KERNL_LOG_H

#ifdef __cplusplus
extern "C" {
#endif

// Níveis de log
typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_DEBUG
} LogLevel;

// Função principal de log
void kernl_log(LogLevel level, const char* module, const char* message);

#ifdef __cplusplus
}
#endif

#endif // KERNL_LOG_H
