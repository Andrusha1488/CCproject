#include <iostream>
#include <string>
#include <algorithm>

std::string removeVowels(std::string word) {
    std::string result = "";
    for (char c : word) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }
    return result;
}

std::string removeConsonants(std::string word) {
    std::string result = "";
    for (char c : word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            result += c;
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string word;
    int choice;

    std::cout << "Введите слово: ";
    std::cin >> word;

    std::cout << "Выберите действие:" << std::endl;
    std::cout << "1. Написать задом наперед." << std::endl;
    std::cout << "2. Убрать гласные." << std::endl;
    std::cout << "3. Убрать согласные." << std::endl;
    std::cout << "4. Перемешать буквы в слове." << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::reverse(word.begin(), word.end());
        std::cout << "Результат: " << word << std::endl;
        break;
    case 2:
        std::cout << "Результат: " << removeVowels(word) << std::endl;
        break;
    case 3:
        std::cout << "Результат: " << removeConsonants(word) << std::endl;
        break;
    case 4:
        std::random_shuffle(word.begin(), word.end());
        std::cout << "Результат: " << word << std::endl;
        break;
    default:
        std::cout << "Неверный выбор" << std::endl;
        break;
    }

    return 0;
}