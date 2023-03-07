#ifndef SUBSCRIBERLIST_H
#define SUBSCRIBERLIST_H

/***********************************************************
Description: SubscriberList class
Author: Gandhar Deshpande
Date: 3/7/2023
************************************************************/

#include <vector>
#include "subscriber.h"
#include <algorithm>

class SubscriberList {
public:
    void addSubscriber(Subscriber* subscriber);
    void removeSubscriber(Subscriber* subscriber);
    std::vector<Subscriber*> getSubscribers() const;
private:
    std::vector<Subscriber*> subscribers;
};

#endif