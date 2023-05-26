// Для случайной матрицы осуществить ее абсолютную сортировку(от[0][0] к[n - 1][n - 1]).

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите число от 1 до 20: ";
    cin >> n; //вводим кол-во строк и столбцов
    if (n > 20 || n < 1) { //проверяем, введены валидные значения или нет
        cout << "Кол-во строк и столбцов должно быть от 1 до 20! ";
        exit;
    }
    else {
        int arr[20][20]; //создаем двумерный массив
        srand(time(NULL));
        cout << "Исходный массив: " << endl;
        for (int i = 0; i < n; i++) { //перебор строк
            for (int j = 0; j < n; j++) { //перебор столбцов
                arr[i][j] = rand() % 1000; //заполняем массив случайными числами 
                cout.width(3); //форматируем вывод
                cout << arr[i][j] << ' '; //выводим массив в консоль
            }
            cout << endl;
        }

        //сортируем массив пузырьком
        cout << "Отсортированный массив: " << endl;
        for (int k = 0; k < n * n; ++k) { 
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j != n - 1) {
                        if (arr[i][j + 1] < arr[i][j]) {
                            int tmp = arr[i][j + 1];
                            arr[i][j + 1] = arr[i][j];
                            arr[i][j] = tmp;
                        }
                    }
                    else {
                        if ((arr[i + 1][0] < arr[i][j]) && (i != n - 1)) {
                            int tmp = arr[i + 1][0];
                            arr[i + 1][0] = arr[i][j];
                            arr[i][j] = tmp;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) { //перебор строк
            for (int j = 0; j < n; j++) { //перебор столбцов
                cout.width(3); //форматируем вывод
                cout << arr[i][j] << ' '; //выводим в консоль отсортированный массив
            }
            cout << endl;
        }
    }
    system("pause");
    return 0;
}

