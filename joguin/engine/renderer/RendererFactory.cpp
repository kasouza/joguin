#include "joguin/engine/events/EventSystem.hpp"
#include <joguin/engine/renderer/Renderer.hpp>
#include <joguin/engine/renderer/RendererFactory.hpp>
#include <joguin/engine/renderer/RendererInitException.hpp>

namespace Joguin {
namespace Engine {
namespace Renderer {

std::vector<std::unique_ptr<Renderer>> RendererFactory::renderers;

Renderer &RendererFactory::create(RendererOptions options,
                                  Events::EventSystem &eventSystem) {
    if (!renderers.empty()) {
        throw RendererInitException("Only one renderer is allowed");
    }

    Renderer *renderer = new Renderer(options, eventSystem);
    if (!renderer) {
        throw RendererInitException("Failed to create renderer");
    }

    renderers.push_back(std::unique_ptr<Renderer>{renderer});
    return *renderers.back();
}

} // namespace Renderer
} // namespace Engine
} // namespace Joguin
