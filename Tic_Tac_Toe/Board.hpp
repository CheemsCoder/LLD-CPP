#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include "PlayingPiece.hpp"

using namespace std;

class Board {
  public:
    int size;
    vector<vector<PlayingPiece* > > board;  // Use pointers to PlayingPiece objects

    // Constructor to initialize the board with a given size
    Board(int size) {
      this->size = size;
      // Initialize a board of size x size with null pointers
      board.resize(size, vector<PlayingPiece*>(size, nullptr)); 
    }

    // Method to print the current state of the board
    void printBoard() {
      for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
          if (board[i][j] == nullptr) {
            cout << "- ";  // Empty cell
          } else {
            cout << (board[i][j]->pieceType == PieceType::X ? "X " : "O ");
          }
        }
        cout << endl;
      }
    }

    // Method to check if there are any free cells left on the board
    bool hasFreeCells() {
      for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
          if (board[i][j] == nullptr) {  // If a cell is null, it's free
            return true;
          }
        }
      }
      return false;  // No free cells
    }

    // Method to add a piece to the board at a specific location
    bool addPiece(int row, int column, PlayingPiece* piece) {
      // Check if the cell is free
      if(row<0 || row>=size || column<0 || column>=size) return false;
      if (board[row][column] == nullptr) {
        board[row][column] = piece;
        return true;  // Piece added successfully
      }
      return false;  // Cell is already occupied
    }
};

#endif
