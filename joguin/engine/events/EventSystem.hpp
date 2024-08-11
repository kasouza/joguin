#ifndef KASOUZA_JOGUIN_JOGUIN_ENGINE_EVENTS_EVENTSYSTEM_HPP
#define KASOUZA_JOGUIN_JOGUIN_ENGINE_EVENTS_EVENTSYSTEM_HPP

#include <joguin/engine/events/EventQueue.hpp>
#include <memory>

namespace Joguin {
namespace Engine {
namespace Events {

class EventSystem {
  public:
    EventSystem() = default;
    ~EventSystem() = default;
    EventSystem(const EventSystem &) = delete;
    EventSystem &operator=(const EventSystem &) = delete;

    template <typename T> void registerEvent() {
        int id = typeid(T).hash_code();
        eventMap[id] = std::make_unique<EventQueue<T>>();
    }

    template <typename T> void pushEvent(T event) {
        int id = typeid(T).hash_code();
        EventQueue<T> &eventQueue = getEventQueue<T>();
        eventQueue.pushEvent(event);
    }

    template <typename T>
    void subscribe(typename EventQueue<T>::EventHandler handler) {
        int id = typeid(T).hash_code();
        EventQueue<T> &eventQueue = getEventQueue<T>();
        eventQueue.subscribe(handler);
    }

    void processEvents();

  private:
    std::unordered_map<int, std::unique_ptr<BaseEventQueue>> eventMap;

    template <typename T> EventQueue<T> &getEventQueue() {
        int id = typeid(T).hash_code();
        return *static_cast<Joguin::Engine::Events::EventQueue<T> *>(
            eventMap[id].get());
    }
};

} // namespace Events
} // namespace Engine
} // namespace Joguin

#endif
