#include "stdafx.h"

#include "Backpack.h"
#include "Item.h"
#include "State.h"

int main()
{
    auto backpack = Backpack(7, {
        Item(4, 8),
        Item(6, 10),
        Item(4, 9),
        Item(3, 4),
        Item(1, 1),
    });

    auto result = backpack.run();

    std::cout << result.getCost();

    return 0;
}