#pragma once

#include <src/ui/state/state.hpp>

// патерн State + Observer для системи стейтів + Singleton для одного state store
class StateManager
{
private:
    State* m_state = nullptr;

public:
    StateManager();
public:
    // при зміні стейту виконати попередження всіх слухачів стейту notify()
    virtual void dispatch(const Action& action) = 0;

};
