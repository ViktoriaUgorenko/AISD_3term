#include "BackpackPacking.h"

void BackpackPacking(const std::vector<Item> items, Backpack& backpack)
{
	std::vector<std::vector<int>> package(items.size() + 1, std::vector<int>(backpack.capacity + 1, 0));

	for (int i = 1; i <= items.size(); i++)
	{
		for (int j = 1; j <= backpack.capacity; j++)
		{
			if (items[i - 1].weight <= j)
			{
				if (package[i - 1][j - items[i - 1].weight] + items[i - 1].price > package[i - 1][j])
				{
					package[i][j] = package[i - 1][j - items[i - 1].weight] + items[i - 1].price;
				}
				else
				{
					package[i][j] = package[i - 1][j];
				}
			}
			else
			{
				package[i][j] = package[i - 1][j];
			}
		}
	}

	int cnt = backpack.capacity;
	for (int i = items.size(); i > 0 && cnt > 0; i--)
	{
		if (package[i][cnt] != package[i - 1][cnt])
		{
			backpack.items.push_back(items[i - 1]);
			cnt -= items[i - 1].weight;
		}
	}

	return;
}
