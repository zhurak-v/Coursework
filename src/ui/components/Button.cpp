#include <ui/components/Button.hpp>
#include <imgui.h>
#include <iostream>

Button::Button(std::string label, std::function<void()> onClick,
               ButtonVariant variant, std::string icon, const UIStyle& style)
    : UIComponent(style), label(std::move(label)), onClick(std::move(onClick)),
      variant(variant), icon(std::move(icon)) {}

void Button::Render() {
    static const std::unordered_map<ButtonVariant, ImVec4> variantColors = {
        {ButtonVariant::Primary, {0.4f, 0.2f, 1.0f, 1.0f}},
        {ButtonVariant::Secondary, {0.5f, 0.5f, 0.5f, 1.0f}},
        {ButtonVariant::Danger, {1.0f, 0.2f, 0.2f, 1.0f}}
    };

    ImGui::PushStyleColor(ImGuiCol_Button, variantColors.at(variant));
    ImGui::PushStyleColor(ImGuiCol_Text, style.textColor);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, style.backgroundColor);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, {style.padding, style.padding});

    if (ImGui::Button(label.c_str()) && onClick) {
        onClick();
    }

    ImGui::PopStyleVar();
    ImGui::PopStyleColor(3);
}

std::shared_ptr<Button> Button::Create(const std::unordered_map<std::string, std::any>& props) {
    return std::make_shared<Button>(
        getValue<std::string>(props, "label", "click"),
        getValue<std::function<void()>>(props, "onClick", {}),
        getValue<ButtonVariant>(props, "variant", ButtonVariant::Primary),
        getValue<std::string>(props, "icon", ""),
        getValue<UIStyle>(props, "style", {})
    );
}

template <typename T>
T Button::getValue(const std::unordered_map<std::string, std::any>& props, const std::string& key, const T& defaultValue) {
    if (auto it = props.find(key); it != props.end() && it->second.type() == typeid(T)) {
        return std::any_cast<T>(it->second);
    }
    return defaultValue;
}