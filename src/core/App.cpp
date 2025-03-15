#include <core/App.hpp>
#include <iostream>
#include <utils/hex-to-imvec4.hpp>

void MyApp::SetupUI(UIManager& uiManager) {    
    auto button = Button::Create({
        {"label", "Create New Design"},
        {"onClick", std::function<void()>([]() {})},
        {"variant", ButtonVariant::Secondary},
        {"style", {}},
        {"className", std::string("custom-button trhts tesd")}
    });


    button->SetStyle({
        {"backgroundColor", HexToImVec4("#00FF00")},
        {"color", HexToImVec4("#fff")},

    });
        
    uiManager.AddWidget(button);
}
