// lab9.cpp Перегрузка 
//

#include "pch.h"
#include <iostream>
#include <sstream> 

using std::cout;
using std::cin;
using std::endl;
//перегрузка - объявление нескольких ф-ций, методов или опреаторов, которые тоже являются ф-циями с одинаковыми именами, но разным набором аргументов 
//различие ф-ций по одному выходному параметру не является перегрузкой, так как на месте вызова компилятору недстаточноинформации, чтобы решить,
//какую ф-цию 


//унарные и бмнарные операторы перегружаются по-разному 
//унарные - в самом классе(получается новый метод класса)
//бинарные - как отдельную ф-цию 

//бинарные операторы прописываются 

//matrix & matrix::operstor += (matrix & second_matr)
//{
//this -> setElem(i,j, first_matr second_matr.gerElem(i,j)


class matrix 
{

private:

	int * matr = new int[rows*columns];
	int rows, columns;
	int *res = new int[rows*columns];

public:

	matrix();
	~matrix();

	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);


	int getElem(int row, int col);
	int getRows()
	{ 
		return rows; }
	int getColumns()
	{ 
		return columns; }

	bool input();
	void transp();


	void printM()

	{

		for (int i = 0; i < rows; i++)

		{

			for (int j = 0; j < columns; j++)

			{

				cout << matr[i*columns + j] << "\t";

			}
			cout << std::endl;
		}

	};


friend std::ostream & operator << (std::ostream & os, matrix & matr);
friend matrix & operetor + (matrix & matr, matrix & matr2);
friend matrix & operetor - (matrix & matr, matrix & matr2);
friend matrix & operetor * (matrix & matr, matrix & matr2);

};
class vector : public matrix
{
private:
	int*vec = new int[n];
	int n;
public:
	vector();
	~vector();
	int getN()
	{
		return n;
	}
	int getElem(int i);
	bool enter();
	void kvec(int k)
	{
		for (int i = 0; i < n; i++)
		{
			vec[i] *= k;
			cout << vec[i] << ' ';
		}
	};
	bool mulvec(vector vec2);
	friend vector & operator *(vector vec, vector vec2);
	friend vector & operator *(vector vec, int k);
	friend std::ostream & operator <<(std::ostream vc, vector vec);
	friend vector & operator +(vector vec, vector vec2);
	friend vector & operator -(vector vec, vector vec2);
};

vector:: vector() {}
vector::~vector() {}
int main()
{
	matrix matrA, matrB, res;
	vector vec, vec2;
	int k;
	cout << res;
	vec.enter();
	cout << vec;
	return 0;
}
matrix::matrix(){}
matrix::~matrix() {}

bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows() && columns == matr2.getColumns.columns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i*columns + j] += matr2.getElem(i, j);
			}
		}
		printM();
		return true;
	}
	else
	{
		cout << "columns and rows are not equal";
		return false;
	}
}
void matrix::transp()
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matr[j*columns + i] << " ";
		}
		cout << std::endl;
	}
}
std::ostream & operator << (std::ostream & os, matrix & matr)
{
	for (int i = 0; i < matr.getRows(); i++)
	{
		for (int j = 0; j < matr.getColumns(); j++)
		{
			os << matr.getElem(i, j) << "\t";
		}
		os << std::endl;
	}
	return os;
}
matrix & operator+(matrix & matr, matrix & matr2)
{
	matrix res;
	if (matr.getRows() == matr2.getRows() && matr.getColumns() == matr2.getColumns())
	{
		for (int i = 0; i < matr.getRows(); i++)
		{
			for (int j = 0; j < matr.getColumns(); j++)
			{
				matr.matr[i*matr.getColumns + j] = matr.getElem(i, j) + matr2.getElem(i, j);
			}
		}
		return matr;
	}
	else {
		cout << "error"; return matr;
	}
}
matrix & operator~(matrix & matr, matrix & matr2)
{
	if (matr.getRows() == matr2.getRows() && matr.getColumns() == matr2.getColumns())
	{
		for (int i = 0; i < matr.getRows(); i++)
		{
			for (int j = 0; j < matr.getColumns(); j++)
			{
				matr.matr[i*matr.getColumns + j] = matr.getElem(i, j) - matr2.getElem(i, j);
			}
		}
		return matr;
	}
	else {
		cout << "error"; return matr;
	}
}
matrix & operator*(matrix & matr, matrix & matr2)
{
	matrix res;
	res.columns = mart2.columns;
	res.rows = matr.rows;
	res.matr = new int[res.getRows*res.columns];
	if (matr.getColumns() == matr2.getRows())
	{
		for (int i = 0; i < matr.getRows(); i++)
		{
			for (int j = 0; j < matr.getColumns(); j++)
			{
				int sum = 0;
				for (int k = 0; k < matr.getColumns(); k++)
				{
					sum += matr.getElem(i, k)*mart2.getElem(k, j);
				}
				res.matr[i*matr2.getColumns() + j] = sum;
			}
		}
		return res;
	}
	else {
		cout << "error"; return matr;
	}
}
vector & operator*(vector vec, vector vec2)
{
	int scal = 0;
	if (vec.getN() == vec2.getN())
	{
		for (int i = 0; i < vec2.getN(); i++)
		{
			scal += vec.getElem(i)*vec2.getElem(i);
		}
		cout << scal;
		return vec;
	}
	else
	{
		return vec;
	}
}
vector & operator*(vector vec, int k)
{
	for (int i = 0; i < vec.getN(); i++)
	{
		vec.vec[i] *= k;
	}
	return vec;
}
std::ostream & operator << (std::ostream vc, vector vec)
{
	for (int i = 0; i < vec.getN(); i++)
	{
		vc << vec.getElem(i) << " ";
	}
	return vc;
}
vector & operator +(vector vec, vector vec2)
{
	if (vec.getN() == vec2.getN())
	{
		for(int i = 0; i < vec2.getN(); i++)
		{
			vec.vec[i] = vec.getElem(i) + vec2.getElem(i);
		}
	}
}
vector & operator -(vector vec, vector vec2)
{
	if (vec.getN() == vec2.getN())
	{
		for (int i = 0; i < vec2.getN(); i++)
		{
			vec.vec[i] = vec.getElem(i) - vec2.getElem(i);
		}
	}
}
bool matrix::multMatrix(matrix matr2)
{
	if (columns == matr2.getRows())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < mart2.getColumns(); j++)
			{
				int sum = 0;
				for (int k = 0; k < columns; k++)
				{
					sum += matr[i*columns + k] * matr2.getElem(k, j);
				}
				res[i*mart2.getColumns() + j] = sum;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				cout << res[i*matr2.getColumns() + j] << "\t";
			}
			cout << std::endl;
		}
		return true;
	}
	else
	{
		cout << "col1 != row2";
		return false;
	}
}
int matrix::getElem(int row, int col)
{
	if (row&rows && col<columns &&row>-1 && col > -1);
	{
		return matr[row*columns + col];
	}
	else
	{
		cout << "error";
		return -1;
	}
}
bool matrix::input()
{
	cout << "rows=";
	cin >> rows;
	cout << "columns";
	cin >> columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matr[i*columns + j];
		}
		cout << endl;
	}
	return true;
}
bool vector::mulvec(vector vec2)
{
	int scal = 0;
	if (n - vec2.getN())
	{
		for (int i = 0; i < n; i++)
		{
			scal += vec[i] * vec2.getElem(i);
		}
		cout << scal;
		return true;
	}
	else {
		return false;
	}
}
bool vector::enter()
{
	cout << "n=";
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		cout << "vec[" << j << "]=";
		cin >> vec[j];
	}
	return true;
}
int vector::getElem(int i)
{
	if (i > -1 && i < n)
	{
		return vec[i];
	}
	else
	{
		cout << "error";
		return -1;
	}
}