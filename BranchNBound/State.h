#pragma once

#include <vector>

#include "Common.h"

class Backpack;
class Item;

class State
{
public:
    State(const Backpack& parent);

	std::vector<Item*>::iterator begin() noexcept;
	std::vector<Item*>::iterator end() noexcept;
	std::vector<Item*>::const_iterator cbegin() const noexcept;
	std::vector<Item*>::const_iterator cend() const noexcept;
	size_t nextItem() noexcept;
    float getCost() const noexcept;
    bool tryPush(Item& item);
    void updateEstimation(const Item& next);

private:
    const Backpack* parent_;
    std::vector<Item*> used_;
    i64 mass_;
    float cost_;
    float estimation_;
    size_t idx_;
};