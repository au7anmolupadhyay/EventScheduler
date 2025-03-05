#include "EventManager.h"
#include "TaskScheduler.h"
#include "APIHandler.h"
#include <iostream>

int main() {
    EventManager eventManager;
    TaskScheduler taskScheduler;

    eventManager.subscribe("APIEvent", []() {
        std::string data = APIHandler::fetchAPIData("https://jsonplaceholder.typicode.com/todos/1");
        std::cout << "API Response: " << data << std::endl;
    });

    eventManager.trigger("APIEvent");
    taskScheduler.schedule([]() { std::cout << "Scheduled Task Executed" << std::endl; }, 3000);
    
    return 0;
}