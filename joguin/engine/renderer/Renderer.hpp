#ifndef KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_RENDERER_HPP
#define KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_RENDERER_HPP

#include "joguin/engine/events/EventSystem.hpp"
#include <joguin/engine/events/EventQueue.hpp>
#include <joguin/engine/renderer/Gl.hpp>

namespace Joguin {
namespace Engine {
namespace Renderer {

class RendererOptions final {
  public:
    int windowWidth{800};
    int windowHeight{600};
    const char *windowTitle{"Joguin"};
};

class Renderer final {
  public:
    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    ~Renderer();

    GLFWwindow *getWindow();

    void present();

  private:
    Events::EventSystem &eventSystem;
    GLFWwindow *window;

    int windowWidth;
    int windowHeight;

    Renderer(RendererOptions options, Events::EventSystem &eventSystem);

    static std::unordered_map<GLFWwindow *, Renderer *> rendererMap;
    static void handleWindowClose(GLFWwindow *window);
    static void handleWindowResize(GLFWwindow *window, int width, int height);

    friend class RendererFactory;
};

} // namespace Renderer
} // namespace Engine
} // namespace Joguin

#endif
