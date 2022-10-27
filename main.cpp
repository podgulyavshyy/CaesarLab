#include <iostream>
#include <fstream>
#include <filesystem>
#include "library.h"

class FileWorker{
public:
    void Run(std::string firstFilePath, std::string secondFilePath, int mode, int key)
    {
        if (FILE *file = fopen(firstFilePath.c_str(), "r")) {
            fclose(file);}
        else return;
        if (FILE *file = fopen(secondFilePath.c_str(), "r")) {
            std::__fs::filesystem::remove(secondFilePath);
        }
        std::ifstream in(firstFilePath);
        std::ofstream f(secondFilePath);
        while (!in.eof()) {
            std::string text;
            getline(in, text);
            if (mode == 1) text = Encrypt(text, key);
            if (mode == 2) text = Decrypt(text, key);
            if (mode == 3) text = Encrypt(text, key);
            f << text << std::endl;
        }
    }
};


int main() {
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
        if (n > 3) {
            std::cout << "The command is not implemented!" << std::endl;
            continue;
        }
        system("clear");
        FileWorker *fileWorker = new FileWorker;
        std::string firstFilePath; std::cout <<"Enter file path to read from: "; std::cin>> firstFilePath;
        fflush(stdin);
        std::string secondFilePath; std::cout <<"Enter file path to wright in: "; std::cin>> secondFilePath;
        fflush(stdin);
        std::string key;
        if (n == 3) key = rand() % 12 + 1;
        else std::cout <<"Enter key: "; std::cin>> key;
        fflush(stdin);
        fileWorker->Run(firstFilePath, secondFilePath, n, std::stoi(key));
        delete (fileWorker);
    }
}