#pragma once

#include <src/ui/components/ui-component.hpp>

class Button : public UIComponent
{
public:
    Button() = default;
public:
    void render() override;
};
