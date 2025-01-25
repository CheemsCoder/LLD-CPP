/*
 * Open/Closed Principle (OCP) Theory
 * -----------------------------------
 * The Open/Closed Principle states that software entities such as classes, modules, and functions 
 * should be open for extension but closed for modification.
 *
 * This means that you should be able to extend the behavior of a system without modifying its existing code.
 *
 * Why OCP is Important:
 * ----------------------
 * - Modifying existing code can introduce bugs.
 * - Maintaining backward compatibility becomes harder if you change existing logic.
 * - It ensures that the system is flexible and adaptable to new requirements without risking existing functionality.
 *
 * Violating OCP:
 * --------------
 * A class is not closed for modification if, to add new functionality, you need to change the existing implementation.
 * */

#include <iostream>
#include <vector>

// Example of OCP Violation
class NotificationService {
public:
    void sendNotification(const std::string& type, const std::string& message) {
        if (type == "Email") {
            std::cout << "Sending Email: " << message << std::endl;
        } else if (type == "SMS") {
            std::cout << "Sending SMS: " << message << std::endl;
        }
        // Adding a new notification type requires modifying this function
    }
};

/*
 * Adhering to OCP:
 * -----------------
 * Create an abstraction for the functionality and extend the behavior by creating new implementations
 * of the abstraction without changing the existing code.
 * */

class Notification {
public:
    virtual void send(const std::string& message) const = 0;
    virtual ~Notification() = default;
};

class EmailNotification : public Notification {
public:
    void send(const std::string& message) const override {
        std::cout << "Sending Email: " << message << std::endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const std::string& message) const override {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};

void sendNotifications(const std::vector<Notification*>& notifications, const std::string& message) {
    for (const auto& notification : notifications) {
        notification->send(message);
    }
}

int main() {
    // Violating OCP
    NotificationService notificationService;
    notificationService.sendNotification("Email", "Hello OCP!");
    notificationService.sendNotification("SMS", "Hello OCP!");

    // Adhering to OCP
    std::vector<Notification*> notifications = {new EmailNotification(), new SMSNotification()};
    sendNotifications(notifications, "Hello OCP!");

    // Clean up
    for (auto& notification : notifications) {
        delete notification;
    }

    return 0;
}

/*
 * Benefits of Adhering to OCP:
 * ----------------------------
 * - The `Notification` abstraction ensures that new notification types can be added without modifying 
 *   existing classes like `EmailNotification` or `SMSNotification`.
 * - The existing code is stable and not at risk of being broken when new features are introduced.
 */
