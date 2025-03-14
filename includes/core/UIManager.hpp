#pragma once

#include <vector>
#include <memory>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class UIWidget {
public:
    virtual ~UIWidget() = default;
    virtual void Render() = 0;
};

class UIManager {
public:
    UIManager(GLFWwindow* window);
    ~UIManager();

    void Begin();
    void End();
    void Render();
    
    void AddWidget(std::shared_ptr<UIWidget> widget);

private:
    std::vector<std::shared_ptr<UIWidget>> widgets;
};