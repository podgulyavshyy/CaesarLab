#include <iostream>
#include "library.h"

int main() {
    int key = 0;
    while (true) {
        int n;
        try {
            std::string s;
            std::cout << "Chose the command: ";
            getline(std::cin, s);
            n = std::stoi(s);
            if (n < 0) throw 1;
        }
        catch (...) {
            std::cerr << "You must answer with a whole number >= 0." << std::endl;
            continue;
        }
        fflush(stdin);
        if (n > 2) {
            std::cout << "The command is not implemented!" << std::endl;
            continue;
        }
        system("clear");
        if (n == 1) {
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
        if (n == 2) {
            std::string text;
            std::cout << "Enter the text: ";
            std::cin >> text;
            fflush(stdin);
            std::string key;
            std::cout << "Enter key: ";
            std::cin >> key;
            fflush(stdin);
            std::cout << Decrypt(text,std::stoi(key)) << std::endl;
        }
    }
}