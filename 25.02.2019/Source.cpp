
#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
//#include <cstdlib>

using namespace std;

void createArray(int *&a, int n) { // передача указателя по ссылке обязательна
	a = new int[n];
}
void fillArray(int *a, int n) { // здесь не нужен & т.к. указатель (который и есть адрес изначальный) не изменяется, адрес тот же, только сами значения изменяются
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10 + 1;
}
void printArray(const int *a, int n) {
	for (int i = 0; i < n; i++)
		cout << setw(3) << a[i] << " ";
	cout << endl;
}
void deleteArray(int *&a) { // и здесь
	delete[] a;
}
void sumArray(const int *a, const int *b, int *c, int n) { // const можно там где не хотим допустить изменений, а можно и без него
	for (int i = 0; i < n; i++)
		c[i] = a[i] + b[i]; // c[i]=*(a+i) + *(b+i) через указатели
}
// 57.	**Написать функцию, которая принимает указатель на массив и число,
// и возвращает указатель на первую ячейку массива,
// в которой найдено это число или ноль, если совпадений нет

//case 5
int *searchElement(int *a, int n, int key) {
	
	for (int *p = a; p < a + n; p++)
		if (*p == key)
			return p;
	return nullptr; // OR return 0;
}

// 59.	**Функция принимает указатель на массив, его размер и указатель на переменную.Определить,
// является ли переменная ячейкой массива(т.е значение указателя совпадает с одним из адресов ячеек массива),
// является ли содержимое указателем адресом внутри массива,
// является ли содержимое указателя ни как ни связанным с массивом адресом.
// Функция должна вернуть три логических значения для каждого случая.


//the same as 59: 60.	*Функция принимает указатель на массив, его размер и указатель на переменную.
//Определить, является ли переменная ячейкой массива(т.е значение указателя совпадает с одним из адресов ячеек массива).
//Функция должна вернуть логическое значение.

// case 7
bool searchElement(int *a, int n, int *p) {
	return(p>=a && p < a + n); // т.е. если указатель p является адресом ячейки массива, то войдет в диапазон a+n и тогда bool вернет TRUE (1), если не входит в диапазон то FALSE (0)
}


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
			// 52.	**Написать программу, которая переводит введенное десятичное число в двоичное число.
			// Результат перевода сохранить в массив минимально возможного размера.
		{
			int n;
			cin >> n;
			int *a;
			int count = 0;

			int tmp = n;
			while (tmp) // т.е. = (tmp!=0) пока не будет ЛОЖЬ, после целочисленного деления - все остальные значения кроме нуля воспринимает как TRUE
			{
				tmp/= 2;
				count++;
			}
			cout << count << endl << endl;

			a = new int[count];
			tmp = n;
			int k = count;
			while (tmp) {
				a[--k] = tmp % 2; // предекремент - чтобы в обратном порядке запись шла после деления для десятичного числа, с конца
				// k-- просто декремент нельзя! т.к. попытается записать в ячейку a[4], которой нет, т.к диапазон от a[0] до a[3]

				tmp /= 2;
			}
			for (int i = 0; i < count; i++)
				cout << a[i];
			cout << endl;

			delete[] a;
		}
		break;
		case 4:
			// 55.	*Написать программу, которая создает три массива из N элементов.
			// N – вводится пользователем.Первые два заполняются случайным образом,
			// третий массив формируется как поэлементная сумма первых двух массивов.
		{
			int *a, *b, *c;
			int n;
			cin >> n;
			a = new int[n];
			b = new int[n];
			c = new int[n];
			
			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 10;
				b[i] = rand() % 10;
				c[i] = a[i] + b[i];

				cout << a[i] << " " << b[i] << "	" << c[i];
				cout << endl;
			}
			
			delete[] a;
			delete[] b;
			delete[] c;
		}
		break;
		case 5:
		{
			int *a, *b;
			int n = 10;

			createArray(a, n);
			fillArray(a, n);
			printArray(a, n);

			// int K;
			// cin >> K;

			b=searchElement(a, n, 5);
			// b=searchElement(a, n, 20); // если искать несуществующее значение (20), то печатает ПУСТОТУ, отсутсвие, т.е. nullptr не воспринимается как нулевое значение, а как отсутсвие такового
			cout << endl;
			if (b != 0)
			{
				cout << b << endl; // address
				cout << *b << endl;
				cout << b - a + 1 << endl; // номер ячейки в массиве, +1 чтобы не с нуля начиналось а порядковый номер 1, 2, 3, 4, 5...
			}
				
			deleteArray(a);
		}
		break;
		case 6:
		{
			int *a, *b, *c;
			int n = 10;

			createArray(a, n);
			createArray(b, n);
			createArray(c, n);

			fillArray(a, n);
			fillArray(b, n);
			printArray(a, n);
			printArray(b, n);

			sumArray(a, b, c, n);
			printArray(c, n);

			deleteArray(a);
			deleteArray(b);
			deleteArray(c);

		}
		break;
		case 7:	
		{
			int *a, *b, x;
			int n = 10;

			createArray(a, n);
			fillArray(a, n);
			printArray(a, n);

			b = &x; // FALSE, несуществующая в массиве ячейка
			// b=a+5; // адрес шестого элемента
			cout << searchElement(a, n, b) << endl;
			cout << endl;
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