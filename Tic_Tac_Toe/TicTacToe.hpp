#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include <iostream>
#include <stack>
#include "Player.hpp"
#include "Board.hpp"
#include "PlayingPiece.hpp"
using namespace std;
class TicTacToe {
    stack<Player*> players;
    Board* gameBoard;
    bool isThereWinner(int, int, PieceType);
    public:
      void initializeGame();
      string startGame();
};

#endif