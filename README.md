# C++ Based Simple Publish Subscribe Library

## compiling and running the application:
#### On Linux:
- simply execute compile_and_run.sh shell script
```sh
./compile_and_run.sh
```
- this script will compile the shared library, link it to the sample application and run the application

## Classes:
- Subscriber 
- Publisher
- subscriberList

## Publisher APIs:
```
void publish(const std::string&)
void addSubscriber(class Subscriber*)
void removeSubscriber(class Subscriber*)
```
## Subscriber APIs:
```
void receive(const std::string& )
void start()
void stop()
void run()
```

## SubscriberList APIs:
```
void addSubscriber(Subscriber*)
void removeSubscriber(Subscriber*)
std::vector<Subscriber*> getSubscribers() const
```

## Design
### Publisher
- The Publisher class is used for publishing a message to all of its subscribers
- It keeps a list of registered subscribers in vector
- The subscriber is added or removed from this list when subscribed or unsubscribed 
### Subscriber
- The Subscriber class is used for receiving the message from the publisher 
- When start() is called, new thread is created for receiving the message from publisher
- std::queue \<std::string\> is used to store all the messages
- 'm_lock' mutex is used to synchronize access to the queue by same thread
- 'global_lock' mutex is used to synchronize all threads for printing messages to stdout
- Thread stops when stop() is called
### SubscriberList
- The SubscriberList class is used just to keep track of all the subscribers so that subscriber objects can be deleted later
- The subscribers are stored in vector and added or removed as per requirement
