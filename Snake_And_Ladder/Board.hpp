#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include <map>
using namespace std;

class Board {
  static Board* boardInstance;
  int size;
  map<int, int> snakes;
  map<int, int> ladders;
  Board(int size) {
    this->size = size;
  }
  public:
    static Board* getInstance(int size) {
      if(boardInstance == nullptr) {
        boardInstance = new Board(size);
      }
      return boardInstance;
    }
    int getSize() {
      return size;
    }
    map<int, int> getSnakes() {
      return snakes;
    }
    map<int,int> getLadders() {
      return ladders;
    }
    void addSnake(int start, int end) {
      snakes[start] = end;
    }
    void addLadder(int start, int end) {
      ladders[start] = end;
    }
};

#endif