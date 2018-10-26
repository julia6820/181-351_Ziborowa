// LAB 7. Динамическое выделение памяти
//

#include "pch.h"
#include <iostream>

using namespace std;

void print(int ** array2D, int rows, int columns)
{
	for (int counter = 0; counter < rows; counter++)
	{
		for (int iter = 0; iter < columns; iter++)
		{
			std::cout << array2D[counter][iter] << "\t";
		}
		std::cout << std::endl;
	}
}



int main()
{
	int l1 = 4, l2 = 4;
	//int arr [l1][l2] = {0}; - в таком объявлении ТОЛЬКО КОНСТАНТНЫЕ РАЗМЕРНОСТИ

	//стековая память ограничена, при неправильном использовании стек переполняется
	//stack overflow)
	//размерности в массивов, выделяемых в стековой памяти, фиксированы и задаются константами 
	//int b[1000][1000] = {0}; - ПЕРЕПОЛНЕНИЕ СТЕКА


	//для использования свободной памяти ОС (heap - "куча")
	//объяляются динамические переменные по синтансису
	//указатель на тип имся переменной =new тип
	//или
	//тип*имя_переменной = new типж
	//работа с динамической памятью происходит через указатели

	//преимущества 
	//1)доступно гораздо больше памяти, нежели в стеке
	//2)размеры массивов и структур данных можно определять и менять во время работы приложения
	//особенность:
	//еси прилодение преднажначего для длительной рабрты, во избежание переполнения памяти 
	//созданные переменные и блоки памятии после использования
	//должны быть освобждены с помощбю оператора delete:
	//delete имя_переменной;

	int * ptr_int = new int;//в нераспределенной памяти создается блок размером
	// с int  и уазатель на него возвращется в переменную ptr_int

	//вызов утечки памяти
	for (int i = 0; i < 10000; i++)
	{
		long long * b = new long long;
		//1)каждый заод в стеке создается новый указатель 
		//2)выделяется блок mew long long; в куче(нераспределенной памяти)
		//приписанный к этой программе
		//3)стековая переменная b исчезает
		//4)а блок по-прежнему остается там же
		//5)при следущем заходе выделяется новый блок
		//совершать нужные действия с переменной
		delete b;//удалить блок памяти пока не потерян указатель на нее
	}
	//пара операторов new/delete - это одно из нововведений С++ относительно С
	//В динамической памяти могут выделяться только одномерыемассивы 
	//тип * имя_указатель = new тип [длина];
	//удаляются одномерные массивы с помощью записи 
	//delete[] имя_указателя;

	int * matr = new int[l1*l2];
	for (int row = 0; row < l2; row++)
	{
		for (int col = 0; col < l1; col++)
		{
			matr[row*l1 + col] = row * l1 + col;
		}
	}
	for (int row = 0; row < l2; row++)
	{
		for (int col = 0; col < l1; col++)
		{
			cout << matr[row*l1 + col] << "\t";
		}
	}
	//для выделения двумерного массива сначала создается одномерный массив, содержащий указатели на другие массивы (строки)

	//МОЖЕМ ЗАДАВАТЬ РАЗМРНОСТИ ПЕРЕМЕННЫМИ
	int ** dynamic2Darray = new int *[l1];
	//затем выделяется блок памяти под каждую строку и указатель на нее возвращается в созданный массив указателей 
	for (int i = 0; i < l1; i++)
	{
		dynamic2Darray[i] = new int[l2];// dynamic2Drray[i] имеет тип (int*) */
		for (int j = 0; j < l2; j++)
		{
			dynamic2Darray[i][j] = j;
		}
	}

	cout << endl;
	cout << "ARRAY IN DYNAMIC MEMORY:" << endl;
	cout << "*** dynamic2Darray[2] ***" << endl;
	cout << "Addiress" << "\t\t\t" << "Value" << endl;
	cout << "----------------------------------" << endl;
	
	for (int * pointer = &dynamic2Darray[0][0] - 4;
		pointer < &dynamic2Darray[0][0] + 8;
		pointer++)
	{
		//cout << /*указатель*\ << '\t' << /*значение*/ << endl;
		cout << "0x" << pointer << '\t' << *pointer << endl;
	}

	cout << endl;
	cout << "ARRAY IN DYNAMIC MEMORY:" << endl;
	cout << "*** dynamic2Darray[2] ***" << endl;
	cout << "Addiress" << "\t\t\t" << "Value" << endl;
	cout << "----------------------------------" << endl;
	
	for (int * pointer = &dynamic2Darray[2][0] - 4;
		pointer < &dynamic2Darray[2][0] + 8;
		pointer++)
	{
		//cout << /*указатель*\ << '\t' << /*значение*/ << endl;
		cout << "0x" << pointer << '\t' << *pointer << endl;
	}

	print(dynamic2Darray, l1, l2);

	//осв.
	for (int i = 0; i < l1; i++)
	{
		delete[] dynamic2Darray[i];//dynamic2Darray[i] имеет тип (int*) */
	}
	delete[] dynamic2Darray;

	//многомерные массивы фиксированной длины в стековой памятичаще всегосразмещаются сплошным блоком 
	//динамические - нет(где ОС выделила место под очередную строку - там она и будет находится
	//и между строками будет неизвестно что 

	int fixed_array[3][3] = { {10,20,30},
		{40,50,60},
		{70,80,90} };

	cout << endl;
	cout << "ARRAY IN DYNAMIC MEMORY:" << endl;
	cout << "*** dynamic2Darray[2] ***" << endl;
	cout << "Addiress" << "\t\t\t" << "Value" << endl;
	cout << "----------------------------------" << endl;

	for (int * pointer = &fixed_array[0][0] - 10;
		pointer < &fixed_array[0][0] + 10; 
		pointer++)

	{
		//cout << /*указатель*\ << '\t' << /*значение*/ << endl;
		cout << "0x" << pointer << '\t' << *pointer << endl;
	}

	getchar();
	return 0;
}

