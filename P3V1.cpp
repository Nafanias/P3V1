#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

int main() {
    SetConsoleCP(1251); // Установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // Установка кодовой страницы win-cp 1251 в поток вывода

    std::ifstream file("C:/Users/vag99/Desktop/input.txt");
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл.";
        return 1;
    }

    std::vector<long> charCounters(256, 0);
    char ch;

    while (file.get(ch)) {
        ++charCounters[static_cast<unsigned char>(ch)];
    }

    file.clear();
    file.seekg(0); // Сброс указателя чтения в начало файла

    int col = 0;
    std::cout << "Цифры:" << std::endl;
    for (int i = 0; i < 256; ++i) {
        if (i >= 48 && i <= 57) {
            if (charCounters[i] > 0) { // Проверка наличия символа в файле
                if (col == 4) {
                    std::cout << '\n';
                    col = 0;
                }
                std::cout << static_cast<char>(i) << ": " << charCounters[i] << '\t';
                col++;
            }
        }
    }
    std::cout << '\n';
    std::cout << "Английские буквы:";
    for (int i = 0; i < 256; ++i) {
        if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122)) {
            if (charCounters[i] > 0) { // Проверка наличия символа в файле
                if (col == 4) {
                    std::cout << '\n';
                    col = 0;
                }
                std::cout << static_cast<char>(i) << ": " << charCounters[i] << '\t';
                col++;
            }
        }
    }
    std::cout << '\n';
    std::cout << "Русские буквы:" << std::endl;
    for (int i = 0; i < 256; ++i) {
        if ((i == 168) || (i == 184) || (i >= 192 && i <= 255)) {
            if (charCounters[i] > 0) { // Проверка наличия символа в файле
                if (col == 4) {
                    std::cout << '\n';
                    col = 0;
                }
                std::cout << static_cast<char>(i) << ": " << charCounters[i] << '\t';
                col++;
            }
        }
    }

    return 0;
}