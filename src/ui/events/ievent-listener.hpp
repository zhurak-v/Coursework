#pragma once

#include <src/ui/events/event.hpp>

class IEventListener
{
public:
    virtual void update(Event event) = 0;
};
