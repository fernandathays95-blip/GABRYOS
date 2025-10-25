#include "kernl_log.h"
#include <stdio.h>
#include <time.h>

// Códigos de cores ANSI
#define COLOR_RESET   "\033[0m"
#define COLOR_INFO    "\033[1;32m"   // Verde
#define COLOR_WARN    "\033[1;33m"   // Amarelo
#define COLOR_ERROR   "\033[1;31m"   // Vermelho
#define COLOR_DEBUG   "\033[1;36m"   // Ciano

static const char* getColor(LogLevel level) {
    switch (level) {
        case LOG_INFO:  return COLOR_INFO;
        case LOG_WARN:  return COLOR_WARN;
        case LOG_ERROR: return COLOR_ERROR;
        case LOG_DEBUG: return COLOR_DEBUG;
        default:        return COLOR_RESET;
    }
}

static const char* getLevelName(LogLevel level) {
    switch (level) {
        case LOG_INFO:  return "INFO";
        case LOG_WARN:  return "WARN";
        case LOG_ERROR: return "ERROR";
        case LOG_DEBUG: return "DEBUG";
        default:        return "LOG";
    }
}

void kernl_log(LogLevel level, const char* module, const char* message) {
    time_t now;
    struct tm* timeinfo;
    char buffer[16];

    time(&now);
    timeinfo = localtime(&now);
    strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);

    printf("%s[%s] [%s/%s] %s%s\n",
           getColor(level),
           buffer,
           getLevelName(level),
           module,
           message,
           COLOR_RESET);
}
