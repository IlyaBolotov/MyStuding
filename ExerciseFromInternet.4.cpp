/*
https://acmp.ru/index.asp?main=task&id_task=16
*/
#include <iostream>

using namespace std;
int main()
{
	int N;     //Количество кубиков
	int p = 1;	 //Минимальное число кубиков на уровень
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество кубиков" << endl;
	cin >> N;
	while (N >= p)
	{
		N = N - p;
		if (N >= p)
		{
			p++;
		}
	}
	cout << "Число лесенок: " << p << endl;
		return 0;
}