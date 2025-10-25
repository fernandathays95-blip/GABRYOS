#include "API_not_supported.h"

APINotSupported::APINotSupported(int apiNumber) {
    this->apiNumber = apiNumber;
}

void APINotSupported::showMessage() const {
    std::cout << "Unsupported API:" << apiNumber << std::endl;
}

int APINotSupported::getAPINumber() const {
    return apiNumber;
}

// Exemplo de uso
#ifdef TEST_API_NOT_SUPPORTED
int main() {
    APINotSupported api(44); // 44 como exemplo
    api.showMessage();
    return 0;
}
#endif
