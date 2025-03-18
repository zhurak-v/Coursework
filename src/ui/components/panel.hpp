#pragma once

#include <vector>

#include <src/ui/components/ui-widget.hpp>

class Panel : public UIWidget
{
protected:
    std::vector<std::shared_ptr<UIWidget>> m_components;

public:
    Panel() = default;
public:
    void addChild(UIWidget& child) override;
    void render  () override;
}
