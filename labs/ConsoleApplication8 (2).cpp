// ConsoleApplication8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	//создать целочисленные переменные а=300 
	  //b=560
	  //вывести на экран a*a*b*b
	  //					b/a
	  //					символ_A + a
	int a = 300, b = 560;
	std::cout << "a*a*b*b=" << a * a*b*b << std::endl;
	int max_int = 0b01111111111111111111111111111111;
	std::cout << "SizeofInt = " << sizeof(int);

	std::cout << "b/a=" << b / a << std::endl;
	std::cout << "A+" << a << std::endl;
	/*Вывести таблицу на экран
	тип данных - занимаемый размер - минимальное значение - максимальное значение
	bool
	char
	int
	short
	long
	long long
	double
	*/
	std::cout << "\n";
	std::cout << "name\t\t|size of \t|min\t\t\t|max\t\n";
	std::cout << "bool \t\t|" << sizeof(bool) << "\t\t|" << 0b0000000 << "\t\t\t|" << 0b10000000 << "\t\n";
	std::cout << "int\t\t|" << sizeof(int) << "\t\t|" << INT_MIN << "\t\t| " << INT_MAX << "\t\n";
	std::cout << "char\t\t|" << sizeof(char) << "\t\t|" << CHAR_MIN << "\t\t\t| " << CHAR_MAX << "\t\n";
	std::cout << "short\t\t|" << sizeof(short) << "\t\t|" << SHRT_MIN << "\t\t\t| " << SHRT_MAX << "\t\n";
	std::cout << "long\t\t|" << sizeof(long) << "\t\t|" << LONG_MIN << "\t\t| " << LONG_MAX << "\t\n";
	std::cout << "double\t\t|" << sizeof(double) << "\t\t|" << DBL_MIN << "\t\t| " << DBL_MAX << "\t\n";
	std::cout << "long long\t|" << sizeof(long long) << "\t\t|" << LLONG_MIN << "\t| " << LLONG_MAX << "\t\n";
}
