/*
 * Dependency Inversion Principle (DIP) Theory
 * --------------------------------------------
 * The Dependency Inversion Principle states that:
 * 1. High-level modules should not depend on low-level modules. Both should depend on abstractions.
 * 2. Abstractions should not depend on details. Details should depend on abstractions.
 *
 * Why DIP is Important:
 * ----------------------
 * - Promotes decoupling between high-level logic and low-level implementation details.
 * - Makes code more flexible, reusable, and easier to test.
 * - Reduces the impact of changes in implementation details on high-level modules.
 *
 * Violating DIP:
 * --------------
 * High-level modules directly depend on low-level modules, making the system rigid and hard to extend.
 * */

#include <iostream>
#include <string>

// Low-level module
class FileLogger {
public:
    void log(const std::string& message) {
        std::cout << "Logging to file: " << message << std::endl;
    }
};

// High-level module depends directly on low-level module
class UserService {
    FileLogger logger; // Direct dependency on low-level module

public:
    void registerUser(const std::string& username) {
        std::cout << "Registering user: " << username << std::endl;
        logger.log("User registered: " + username);
    }
};

/*
 * Adhering to DIP:
 * -----------------
 * Use an abstraction (e.g., an interface) that both high-level and low-level modules depend on.
 * */

class ILogger {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~ILogger() = default;
};

// Low-level module depends on abstraction
class ConsoleLogger : public ILogger {
public:
    void log(const std::string& message) override {
        std::cout << "Logging to console: " << message << std::endl;
    }
};

class FileLoggerDIP : public ILogger {
public:
    void log(const std::string& message) override {
        std::cout << "Logging to file: " << message << std::endl;
    }
};

// High-level module depends on abstraction
class UserServiceDIP {
    ILogger& logger; // Depends on abstraction, not a specific implementation

public:
    explicit UserServiceDIP(ILogger& logger) : logger(logger) {}

    void registerUser(const std::string& username) {
        std::cout << "Registering user: " << username << std::endl;
        logger.log("User registered: " + username);
    }
};

int main() {
    // Violating DIP
    UserService userService;
    userService.registerUser("JohnDoe");

    // Adhering to DIP
    ConsoleLogger consoleLogger;
    UserServiceDIP userServiceDIP(consoleLogger);
    userServiceDIP.registerUser("JaneDoe");

    FileLoggerDIP fileLogger;
    UserServiceDIP fileUserService(fileLogger);
    fileUserService.registerUser("Alice");

    return 0;
}

/*
 * Benefits of Adhering to DIP:
 * ----------------------------
 * - High-level modules are not tightly coupled to specific low-level modules, improving flexibility.
 * - Switching or extending implementations (e.g., changing logging from file to console) requires no changes to high-level modules.
 * - Code becomes easier to test using mock or dummy implementations of the abstractions.
 */
