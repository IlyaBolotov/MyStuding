//https://acmp.ru/index.asp?main=task&id_task=12
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int k;
	int X, Y, X1, X2, X3, X4, Y1, Y2, Y3, Y4;
	cout << "Введите количество дачников" << endl;
	cin >> k;
	cout << "Введите координаты первого дачника и его участка" << endl;
	cin >> X >> Y >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 >> X4 >> Y4;;
	if ((X1 == X2) && (Y1 == Y4))
	{
		if ((X >= X1) && (X <= X3) && (Y >= Y1) && (Y <= Y3))
		{
			cout << "Попал" << endl;
		}
	}
	//Остальное делается через уравнение прямой, которое я должен!!! вспомнить после того, как прилечу домойЫ
	return 0;
}