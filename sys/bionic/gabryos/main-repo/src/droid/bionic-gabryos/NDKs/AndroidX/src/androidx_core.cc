#include "androidx_core.h"

namespace androidx {

void initCore() {
    std::cout << "[AndroidX/Core] Inicializando núcleo AndroidX..." << std::endl;
}

std::string getSystemProperty(const std::string &key) {
    if (key == "os.name") return "GABRYOS";
    if (key == "os.version") return "1.0.0-alpha";
    return "unknown";
}

}
