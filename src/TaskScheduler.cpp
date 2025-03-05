#include "TaskScheduler.h"
#include <iostream>
#include <chrono>
#include <thread>

TaskScheduler::TaskScheduler() : running(true) {
    worker = std::thread(&TaskScheduler::run, this);
}

TaskScheduler::~TaskScheduler() {
    running = false;
    cv.notify_one();
    worker.join();
}

void TaskScheduler::schedule(std::function<void()> task, int delayMs) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    task();
}

void TaskScheduler::run() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}