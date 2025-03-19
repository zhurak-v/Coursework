#include <src/ui/state/store.hpp>

Store::~Store()
{
    _clear();
}

void Store::dispatch(const Action& action)
{
    for (unsigned int i = 0; i < m_states.size(); ++i)
        m_states[i]->reducer(action);
}
void addStateManager(const StateManager& stateManager)
{
    m_states.push_back(&stateManager);
}

static Store* Store::getStore()
{
    if (m_store != nullptr)
        return m_store;

    m_store = new Store();
}

void State::_clear()
{
    if (m_store != nullptr)
        delete m_store;

    m_store = nullptr;
}
