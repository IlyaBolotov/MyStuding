/*Решение нелинейных уравнений
* 1 Метод половинного деления
* 2 Метод Ньютона
* 3 Метод итерации */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double func(double a)	// Функция
{
	return a - cos(a);
}


double func1(double a)	// Первая производная
{
	return sin(a) + 1;
}


double func2(double a)		// Вторая производная
{
	return cos(a);
}


double binary(double first, double second, double e) // Метод бинарного поиска
{
	double a1, result = first;

	if (abs(func(first)) <= e)
	{
		result = first;
	}

	else while (abs(func(result)) > e)
	{

		if (abs(func(first)) <= e) // Проверка левого корня
		{
			result = second;
		}

		else if (abs(func(second)) <= e) // Проверка правого корня
		{
			result = second;
		}

		else a1 = (first + second) / 2; // Вычисляем среднее между меньшим и большим корнями

		if (abs(func(a1)) <= e) result = a1; // Проверяем средний корень

		else if ((func(first) * func(a1)) < 0) // Проверяем есть ли корень на промежутке
		{
			second = a1;
		}

		else if ((func(a1) * func(second)) < 0) // Проверяем есть ли корень на другом промежутке
		{
			first = a1;
		}

	}

	return result;
}


double kas(double first, double second, double e) // Метод Ньютона
{
	double a;
	double result;
	
	if (abs(func(first)) <= e) result = first; // Проверяем меньшую переменную

	else if (abs(func(second)) <= e) result = second; // Проверяем большую переменную

	while (!result)
	{

		if (func(first) * func2(first) >= 0) // Проверка и работа с убывающей функцией
		{
			a = first - (func(first) / func1(first));
			if (abs(func(a)) <= e) result = a;
			else if (abs(func(a) - func(first) <= e)) result = a;
			else first = a;
		}

		if (func(second) * func2(second) >= 0) // Проверка и работа с возрастающей функцией
		{
			a = second - (func(second) / func1(second));
			if (abs(func(a)) <= e) result = a;
			else if (abs(func(a) - func(second)) <= e) result = a;
			else second = a;
		}
	}

	return result;
}


double sec(double first, double second, double e) // Метод секущих (модификация метода Ньютона)
{												  // Вычисляется по формуле x(n+1) = x(n) - (((x(n) - x(n-1)) * f(x(n))) / (f(x(n)) - f(x(n-1)))
	double result = first, a1, a2;

	if (func1(first) * func1(second) < 0) // Работаем с убывающей функцией
	{
		a2 = first + e;
	}
	else if (func1(first) * func1(second) > 0) // Работаем с возрастающей функцией
	{
		a2 = second - e;
	}
	else if (first < (pow(3, 0.5) / 3))
	{
		first = pow(3, 0.5) / 3;
	}

	if (abs(func(first)) <= e) result = first; // Проверяем правую переменную

	else if (abs(func(second)) <= e) result = second; // Проверяем левую переменную

	
	while ((abs(func(result)) > e) && (e != 0))
	{
		if (func1(first) > 0) // Проверяем и работаем, если функция убывает
		{
			a1 = first - (((first - a2) * func(first)) / (func(first) - func(a2)));
			if (abs(func(a1)) <= e) result = a1;
			a2 = first;
			first = a1;
		}

		if (func1(first) < 0) // Проверяем и рабоатем, если функция возрастает
		{
			a1 = second - (((second - a2) * func(second)) / (func(second) - func(a2)));
			if (abs(func(a1)) <= e) result = a1;
			a2 = second;
			second = a1;
		}	
	}

	if (e == 0) cout << "При допустимой погрешности в нуль метод секущих не работает" << endl;
	else return result;
}



double hor(double first, double second, double e) // Метод хорд (тоже модификация метода Ньютона
{												  // Вычисляется по формуле x(n+1) = x(n) - ((b - x(n)) * f(x(n))) / (f(b) - f(x(n)))
	double result = first;
	double b, a1;
	double sad = func(first) * func2(first);



	if (func(first) * func2(first) > 0) // Проверка и работа с убывающей функцией
	{
		b = first;
	}
	else if (func(second) * func2(second) > 0) // Проверка и работа с возрастающей функцией
	{
		b = second;
	}
	if (first < (pow(3, 0.5) / 3))
	{
		first = pow(3, 0.5) / 3;
	}

	if (abs(func(first)) <= e) result = first; // Проверяем правую переменную

	else if (abs(func(second)) <= e) result = second; // Проверяем левую переменную

	while (abs(func(result)) > e)
	{
		if (func(second) * func2(second) > 0)
		{
			a1 = first - (((b - first) * func(first)) / (func(b) - func(first)));
			first = a1;
		}
		else if (func(first) * func2(first) > 0)
		{
			a1 = second - (((b - second) * (func(second))) / (func(b) - func(second)));
			second = a1;
		}

		if (abs(func(a1)) <= e)
		{
			result = a1;
		}
	}
	
	if (e == 0) cout << "При допустимой погрешности в нуль метод хорд не работает" << endl;
	else return result;
}



double fi(double x)
{
	return cos(x);
}



double fip(double x)
{
	return -1 * sin(x);
}



double iter(double first, double second, double e)
{
	double result = first;

	if (abs(func(first)) <= e) result = first; // Проверяем правую переменную

	else if (abs(func(second)) <= e) result = second; // Проверяем левую переменную

	cout << "sdasd  ";
	while ((abs(fi(result)) > e));
	{
		second = fi(second);
		if (abs(fi(second)) <= e)
		{
			result = second;
			cout << "sadas";
		}
	}
	cout << "pizda ";
	return result;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Функция x - cos(x) = 0\n";
	cout << "Введите границы, в которых есть только один корень,пожалуйста\n";
	
	double first, second; // Переменные для записи границ
	double result, e; // Переменные для записи результата, и погрешности
	string g; // Переменная для записи погрешности в текстовом виде (потому что для отделения мантиссы используется именно точка (.), а неопытный пользователь может для этого использовать запятую
	int i, length, whole=0, fract=0; // вспомогательные переменные для записи из строки в число
	bool flag = true; // Вспомогательная переменная для записи из строки в число
	
	do // Цикл для проверки, чётное или нечётное количество корней в заданном промежутке
	{

		cin >> first >> second;
		if (second < first) // На случай, если вводимый перепутал местами границы
		{
			e = second;
			second = first;
			first = e;
		}

	} while (func(first) * func(second) > 0);

	cout << "Введите допустимую погрешность (не равную нулю)\n";

	cin >> g;	//  Записываем погрешность в строку
	length = g.length();  // Находим её длину

	for (i = 0; i <= length - 1; i++) // Находим длину целой части и мантисы
	{
		if ((g[i] == '.') || (g[i] == ',')) 	flag = false;
		else if (flag)	  whole++;
		else	fract++;
	}

	e = 0;

	for (i = 0; i <= whole - 1; i++) // Записываем целую часть
	{
		e += g[i] - '0' * pow(10, whole - 1 - i);
	}

	for (i = 0; i <= fract-1; i++)
	{
		e += (g[whole + i + 1] - '0') * pow(10, (i + 1) * (-1));
	}



	// Метод половинного деления

	cout << endl;
	cout << endl;
	cout << "Результат методом половинного деления равен: " << binary(first, second, e) << endl;

	//Метод половинного деления



	// Метод Ньютона

	cout << endl;
	cout << endl;
	cout << "Результат методом Ньютона равен: " << kas(first, second, e) << endl;

	// Метод Ньютона



	// Метод секущих

	cout << endl;
	cout << endl;
	cout << "Результат методом секущих равен: " << sec(first, second, e) << endl;

	// Метод секущих



	// Метод хорд

	cout << endl;
	cout << endl;
	cout << "Результат методом хорд равен: " << hor(first, second, e) << endl;

	// Метод хорд



	// Метод простых итераций

	cout << endl;
	cout << endl;
	cout << "Результат методом простых итераций равен: " << iter(first, second, e) << endl;

	// Метод простых итераций
	return 0;
}