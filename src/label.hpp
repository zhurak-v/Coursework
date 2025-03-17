#pragma once

#include <src/iui-component.hpp>

class Label : public IUIComponent<Label>
{
public:
    Label() = default;
public:
    void renderImpl();
    
};
