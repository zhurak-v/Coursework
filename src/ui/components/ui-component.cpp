#include <src/ui/components/ui-component.hpp>

UIComponent* UIComponent::getParent() const
{
    return m_parent;
}
void         UIComponent::setParent(UIComponent& parent)
{
    m_parent = &parent;
}

void UIComponent::addChild(UIComponent& component)
{
    m_components.push_back(&component);
}
