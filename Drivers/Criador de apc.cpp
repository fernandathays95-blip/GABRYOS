#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string appName;
    std::string userCode;
    std::string userLayout;

    std::cout << "Digite o nome do aplicativo: ";
    std::getline(std::cin, appName);

    std::cout << "Digite o código do aplicativo (linha única para teste): ";
    std::getline(std::cin, userCode);

    std::cout << "Digite o layout do aplicativo (linha única para teste): ";
    std::getline(std::cin, userLayout);

    // Criando a pasta APC_NOME
    std::string folderName = "APC_" + appName;
    system(("mkdir " + folderName).c_str());

    // conf.mpl
    std::ofstream conf(folderName + "/conf.mpl");
    conf << "APC NOME(" << appName << ")\n";
    conf << "PID: MM-apc-" << appName << "-\n";
    conf.close();

    // Apc (código do usuário)
    std::ofstream apcFile(folderName + "/Apc");
    apcFile << userCode << "\n";
    apcFile.close();

    // Layout.mpl
    std::ofstream layoutFile(folderName + "/Layout.mpl");
    layoutFile << userLayout << "\n";
    layoutFile.close();

    std::cout << "Arquivo APC criado com sucesso na pasta: " << folderName << std::endl;

    return 0;
}
