// laba3theCaesarshift.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
int main()
{

	string input;
	int count = 0, length, sdvig;

	cout << "Enter your text: \n";
	getline(cin, input);
	cout << "Sdvig: \n";
	cin >> sdvig;

	length = (int)input.length();

	for (count = 0; count < length; count++)
	{
		if (isalpha(input[count]))
		{
			input[count] = tolower(input[count]);
			for (int i = 0; i < sdvig; i++)
			{
				if (input[count] == 'z')
					input[count] == 'a';
				else
					input[count]++;
			}
		}
	}

	cout << "Results: \n"
		<< input << endl;
	system("pause");
	return 0;
}
