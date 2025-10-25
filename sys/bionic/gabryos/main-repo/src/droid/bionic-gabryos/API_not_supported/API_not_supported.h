#ifndef API_NOT_SUPPORTED_H
#define API_NOT_SUPPORTED_H

#include <string>
#include <iostream>

class APINotSupported {
public:
    // Construtor com número mínimo suportado
    APINotSupported(int minSupportedAPI);

    // Verifica se a API atual é suportada e mostra mensagem
    void checkAPI(int currentAPI = -1) const;

    // Getter do mínimo suportado
    int getMinSupportedAPI() const;

private:
    int minSupportedAPI;
};

#endif // API_NOT_SUPPORTED_H
