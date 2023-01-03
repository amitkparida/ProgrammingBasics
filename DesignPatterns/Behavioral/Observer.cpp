//Subject-Observer. Also called Publisher-Subscriber

// Observer Design Pattern:
// 1. It defines a one-to-may dependency between objects so that when one object changes state, 
// all its dependents are notified and updated automatically.
// 2. The observer pattern is a pattern in which an object, called the subject, maintains a list of its dependents, called observers,
// and notifies them automatically of any state changes, usually by calling one of their methods.


#include <iostream>
#include <list>
using namespace std;

//Observer or Subscriber
class ISubscriber {
public:
    virtual void notify(string msg) = 0;
};

//Concrete Observer
class User : public ISubscriber {
    int userId;

public:
    User(int userId) {
        this->userId = userId;
    }

    void notify(string msg) {
        cout << "User " << userId << " received msg " << msg << endl;
    }
};

//Subject or Publisher
class IPublisher {
public:
    virtual void subscribe(ISubscriber* user) = 0;      // Subscribe or Add or Register
    virtual void unsubscribe(ISubscriber* user) = 0;    // Unsubscribe or Remove or Unregister
    virtual void notify(string msg) = 0;                // Notify or Update
};


//Concrete Subject
class Group : public IPublisher {
    list<ISubscriber*> users;

public:
    void subscribe(ISubscriber* user) {
        users.push_back(user);
    }

    void unsubscribe(ISubscriber* user) {
        users.remove(user);
    }

    void notify(string msg) {
        for (auto user : users) {
            user->notify(msg);
        }
    }
};

int main()
{
    Group* group = new Group;

    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("First message");
    group->unsubscribe(user1);
    group->notify("Second message");
}

