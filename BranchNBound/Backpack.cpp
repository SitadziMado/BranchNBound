#include "stdafx.h"
#include "Backpack.h"

#include "Item.h"
#include "State.h"

Backpack::Backpack(i64 capacity) :
    capacity_(capacity)
{
}

Backpack::Backpack(i64 capacity, const std::initializer_list<Item>& items) :
    Backpack(capacity)
{
    items_ = items;
    items_.push_back(Item(1, 0));

    std::sort(
        items_.begin(),
        items_.end(),
        [](const Item& lhs, const Item& rhs) { return lhs.getCost() > rhs.getCost(); }
    );
}

i64 Backpack::getCapacity() const noexcept
{
    return capacity_;
}

State Backpack::run()
{
    auto cmp = [](const State& lhs, const State& rhs) {
        return lhs.getCost() < rhs.getCost();
    };

    auto queue =
        std::priority_queue<State, std::vector<State>, decltype(cmp)>(cmp);

    auto best = State(*this);
    queue.push(best);

    size_t cnt = 0;

    while (!queue.empty())
    {
        ++cnt;
        auto skip = queue.top();
        queue.pop();

        auto idx = skip.nextItem();

        if (idx < items_.size() - 1)
        {
            auto get = skip;

            if (!get.tryPush(items_[idx]))
            {
                if (get.getCost() > best.getCost())
                {
                    best = std::move(get);
                }
            }
            else
            {
                get.updateEstimation(items_[idx + 1]);

                if (get.getCost() >= best.getCost())
                {
                    queue.push(get);
                }
                else
                {
                    std::cout << "No way" << std::endl;
                }
            }

            skip.updateEstimation(items_[idx + 1]);
            
            if (skip.getCost() >= best.getCost())
            {
                queue.push(skip);
            }
            else
            {
                std::cout << "No way" << std::endl;
            }
        }
        else
        {
            if (skip.getCost() > best.getCost())
            {
                best = std::move(skip);
            }
        }
    }

    return best;
}