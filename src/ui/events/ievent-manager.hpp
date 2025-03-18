#pragma once

#include <src/ui/events/ievent-listener.hpp>

// патерн спостерігача для системи івентів
class IEventManager
{
public:
    ~IEventManager() = default;
public:
    virtual void notify() = 0;
    virtual void attach(const IEventListener* listener) = 0;
    virtual void detach(const IEventListener* listener) = 0;
};
