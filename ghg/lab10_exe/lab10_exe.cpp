// lab10_exe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

extern int func1(double p1, char p2);

int main()
{
	std::cout << func1(20, 10) << std::endl;
}

