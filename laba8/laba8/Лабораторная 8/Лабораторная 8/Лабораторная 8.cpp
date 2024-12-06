#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include "BackpackPacking.h"
using namespace std;


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int capacity;
	Backpack backpack;
	vector<Item> items;

	cout << "Введите вместимость рюкзака: ";

	while (true)
	{
		cin >> capacity;
		if (cin.fail() || capacity < 0)
		{
			cout << "Неверный ввод. Введите вместимость рюкзака заново: ";
			cin.clear();
			cin.ignore(10000, '\n'); 
			continue;
		}
		else
		{
			backpack.capacity = capacity;
			cin.ignore(10000, '\n');
			break;
		}
	}

	cout << "\nВводите товары (окончание - пустая строка поля названия товара):\n";

	while (true)
	{
		Item temp;
		string name;
		cout << "\nНазвание товара: ";
		getline(cin, name);

		if (!name.empty())
		{
			temp.name = name;
		}
		else
		{
			break;
		}

		int price;
		cout << "Цена товара: ";
		while (true)
		{
			cin >> price;
			if (cin.fail() || price < 0.0)
			{
				cout << "Неверный ввод. Введите цену товара заново: ";
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			else
			{
				temp.price = price;
				cin.ignore(10000, '\n');
				break;
			}
		}

		int weight;
		cout << "Вес товара: ";
		while (true)
		{
			cin >> weight;
			if (cin.fail() || weight < 0)
			{
				cout << "Неверный ввод. Введите вес товара заново: ";
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			else
			{
				temp.weight = weight;
				cin.ignore(10000, '\n');
				break;
			}
		}

		items.push_back(temp);
	}

	BackpackPacking(items, backpack);

	cout << "\nРюкзак:\n";
	int maxTotalCost = 0;
	for (const auto& item : backpack.items)
	{
		cout << item.name << ", " << item.weight << " кг, " << item.price << "$\n";
		maxTotalCost += item.price;
	}
	cout << "\nМаксимальная суммарная стоимость: " << maxTotalCost << " $\n";

	return 0;
}