#include <windows.h>
#include <iostream>

void PressKey(char key) {
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = VkKeyScan(key); // converte caractere em tecla virtual
    ip.ki.dwFlags = 0;           // Key down
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.dwFlags = KEYEVENTF_KEYUP; // Key up
    SendInput(1, &ip, sizeof(INPUT));
}

int main() {
    std::cout << "Pressionando tecla A em 3 segundos..." << std::endl;
    Sleep(3000);
    PressKey('A'); // envia a tecla 'A' para o sistema
    std::cout << "Tecla enviada!" << std::endl;
    return 0;
}
