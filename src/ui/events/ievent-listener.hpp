#pragma once

#include <src/ui/events/event.hpp>

class IEventListener
{
public:
    ~IEventListener() = default;
public:
    virtual void update(Event event) = 0;
};
