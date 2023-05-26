// Создайте матрицу A[2*N+1]x[2*N+1], заполненную по спирали от центра по часовой стрелке, начиная с 0.

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "Введите число от 1 до 10: " << endl;
    cin >> N;
    int n, m;
    n = N * 2 + 1; //кол-во столбцов
    m = N * 2 + 1; //кол-во строк
    int s = m * n;
    //Создаем массив и заполняем его нулями.
    int array [30] [30] = { { 0 } };
    //Заполняем периметр массива против часовой стрелки.
    for (int x = 0; x < m; x++) {
        array[x][0] = s;
        s--;
    }
    for (int y = 1; y < n; y++) {
        array[m - 1][y] = s;
        s--;
    }
    for (int x = m - 2; x >= 0; x--) {
        array[x][n - 1] = s;
        s--;
    }
    for (int y = n - 2; y >= 1; y--) {
        array[0][y] = s;
        s--;
    }

    //Периметр заполнен. Продолжаем заполнять массив и задаём координаты ячейки, которую необходимо заполнить следующей.
    int c = 1;
    int d = 1;

    while (s > 1) {
        //Движемся вниз.
        while (array[c + 1][d] == 0) {
            array[c][d] = s;
            s--;
            c++;
        }
        //Движемся вправо.
        while (array[c][d + 1] == 0) {
            array[c][d] = s;
            s--;
            d++;
        }
        //Движемся вверх.
        while (array[c - 1][d] == 0) {
            array[c][d] = s;
            s--;
            c--;
        }
        //Движемся влево.
        while (array[c][d - 1] == 0) {
            array[c][d] = s;
            s--;
            d--;
        }
    }
    //Убираем незаполненную ячейку.
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (array[x][y] == 0) {
                array[x][y] = s;
            }
        }
    }
    //Выводим массив в консоль.
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
                cout.width(4);
                cout << array[x][y];
        }
        cout << endl;
    }
    system("pause");
    return 0;
}

