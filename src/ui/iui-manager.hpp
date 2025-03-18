#pragma once

#include <vector>
#include <string>

#include <src/ui/components/iui-component.hpp>

// UIManager повинен зберігати всі віджети і здійснювати управління ними
class IUIManager
{
public:
    ~IUIManager() = default;
public:
    virtual std::vector<IUIComponent*> getComponentsByTag(const std::string tag);
};
