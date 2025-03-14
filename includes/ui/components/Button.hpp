#pragma once
#include <core/UIManager.hpp>
#include <functional>
#include <string>

enum class ButtonVariant {
    Primary,
    Secondary,
    Danger
};

class Button : public UIWidget {
public:
    Button(const char* label, std::function<void()> onClick, 
           ButtonVariant variant = ButtonVariant::Primary, 
           const char* icon = nullptr);

    ~Button() override;

    void Render() override;

private:
    const char* label;
    std::function<void()> onClick;
    ButtonVariant variant;
    const char* icon;
};
