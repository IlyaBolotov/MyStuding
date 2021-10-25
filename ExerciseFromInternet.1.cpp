/*
https://acmp.ru/index.asp?main=task&id_task=6
*/
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	char a;
	char b;
	char c;
	char d;
	char e;
	cout << "Введите ход конём" << endl;
	cin >> a >> b >> c >> d >> e;
	if (a == d)
	{
		cout << "Ты дурак, так нельзя ходить!!!";
	}
	else if (b == e)
	{
		cout << "Ты дурак, так нельзя ходить!";
	}
	else if ((abs(a - d) == 1) && (abs(b-e)==2))
	{
		cout << "Хады, дарагой!!!!!";
	}
	else if ((abs(a - d) == 2)&&(abs (b-e)==1))
	{
		cout << "Хады, дарагой!!!!!";
	}
	else cout << "Так не ходить пожалуйста, зачем вы так делать?";
	cout << "" << endl;
		return 0;
}
