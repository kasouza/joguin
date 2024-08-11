#include "joguin/engine/events/EventQueue.hpp"
#include "joguin/engine/events/EventSystem.hpp"
#include "joguin/engine/renderer/WindowCloseEvent.hpp"
#include "joguin/engine/renderer/WindowResizeEvent.hpp"
#include <joguin/engine/renderer/Renderer.hpp>
#include <joguin/engine/renderer/RendererFactory.hpp>

#include <iostream>

#define WIDTH 800
#define HEIGHT 600

int main() {
    using namespace Joguin::Engine::Renderer;

    RendererOptions options;
    options.windowWidth = WIDTH;
    options.windowHeight = HEIGHT;

    Joguin::Engine::Events::EventSystem eventSystem;
    eventSystem.registerEvent<WindowCloseEvent>();
    eventSystem.registerEvent<WindowResizeEvent>();

    Renderer &renderer = RendererFactory::create(options, eventSystem);

    GLFWwindow *window = renderer.getWindow();
    bool isRunning = true;

    eventSystem.subscribe<WindowCloseEvent>(
        [&isRunning](const WindowCloseEvent &event) { isRunning = false; });

    eventSystem.subscribe<WindowResizeEvent>(
        [&renderer](const WindowResizeEvent &event) {
            std::cout << "Window resized to " << event.width << "x"
                      << event.height << std::endl;
        });

    while (isRunning) {
        renderer.present();
        eventSystem.processEvents();
    }

    return 0;
}
