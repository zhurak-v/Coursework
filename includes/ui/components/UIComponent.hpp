#pragma once
#include <core/UIManager.hpp>
#include <imgui.h>
#include <unordered_map>
#include <string>
#include <any>

struct UIStyle {
    ImVec4 textColor;
    ImVec4 backgroundColor;
    float padding;
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
    UIStyle style;
    std::string className = "";
    
public:
    template <typename T>
    static T getValue(const std::unordered_map<std::string, std::any>& props, 
                      const std::string& key, 
                      const T& defaultValue) {
        if (auto it = props.find(key); it != props.end() && it->second.type() == typeid(T)) {
            if constexpr (std::is_same_v<T, std::string>) {
                return defaultValue.empty() ? std::any_cast<T>(it->second)
                                            : defaultValue + " " + std::any_cast<T>(it->second);
            }
            return std::any_cast<T>(it->second);
        }
        return defaultValue;
    }
};