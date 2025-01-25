#ifndef PLAYINGPIECE_HPP
#define PLAYINGPIECE_HPP
#include "PieceType.hpp"

class PlayingPiece {
  public:
    PieceType pieceType;
    PlayingPiece(PieceType pieceType) : pieceType(pieceType) { }
};

#endif