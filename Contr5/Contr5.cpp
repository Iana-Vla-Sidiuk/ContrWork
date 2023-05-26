//Напишите функцию для удаления всех пустых пробелов после окончания строки. Заготовка: void trimRight(char* a);

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void trimRight(char* a) //создаем функцию удаления пробелов после окончания строки
{
	if (!a) return; // нет строки
	char* spc = a; // создаем указатель на начало последней группы пробелов
	for (; *a; a++) 
		if (*a != ' ') 
			spc = a + 1; 
	        *spc = 0; // задаем новый конец строки
	return;
}
int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	char a[100]; //создаем строку
	cout << "Введите строку: " << endl;
	cin.getline(a, 100);
	trimRight(a);
	//выводим в консоль строку без пробелов в конце строки
	cout << "Удаление пробелов в конце строки: " << a << "*конец строки*" << endl; 
	system("pause");
	return 0;
}
