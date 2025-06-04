#pragma once
#include "Event.h"
#include <vector>
#include <functional>
#include <string>

class EventStore
{
    private:
        std::vector<Event> events_;

    public:
        void addEvent(const Event& event);
        void addEvent(Event&& event); // Suporte para std::move

        size_t size() const noexcept;

        void forEach(const std::function<void(const Event&)>& func) const;

        std::vector<const Event*> filter(const std::function<bool(const Event&)>& predicate) const;


};