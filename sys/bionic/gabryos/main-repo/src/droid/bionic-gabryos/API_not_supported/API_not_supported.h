#ifndef API_NOT_SUPPORTED_H
#define API_NOT_SUPPORTED_H

#include <string>
#include <iostream>

class APINotSupported {
public:
    // Construtor com número da API
    APINotSupported(int apiNumber);

    // Função que mostra a mensagem de API não suportada
    void showMessage() const;

    // Getter do número da API
    int getAPINumber() const;

private:
    int apiNumber;
};

#endif // API_NOT_SUPPORTED_H
