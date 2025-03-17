#pragma once

#include <vector>

#include <src/ui/components/iui-component.hpp>

class UIComponent : public IUIComponent
{
protected:
    UIComponent* m_parent = nullptr;
    std::vector<UIComponent*> m_components;

public:
    virtual ~UIComponent() = default;
public:
    UIComponent* getParent() const;
    void         setParent(UIComponent& component);
    
    void addChild(UIComponent& component);
};