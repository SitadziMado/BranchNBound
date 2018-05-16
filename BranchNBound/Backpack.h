#pragma once

#include <vector>
#include <initializer_list>

#include "Common.h"

class Item;
class State;

class Backpack
{
public:
    Backpack(i64 capacity);
    Backpack(i64 capacity, const std::initializer_list<Item>& items);

    i64 getCapacity() const noexcept;
    State run();

private:
    i64 capacity_;
    std::vector<Item> items_;
    std::vector<State> states_;
};

