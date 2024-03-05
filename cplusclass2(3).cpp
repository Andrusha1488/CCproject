#include <string>
#include <iostream>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian");
    const int rows = 3;
    const int cols = 5;
    double array[rows][cols];


    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> array[i][j];
        }
    }


    cout << "Средние арифметические для каждой строки:" << endl;
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += array[i][j];
        }
        double average = sum / cols;
        cout << "Строка " << i + 1 << ": " << average << endl;
    }

    return 0;
}
