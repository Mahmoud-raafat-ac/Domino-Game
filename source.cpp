#include<iostream>
#include<string>
#include"CDominoesGame.h"
using namespace std;

// Forward function declarations
GameOptions getGameOptions();
bool getPlayAgain();
int numofplayerstotal=0;
int main()
{
	system("color");
    CDominoesGame domGame;
	bool playAgain = true; 
    cout << "\033[1;34m Welcome to Domino-Game!  \033[0m" << endl;
	cout << "\033[1;34m This program was created by best team ever. \033[0m" << endl << endl; 
    system("pause");

    // Main game loop
	while (playAgain)
	{
		GameOptions curRoundOpt = getGameOptions(); // Get player count and player names for next round 
		domGame.newGame(curRoundOpt); // Set up new game state

		while (domGame.gameActive())  // Loop until game is over
		{
			domGame.processTurn();      // Process next player's turn
		}


		domGame.showWinMessage();   // Display winner
		
		playAgain = getPlayAgain(); // Ask user if they want to play again
	}

    return 0;
}

// Asks user for the next game's options, such as
// number of players, their names, if they are
// a human player or AI, etc.
GameOptions getGameOptions()
{
	// Prepare GameOptions struct
	GameOptions newOpt;

	// Loop until user inputs a valid player count (2-4)
	while (true)
	{
		system("CLS");

		cout << "\033[1;34m Please enter the number of players (2-4): \033[0m\n";

		string ans;
		cin >> ans;

		try
		{
			int num = stoi(ans, nullptr, 10);

			if (num < 2 || num > 4)
			{
				cout << "\033[1;31m Error: Enter a number between 2 and 4. \033[0m" << endl << endl;
			}
			else
			{
				newOpt.numPlayers = num;
				numofplayerstotal=num;
				break;
			}
		}
		catch (exception ex)
		{
			cout << "\033[1;31m Error: Invalid input format. \033[0m" << endl << endl;
		}

		system("pause");
	}

	// Loop through each player and ask for their name,
	// and if they are a human or AI player.
	for (int i = 0; i < newOpt.numPlayers; i++)
	{
		system("CLS");

		string name = "";

		cout << "\033[1;34m Please enter the name of Player \033[0m" << (i + 1) << ": " << flush;

		while (name.length() == 0)
		{
			std::getline(std::cin, name);
		}

		newOpt.playerNames[i] = name;

		// Get AI status
		while (true)
		{
			system("CLS");
			cout << "\033[1;34m Is \033[0m" << name << "\033[1;34m a human player (y or n)? \033[0m";
			
			string ans = "";
			cin >> ans;

			if (ans == "y" || ans == "Y")
			{
				newOpt.playerIsAI[i] = false;
				break;
			}
			else if (ans == "n" || ans == "N")
			{
				newOpt.playerIsAI[i] = true;
				break;
			}
			else
			{
				cout << "\033[1;31m Error: Invalid input. \033[0m" << endl << endl;
				system("pause");
			}
		}
	}

	int startingHand = 7;

	// Loop until user inputs valid starting hand size (6-10 dominoes)
	

	newOpt.piecesPerPlayer = startingHand;

	// Return selected game options struct
	return newOpt;
}

// Returns true if user wants to play again, otherwise false.
bool getPlayAgain()
{

	while (true)
	{
		string ans;
		cout<<endl<<"\033[1;34m Would you like to play again (Y OR N)? \033[0m"<<endl;
		cin>>ans;

		if(ans.length() > 0){
			if(ans=="y" || ans=="Y")
				return true;
			else if(ans=="n" || ans=="N")
				return false;
		}
		cout << endl << "\033[1;31m Invalid Input. \033[0m" << endl;
		}
	
}
