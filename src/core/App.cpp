#include <core/App.hpp>
#include <iostream>

void MyApp::SetupUI(UIManager& uiManager) {
    auto button = std::make_shared<Button>(
        "Create Design", 
        []() { std::cout << "Button Clicked!" << std::endl; }, 
        ButtonVariant::Primary, 
        ""
    );

    uiManager.AddWidget(button);
}