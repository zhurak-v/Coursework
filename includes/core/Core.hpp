#pragma once

#include <GLFW/glfw3.h>
#include <core/UIManager.hpp>

class Core {
    public:
        Core();
        ~Core();
    
        void Run();
    
    protected:
        virtual void SetupUI(UIManager& uiManager) = 0; 
    
    private:
        void InitGLFW();
        void InitGLAD();
    
        GLFWwindow* window;
};
