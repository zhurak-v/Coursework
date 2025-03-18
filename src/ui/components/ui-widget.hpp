#pragma once

#include <src/ui/components/iui-widget.hpp>

class UIWidget : public IUIWidget
{
protected:
    UIWidget* m_parent;

public:
    virtual ~UIWidget() = default;
public:
    UIWidget* getParent() const;
    void      setParent(UIWidget& parent);

    virtual void addChild(UIWidget& child) = 0;
};
