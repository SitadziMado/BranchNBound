#include "stdafx.h"
#include "State.h"

#include "Backpack.h"
#include "Item.h"

State::State(const Backpack& parent) :
    parent_(&parent),
    mass_(0),
    estimation_(0.0f),
    idx_(0)
{
}

std::vector<Item*>::iterator State::begin() noexcept
{
	return used_.begin();
}

std::vector<Item*>::iterator State::end() noexcept
{
	return used_.end();
}

std::vector<Item*>::const_iterator State::cbegin() const noexcept
{
	return used_.cbegin();
}

std::vector<Item*>::const_iterator State::cend() const noexcept
{
	return used_.cend();
}

size_t State::nextItem() noexcept
{
    return idx_++;
}

float State::getCost() const noexcept
{
    return this->cost_ + this->estimation_;
}

bool State::tryPush(Item& item)
{
    bool result = true;

    if (this->mass_ + item.getMass() <= parent_->getCapacity())
    {
        used_.push_back(&item);
        this->mass_ += item.getMass();
        this->cost_ += item.getValue();
    }
    else
    {
        result = false; 
        this->estimation_ = 0.0f;
    }

    return result;
}

void State::updateEstimation(const Item& next)
{
    auto spaceLeft = parent_->getCapacity() - this->mass_;

    if (spaceLeft)
    {
		this->estimation_ = next.getCost() * spaceLeft; // (float)next.getValue() / spaceLeft;
    }
    else
    {
        this->estimation_ = 0.0f;
    }
}
