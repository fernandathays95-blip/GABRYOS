#include "API_not_supported.h"

// Construtor
APINotSupported::APINotSupported(int minSupportedAPI) {
    this->minSupportedAPI = minSupportedAPI;
}

// Verifica se API atual é suportada
void APINotSupported::checkAPI(int currentAPI) const {
    // Se currentAPI não for informado, usamos valor simulado
    if (currentAPI == -1) {
        currentAPI = 44; // Exemplo de API detectada
    }

    if (currentAPI < minSupportedAPI) {
        std::cout << "Unsupported API:" << currentAPI 
                  << " (minimum supported: " << minSupportedAPI << ")" << std::endl;
    } else {
        std::cout << "API " << currentAPI << " is supported." << std::endl;
    }
}

// Getter do mínimo suportado
int APINotSupported::getMinSupportedAPI() const {
    return minSupportedAPI;
}

// Exemplo de teste standalone
#ifdef TEST_API_NOT_SUPPORTED
int main() {
    APINotSupported apiChecker(45); // 45 é a API mínima suportada
    apiChecker.checkAPI();          // Usa API simulada = 44
    apiChecker.checkAPI(46);        // Exemplo de API suportada
    return 0;
}
#endif
