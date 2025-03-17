#pragma once

#include <iostream>
#include <tuple>
#include <type_traits>

#include <src/iui-component.hpp>

template <typename... Components>
class Panel : public IUIComponent<Panel<Components...>>
{
private:
    std::tuple<Components...> m_components;
private:
    template <size_t Idx = 0, typename... T>
    void _render(std::tuple<T...>& t)
    {
        if constexpr (Idx < sizeof...(T))
        {
            std::get<Idx>(t).render();

            _render<Idx + 1>(t);
        }
    }

public:
    Panel(Components... components) 
    : 
        m_components(std::make_tuple(components...))
    {}
public:
    void renderImpl()
    {
        std::cout << "Render Panel" << std::endl;

        _render(m_components);
    }

};
