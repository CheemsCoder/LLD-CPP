#ifndef OBSTACLEFACTORY_HPP
#define OBSTACLEFACTORY_HPP
#include <iostream>
using namespace std;

#include "Board.hpp"

class ObstacleFactory {
  public:
    static void createSnakes(Board* board, vector<pair<int,int> > snakes) {
      for(int i=0;i<snakes.size();i++) {
        board->addSnake(snakes[i].first ,  snakes[i].second);
      }
    }

    static void createLadders(Board* board, vector<pair<int,int> > ladders) {
      for(int i=0;i<ladders.size();i++) {
        board->addLadder(ladders[i].first ,  ladders[i].second);
      }
    }
};

#endif