// sys/bionic/gabryos/main-repo/src/droid/bionic-gabryos/kernel/kernl/kernl_drivers.cc
#include "kernl_log.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace kernl_log;

struct Driver {
    std::string name;
    bool loaded;
    int (*init_fn)(); // protótipo de init (0 = ok)
};

// drivers registrados (simulação)
static std::vector<Driver> drivers;

static int driver_init_stub() {
    log(INFO, "Driver stub init called.");
    return 0;
}

extern "C" {

// registra um driver simples
void kernl_register_driver(const char* name) {
    drivers.push_back(Driver{ std::string(name), false, driver_init_stub });
    log(INFO, "Registered driver: %s", name);
}

// tenta carregar todos
void kernl_load_drivers() {
    log(INFO, "Loading %zu drivers...", drivers.size());
    for (auto &d : drivers) {
        int r = d.init_fn();
        d.loaded = (r == 0);
        log(r == 0 ? INFO : ERROR, "Driver %s load %s", d.name.c_str(), d.loaded ? "OK" : "FAIL");
    }
}

// lista drivers (retorna quantidade)
int kernl_list_drivers(char outBuf[][64], int maxItems) {
    int i = 0;
    for (auto &d : drivers) {
        if (i >= maxItems) break;
        snprintf(outBuf[i], 64, "%s|%s", d.name.c_str(), d.loaded ? "LOADED" : "UNLOADED");
        ++i;
    }
    return i;
}

// unload (simulado)
void kernl_unload_all_drivers() {
    log(WARN, "Unloading drivers...");
    for (auto &d : drivers) d.loaded = false;
}

} // extern "C"
