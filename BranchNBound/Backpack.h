#pragma once

#include <vector>
#include <initializer_list>

#include "Common.h"

class Item;
class State;

class Backpack
{
public:
	template<typename FwdIt>
	Backpack(i64 capacity, FwdIt begin, FwdIt end);

    Backpack(i64 capacity);
	Backpack(i64 capacity, const std::initializer_list<Item>& items);

    i64 getCapacity() const noexcept;
    State run();

private:
	void initItems();

    i64 capacity_;
    std::vector<Item> items_;
    std::vector<State> states_;
};

template<typename FwdIt>
inline Backpack::Backpack(i64 capacity, FwdIt begin, FwdIt end) :
	Backpack(capacity)
{
	this->items_ = std::vector<Item>(begin, end);
	this->items_.push_back(Item());
	this->initItems();
}