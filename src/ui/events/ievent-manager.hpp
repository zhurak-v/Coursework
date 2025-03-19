#pragma once

#include <src/ui/events/ievent-listener.hpp>

// патерн спостерігача для системи івентів
class IEventManager
{
public:
    ~IEventManager() = default;
public:
    virtual void notify() = 0;
    virtual void attach(IEventListener* listener) = 0;
    virtual void detach(IEventListener* listener) = 0;
};
