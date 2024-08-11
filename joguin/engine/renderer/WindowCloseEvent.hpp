#ifndef KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_WINDOWEVENT_HPP
#define KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_WINDOWEVENT_HPP

#include <joguin/engine/renderer/Gl.hpp>

namespace Joguin {
namespace Engine {
namespace Renderer {

struct WindowCloseEvent {
    GLFWwindow *window;
};

} // namespace Renderer
} // namespace Engine
} // namespace Joguin

#endif
