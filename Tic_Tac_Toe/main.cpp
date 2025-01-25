#include <iostream>
using namespace std;

#include "TicTacToe.hpp"

int main() {
  TicTacToe* game = new TicTacToe();
  game->initializeGame();
  string winner = game->startGame();
  cout << "Game Winner is: " << winner << endl;
  return 0;
}