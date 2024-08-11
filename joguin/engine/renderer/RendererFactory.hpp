#ifndef KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_RENDERERFACTORY_HPP
#define KASOUZA_JOGUIN_JOGUIN_ENGINE_RENDERER_RENDERERFACTORY_HPP

#include "joguin/engine/events/EventSystem.hpp"
#include <memory>
#include <vector>

#include <joguin/engine/renderer/Renderer.hpp>

namespace Joguin {
namespace Engine {
namespace Renderer {

class RendererFactory {
  public:
    RendererFactory() = delete;
    ~RendererFactory() = delete;
    RendererFactory(const RendererFactory &) = delete;
    RendererFactory &operator=(const RendererFactory &) = delete;

    static Renderer &create(RendererOptions options, Events::EventSystem &eventQueueGroup);

  private:
    static std::vector<std::unique_ptr<Renderer>> renderers;
};

} // namespace Renderer
} // namespace Engine
} // namespace Joguin
#endif
