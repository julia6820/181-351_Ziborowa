#include "pch.h"
#include <iostream>

int size, l;
int *a;
int func() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				l = a[j];
				a[j] = a[j + 1];
				a[j + 1] = l;
			}
		}
	}
	return 0;
}
int main()
{
	std::cin >> size;
	a = new int [size];
	for (int i = 0; i < size; i++) {
		std::cin >> a[i];
	}
	func();
	for (int i = 0; i < size; i++)
		std::cout << a[i] << " ";
}
