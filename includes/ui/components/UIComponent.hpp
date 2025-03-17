#pragma once
#include <core/UIManager.hpp>
#include <imgui.h>
#include <unordered_map>
#include <string>
#include <any>

struct UIStyle {
    ImVec4 textColor = {1, 1, 1, 1};
    ImVec4 backgroundColor = {0, 0, 0, 1};
    float padding = 5.0f;

    UIStyle() = default;
};

class UIComponent : public UIWidget {
public:
    UIComponent(
        const UIStyle& style,
        const std::string& className
    );

    void SetStyle(const std::unordered_map<std::string, std::any>& styleMap);
    void SetClassName(const std::string& newClassName);

    std::string GetClassName() const;
    UIStyle GetStyle() const;

protected:
    void ApplyStyle() const;
    void ResetStyle() const;

    UIStyle style;
    std::string className = "";

public:
    template <typename T>
    static T getValue(const std::unordered_map<std::string, std::any>& props, 
                      const std::string& key, 
                      const T& defaultValue) {
        auto it = props.find(key);
        if (it != props.end() && it->second.type() == typeid(T)) {
            if constexpr (std::is_same_v<T, std::string>) {
                return defaultValue.empty() ? std::any_cast<T>(it->second)
                                            : defaultValue + " " + std::any_cast<T>(it->second);
            }
            return std::any_cast<T>(it->second);
        }
        return defaultValue;
    }
};
