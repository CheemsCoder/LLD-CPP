#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include "PlayingPiece.hpp"
using namespace std;

class Player {
  public:
    string name;
    PlayingPiece* playingPiece;

    // Constructor using an initializer list
    Player(string name, PlayingPiece* playingPiece)
        : name(name), playingPiece(playingPiece) { }

    string getName() const {
      return name;
    }

    void setName(const string& name) {
      this->name = name;
    }

    PlayingPiece* getPlayingPiece() const {
      return playingPiece;
    }

    void setPlayingPiece(PlayingPiece* playingPiece) {
      this->playingPiece = playingPiece;
    }
};

#endif
