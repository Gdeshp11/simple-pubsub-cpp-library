/************************************************************
Description: Subscriber Class
Author: Gandhar Deshpande
Date: 3/7/2023
*************************************************************/

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
#include <thread>
#include <queue>
#include <mutex>

//to prevent all subscriber threads from race condition while printing to stdout
extern std::mutex global_lock;

class Subscriber {
public:
    Subscriber(int id);
    void receive(const std::string& message);
    void start();
    void stop();
    void run();
private:
    int id;
    volatile bool is_running = true;
    std::thread sub_thread;
    std::mutex m_lock;
    std::queue<std::string> m_queue;
};

#endif