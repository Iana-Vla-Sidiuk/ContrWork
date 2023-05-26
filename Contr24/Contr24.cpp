// Отсортировать столбцы матрицы по результату среднего арифметического элементов.

#include <iostream>
#include <cstdlib>
using namespace std;

double SumColumn(double** K, int n, int idx) { //создаем функцию подсчета суммы столбцов
    double sum = 0.;
    for (int i = 0; i < n; i++)
        sum += K[i][idx];
    return sum;
}

int main() {   
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n, p = 0;
    cout << "Введите число от 1 до 10: "; cin >> n;

    double** K = new double* [n], sum; //создаем динамический массив
    for (int i = 0; i < n; i++)
        K[i] = new double[n];

    for (int i = 0; i < n; i++) { //заполняем массив случайными числами
        for (int j = 0; j < n; j++) { 
            K[i][j] = rand() % 9 + 1;
            cout << K[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++) { //подсчитываем и выводим в консоль сумму элементов и среднее арифметическое столбцов
        sum = SumColumn(K, n, i);
        cout << "Столбец " << i + 1 << ":  сумма = " << sum << ", среднее арифметическое = " << sum / n << endl;
    }
    cout << endl;

    for (int j = 1; j < n; j++) //сортируем столбцы матрицы по среднему арифметическому элементов
        for (int k = 0; k < n - j; k++)
            if (SumColumn(K, n, k) > SumColumn(K, n, k + 1)) {
                p = 1;
                for (int i = 0; i < n; i++)
                    swap(K[i][k], K[i][k + 1]);
            }

    if (p) {
        for (int i = 0; i < n; i++) { //выводим отсортированный массив в консоль
            for (int j = 0; j < n; j++)
                cout << K[i][j] << " ";
            cout << "\n";
        }

        for (int i = 0; i < n; i++) {
            sum = SumColumn(K, n, i);
            cout << "Столбец " << i + 1 << ": сумма = " << sum << ", среднее арифметическое = " << sum / n << endl;
        }
    }
    else cout << "Матрица отсортирована" << endl;

    for (int i = 0; i < n; i++)
        delete[]K[i]; //очищаем память
    delete[]K; 
    system("pause");
    return 0;
}