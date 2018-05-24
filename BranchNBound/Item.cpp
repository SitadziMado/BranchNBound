#include "stdafx.h"
#include "Item.h"

Item::Item(i64 mass, i64 value) :
    mass_(mass),
    value_(value),
    idx_(NonIndexed),
    cost_((float)value / mass)
{
}

Item::Item() :
    Item(1, 0)
    // mass_(1),
    // value_(0)
{
}

i64 Item::getMass() const noexcept
{
    return mass_;
}

i64 Item::getValue() const noexcept
{
    return value_;
}

size_t Item::getIdx() const noexcept
{
    return idx_;
}

float Item::getCost() const noexcept
{
    return cost_;
}

void Item::setIdx(size_t value) noexcept
{
    idx_ = value;
}

std::string Item::toString() const
{
	std::string result = "Вещь №";
	result += std::to_string(this->idx_ + 1) + 
		": Масса: " + std::to_string(this->mass_) +
		", Стоимость: " + std::to_string(this->value_);
	
	return result;
}