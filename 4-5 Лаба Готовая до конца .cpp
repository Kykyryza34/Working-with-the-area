#include <iostream>
using namespace std;

int PZR(int x, int arr[100])
{

	for (int i = 1; i < x; ++i)
	{
		for (int r = 0; r < x - i; r++)
		{
			if (arr[r] > arr[r + 1])
			{
				// Обмен местами
				int temp = arr[r];
				arr[r] = arr[r + 1];
				arr[r + 1] = temp;
			}
		}
	}

	return arr[100];
}

int Elements(int x, int arr[100])
{
	int z = 0;
	for (int i = 0; i < x; i++)
	{

		if (arr[i] % 3 == 0)
		{
			z++;
		}
	}
	cout << " Количество элементов  кратных трем =  " << z << '\n';
	return z;
}

int Min(int x, int arr[100])
{
	int min = 0;
	// Часть 3 самое Литл 
	int arr1[100];
	// сохранение данных в доп масик 
	for (int i = 0; i < 100; i++)
		arr1[i] = arr[i];
	min = arr1[0];
	for (int i = 1; i < x; i++) {
		if (arr[i] < min) { min = arr1[i]; }
	}

	cout << "Наименьшие число массива:" << min << '\n';

	return min;
}
 
int Bin(int x, int arr[100])
{

	int key;
	cout << endl << "Введите искомое число : ";

	cin >> key; // считываем ключ

	bool flag = false;
	int l = 0; // левая граница
	int r = x; // правая граница
	int mid;

	while ((l <= r) && (flag != true)) {
		mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

		if (arr[mid] == key) flag = true; //проверяем ключ со серединным элементом
		if (arr[mid] > key) r = mid - 1; // проверяем, какую часть нужно отбросить
		else l = mid + 1;
	}


	if (flag) cout << "Ваше число" << key << " оно лежит в ячейке: ""\n" << mid;
	else cout << "Такова элемента в масиве нет ""\n";

	return 0;

}



int main(int x, int arr[100])
{
	setlocale(LC_ALL, "Russian");
	char YesNo;
	do
	{
		bool flag = false,flag1 = false;
		setlocale(LC_ALL, "Russian");
		char sign;
		int arr[100];
		int x = 0, n = 1, z = 0, min = 0;
	link2:
		cout << "1.Задать/Изменить размер масива " "\n" << "2.Отсортировать пузырьком " "\n" << "3.Элементы кратные 3 " "\n" << "4.Самое маленькое число массива  " "\n" << "5.Поиск ячейки определённого значения " "\n";
		cout << "Выбор действия:";
		cin >> sign;
		switch (sign)
		{
		case '1':
		{


			cout << "Выберите количество произвольных чисел n : ";
			cin >> x;
			int z = 0, d = 0;
			for (int i = 0; i < 100; i++) {
				arr[i] = 0;
			}
			// Присваивание ячеик 
			for (int i = 0; i < 100; i++) {
				arr[i] = rand() % 10;
				n++; if (n > x && n != x) { break; }
			}
			flag = true;
			goto link2;

		}
		case '2':
		{
			if (flag)PZR(x, arr);
			else
			{
				cout << "Определите массив!!!""\n";
				goto link2;
			}
			flag1 = true;
			goto link1;
		}
		case '3':
		{
			if (flag)Elements(x, arr);
			else
			{
				cout << "Определите массив!!!""\n";
				goto link2;
			}
			goto link1;
		}
		case '4':
		{
			if (flag)Min(x, arr);
			else
			{
				cout << "Определите массив!!!";
				goto link2;
			}
			goto link1;
		}
		case '5':
		{

			if (flag && flag1 )Bin(x, arr);
			else
			{
				cout << "Определите и отсортируйте массив!!!""\n";
				goto link2;
			}
			goto link1;
		}
		default:
		{
			cout << "Некоректное символ.";
			break;
		}
		}


	link1:
		cout << "Продолжить работу над массивом /Выйти ('Y'/'N')\n";
		cin >> YesNo;
		goto link2;
	} while ((YesNo == 'Y' || YesNo == 'y'));
	cin.get();
}
