﻿// (B) Дано число n и квадратный массив int A[n][n]. Проверьте, является ли массив симметричным относительно главной диагонали.
//Программа должна выводить слово yes для симметричного массива и слово no для несимметричного.
//Указание. Для элемента A[i][j] симметричным ему является элемент A[j][i].

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите число от 1 до 20: ";
    cin >> n; //вводим кол-во строк
    if (n > 20 || n < 1) { //проверяем, введены валидные значения или нет
        cout << "Число должно быть от 1 до 20! ";
        exit;
    }
    else {
        int A[20][20]; //создаем двумерный массив
        cout << "Введите элементы массива:" << endl;
        for (int i = 0; i < n; i++) { //заполняем массив
            for (int j = 0; j < n; j++) { 
                cin >> A[i][j];
            }
        }

        cout << "Введенный массив:" << endl;
        for (int i = 0; i < n; i++) { //выводим массив в консоль
            for (int j = 0; j < n; j++) { 
                cout.width(3);
                cout << A[i][j] << ' '; 
            }
            cout << endl;
        }

        int k = 0; //создаем переменную-счетчик симметричных элементов массива
        for (int i = 0; i < n; i++) { //проверяем элементы массива на симметричность
            for (int j = 0; j < n; j++) {
                if (A[i][j] == A[j][i]) 
                    k++;
            }
        }
 //выводим yes/no, если массив симметричный/несимметричный относительно главной диагонали
        cout << ((k == n * n) ? "yes" : "no") << endl; 
    }
    system("pause");
    return 0;
}

