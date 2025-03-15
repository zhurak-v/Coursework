#include <core/App.hpp>
#include <iostream>

void MyApp::SetupUI(UIManager& uiManager) {    
    auto button = Button::Create({
        {"label", "Create New Design"},
        {"onClick", std::function<void()>([]() { std::cout << "Button Clicked!" << std::endl; })},
        {"variant", ButtonVariant::Secondary},
        {"style", UIStyle{ImVec4(1.0f, 0.0f, 0.0f, 1.0f), ImVec4(0.0f, 0.0f, 1.0f, 1.0f), 10.0f}},
    });

    button->SetStyle({
        {"padding", 100.0f}
    });

    uiManager.AddWidget(button);
}
