// Напишите функцию myStrcpy – аналог библиотечной функции strcpy.Заготовка: void myStrcpy(char* a, char* b);
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;


void myStrcpy(char* a, char* b) //создаем функцию, которая копирует строку b в строку a
{
	while ((*a++ = *b++));
}

int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	char b[100]; //создаем строку, которую нужно скопировать
	cout << "Введите строку, которую нужно скопировать: " << endl;
	cin.get(b, 100); 
	char a[100]; //создаем строку, в которую нужно скопировать 1 строку
	myStrcpy(a, b); //вызываем функцию
	cout << "Скопированная строка: " << endl;
	cout << a << endl; //выводим скопированную строку в консоль
	system("pause");
	return 0;
}
