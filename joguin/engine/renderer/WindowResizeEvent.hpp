#ifndef KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_WINDOWRESIZEEVENT_HPP
#define KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_WINDOWRESIZEEVENT_HPP

#include <joguin/engine/renderer/Gl.hpp>

namespace Joguin {
namespace Engine {
namespace Renderer {

struct WindowResizeEvent {
    GLFWwindow *window;
    int width;
    int height;
};

} // namespace Renderer
} // namespace Engine
} // namespace Joguin

#endif
