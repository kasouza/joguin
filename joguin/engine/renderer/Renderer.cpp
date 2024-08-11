#include "joguin/engine/events/EventSystem.hpp"
#include "joguin/engine/renderer/RendererException.hpp"
#include "joguin/engine/renderer/RendererInitException.hpp"
#include "joguin/engine/renderer/WindowCloseEvent.hpp"
#include "joguin/engine/renderer/WindowResizeEvent.hpp"
#include <joguin/engine/renderer/Gl.hpp>
#include <joguin/engine/renderer/Renderer.hpp>

namespace Joguin {
namespace Engine {
namespace Renderer {

std::unordered_map<GLFWwindow *, Renderer *> Renderer::rendererMap{};

void Renderer::handleWindowClose(GLFWwindow *window) {
    WindowCloseEvent windowEvent{};
    windowEvent.window = window;

    Renderer *renderer = rendererMap[window];
    if (!renderer) {
        throw RendererException("Failed to find renderer for window");
    }

    renderer->eventSystem.pushEvent(windowEvent);
}

void Renderer::handleWindowResize(GLFWwindow *window, int width, int height) {
    WindowResizeEvent windowEvent{};
    windowEvent.window = window;
    windowEvent.width = width;
    windowEvent.height = height;

    Renderer *renderer = rendererMap[window];
    if (!renderer) {
        throw RendererException("Failed to find renderer for window");
    }

    renderer->eventSystem.pushEvent(windowEvent);
}

Renderer::Renderer(RendererOptions options, Events::EventSystem &eventSystem)
    : eventSystem{eventSystem}, windowWidth{options.windowWidth},
      windowHeight{options.windowHeight} {
    if (!glfwInit()) {
        throw RendererInitException("Failed to initialize GLFW");
    }

    GLFWwindow *window{glfwCreateWindow(options.windowWidth,
                                        options.windowHeight,
                                        options.windowTitle, NULL, NULL)};

    if (!window) {
        glfwTerminate();
        throw RendererInitException("Failed to create window");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        throw RendererInitException("Failed to initialize GLAD");
    }

    glViewport(0, 0, options.windowWidth, options.windowHeight);

    glfwSetFramebufferSizeCallback(window, handleWindowResize);
    glfwSetWindowCloseCallback(window, handleWindowClose);

    this->window = window;

    rendererMap[window] = this;
}

GLFWwindow *Renderer::getWindow() { return window; }

Renderer::~Renderer() { glfwTerminate(); }

void Renderer::present() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

} // namespace Renderer
} // namespace Engine
} // namespace Joguin
