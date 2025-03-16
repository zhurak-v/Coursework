#pragma once
#include <ui/components/UIComponent.hpp>
#include <functional>
#include <string>
#include <memory>
#include <unordered_map>
#include <any>

enum class ButtonVariant
{
    Primary,
    Secondary,
    Danger
};

class Button : public UIComponent
{
public:
    Button(std::string label,
           std::function<void()> onClick = {},
           ButtonVariant variant = ButtonVariant::Primary,
           std::string icon = "",
           const UIStyle &style = {},
           const std::string className = "button");

    void Render() override;
    static std::shared_ptr<Button> Create(const std::unordered_map<std::string, std::any> &props);

public:
    std::string label;
    std::function<void()> onClick;
    ButtonVariant variant;
    std::string icon;
};