/*********************************************************
Description: Publisher Class
Author: Gandhar Deshpande
Date: 3/7/2023
**********************************************************/

#include "publisher.h"
#include "subscriber.h"
#include <algorithm>

// publish the message to all subscribers
void Publisher::publish(const std::string &message)
{
    std::unique_lock<std::mutex> lock(mutex);
    for (auto subscriber : subscribers)
    {
        subscriber->receive(message);
    }
}

// add the subscriber to the list
void Publisher::addSubscriber(Subscriber *subscriber)
{
    std::unique_lock<std::mutex> lock(mutex);
    subscribers.push_back(subscriber);
}

// remove the subscriber from the list
void Publisher::removeSubscriber(Subscriber *subscriber)
{
    std::unique_lock<std::mutex> lock(mutex);
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
}
