#include <core/App.hpp>
#include <iostream>
#include <utils/style-value.hpp>

void MyApp::SetupUI(UIManager& uiManager) {    
    auto button = Button::Create({
        {"onClick", std::function<void()>([]() {
            std::cout << "Button clicked" << std::endl;
        })},
        {"className", std::string("custom-button")}
    });

    button->SetStyle({
        {"backgroundColor", HexToImVec4("#00FF00")},
        {"color", HexToImVec4("#fff")},

    });

    std::cout << "Button class: " << button->GetClassName() << std::endl;
        
    uiManager.AddWidget(button);
}
