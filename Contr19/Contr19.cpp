﻿// (E) Состязания - 3. Будем считать, что побеждает спортсмен, у которого максимален наилучший бросок.
//Если таких несколько, то из них побеждает тот, у которого наилучшая сумма результатов по всем попыткам. Если и таких несколько, 
//победителем считается спортсмен с минимальным номеров. Определите номер победителя соревнований.

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

        int max = 0; //создаем переменную максимального элемента в массиве
        int str = 0; //создаем переменную номера строки максимального элемента в массиве (победителя соревнований)
        int sum = 0; //создаем переменную суммы элементов в строке
        int sm = 0; //создаем переменную-счетик появления в строке максимального элемента 
        int sr = 0; //создаем переменную-счетик появления в строке элемента, равного максимальному
        int maxsum = 0; //создаем переменную суммы элементов в строке с максимльным элементом 
        for (int i = 0; i < n; i++) { //перебор строк
            for (int j = 0; j < m; j++) { //перебор столбцов
                if (j == 0) { //сбрасываем сумму в начале каждой новой строки
                    sum = 0;
                }
                sum = sum + A[i][j]; //подсчитываем сумму в строке
                if (A[i][j] > max) { //ищем максимальный элемент в массиве
                    max = A[i][j];
                    sm ++;
                }
                else if (A[i][j] == max) {
                    sr ++;
                }
                if (j == m - 1) { //в конце каждой строки обновляем сумму элементов в строке с максимальным элементом
                    if (sm > 0 || (sr > 0 && sum > maxsum)) {
                        maxsum = sum;
                        str = i;
                    }
                }
            }
            sm = 0;
            sr = 0;
        }
        //выводим в консоль номер строки с макисмальным элементом (победителя соревнований)
        cout << "Номер победителя соревнований: " << str << endl; 
    }
    system("pause");
    return 0;
}
