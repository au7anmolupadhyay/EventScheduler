#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <functional>
#include <map>
#include <vector>
#include <string>

class EventManager {
public:
    using EventCallback = std::function<void()>;
    void subscribe(const std::string& event, EventCallback callback);
    void trigger(const std::string& event);
private:
    std::map<std::string, std::vector<EventCallback>> eventHandlers;
};

#endif