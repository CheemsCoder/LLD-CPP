/*
 * Liskov Substitution Principle (LSP) Theory
 * -------------------------------------------
 * The Liskov Substitution Principle states that objects of a superclass should be replaceable 
 * with objects of its subclasses without affecting the correctness of the program.
 *
 * In simpler terms, if class B is a subclass of class A, then we should be able to use objects 
 * of class B in place of objects of class A without modifying the behavior of the program.
 *
 * Why LSP is Important:
 * ----------------------
 * - It ensures that derived classes extend the behavior of their base class without altering its functionality.
 * - Violations of LSP lead to fragile code, unexpected behavior, and tight coupling between classes.
 *
 * Violating LSP:
 * --------------
 * A subclass violates LSP if it fails to conform to the expected behavior of the base class.
 * */

#include <iostream>
#include <memory>
#include <stdexcept>

// Base class
class Bird {
public:
    virtual void fly() const {
        std::cout << "Bird is flying" << std::endl;
    }
    virtual ~Bird() = default;
};

// Subclass 1 (adheres to LSP)
class Sparrow : public Bird {
public:
    void fly() const override {
        std::cout << "Sparrow is flying" << std::endl;
    }
};

// Subclass 2 (violates LSP)
class Penguin : public Bird {
public:
    void fly() const override {
        throw std::logic_error("Penguins can't fly!"); // Violates LSP
    }
};

void makeBirdFly(const Bird& bird) {
    bird.fly(); // Expects all birds to fly
}

int main() {
    // LSP adhered to
    Sparrow sparrow;
    makeBirdFly(sparrow);

    // LSP violated
    Penguin penguin;
    try {
        makeBirdFly(penguin); // Throws an exception, breaking the program's correctness
    } catch (const std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

/*
 * Adhering to LSP:
 * -----------------
 * To adhere to LSP, avoid overriding base class methods in a way that breaks the behavior expected 
 * by the client code. For cases where a subclass cannot fulfill the contract of the base class, 
 * consider redesigning the class hierarchy.
 * */

#include <iostream>

// Base class with explicit design
class BirdLSP {
public:
    virtual void move() const {
        std::cout << "Bird is moving" << std::endl;
    }
    virtual ~BirdLSP() = default;
};

class FlyingBird : public BirdLSP {
public:
    virtual void fly() const {
        std::cout << "Flying bird is flying" << std::endl;
    }
};

class NonFlyingBird : public BirdLSP {
public:
    void move() const override {
        std::cout << "Non-flying bird is walking" << std::endl;
    }
};

int main() {
    // Adhering to LSP
    FlyingBird sparrow;
    sparrow.fly();

    NonFlyingBird penguin;
    penguin.move();

    return 0;
}

/*
 * Benefits of Adhering to LSP:
 * ----------------------------
 * - Ensures subclasses are interchangeable with their base class.
 * - Reduces bugs caused by unexpected subclass behavior.
 * - Promotes proper inheritance design and prevents misuse of polymorphism.
 */


