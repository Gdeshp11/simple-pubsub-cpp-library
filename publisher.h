/*********************************************************
Description: Publisher Class
Author: Gandhar Deshpande
Date: 3/7/2023
**********************************************************/

#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>
#include <vector>
#include <mutex>
#include <chrono>

class Publisher {
public:
    void publish(const std::string& message);
    void addSubscriber(class Subscriber* subscriber);
    void removeSubscriber(class Subscriber* subscriber);
private:
    std::vector<class Subscriber*> subscribers;
    std::mutex mutex;
};

#endif