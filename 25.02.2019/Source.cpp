
#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
//#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			int *a;
			a = new int; // выделили ячейку памяти и записали ее адрес под указателем а
			*a = 100;

			cout << a << " " << *a << endl;


			delete a; // удаление указателя
			a = new int[10];

			for (int i = 0; i < 10; i++)
			{
				a[i] = 10;
				cout << a[i] << " ";
			}
			cout << endl << endl;
			delete[] a;

		}
		break;
		case 2:
			// 50.	*Написать программу, которая генерирует случайное число N, создает динамический массив из N элементов,
			// заполняет его случайными числами и выводит на экран
		{
			int N;
			int *a;
			N = rand() % 15 + 1;
			a = new int[N];

			for (int i = 0; i < N; i++)
			{
				a[i] = rand() % 10 + 1;
				cout << a[i] << " ";
			}
			cout << endl;

			delete[] a;
		}
		break;
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}