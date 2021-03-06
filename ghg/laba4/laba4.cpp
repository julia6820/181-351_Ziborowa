// laba4.cpp : Операторы цикла. Операторы. Указатели
//

#include "pch.h"
#include <iostream>

int main()
{
	//Указатель(pointer) - переменная, хранящая адрес(смещение) каких-либо данных, 
	//переменных в оперативной памяти 
	//фактически, указатель - это unsigned int or unsigned long long с адресом,
	// так как дробных или отрицательных адресов ет 
	int a; 
	int b;
	int *ptr_int;
	ptr_int = &a;//унарный рператор амперсент - оператори получения адеса
	int *ptr_dbl;
	ptr_dbl = &b;
	//2.размер указателя 
	//все указатели всегда одной и той же разрядности(размра)
	//каким бы не был огромный тип данных(строка,об
	//указатель на него всегда будет заимать 4/8 байт, что является осовным 
	//преимуществом указателей std::cout << "int pointer size =" << sizeof(ptr_int) << std::andl;
	using namespace std;
	std::cout << "int pointer size = " << sizeof(ptr_int) << std::endl;
	std::cout << "double pointer size = " << sizeof(ptr_dbl) << std::endl;
	std::cout << "char pointer size = " << sizeof(char*) << std::endl;
	std::cout << "long long pointer size = " << sizeof(long long*) << std::endl;
	std::cout << "bool pointer size = " << sizeof(bool*) << std::endl;
	//
	int arr1D[10] = { 1,50,11,12,101 };
	std::cout << "arr = " << arr1D << std::endl;
	std::cout << "arr = arr[0] = " << *arr1D << std::endl;
	std::cout << "*(arr+4) = arr[4] =" << *(arr1D+4) << std::endl;
}
