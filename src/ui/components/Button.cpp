#include <ui/components/Button.hpp>
#include <imgui.h>
#include <unordered_map>

Button::Button(const char* label, std::function<void()> onClick, 
               ButtonVariant variant, const char* icon)
    : label(label), onClick(onClick), variant(variant), icon(icon) {}

Button::~Button() = default;

void Button::Render() {
    static std::unordered_map<ButtonVariant, ImVec4> variantColors = {
        {ButtonVariant::Primary, ImVec4(0.4f, 0.2f, 1.0f, 1.0f)},
        {ButtonVariant::Secondary, ImVec4(0.5f, 0.5f, 0.5f, 1.0f)},
        {ButtonVariant::Danger, ImVec4(1.0f, 0.2f, 0.2f, 1.0f)}
    };

    ImGui::PushStyleColor(ImGuiCol_Button, variantColors[variant]);

    if (icon) {
        ImGui::Text("%s ", icon);
        ImGui::SameLine();
    }

    if (ImGui::Button(label)) {
        if (onClick) {
            onClick();
        }
    }

    ImGui::PopStyleColor();
}
