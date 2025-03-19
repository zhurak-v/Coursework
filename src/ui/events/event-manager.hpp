#pragma once

#include <list>

#include <src/ui/events/ievent-manager.hpp>

class EventManager : public IEventManager
{
private:
    Event m_event;
    std::list<IEventListener*> m_listeners;

public:
    EventManager() = default;
public:
    void notify() override;
    void attach(IEventListener* listener) override;
    void detach(IEventListener* listener) override;

};
