#include <iostream>
#include <list>
using namespace std;

class ISubscriber {
  public:
    virtual void notify(string msg) = 0; // Pure virtual function
};

class User : public ISubscriber {
  private:
    int userId;
  public:
    User(int id) {
      userId = id;
    }
    void notify(string msg) override { // Override keyword for clarity
      cout << userId << " has been notified with the message: " << msg << endl;
    }
};

class Group {
  private:
    list<ISubscriber*> users; // List of subscribers
  public:
    void subscribe(ISubscriber* user) { // Subscribe a user
      users.push_back(user);
    }
    void unsubscribe(ISubscriber* user) { // Unsubscribe a user
      users.remove(user);
    }
    void notify(string msg) { // Notify all subscribers
      for (auto user : users) {
        user->notify(msg);
      }
    }
};

int main() {
  Group* group = new Group();
  User* user1 = new User(1);
  User* user2 = new User(2);
  User* user3 = new User(3);

  group->subscribe(user1);
  group->subscribe(user2);
  group->subscribe(user3);

  group->notify("Some Msg");

  group->unsubscribe(user1);
  group->notify("New Msg");


  return 0;
}
