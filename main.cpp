/****************************************************************************
Description: Sample Application for publish subscribe library
Author: Gandhar Deshpande
Date: 3/7/2023
*****************************************************************************/

#include "publisher.h"
#include "subscriber.h"
#include "subscriberlist.h"
#include <iostream>
#include <chrono>

int main()
{
    Publisher publisher1;
    Publisher publisher2;
    SubscriberList subscriberList1;
    SubscriberList subscriberList2;

    // Create 4 subscribers for 2 publishers

    Subscriber *subscriber1 = new Subscriber(1);
    subscriberList1.addSubscriber(subscriber1);
    publisher1.addSubscriber(subscriber1);
    subscriber1->run();

    Subscriber *subscriber2 = new Subscriber(2);
    subscriberList1.addSubscriber(subscriber2);
    publisher1.addSubscriber(subscriber2);
    subscriber2->run();

    Subscriber *subscriber3 = new Subscriber(3);
    subscriberList2.addSubscriber(subscriber3);
    publisher2.addSubscriber(subscriber3);
    subscriber3->run();

    Subscriber *subscriber4 = new Subscriber(4);
    subscriberList2.addSubscriber(subscriber4);
    publisher2.addSubscriber(subscriber4);
    subscriber4->run();

    // Publish messages every 1 seconds to subscribers
    int count = 0;
    while (count <= 5)
    {
        std::string message = "Publisher-1 Message: " + std::to_string(count);
        publisher1.publish(message);
        count++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    while (count <= 10)
    {
        std::string message = "Publisher-2 Message: " + std::to_string(count);
        publisher2.publish(message);
        count++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Remove all subscribers from the publisher
    for (auto subscriber : subscriberList1.getSubscribers())
    {
        subscriber->stop();
        publisher1.removeSubscriber(subscriber);
    }

    for (auto subscriber : subscriberList2.getSubscribers())
    {
        subscriber->stop();
        publisher2.removeSubscriber(subscriber);
    }

    // Cleanup
    for (auto subscriber : subscriberList1.getSubscribers())
    {
        delete subscriber;
    }
    for (auto subscriber : subscriberList2.getSubscribers())
    {
        delete subscriber;
    }

    return 0;
}
