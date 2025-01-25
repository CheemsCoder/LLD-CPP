/*
 * Interface Segregation Principle (ISP) Theory
 * --------------------------------------------
 * The Interface Segregation Principle states that a class should not be forced to implement 
 * interfaces it does not use. Instead, create smaller, more specific interfaces for clients.
 *
 * Why ISP is Important:
 * ----------------------
 * - Reduces the impact of changes by segregating behavior into smaller interfaces.
 * - Prevents clients from being forced to depend on methods they do not need.
 * - Promotes modularity and easier maintenance.
 *
 * Violating ISP:
 * --------------
 * A large interface with many unrelated methods forces implementing classes to provide 
 * implementations for methods they don't use, leading to unnecessary complexity.
 * */

#include <iostream>

// Violating ISP: A single large interface
class Machine {
public:
    virtual void print(const std::string& content) = 0;
    virtual void scan(const std::string& content) = 0;
    virtual void fax(const std::string& content) = 0;
    virtual ~Machine() = default;
};

// A class forced to implement unused methods
class SimplePrinter : public Machine {
public:
    void print(const std::string& content) override {
        std::cout << "Printing: " << content << std::endl;
    }

    void scan(const std::string& content) override {
        // Not needed, but must implement
        throw std::logic_error("Scan not supported!");
    }

    void fax(const std::string& content) override {
        // Not needed, but must implement
        throw std::logic_error("Fax not supported!");
    }
};

/*
 * Adhering to ISP:
 * -----------------
 * Create smaller, more specific interfaces that group related behavior.
 * */

class Printer {
public:
    virtual void print(const std::string& content) = 0;
    virtual ~Printer() = default;
};

class Scanner {
public:
    virtual void scan(const std::string& content) = 0;
    virtual ~Scanner() = default;
};

class Fax {
public:
    virtual void fax(const std::string& content) = 0;
    virtual ~Fax() = default;
};

// Classes only implement the interfaces they need
class SimplePrinterISP : public Printer {
public:
    void print(const std::string& content) override {
        std::cout << "Printing: " << content << std::endl;
    }
};

class AdvancedMachine : public Printer, public Scanner, public Fax {
public:
    void print(const std::string& content) override {
        std::cout << "Printing: " << content << std::endl;
    }

    void scan(const std::string& content) override {
        std::cout << "Scanning: " << content << std::endl;
    }

    void fax(const std::string& content) override {
        std::cout << "Faxing: " << content << std::endl;
    }
};

int main() {
    // Using ISP-compliant classes
    SimplePrinterISP printer;
    printer.print("ISP Example Document");

    AdvancedMachine machine;
    machine.print("Advanced Machine Document");
    machine.scan("Document to Scan");
    machine.fax("Document to Fax");

    return 0;
}

/*
 * Benefits of Adhering to ISP:
 * ----------------------------
 * - Prevents unnecessary code implementation in classes.
 * - Promotes clear, modular, and purpose-specific interfaces.
 * - Reduces the risk of unintended side effects when interfaces change.
 */
