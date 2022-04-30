/* members team :
(1) Name :  Mahmoud raafat mohamed shaaban               ,    Sec : 4                , B.N : 1
(2) Name :  Ahmed mohamed mohamed ibrahiem               ,    Sec : 1                , B.N : 22 
(3) Name :  Mohamed hisham hammad abdel rahman           ,    Sec : 3                , B.N : 53
(4) Name : Mohamed yahya abdel fattah                    ,    Sec : 3                , B,N : 54
*/

#include<iostream>
#include<string>
#include"CDominoesGame.h"
using namespace std;

// Forward function declarations & global variables
GameOptions getGameOptions();
GameOptions getGameOptionsforcontinuegame();
int getPlayAgain();
int getplayagainend();
int numofplayerstotal=0;
string playernames[4];
bool playerisai[4];
int score[4]={0};
int main()
{ 
	system("color");
    CDominoesGame domGame;
	int playAgain = 1; 
	int endgame=0;
   	cout << "\033[1;34m-----------------------------\033[0m" << endl;
	cout << "\033[1;34m|  D O M I N O E - G A M E  |\033[0m" << endl;
	cout << "\033[1;34m-----------------------------\033[0m" << endl << endl;
	cout << "\033[1;34mOur goal is for you to have fun. \033[0m" << endl << endl; 
    system("pause");

    // Main game loop
	while (playAgain)
	{
		
		switch(playAgain)
	   {
		case 1:
		{
			GameOptions curRoundOpt = getGameOptions(); // Get player count and player names for next round 
			domGame.newGame(curRoundOpt); // Set up new game state
		break;
	   }
	   case 2:
	   {
       GameOptions curRoundOptcontinue = getGameOptionsforcontinuegame(); // Get player count and player names for next round
		domGame.continuegame(curRoundOptcontinue);  // set up last game stats and continue on it
	   break;
	   }
	   }
		while (domGame.gameActive())  // Loop until game is over
		{
			domGame.processTurn();      // Process next player's turn
		}
	    domGame.showWinMessage();   // Display winner
	    endgame=domGame.checkendgame();
		if(endgame==0)
		playAgain = getPlayAgain(); // Ask user if they want to play again or continue or exit
		else
		 playAgain=getplayagainend(); //Ask user if they want to play again or exit
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
		playernames[i]=name;

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
				playerisai[i]=false;
				break;
			}
			else if (ans == "n" || ans == "N")
			{
				newOpt.playerIsAI[i] = true;
				playerisai[i]=true;
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
// Load old game options into new round status
GameOptions getGameOptionsforcontinuegame()
{
	// Prepare GameOptions struct
	GameOptions newOpt;

	// Loop until user inputs a valid player count (2-4)
	newOpt.numPlayers=numofplayerstotal;

	// Loop through each player and ask for their name,
	// and if they are a human or AI player.
	for (int i = 0; i < newOpt.numPlayers; i++)
	{
		newOpt.playerNames[i] = playernames[i];

		// Get AI status
		newOpt.playerIsAI[i]=playerisai[i];
	}
	int startingHand = 7;
	//  user inputs  starting hand size 7
	newOpt.piecesPerPlayer = startingHand;

	// Return selected game options struct
	return newOpt;
}
// Returns 1 if user wants to start a new game,
// 2 if you want to continue on last status and
// 0 if you want to exit
int getPlayAgain()
{

	while (true)
	{
		int ans;
		cout<<endl<<"\033[1;34m Choose an option: \033[0m"<<endl;
		cout<<"\033[1;34m 0: Exit game \033[0m"<<endl;
		cout<<"\033[1;34m 1: start a new round \033[0m"<<endl;
		cout<<"\033[1;34m 2: Continue game on last round stats till score > 101 \033[0m"<<endl;
		cin>>ans;

		if(ans==0)
		{
			return 0;
		}
		else if(ans==1)
		{
			return 1;
		}
		else if(ans==2)
		{
			return 2;
		}
		cout << endl << "\033[1;31m Invalid Input. \033[0m" << endl;
		}
	
}
// Returns true if user wants to play again, otherwise false.
int getplayagainend()
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
