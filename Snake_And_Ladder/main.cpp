// UML DIAGRAM: Snakes and Ladders Game

// ---------------------------------------------------------------------
//                          +--------------------+
//                          |     GameManager    |
//                          +--------------------+
//                          | - board: Board     |
//                          | - players: List<Player> |
//                          | - currentPlayer: Player |
//                          | - observer: Observer |
//                          +--------------------+
//                          | + startGame(): void |
//                          | + nextTurn(): void  |
//                          +--------------------+
//                                    |
//                                    v
//                          +--------------------+
//                          |    Player (Observer) |
//                          +--------------------+
//                          | - name: String       |
//                          | - position: int      |
//                          | + updateTurn(): void |
//                          +--------------------+

// ---------------------------------------------------------------------
//                          +--------------------+
//                          |       Board        |
//                          +--------------------+
//                          | - instance: Board  | // Singleton
//                          | - cells: List<Cell>|
//                          | - snakes: List<Snake> |
//                          | - ladders: List<Ladder>|
//                          +--------------------+
//                          | + getInstance(): Board |
//                          | + placeSnakesAndLadders(): void |
//                          | + getCell(position: int): Cell |
//                          +--------------------+
//                                    ^
//                                    |
//                          +--------------------+
//                          |   FactoryPattern   |
//                          +--------------------+
//                          | + createSnakes(): List<Snake>|
//                          | + createLadders(): List<Ladder>|
//                          +--------------------+

// ---------------------------------------------------------------------
//                          +--------------------+
//                          |    Dice (Strategy) |
//                          +--------------------+
//                          | - rollBehavior: RollBehavior |
//                          +--------------------+
//                          | + roll(): int |
//                          | + setRollBehavior(behavior: RollBehavior): void |
//                          +--------------------+
//                                    |
//                                    v
//      +--------------------+      +--------------------+      +--------------------+
//      |   RollStandard     |      |    RollBiased      |      |   RollMultipleDice |
//      +--------------------+      +--------------------+      +--------------------+
//      | + roll(): int      |      | + roll(): int      |      | + roll(): int      |
//      +--------------------+      +--------------------+      +--------------------+

// ---------------------------------------------------------------------
//                          +--------------------+
//                          |  Command Pattern   |
//                          +--------------------+
//                          | - commands: Queue<Command> |
//                          +--------------------+
//                          | + execute(command: Command): void |
//                          | + undo(): void |
//                          +--------------------+
//                                    ^
//                                    |
//                          +--------------------+
//                          |     MoveCommand    |
//                          +--------------------+
//                          | - player: Player   |
//                          | - newPosition: int |
//                          +--------------------+
//                          | + execute(): void  |
//                          | + undo(): void     |
//                          +--------------------+


// Features Required:
// Board Initialization: A board with a predefined size.

// Players: Multiple players can play the game.

// Snakes and Ladders: Random placement of snakes and ladders.

// Dice Roll: A player can roll a dice and move accordingly.

// Game Logic: Movement according to dice roll and handling snakes and ladders.

// Design Patterns Involved:
// Singleton Pattern: Used for creating a single instance of the board to ensure that all players interact with the same board.

// Factory Pattern: Used to create snakes and ladders on the board.

// Observer Pattern: Used to notify players about their turns.

// Strategy Pattern: Used to define the dice rolling strategy, which can be changed dynamically.

// Command Pattern: Used to encapsulate a request as an object to parameterize clients with queues, requests, and operations.

#include <iostream>
#include <vector>
#include "Board.hpp"
#include "ObstacleFactory.hpp"
#include "Player.hpp"
#include "Dice.hpp"
#include "Command.hpp"
using namespace std;
Board* Board::boardInstance = nullptr;


int main() {
  Game* game = new Game();
  Board* board = Board::getInstance(100);
  vector<pair<int, int> > snakes = {
    {16, 6}, {48, 26}, {49, 11}, {56, 53}, {62, 19},
    {64, 60}, {87, 24}, {93, 73}, {95, 75}, {98, 78}
  };
  vector<pair<int,int> > ladders = {
    {1, 38}, {4, 14}, {9, 31}, {21, 42}, {28, 84},
    {36, 44}, {51, 67}, {71, 91}, {80, 100}
  };
  ObstacleFactory::createLadders(board, ladders);
  ObstacleFactory::createSnakes(board, snakes);
  Player* player1 = new Player("player1");
  Player* player2 = new Player("player2");
  game->addPlayer(player1);
  game->addPlayer(player2);
  
  DiceStrategy* dice = new NormalDice();

  while(true) {
    Player* currentPlayer = game->getCurrentPlayer();
    int diceRoll = dice->rollDice();
    Command* moveCommand = new MoveCommand(currentPlayer, diceRoll, board);
    moveCommand->execute();

    game->notifyPlayers(currentPlayer->getName() + " rolled a " + std::to_string(diceRoll) + " and moved to " + std::to_string(currentPlayer->getPosition()));

    if (currentPlayer->getPosition() == board->getSize()) {
        game->notifyPlayers(currentPlayer->getName() + " wins!");
        break;
    }
    game->nextTurn();
  }
  return 0;

}