#ifndef PLAYINGPIECEX_HPP
#define PLAYINGPIECEX_HPP

#include "PlayingPiece.hpp"
#include "PieceType.hpp"

class PlayingPieceX : public PlayingPiece {
public:
    PlayingPieceX() : PlayingPiece(PieceType::X) { }
};


#endif
