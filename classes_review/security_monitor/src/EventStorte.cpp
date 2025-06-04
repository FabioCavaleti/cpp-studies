#include "EventStore.h"

void EventStore::addEvent(const Event& event)
{
    events_.push_back(event);
}

void EventStore::addEvent(Event&& event)
{
    events_.push_back(std::move(event));
}

size_t EventStore::size() const noexcept
{
    return events_.size();
}

void EventStore::forEach(const std::function<void(const Event&)>& func) const
{
    for (const auto& event: events_ )
    {
        func(event);
    }
}


std::vector<const Event*> EventStore::filter(const std::function<bool(const Event&)>& predicate) const
{
    std::vector<const Event*> result;
    for (const  auto& event : events_)
    {
        if(predicate(event))
        {
            result.push_back(&event);
        }
    }

    return result;
}


