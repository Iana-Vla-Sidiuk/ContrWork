﻿// 7. Напишите функцию для добавления дополнительных пробелов после окончания строки, чтобы длина строки стала равна n.
//Если строка уже из n или больше символов, то изменять строку не нужно. Заготовка: void padRight(char* a, int n);

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void padRight(char* a, int n) //создаем функцию добавления пробелов после окончания строки
{
	string s = a; //преобразуем массив символов в строку
	//добавляем дополнительные пробелы в конце строки, чтобы длина строки стала равна n, если n > длины строки
	if (s.length() < n) {
		for (int i = 0; i < n - s.length(); i++)
			s += ' ';
	}
	cout << s << "*Конец строки*" << endl; //выводим в консоль новую строку с дополнительными пробелами
}

int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	char a[100]; //создаем массив символов
	cout << "Введите строку: " << endl;
	cin.getline(a, 100); 
	int n;
	cout << "Введите число: " << endl;
	cin >> n;
	cout << "Строка с дополнительными пробелами: " << endl;
	padRight(a, n); //вызываем функцию
	system("pause");
	return 0;
}
