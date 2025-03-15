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
    UIComponent(const UIStyle& style);
    void SetStyle(const std::unordered_map<std::string, std::any>& styleMap);
    UIStyle GetStyle() const;
    // void SetClassName(const std::string& newClassName);
    // std::string GetClassName() const;

protected:
    UIStyle style;
    // std::string className;
};