#pragma once
#include <vector>
#include "Item.h"

struct Backpack
{
	int capacity;
	std::vector<Item> items;
};