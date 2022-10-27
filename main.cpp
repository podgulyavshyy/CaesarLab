#include <iostream>
#include <fstream>
#include "library.h"

int main() {
    std::string key = "3";
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
        std::ifstream in("file2.txt");
        std::ofstream f("file1.txt");
        while (!in.eof()) {
            std::string text;
            getline(in, text);
            if (n == 1) text = Encrypt(text, std::stoi(key));
            if (n == 2) text = Decrypt(text, std::stoi(key));
            std::cout << text << std::endl;
            f << text << std::endl;
        }
    }
}