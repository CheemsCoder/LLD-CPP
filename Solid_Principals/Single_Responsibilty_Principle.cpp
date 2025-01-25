/*
 * Single Responsibility Principle (SRP) Theory
 * --------------------------------------------
 * SRP states that a class should have only one responsibility, meaning it should have only one reason to change.
 * This principle helps in creating cohesive classes with minimal coupling, making code easier to maintain and extend.
 *
 * Violating SRP:
 * --------------
 * When a class performs multiple responsibilities, it becomes tightly coupled, leading to a higher likelihood of changes 
 * in one responsibility affecting the others. This makes the code harder to understand, maintain, and test.
 *
 * Adhering to SRP:
 * ----------------
 * Divide responsibilities among multiple classes, each focusing on a single task. This improves clarity and reduces 
 * dependencies, ensuring that changes in one area have minimal impact elsewhere.
 *
 * Example:
 * --------
 * Consider a class that handles both user authentication and logging. These are two distinct responsibilities.
 * Violating SRP:
 * */

#include <iostream>
#include <string>

class AuthService {
public:
    void authenticateUser(const std::string& username, const std::string& password) {
        std::cout << "Authenticating user: " << username << std::endl;
        // Authentication logic
    }

    void logActivity(const std::string& activity) {
        std::cout << "Logging activity: " << activity << std::endl;
        // Logging logic
    }
};

/*
 * Adhering to SRP:
 * ----------------
 * Separate the responsibilities into two classes: one for authentication and another for logging.
 * */

class UserAuthenticator {
public:
    void authenticateUser(const std::string& username, const std::string& password) {
        std::cout << "Authenticating user: " << username << std::endl;
        // Authentication logic
    }
};

class ActivityLogger {
public:
    void logActivity(const std::string& activity) {
        std::cout << "Logging activity: " << activity << std::endl;
        // Logging logic
    }
};

int main() {
    // Violating SRP
    AuthService authService;
    authService.authenticateUser("JohnDoe", "password123");
    authService.logActivity("User logged in");

    // Adhering to SRP
    UserAuthenticator authenticator;
    authenticator.authenticateUser("JohnDoe", "password123");

    ActivityLogger logger;
    logger.logActivity("User logged in");

    return 0;
}
