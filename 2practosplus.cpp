#include <iostream>
#include <cmath>


int main() {
    setlocale(LC_ALL, "Russian");
    float a;
    float b;
    float c;
    float e = 1;
    int operation = 0;
    while (operation != 9) {
        std::cout << "Добро пожаловать в калькулятор! Что вы хотите сделать?" << std::endl;
        std::cout << "1. Сложение двух чисел" << std::endl;
        std::cout << "2. Вычитание одного числа из другого" << std::endl;
        std::cout << "3. Перемножение двух чисел" << std::endl;
        std::cout << "4. Деление двух чисел" << std::endl;
        std::cout << "5. Возведение первого числа в степень второго" << std::endl;
        std::cout << "6. Квадратный корень числа" << std::endl;
        std::cout << "7. Найти один процент от числа" << std::endl;
        std::cout << "8. Факториал числа" << std::endl;
        std::cout << "9. Выйти из программы" << std::endl;
        std::cin >> operation;
        switch (operation) {
        case 1:
            std::cout << "Введите первое число: ";
            std::cin >> a;
            std::cout << "Введите второе число: ";
            std::cin >> b;
            std::cout << "Сумма " << a << " и " << b << " равна " << a + b << std::endl;
            break;
        case 2:
            std::cout << "Введите первое число: ";
            std::cin >> a;
            std::cout << "Введите второе число: ";
            std::cin >> b;
            std::cout << "Разность " << a << " и " << b << " равна " << a - b << std::endl;
            break;
        case 3:
            std::cout << "Введите первое число: ";
            std::cin >> a;
            std::cout << "Введите второе число: ";
            std::cin >> b;
            std::cout << "Произведение " << a << " и " << b << " равно " << a * b << std::endl;
            break;
        case 4:
            std::cout << "Введите первое число: ";
            std::cin >> a;
            std::cout << "Введите второе число: ";
            std::cin >> b;
            if (b == 0) {
                std::cout << "Ошибка. На ноль делить нельзя." << std::endl;
            }
            else {
                std::cout << "Частное " << a << " и " << b << " равно " << a / b << std::endl;
            }
            break;
        case 5:
            std::cout << "Введите число: ";
            std::cin >> a;
            std::cout << "Введите степень числа: ";
            std::cin >> b;
            std::cout << "Число " << a << " в степени " << b << " равно " << pow(a, b) << std::endl;
            break;
        case 6:
            std::cout << "Введите число: ";
            std::cin >> a;
            if (a >= 0) {
                std::cout << "Квадратный корень " << a << " равен " << sqrt(a) << std::endl;
            }
            else {
                std::cout << "Ошибка. Из отрицательного числа корень не выводится" << std::endl;
            }
            break;
        case 7:
            std::cout << "Введите число: ";
            std::cin >> a;
            std::cout << "Один процент от числа " << a << " равен " << a * 0.01 << std::endl;
            break;
        case 8:
            std::cout << "Введите число: ";
            std::cin >> a;
            c = a;
            while (c > 0) {
                e *= c;
                c--;
            }
            std::cout << "Факториал числа " << a << " равен " << e << std::endl;
            e = 1;
            break;
        case 9:
            break;
        default:
            std::cout << "такой операции нет в списке." << std::endl;
            break;
        }
    }
    return 0;
}


