#include <core/Renderer.hpp>
#include <glad/gl.h>

Renderer::Renderer() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void Renderer::ClearScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
}
