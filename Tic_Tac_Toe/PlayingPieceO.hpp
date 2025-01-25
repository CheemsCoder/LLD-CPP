#ifndef PLAYINGPIECEO_HPP
#define PLAYINGPIECEO_HPP

#include "PlayingPiece.hpp"
#include "PieceType.hpp"

class PlayingPieceO : public PlayingPiece {
public:
    PlayingPieceO() : PlayingPiece(PieceType::O) { }
};

#endif
