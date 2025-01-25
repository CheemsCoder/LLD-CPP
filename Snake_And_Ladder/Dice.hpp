#ifndef DICE_HPP
#define DICE_HPP
#include <iostream>
#include <random>
using namespace std;

// Interface for DiceStrategy
class DiceStrategy {
public:
    virtual int rollDice() = 0; // Pure virtual method
    virtual ~DiceStrategy() = default; // Virtual destructor
};

// NormalDice class implementing DiceStrategy
class NormalDice : public DiceStrategy {
public:
    NormalDice() {
        std::srand(std::time(nullptr)); // Seed the random number generator
    }

    int rollDice() override {
        return (std::rand() % 6) + 1; // Generate a number between 1 and 6
    }
};

// LoadedDice class implementing DiceStrategy
class LoadedDice : public DiceStrategy {
public:
    LoadedDice() {
        std::srand(std::time(nullptr)); // Seed the random number generator
    }

    int rollDice() override {
        return (std::rand() % 3) + 4; // Generate a number between 4 and 6
    }
};

#endif