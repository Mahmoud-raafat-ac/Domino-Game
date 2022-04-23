/* =============================================
* File: CDominoesGame.cpp
* Description: Implementation file for GameOptions
*     struct and CDominoesGame class. Represents 
*     the Domino game. Encompasses table, Boneyard
*     pile, and game players. Manages turn logic
*     and win state. Sets up initial game state
*     and player classes.
* ==============================================
*/

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "CDominoesGame.h"
int score[4]={0};
using namespace std;

// Default constructor for GameOptions struct
GameOptions::GameOptions() : numPlayers(0), piecesPerPlayer(0)
{
	playerNames[0] = "(none)";
	playerNames[1] = "(none)";
	playerNames[2] = "(none)";
	playerNames[3] = "(none)";

	playerIsAI[0] = false;
	playerIsAI[1] = false;
	playerIsAI[2] = false;
	playerIsAI[3] = false;
}

// Default constructor for CDominoesGame class
CDominoesGame::CDominoesGame() :
	playerArr(0), numPlayers(0), isGameActive(false), curPlayerTurn(0), sequentialPasses(0), winner(-1)
{
	table = CDominoCollection(); // Initialize table collection
	pile = CDominoCollection();  // Initialize Boneyard pile collection
}

// Destructor. Calls clear game state.
CDominoesGame::~CDominoesGame()
{
	this->clearState();
}

// Resets game state, releases memory alocated for player array
// Empties table and pile collections
void CDominoesGame::clearState()
{
	// Release memory
	if (playerArr) {
		delete[] playerArr;
		playerArr = 0;
	}

	table.clear();
	pile.clear();

	isGameActive = false;
	curPlayerTurn = 0;
	sequentialPasses = 0;
	winner = -1;
}

// Initializes array of CPlayer objects using the given GameOptions
bool CDominoesGame::initPlayerArr(const GameOptions &opt)
{
	if (playerArr) { return false; } // An array of players has already been allocated

	playerArr = new CPlayer[opt.numPlayers]; // Allocate new array of given number of players

	// Initialize each CPlayer object with their name and AI state
	for (int i = 0; i < opt.numPlayers; i++)
	{
		playerArr[i] = CPlayer(opt.playerNames[i], opt.playerIsAI[i]); // Assign player names
	}

	return true;
}

// Returns true if a game is currently in session
bool CDominoesGame::gameActive()
{
	return this->isGameActive;
}

// Returns true if a winner is found or the game has ended
bool CDominoesGame::checkGameOver()
{
	// Check for a tie, i.e, players cannot play or draw.
	if (sequentialPasses >= numPlayers)
	{
		isGameActive = false; // All players have passed their turn, end game because no one can play.
		return true;
	}
	else
	{
		// Check each player and see if their hand is empty
		for (int i = 0; i < numPlayers; i++)
		{
			// We have a winner!
			if (playerArr[i].isHandEmpty())
			{
				// Update winner and active state
				winner = i;
				isGameActive = false;
				return true;
			}
		}
	}

	// Game is not over yet
	return false;
}

// Returns the name of winning player, or "Tie." if there was a tie.
string CDominoesGame::getWinner()
{   
	if(winner==-1)
	{
		if(numofplayerstotal==2)
		{
			if(playerArr[0].sumhand()<playerArr[1].sumhand())
			return playerArr[0].getName();
			else 
		return playerArr[1].getName();
		}
		else if(numofplayerstotal==3)
		{
			if((playerArr[0].sumhand()<playerArr[1].sumhand())&&(playerArr[0].sumhand()<playerArr[2].sumhand()))
              return playerArr[0].getName();
			  else if((playerArr[1].sumhand()<playerArr[0].sumhand())&&(playerArr[1].sumhand()<playerArr[2].sumhand()))
			  return playerArr[1].getName();
			  else return playerArr[2].getName();
		}
		else if(numofplayerstotal==4)
		{
			if((playerArr[0].sumhand()<playerArr[1].sumhand())&&(playerArr[0].sumhand()<playerArr[2].sumhand())&&(playerArr[0].sumhand()<playerArr[3].sumhand()))
		return playerArr[0].getName();
		else if((playerArr[1].sumhand()<playerArr[0].sumhand())&&(playerArr[1].sumhand()<playerArr[2].sumhand())&&(playerArr[1].sumhand()<playerArr[3].sumhand()))
		return playerArr[1].getName();
		else if((playerArr[2].sumhand()<playerArr[0].sumhand())&&(playerArr[2].sumhand()<playerArr[1].sumhand())&&(playerArr[2].sumhand()<playerArr[3].sumhand()))
		return playerArr[2].getName();
		else return playerArr[3].getName();
		}
		
	}
	
	
return playerArr[winner].getName();
} 

// Returns name of player who's turn is active
string CDominoesGame::getCurrentPlayer()
{
	return playerArr[curPlayerTurn].getName();
}

// Increments the curPlayerTurn variable with wrap-around
void CDominoesGame::advPlayerTurn()
{
	this->curPlayerTurn += 1;

	// Wrap around to first player
	if (curPlayerTurn >= numPlayers)
	{
		curPlayerTurn = 0;
	}
}

// Displays end turn message and resets sequentialPasses counter
void CDominoesGame::playerTurnSuccess()
{
	system("CLS");

	cout << getCurrentPlayer() << "\033[1;35m has finished his/her turn! \033[0m" << endl << endl;
	sequentialPasses = 0;

	system("pause");
}

// Displays player passed message and increment sequentialPasses counter
void CDominoesGame::playerTurnPassed()
{
	system("CLS");

	cout << getCurrentPlayer() << "\033[1;35m has passed his/her turn! \033[0m" << endl << endl;
	sequentialPasses += 1;

	system("pause");
}

// Sets up a new game state using the given GameOptions
void CDominoesGame::newGame(const GameOptions &opt)
{
	// Data sanity check for player count
	if (opt.numPlayers < 2 || opt.numPlayers > 4)
	{
		cout << "\033[1;31m  Error creating new game: Invalid player count: \033[0m" << opt.numPlayers;
		this->isGameActive = false;
		return;
	}

	clearState(); // Clear old game state

	initPlayerArr(opt); // Initialize array of active players

	srand(time(0)); // Get new seed for random number generator

	// Prepare state for new game
	this->isGameActive = true;
	this->numPlayers = opt.numPlayers;
	this->curPlayerTurn = rand() % numPlayers; // Select random player to start
	this->winner = -1;

	pile.generateAllPieces(); // Generate all 28 domino pieces
	pile.shuffle();           // Shuffle/randomize all 28 domino pieces

	// Loop through each player and give them the initial hand of
	// domino pieces from the pile
	for (int i = 0; i < numPlayers; i++)
	{
		playerArr[i].fillHand(pile);
	}
}

// Processes the next player turn
void CDominoesGame::processTurn()
{
	if (!this->isGameActive) { return; } // A game is not currently active, return

	// Process turn for current player
	if (playerArr[curPlayerTurn].processTurn(table, pile))
	{
		// Player was able to make a move or draw a piece
		playerTurnSuccess();
	}
	else
	{
		// Player could not make a move, so they passed their turn
		playerTurnPassed();
	}

	// Check if game is over
	if (!checkGameOver())
	{
		// If we don't have a winner, advance turn to next player.
		advPlayerTurn();
	}
}

// Prints table/game board to the console
void CDominoesGame::displayGameBoard()
{
	table.printAsChainedList();
}

// Displays message stating the winner of the match,
// and stats about the game and players
void CDominoesGame::showWinMessage()
{
	system("CLS");

	system("pause");

	cout << endl << "\033[1;36m === Pieces on the Table === \033[0m" << endl << endl;
	table.printAsNumberedList();

	cout << endl;

	system("pause");

	cout << endl << "\033[1;36m === Pieces in Boneyard pile ===  \033[0m" <<endl<<endl;
	pile.printAsNumberedList();

	cout << endl;

	system("pause");

	for (int i = 0; i < numPlayers; i++)
	{
		cout<<endl<<"\033[1;36m === Stats for \033[0m"<<playerArr[i].getName()<<"\033[1;36m === \033[0m"<<endl<<endl;
		cout << "\033[1;36m Dominoes Played: \033[0m" << playerArr[i].getPiecesPlayed() << endl;
		cout << "\033[1;36m Dominoes Drawn:  \033[0m" << playerArr[i].getPiecesDrawn() << endl;
		cout << "\033[1;36m Dominoes Left:   \033[0m" << playerArr[i].getPiecesInHand() << endl << endl;

		playerArr[i].printHand();
      cout<<"\033[1;36m sum of cards in hand \033[0m"<<playerArr[i].sumhand();
		cout << endl;
		system("pause");
	}
if (winner == -1)
	{
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\033[1;36m Nobody can make a move! The game has ended \033[0m";
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
		
		cout << "\033[1;36m Congratulations! \033[0m" << getWinner() << "\033[1;36m has won the game! \033[0m";
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	}
	else
	{
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		
		cout << "\033[1;36m Congratulations! \033[0m" << getWinner() << "\033[1;36m has won the game! \033[0m";
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	}
	}
	

/* =========================================
*  End of File
*  =========================================
*/