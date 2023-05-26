﻿// (D) Состязания - 2. Победителем соревнований объявляется тот спортсмен, у которого максимален наилучший результат по всем броскам.
//Таким образом, программа должна найти значение максимального элемента в данном массиве, а также его индексы
//(то есть номер спортсмена и номер попытки).Программа выводит значение максимального элемента, затем номер строки и
//номер столбца, в котором он встречается. Если в массиве несколько максимальных элементов, то нужно вывести
//минимальный номер строки, в которой встречается такой элемент, а если в этой строке таких элементов несколько, 
//то нужно вывести минимальный номер столбца. Не забудьте, что все строки и столбцы нумеруются с 0.

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "Введите кол-во спортсменов от 1 до 10: ";
    cin >> n; //вводим кол-во спортсменов
    cout << "Введите кол-во бросков от 1 до 10: ";
    cin >> m; //вводим кол-во бросков
    if (n > 10 || m > 10 || n < 1 || m < 1) { //проверяем, введены валидные значения или нет
        cout << "Кол-во строк и столбцов должно быть от 1 до 10! ";
        exit;
    }
    else {
        cout << "Результаты соревнований: " << endl;
        int A[10][10]; //создаем двумерный массив
        srand(time(NULL));
        for (int i = 0; i < n; i++) { //перебор строк
            for (int j = 0; j < m; j++) { //перебор столбцов
                A[i][j] = rand() % 10; //заполняем массив случайными числами 
                cout << A[i][j] << ' '; //выводим массив в консоль
            }
            cout << endl;
        }

        //создаем переменные максимального элемента в массиве, номера строки и номера столбца максимального элемента
        int max = 0, str = 0, st = 0; 
        for (int i = 0; i < n; i++) { //перебор строк
            for (int j = 0; j < m; j++) { //перебор столбцов
                if (A[i][j] > max) { //ищем максимальный элемент в массиве
                    max = A[i][j];
                    str = i;
                    st = j;
                }
            }
        }
        //выводим в консоль максимальный элемент в массиве, номер строки и номер столбца максимального элемента в массиве
        cout << "Максимальный элемент в массиве: " << max << endl;
        cout << "Номер строки максимального элемента в массиве: " << str << endl;
        cout << "Номер столбца максимального элемента в массиве: " << st << endl;
    }
    system("pause");
    return 0;
}
