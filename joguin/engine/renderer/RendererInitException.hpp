#ifndef KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_RENDERERINITEXCEPTION_HPP
#define KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_RENDERERINITEXCEPTION_HPP

#include "joguin/engine/renderer/RendererException.hpp"
#include <exception>

namespace Joguin {
namespace Engine {
namespace Renderer {

class RendererInitException : public RendererException {
  public:
    RendererInitException(const char *message) : RendererException{message} {}
};

} // namespace Renderer
} // namespace Engine
} // namespace Joguin

#endif
