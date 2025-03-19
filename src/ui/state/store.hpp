#pragma once

#include <vector>

#include <src/ui/state/state-manager.hpp>

class Store
{
private:
    static Store* m_store;
    std::vector<StateManager*> m_states;
private:
    Store() = default;
private:
    void _clear();

public:
    ~Store();
public:
    void dispatch(const Action& action);
    void addStateManager(const StateManager& stateManager);
public:
    static Store* getStore();
};
