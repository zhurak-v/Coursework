#include <src/ui/state/state-manager.hpp>

StateManager(std::function<void(const Action&, State*&)> reducer, const State* state)
:
    m_reducer(reducer),
    m_state(state),
    m_prev_state(state)
{}

void setReducer(std::function<void(const Action&, State*&)> reducer)
{
    m_reducer = reducer;
}

void reducer(const Action& action)
{
    m_reducer(action, m_state);

    if (m_state != m_prev_state)
        m_state.notify();

    m_prev_state = m_state;
}
