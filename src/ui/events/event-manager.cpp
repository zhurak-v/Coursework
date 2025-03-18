#include <src/ui/events/event-manager.hpp>

void EventManager::notify() override
{
    for (unsigned int i = 0; i < m_listeners.size(); ++i)
        m_listeners[i].update(m_event);
}
void EventManager::attach(const IEventListener* listener) override
{
    m_listeners.push_back(listener);
}
void EventManager::detach(const IEventListener* listener) override
{
    m_listeners.remove(listener);
}
