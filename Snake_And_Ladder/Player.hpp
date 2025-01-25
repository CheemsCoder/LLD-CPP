#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<iostream>
#include <vector>
using namespace std;

#include "Board.hpp"

class IPlayer {
  public: 
    virtual void update(string message) = 0;
};

class Player : public IPlayer {
  string name;
  int position;
  public:
    Player(string name) {
      this->name = name;
      this->position = 0;
    }
    string getName() {
      return name;
    }
    int getPosition() {
      return position;
    }
    void setName(string name) {
      this->name = name;
    } 
    void setPosition(int position) {
      this->position = position;
    }
    void update(string message) {
      cout << name + ": " + message <<endl;
    }
};

class Game {
  vector<Player* > players;
  int currentPlayerIndex;

  public:
    Game() {
      players.clear();
      this->currentPlayerIndex = 0;
    }
    void addPlayer(Player* player) {
      players.push_back(player);
    }
    void notifyPlayers(string message) {
      for(auto player: players) {
        player->update(message);
      }
    }
    Player* getCurrentPlayer() {
      return players[currentPlayerIndex];
    }
    void nextTurn() {
      currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }
};


#endif