#include <joguin/engine/events/EventSystem.hpp>

namespace Joguin {
namespace Engine {
namespace Events {

void EventSystem::processEvents() {
    for (auto &event : eventMap) {
        event.second->processEvents();
    }
}

} // namespace Events
} // namespace Engine
} // namespace Joguin
