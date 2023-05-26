﻿// (C) Состязания-1. В метании молота состязается n спортсменов.Каждый из них сделал m бросков.Победителем считается тот спортсмен, у
//которого сумма результатов по всем броскам максимальна. Если перенумеровать спортсменов числами от 0 до n - 1, а попытки
//каждого из них – от 0 до m - 1, то на вход программа получает массив intA[n][m], состоящий из неотрицательных чисел.
//Программа должна определить максимальную сумму чисел в одной строке и вывести на экран эту сумму и номер строки,
//для которой достигается эта сумма.Если таких строк несколько,то выводится номер наименьшей из них.

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

        int max = 0, sum = 0, str = 0; //создаем переменные максимальной суммы, суммы в строке, номера строки с максимальной суммой
        for (int i = 0; i < n; i++) { //перебор строк
            for (int j = 0; j < m; j++) { //перебор столбцов
                if (j == 0) {
                    sum = 0;
                }
                sum = sum + A[i][j]; //подсчитываем сумму в строке
            }
            if (sum > max) { //ищем максимальную сумму в строке
                max = sum; 
                str = i;
            }
        }
        //выводим в консоль максимальную сумму в строке и номер строки с максимальной суммой
        cout << "Максимальная сумма чисел в одной строке: " << max << endl;
        cout << "Номер строки с максимальной суммой чисел: " << str << endl;
    }
    system("pause");
    return 0;
}

