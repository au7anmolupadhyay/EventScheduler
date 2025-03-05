#include "EventManager.h"
#include <iostream>

void EventManager::subscribe(const std::string& event, EventCallback callback) {
    eventHandlers[event].push_back(callback);
}

void EventManager::trigger(const std::string& event) {
    if (eventHandlers.count(event)) {
        for (auto& handler : eventHandlers[event]) {
            handler();
        }
    }
}