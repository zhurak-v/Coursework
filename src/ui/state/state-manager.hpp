#pragma once

#include <functional>

#include <src/ui/state/state.hpp>

// патерн State + Observer для системи стейтів + Singleton для одного state store
// частково патерн Strategy через задання редюсера
class StateManager
{
private:
    State* m_prev_state = nullptr;
    State* m_state = nullptr;
    std::function<void(const Action&, State*&)> m_reducer;

public:
    StateManager(std::function<void(const Action&, State*&)> reducer, const State* state);
public:
    // при зміні стейту виконати попередження всіх слухачів стейту notify()
    void setReducer(std::function<void(const Action&, State*&)> reducer);

    void reducer(const Action& action);
};
