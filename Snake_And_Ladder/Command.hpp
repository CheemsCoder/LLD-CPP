#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include "Player.hpp"
#include "Board.hpp"
using namespace std;

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class MoveCommand : public Command {
    Player* player;
    int steps;
    Board* board;

public:
    MoveCommand(Player* player, int steps, Board* board)
        : player(player), steps(steps), board(board) {}

    void execute() override {
        int newPosition = player->getPosition() + steps;
        if (newPosition > board->getSize()) {
            newPosition = board->getSize();
        }
        if (board->getSnakes().count(newPosition)) {
            newPosition = board->getSnakes().at(newPosition);
        } else if (board->getLadders().count(newPosition)) {
            newPosition = board->getLadders().at(newPosition);
        }
        player->setPosition(newPosition);
    }
};

#endif