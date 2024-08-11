#ifndef KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_RENDEREREXCEPTION_HPP
#define KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_RENDEREREXCEPTION_HPP

#include <exception>

namespace Joguin {
namespace Engine {
namespace Renderer {

class RendererException : public std::exception {
  public:
    RendererException(const char *message) : message{message} {}

    const char *what() const noexcept override { return message; }

  private:
    const char *message;
};

} // namespace Renderer
} // namespace Engine
} // namespace Joguin

#endif
