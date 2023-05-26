// Напишите функцию myStrlen – аналог библиотечной функции strlen. Заготовка: int myStrlen(char* a);
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int myStrlen(char* a) //создаем функцию - аналог библиотечной функции strlen
{
	int length = 0;
	while (*a) {
		length ++;
		a++;
	}
	return(length);
}
int main() {
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	char a [100];
	cout << "Введите строку: " << endl;
	cin.get(a, 100); //вводим строку
	cout << "Строка " << a << " содержит " << myStrlen(a) << " символов" << endl; //выводим в консоль кол-во символов в строке
	system("pause");
	return 0;
}