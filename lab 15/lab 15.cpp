// lab 15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include"exam.h"
#include<iostream>
#include<fstream>

int main()
{
	std::string name = "asdfqwer";

	Exam first;
	Exam second("123456789");
	Exam tre(name);
	Exam four(tre);
	name = "8";
	std::cout << second;

	getchar();
	return 0;
}



