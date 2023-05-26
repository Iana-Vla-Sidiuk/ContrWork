// Напишите функцию myStrcat – аналог библиотечной функции strcat.Заготовка: void myStrcat(char* a, char* b);

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void myStrcat(char* a, char* b) //создаем функцию объединения строк
{
	int i, j;
	for (i = 0; a[i] != '\0'; i++); //ищем индекс нулевого символа 1 строки
	for (j = 0; b[j] != '\0'; j++) //записываем 2 строку в конце 1 строки
		a[i + j] = b[j];
	a[i + j] = '\0'; //добавляем новый нулевой символ в конце 1 строки
}

int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	char a[100]; //создаем строку 1
	cout << "Введите строку 1: " << endl;
	cin.getline(a, 100);
	char b[100]; //создаем строку 2
	cout << "Введите строку 2: " << endl;
	cin.getline(b, 100);
	myStrcat(a, b); //вызываем функцию
	cout << "Новая строка: " << endl;
	cout << a << endl; //выводим новую строку в консоль
	system("pause");
	return 0;
}
