#ifndef KASOUZA_JOGUIN_JOGUIN_ENGINE_EVENTS_EVENTQUEUE_HPP
#define KASOUZA_JOGUIN_JOGUIN_ENGINE_EVENTS_EVENTQUEUE_HPP

#include <functional>
#include <queue>

namespace Joguin {
namespace Engine {
namespace Events {

class BaseEventQueue {
  public:
    virtual ~BaseEventQueue() = default;
    virtual void processEvents() = 0;
};

template <typename T> class EventQueue final : public Events::BaseEventQueue {
  public:
    using EventHandler = std::function<void(T)>;

    EventQueue() = default;

    EventQueue(const EventQueue &) = delete;
    EventQueue &operator=(const EventQueue &) = delete;

    void pushEvent(T event) { events.push(event); }

    void subscribe(EventHandler handler) { handlers.push_back(handler); }

    void unsubscribe(EventHandler handler) {
        handlers.erase(std::remove(handlers.begin(), handlers.end(), handler),
                       handlers.end());
    }

    void processEvents() {
        while (!events.empty()) {
            T event = popEvent();
            for (auto handler : handlers) {
                handler(event);
            }
        }
    }

  private:
    std::queue<T> events;
    std::vector<EventHandler> handlers;

    T popEvent() {
        T event = events.front();
        events.pop();
        return event;
    }
};

} // namespace Events
} // namespace Engine
} // namespace Joguin

#endif
