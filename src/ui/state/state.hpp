#pragma once

#include <list>
#include <functional>

#include <src/ui/state/state-listener.hpp>

class State
{
protected:
    std::list<StateListener*> m_listeners;
    function<void(const Action&)> m_callback;
    StateManager* m_context = nullptr;
    // + поле для властивостей, які передаються до слухачів стейту, через посилання
    // всі всластивості зберігаються в сторі
public:
    State() = default;
public:
    void setContext (const StateManager* context);
    void setCallback(const std::function<void(const Action&)> callback);
public:
    void callback(const Action& action);

    void notify();
    void attach(const StateListener* listener);
    void detach(const StateListener* listener);

};
