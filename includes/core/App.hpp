#pragma once

#include <core/Core.hpp>
#include <ui/UI.hpp>

class MyApp : public Core {
    protected:
        void SetupUI(UIManager& uiManager) override;
    };
