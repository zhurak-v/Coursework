#include <ui/components/UIComponent.hpp>
#include <functional>

UIComponent::UIComponent(const UIStyle& style)
    : style(style) {}

void UIComponent::SetStyle(const std::unordered_map<std::string, std::any>& styleMap) {
    static const std::unordered_map<std::string, std::function<void(UIStyle&, const std::any&)>> setters = {
        {"color", [](UIStyle& s, const std::any& v) { s.textColor = std::any_cast<ImVec4>(v); }},
        {"backgroundColor", [](UIStyle& s, const std::any& v) { s.backgroundColor = std::any_cast<ImVec4>(v); }},
        {"padding", [](UIStyle& s, const std::any& v) { s.padding = std::any_cast<float>(v); }}
    };

    for (const auto& [key, value] : styleMap) {
        if (auto it = setters.find(key); it != setters.end()) {
            it->second(style, value);
        }
    }
}

UIStyle UIComponent::GetStyle() const {
    return style;
}

// void UIComponent::SetClassName(const std::string& newClassName) {
//     className = newClassName;
// }

// std::string UIComponent::GetClassName() const {
//     return className;
// }