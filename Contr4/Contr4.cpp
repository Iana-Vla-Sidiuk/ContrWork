// Напишите функцию myStrcmp – аналог библиотечной функции strcmp.Заготовка: int myStrcmp(char* a, char* b); 
// Например,i = myStrcmp("abc", "after"); //вернет отрицательное значение

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int myStrcmp(char* a, char* b) //создаем функцию - аналог strcmp
{
	int c;
	while (*a == *b && *a)
	{
		++a; ++b; //пропускаем равную часть строк  
	}
	if (*a - *b == 0) //возвращаем 0, если строки равны
		c = 0;
	else if (*a < *b || *a == '\0') //возвращаем -1, если первый неравный символ в 1 строке меньше, либо 1 строка меньше
		c = -1;
	else if (*a > *b || *b == '\0') //возвращаем 1, если первый неравный символ в 1 строке больше, либо 1 строка больше
		c = 1;
	return c; 
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
	cout << "Результат работы функции: " << myStrcmp(a, b) << endl; //выводим в консоль результат работы функции
	system("pause");
	return 0;
}
