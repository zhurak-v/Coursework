#include <iostream>

#include <src/ui/components/ui-widget.hpp>

UIWidget* UIWidget::getParent() const { return m_parent }
void      UIWidget::setParent(UIWidget& parent) { m_parent = &parent; }

void UIWidget::addChild(UIWidget& child)
{
    std::cout << "addChild is not specified" << std::endl;
}
