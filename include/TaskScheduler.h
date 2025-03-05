#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class TaskScheduler {
public:
    TaskScheduler();
    ~TaskScheduler();
    void schedule(std::function<void()> task, int delayMs);
    void run();
private:
    std::priority_queue<std::pair<int, std::function<void()>>> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    bool running;
    std::thread worker;
};

#endif