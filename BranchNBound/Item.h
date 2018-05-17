#pragma once

#include <iostream>
#include <limits>
#include <string>

#include "Common.h"

class Item
{
public:
    static constexpr auto NonIndexed = std::numeric_limits<size_t>::max();

	Item();
    Item(i64 mass, i64 value);

    i64 getMass() const noexcept;
    i64 getValue() const noexcept;
    size_t getIdx() const noexcept;
    float getCost() const noexcept;
    void setIdx(size_t value) noexcept;
	std::string toString() const;

private:
    i64 mass_;
    i64 value_;

    size_t idx_;
    float cost_;
};