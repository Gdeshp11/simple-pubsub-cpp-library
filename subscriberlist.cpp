/***********************************************************
Description: SubscriberList class
Author: Gandhar Deshpande
Date: 3/7/2023
************************************************************/

#include "subscriberlist.h"

// add the subscriber to the list
void SubscriberList::addSubscriber(Subscriber *subscriber)
{
    subscribers.push_back(subscriber);
}

// remove the subscriber from the list
void SubscriberList::removeSubscriber(Subscriber *subscriber)
{
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
}

// get the list of all the subscribers
std::vector<Subscriber *> SubscriberList::getSubscribers() const
{
    return subscribers;
}
