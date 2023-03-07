/************************************************************
Description: Subscriber Class
Author: Gandhar Deshpande
Date: 3/7/2023
*************************************************************/

#include "subscriber.h"
#include <iostream>

std::mutex global_lock;

Subscriber::Subscriber(int id) : id(id) {}

// Receive the message from the publisher
void Subscriber::receive(const std::string &message)
{
    std::unique_lock<std::mutex> lock(m_lock);
    this->m_queue.push(message);
}

// thread to check for publisher messages
void Subscriber::start()
{
    // std::cout <<"in subscriber " << id <<" start...\n";
    while (is_running)
    {
        if (!m_queue.empty())
        {
            std::unique_lock<std::mutex> lock(global_lock);
            std::cout << "Subscriber " << id << " received message: " << m_queue.front() << std::endl;
            m_queue.pop();
        }
    }
    std::cout << "subscriber thread: " << id << " stopped" << std::endl;
}

// start the thread
void Subscriber::run()
{
    sub_thread = std::thread(&Subscriber::start, this);
}

// stop the thread
void Subscriber::stop()
{
    is_running = false;
    sub_thread.join();
}