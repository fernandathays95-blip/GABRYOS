// sys/bionic/gabryos/main-repo/src/droid/bionic-gabryos/kernel/kernl/kernl_log.h
#ifndef KERNL_LOG_H
#define KERNL_LOG_H

#include <cstdio>
#include <cstdarg>

namespace kernl_log {
    enum Level { INFO, WARN, ERROR, DEBUG };

    // simples logger C-style (stdout)
    void log(Level lvl, const char* fmt, ...);

    // convenience
    inline const char* lvl_to_str(Level l) {
        switch(l) {
            case INFO: return "INFO";
            case WARN: return "WARN";
            case ERROR: return "ERROR";
            case DEBUG: return "DEBUG";
            default: return "UNK";
        }
    }
}

#endif // KERNL_LOG_H
