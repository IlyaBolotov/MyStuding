/*

*/

#include <iostream>
#include <cmath>

double z1() // 2.17
{
	int N, st;
	double sum = 0, current = 1;
	std::cout << "Введите степень многочлена: ";
	std::cin >> st;
	std::cout << "Введите точку, в которой хотите найти значение многочлена: ";
	std::cin >> N;
	for (int i = 1; i <= st; i++)
	{
		sum += current;
		current *= N / i;
	}
	sum += current;
	return sum;
}

double z2() // 2.18
{
	int i = 0, N;
	std::cout << "Введите число: ";
	std::cin >> N;
	while (N > 0)
	{
		i = i*10 + N % 10;
		N /= 10;
	}
	std::cout << "Введённое число наоборот будет: ";
	return i;
}

double z3() // 2.19
{
	int N, sum = 0;
	std::cout << "Введите крайний элемент последовательности: \n";
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		if (i % 3 == 0)
		{
			sum += -i;
		}
		else sum += i;
	}
	return sum;
}

double z4() // 2.20
{
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int N, st, i;


	std::cout << "Введите задание, ответ которого интересует\n";
	std::cout << "2.";
	std::cin >> i;
	
	switch (i)
	{
	case (17):
		std::cout << z1() << std::endl;
		break;

	case (18):
		std::cout << z2() << std::endl;
		break;

	case (19):
		std::cout << z3() << std::endl;
		break;

	case (20):
		std::cout << z4() << std::endl;
		break;

	default:
		break;
	}
	return 0;
}