#include <iostream> 
#include <iostream>
#include <string>
#include <list>
#include <iterator> 
#include <ctime>
#include <set>
#include <map> 


#include <stack> //  подключаем библиотеку для использования стека 
#include <queue> // подключили библиотеку для использования очереди  
#include <deque> // подключили библиотеку для использования дека

/*
#include <list> // подключили библиотеку для использования списка
#include <set> // подключили библиотеку для использования множества
#include <map> // подключили библиотеку для использования ассоциативного массива
*/
// int main()
//{
// setlocale(LC_ALL, "rus");
	/*
Стек — это структура данных, которая работает
по принципу FILO(first in — last out; первый пришел — последний ушел).

В стеке нет индексов,т.е. нельзя обратиться к определенному элементу.
Каждый элемент имеет указатель на следующий элемент.
Головной элемент указывает на NULL.

Достоинство: операции удаления и добавления элемента делаются за const время.

*/
	/*
	std::stack<int> stackInt;//stack <тип данных> <имя>; -создание стека 
	int i = 0, a = 0;
	std::cout << "Введите 5 целых чисел:  " << std::endl;
	while (i != 5) {
		std::cin >> a;
		stackInt.push(a); // добавляем введенное число  
		i++;
	}

	if (stackInt.empty()) // проверяем пуст ли стек (нет)  
		std::cout << "Стек не пуст";

	std::cout << "Верхний элемент стека: " << stackInt.top() << std::endl;
	stackInt.pop(); // удаляем верхний элемент  

	std::cout << "Новый верхний элемент: " << stackInt.top() << std::endl;
*/
	// ЗАДАНИЕ 1 
/*
Проверить правильность расстановки скобок (,),[,],{,}
в введенном пользователем выражении за линейное время
(один просмотр выражения).
2+4-5(87192479_7348){72648]76823[] -> no
({}) -> yes
({)} -> no
*/

	//решение 
/*
Считываем элемент.
Если это (,[ или {, то помещаем ее в стек.
Если это ),] или }, то сравниваем с верхним элементом стека.
Если образовалась пара, то верхний элемент стека удаляем.
Иначе - выражение неправильное.

Когда все элементы считали, то проверяем стек на пустоту.
Если стек пуст, то выражение правильное.
Иначе - выражение неправильное.
*/
/*
bool ArePair(char opening, char closing)
{
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	return false;
}
bool AreParanthesesBalanced(std::string exp)
{
	std::stack<char>  S;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !ArePair(S.top(), exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true : false;
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::string expression;
	std::cout << "Enter an expression:  ";
	std::cin >> expression;
	if (AreParanthesesBalanced(expression))
		std::cout << "Balanced\n";
	else
		std::cout << "Not Balanced\n";

	system("pause");
	return 0;
}
*/

	
/*
Очередь — это структура данных, которая построена по принципу
LILO (last in — last out: последним пришел — последним вышел).
*/
 
	/*
	std::queue <int> MyQueue; // создали очередь 
	std::cout << "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		MyQueue.push(a); // добавляем в очередь элементы
	}
	std::cout << std::endl;
	std::cout << "Первый элемент в очереди: " << MyQueue.front() << std::endl;
	MyQueue.pop(); // удаляем элемент из очереди  
	std::cout << "Первый элемент (после удаления): " << MyQueue.front() << std::endl;

	if (!MyQueue.empty()) // проверяем пуста ли очередь (нет) 
		std::cout << "Очередь не пуста!";
		*/
	/*
Очередь с приоритетом (priority_queue) — это обычная очередь,
но в ней новый элемент добавляется в такое место,
чтобы очередь была отсортирована по убыванию.
*/
/*
	std::priority_queue <int> priority_q; // объявляем приоритетную очередь 

	std::cout << "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		priority_q.push(a); // добавляем элементы в очередь
	}
	// выводим первый 
	std::cout << "Первый элемент очереди: " << priority_q.top();
	*/
	// ЗАДАНИЕ 2 
/*
Программа на вход получает список школьников.
В каждой строке сначала записан номер класса (число, равное 9, 10 или 11),
затем (через пробел) – фамилия.
Необходимо вывести список по классам:
сначала всех учащихся 9 класса, затем – 10, затем – 11.
Внутри одного класса порядок вывода должен быть таким же, как на входе.
*/

/*
Создаем 3 очереди (свою для каждого класса).

Считываем очередную строку. В зависимости от класса
добавляем фамилию в соответствующую очередь

Когда все считали, выводим очереди последовательно:

сначала для 9 класса, затем очередь 10 класса,
а в самом конце очередь 11 класса.
*/
/*
std::queue <std::string> q9, q10, q11;
std::string cl, name;
while (1)
{
	std::getline(std::cin, cl);
	if (cl == "0")break;
	if (cl[0] == '9')
	{
		name.assign(cl.begin() + 2, cl.end());
		q9.push(name);
	};
	if (cl[0] == '1')
	{
		if (cl[1] == '0')
		{
			name.assign(cl.begin() + 3, cl.end());
			q10.push(name);
		}
		if (cl[1] == '1')
		{
			name.assign(cl.begin() + 2, cl.end());
			q11.push(name);
		}
	};
}
std::cout << "9 class" << std::endl;
while (!q9.empty())
{
	std::cout << q9.front() << std::endl;
	q9.pop();
}
std::cout << "10 class" << std::endl;
while (!q10.empty())
{
	std::cout << q10.front() << std::endl;
	q10.pop();
}
std::cout << "11 class" << std::endl;
while (!q9.empty())
{
	std::cout << q11.front() << std::endl;
	q11.pop();
}
*/
/*
Деком (англ. deque – аббревиатура от double-ended queue, двухсторонняя очередь)
называется структура данных, в которую можно
удалять и добавлять элементы
как в начало, так и в конец.

Дек хранится в памяти так же, как и
очередь.
*/
int main()
{
	std::queue<std::string> Class_9;
	std::queue<std::string> Class_10;
	std::queue<std::string> Class_11;

	int input_class;
	std::cin >> input_class;

	while (input_class != 0)
	{

		if (input_class == 9)
		{
			std::string student;
			std::cin >> student;
			Class_9.push(student);
		}

		if (input_class == 10)
		{
			std::string student;
			std::cin >> student;
			Class_10.push(student);
		}

		if (input_class == 11)
		{
			std::string student;
			std::cin >> student;
			Class_11.push(student);
		}

		std::cin >> input_class;

	}

	while (!Class_9.empty())
	{
		std::cout << Class_9.front() << std::endl;
		Class_9.pop();
	}

	while (!Class_10.empty())
	{
		std::cout << Class_10.front() << std::endl;
		Class_10.pop();
	}

	while (!Class_11.empty())
	{
		std::cout << Class_11.front() << std::endl;
		Class_11.pop();
	}

}

//ЗАДАЧА 3 
/*
Проверить, является ли введенная строка палиндромом
(читается одинаково слева направо и справа налево). Использовать дек.
*/
/*int main()
{
	std::deque<std::string>p1;
	std::string input;
	std::cin >> input;
	p1.push_back(input);
	while (p1.size() > 1 && p1.front() == p1.back())
	{
		if (p1.front() == p1.back())
		{
			p1.pop_front();
			if (!p1.empty())
				p1.pop_back();
		}
		else
			std::cout << "no" << std::endl;
	}
	if (p1.size() == 1)
	{
		p1.pop_back();
		std::cout << "yes" << std::endl;
	}
	else
		std::cout << "no" << std::endl;
*/


/*

Считываем строку посимвольно. каждый символ добавляем в хвост дека.
Далее сравниваем первый и последний символ дека.
*/

//ЗАДАЧА 4 
/*
Описать структуру данных List.
Продемонстрировать работу с этой структурой:
ввод, вывод,
добавление элемента и удаление,
сортировка.
*/

/*
using namespace std;

int main() {
	list <int> mylist;
	list <int> listmerge = { 7, 8, 9 };

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 6; j++) {
			mylist.push_back(i); // добавили 10 элементов
		}
	}

	copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	mylist.insert(mylist.end(), 6);  // добавили новый элемент

	copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	mylist.unique();  // удалили все дубликаты
	list <int> ::iterator it;

	for (it = mylist.begin(); it != mylist.end(); it++) {
		cout << (*it) << " ";
	}

	mylist.merge(listmerge);  // присвоили список 
	for (it = mylist.begin(); it != mylist.end(); it++) {
		cout << (*it) << " ";
	}
	return 0;
}
*/

//ЗАДАЧА 5 
/*
Описать структуру данных Set.
Продемонстрировать работу с этой структурой:
ввод, вывод,
добавление элемента и удаление.
*/
/*
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	set <int> mst; //создали set

	cout << "Добавление значений: " << endl; //случайные числа
	for (int i = 0; i < 10; i++) {
		int random = rand() % 10 + 1;
		mst.insert(random);
		cout << i + 1 << ") " << random << endl;
	}

	set <int> ::iterator it = mst.begin();

	cout << "Отсортированный: " << endl;
	for (int i = 1; it != mst.end(); i++, it++) { //сравниваем на неравенство
		cout << *it << " ";
	}

	system("pause");
	return 0;
}
*/

//ЗАДАЧА 6 
/*
Описать структуру данных map.
Продемонстрировать работу с этой структурой:
ввод, вывод,
добавление элемента и удаление.
*/
/*
using namespace std;

int main()
{
	map <string, string> passport = { { "Ziborowa", "Julia" }, //string - ключ, int - значение
								   { "Gorbunov", "Maksim" } }; 

	passport["maxim"] = "Konova";   
	passport["andrey"] = "Tichonova"; 
	passport["dima"] = "Zaytcev";     

	cout << "Size: " << passport.size() << endl;

	map <string, string> ::iterator full_name; // создали итератор на passport

	full_name = passport.find("andrey"); // находим ячейку
	passport.erase(full_name);           // удаляем

	cout << "Size: " << passport.size();
}
*/

//В этот контейнер можно помещать сразу два значения. 
//Это ассоциативный контейнер, который работает по принципу — [ключ — значение]. 
//При добавлении нового элемента контейнер будет отсортирован по возрастанию.
//При создании map все его элементы будут иметь значение нуля.

// ЗАДАЧА 7 
/*
Составить таблицу сравнения по времени выполнения операций
для дека, стека, очереди, списка, множества, массива из n элементов.
Список операций:
добавление в начало
добавление в конец
добавление в середину
удаление из начала
удаление с конца
удаление из середины
значение элемента из начала
значение элемента с конца
значение элемента из середины
*/
/*
	std::stack<int> stackInt;//stack <тип данных> <имя>; -создание стека
	int i = 0, a = 0;
	std::cout << "Введите 5 целых чисел:  " << std::endl;
	while (i != 5) {
		std::cin >> a;
		deque.push_back(a);
		deque.push_front(a);
		//stackInt.push(a);  добавляем введенное число
		i++;
	}

	if (deque.empty()) // проверяем пуст ли стек (нет)
		std::cout << "Стек не пуст";

	std::cout << "Верхний элемент стека:" << stackInt.top() << std::endl;
	stackInt.pop(); // удаляем верхний элемент
	*/
	//system("pause");
	//return 0;
	
//}