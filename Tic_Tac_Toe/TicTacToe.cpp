#include <iostream>
#include "TicTacToe.hpp"
#include "PlayingPiece.hpp"
#include "PlayingPieceX.hpp"
#include "PlayingPieceO.hpp"
using namespace std;


bool TicTacToe::isThereWinner(int row, int column, PieceType pieceType) {
    bool rowMatch = true;
    bool columnMatch = true;
    bool diagonalMatch = true;
    bool antiDiagonalMatch = true;

    // Check the row
    for (int i = 0; i < gameBoard->size; ++i) {
        if (gameBoard->board[row][i] == nullptr || gameBoard->board[row][i]->pieceType != pieceType) {
            rowMatch = false;
            break;
        }
    }

    // Check the column
    for (int i = 0; i < gameBoard->size; ++i) {
        if (gameBoard->board[i][column] == nullptr || gameBoard->board[i][column]->pieceType != pieceType) {
            columnMatch = false;
            break;
        }
    }

    // Check the diagonal (if the position is on the diagonal)
    if (row == column) {
        for (int i = 0; i < gameBoard->size; ++i) {
            if (gameBoard->board[i][i] == nullptr || gameBoard->board[i][i]->pieceType != pieceType) {
                diagonalMatch = false;
                break;
            }
        }
    } else {
        diagonalMatch = false;
    }

    // Check the anti-diagonal (if the position is on the anti-diagonal)
    if (row + column == gameBoard->size - 1) {
        for (int i = 0, j = gameBoard->size - 1; i < gameBoard->size; ++i, --j) {
            if (gameBoard->board[i][j] == nullptr || gameBoard->board[i][j]->pieceType != pieceType) {
                antiDiagonalMatch = false;
                break;
            }
        }
    } else {
        antiDiagonalMatch = false;
    }

    // Return true if there is a winner in any of the directions
    return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;
}

void TicTacToe::initializeGame() {
    PlayingPieceX* crossPiece = new PlayingPieceX(); 
    Player* player1 = new Player("Player1", crossPiece);

    PlayingPieceO* noughtsPiece = new PlayingPieceO();
    Player* player2 = new Player("Player2", noughtsPiece);

    players.push(player2);
    players.push(player1);

    // Initialize the board
    gameBoard = new Board(3);
}

string TicTacToe::startGame() {
    bool noWinner = true;
    while (noWinner) {
        Player* playerTurn = players.top(); // Get player turn
        players.pop();
        gameBoard->printBoard();

        if (!gameBoard->hasFreeCells()) {
            noWinner = false;
            continue;
        }

        int inputRow, inputColumn;
        cout << "Player: " << playerTurn->getName() << " Enter row,column: ";
        cin >> inputRow >> inputColumn;

        bool pieceAddedSuccessfully = gameBoard->addPiece(inputRow, inputColumn, playerTurn->getPlayingPiece());
        if (!pieceAddedSuccessfully) {
            cout << "Incorrect position chosen, try again" << endl;
            players.push(playerTurn);
            continue;
        }

        bool winner = isThereWinner(inputRow, inputColumn, playerTurn->getPlayingPiece()->pieceType);
        if (winner) {
            gameBoard->printBoard();
            return playerTurn->getName();
        }

        // Swap players
        Player* nextPlayer = players.top();
        players.pop();
        players.push(playerTurn);
        players.push(nextPlayer);
    }
    return "tie";
}