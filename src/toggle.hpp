#pragma once

#include <src/iui-component.hpp>

class Toggle : public IUIComponent<Toggle>
{
public:
    Toggle() = default;
public:
    void renderImpl();

};
