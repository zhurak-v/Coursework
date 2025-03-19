#include <src/ui/events/event-manager.hpp>

void EventManager::notify()
{
    std::list<IEventListener*>::iterator iterator = m_listeners.begin();

    while (iterator != m_listeners.end()) {
        (*iterator)->update(m_event);
        ++iterator;
    }
}
void EventManager::attach(IEventListener* listener)
{
    m_listeners.push_back(listener);
}
void EventManager::detach(IEventListener* listener)
{
    m_listeners.remove(listener);
}
