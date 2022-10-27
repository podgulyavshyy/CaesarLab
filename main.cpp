#include <iostream>
#include "library.h"

int main() {
    int key = 0;
    while (true) {
        std::string text;
        std::cout << "Enter the text: ";
        std::cin >> text;
        fflush(stdin);
        std::string key;
        std::cout << "Enter key: ";
        std::cin >> key;
        fflush(stdin);
        std::cout << Encrypt(text,std::stoi(key)) << std::endl;
    }
}