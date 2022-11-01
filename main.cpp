#include <iostream>
#include <fstream>
#include <filesystem>
#include "library.h"
#include <cstdlib>
#include <vector>

class FileWriter{
public:
    void writeText(std::string filePath,std::vector<char> buffer)
    {
        std::string s(buffer.begin(), buffer.end());

        std::ofstream output(filePath, std::ios::app);
        output << s;
        output.close();
    }
};

class FileReader{
public:
    int n = 1;
    int key = 0;
    const int BUFFER_SIZE = 1024;
public:
    void readFile(std::string firstFilePath)
    {
        std::ifstream ifile(firstFilePath, std::ifstream::binary);
        if (ifile.good())
        {
            while (1)
            {
                std::vector<char> buffer (BUFFER_SIZE + 1, 0);
                ifile.read(buffer.data(), BUFFER_SIZE);
                std::streamsize s = ((ifile) ? BUFFER_SIZE : ifile.gcount());
                buffer[s] = 0;
                encryptBufferAndWrite(buffer, "otp" + firstFilePath);
                if(!ifile) break;
            }
            ifile.close();
        }
        else
        {
            std::cout << "error in file"<<std::endl;
            return;
        }
    }

    void encryptBufferAndWrite(std::vector<char> buffer,std::string filePath){
        int i = 0;
        while (i <= BUFFER_SIZE){
            if (buffer[i] == '\0'){i++; continue;}
            if (buffer[i] == 0) break;
            if (this->n == 1 || this->n == 3){buffer[i] = Encrypt(buffer[i],this->key);}
            if (this->n == 2){buffer[i] = Decrypt(buffer[i],this->key);}
            i++;
        }
        FileWriter *writer = new FileWriter;
        writer->writeText(filePath,buffer);
        //write buffer.data() in filePath from separate class
        std::cout << buffer.data() << std::endl;
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
        if (n > 4) {
            std::cout << "The command is not implemented!" << std::endl;
            continue;
        }
        if (n == 4){
            break;
        }
        system("clear");
        FileReader *fileReader = new FileReader;
        std::string firstFilePath; std::cout <<"Enter file path to read from: "; std::cin>> firstFilePath;
        firstFilePath = firstFilePath + ".txt";
        fflush(stdin);
        if (FILE *file = fopen(firstFilePath.c_str(), "r")) {fclose(file);}
        else {std::cout << "no file to read from" << std::endl;continue;}
        if (FILE *file = fopen(("otp" + firstFilePath).c_str(), "r")) {
            std::__fs::filesystem::remove(("otp" + firstFilePath));
        }

        fileReader->n = n;
        if (n == 3){
            fileReader->key = rand() % 26 + 1;
        } else {
            std::string key;
            std::cout <<"Enter key: "; std::cin>> key;
            fflush(stdin);
            fileReader->key = std::stoi(key);
        }
        fileReader->readFile(firstFilePath);
        delete (fileReader);
    }
}
