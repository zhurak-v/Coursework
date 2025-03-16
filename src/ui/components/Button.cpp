#include <ui/components/Button.hpp>
#include <imgui.h>
#include <iostream>

Button::Button(
    std::string label,
    std::function<void()> onClick,
    ButtonVariant variant,
    std::string icon,
    const UIStyle &style,
    const std::string className)
    : 
    UIComponent(style, className),
    label(std::move(label)),
    onClick(onClick ? std::move(onClick) : nullptr),
    variant(variant),
    icon(std::move(icon)) {}

void Button::Render()
{
    static const std::unordered_map<ButtonVariant, ImVec4> variantColors = {
        {ButtonVariant::Primary, {0.4f, 0.2f, 1.0f, 1.0f}},
        {ButtonVariant::Secondary, {0.5f, 0.5f, 0.5f, 1.0f}},
        {ButtonVariant::Danger, {1.0f, 0.2f, 0.2f, 1.0f}}};

    ImGui::PushStyleColor(ImGuiCol_Button, variantColors.at(variant));

    ApplyStyle();

    if (ImGui::Button(label.c_str()) && onClick)
    {
        onClick();
    }

    ResetStyle();
    ImGui::PopStyleColor();
}

std::shared_ptr<Button> Button::Create(const std::unordered_map<std::string, std::any> &props)
{
    return std::make_shared<Button>(
        getValue<std::string>(props, "label", "click"),
        getValue<std::function<void()>>(props, "onClick", {}),
        getValue<ButtonVariant>(props, "variant", ButtonVariant::Primary),
        getValue<std::string>(props, "icon", ""),
        getValue<UIStyle>(props, "style", {}),
        getValue<std::string>(props, "className", "component"));
}