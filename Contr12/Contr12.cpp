﻿// Напишите функцию deleteChar, которая удаляет все вхождения символа c в строке a. Заготовка:void deleteChar(char* a, char c);

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void deleteChar(char* a, char c) //создаем функцию, которая удаляет все вхождения указанного символа в строке
{
	string s = a; //преобразуем массив символов в строку
	for (int i = 0; i < s.length(); i++) { //удаляем все вхождения символа в строке
		if (s[i] == c) {
			s.erase(i, 1);
			i--;
		}
	}
	cout << s << endl; //выводим в консоль строку с удаленными символами
}
int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	char a[100]; //создаем массив символов
	cout << "Введите строку: " << endl;
	cin.getline(a, 100);
	char c; //создаем переменную для символа, который нужно удалить из строки
	cout << "Введите символ, который нужно удалить: " << endl;
	cin >> c;
	cout << "Вывод строки после удаления повторений символа " << c << " в строке: " << endl;
	deleteChar(a, c); //вызывавем функцию, которая удаляет все вхождения указанного символа в строке
	system("pause");
	return 0;
}
