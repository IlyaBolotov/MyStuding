/*
https://acmp.ru/index.asp?main=task&id_task=18
*/

#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n; //Число, факториал которого находим
	long int f = 1; //Сам факториал
	cout << "Введите число, факториал которого надо найти" << endl;
	cin >> n;
	if (n == 0)
	{
		f = 1;
	}
	else
	{
		while (n > 0)
		{
			f = f * n;
			n = n - 1;
		}
	}
	cout << "Ваш факториал: " << f << endl;
	return 0;
}
