#include "stdafx.h"

#include "Backpack.h"
#include "Item.h"
#include "State.h"

int main()
{
	std::setlocale(LC_ALL, "Russian");

	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	size_t n, m;

	in >> n >> m;

	std::vector<Item> items;

	for (size_t i = 0; i < n; ++i)
	{
		i64 mass;
		i64 value;
		in >> mass >> value;
		auto item = Item(mass, value);
		items.push_back(item);
	}

	auto backpack = Backpack(m, items.cbegin(), items.cend());

    auto result = backpack.run();

    std::cout << "Полученная стоимость: " << result.getCost() << std::endl;

	for (auto& a : result)
	{
		std::cout << a->toString() << std::endl;
	}

    return 0;
}