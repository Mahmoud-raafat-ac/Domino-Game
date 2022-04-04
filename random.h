
/*
           included libraries
*/
#include "carddefinitions.h"
#include <time.h>

/*
                      DEFINITIONS
*/
#define MAX_CARDS 7 // maximum number of cards for each player
#define MAX_CARDSDECK 14 // Number of remaining cards on deck
card* playercards[MAX_CARDS];// ADDRESSES Of player cards
card* computercards[MAX_CARDS];// ADDRESSES Of computer cards
card* deckcards[MAX_CARDSDECK];// ADDRESSES Of deck cards

//extern card* CARDS_ADDR[MAX_SIZE];// Addresses of all cards in this array

/* 
Function to assign card for player, computerand deck randomly
using rand() funtion
it assign cards for player at first by checking if the random number card is already used or not
and if used we ask for another random number 
untill condition is true and assign that number to player 
then increment player counter untill he reaches 7 as he only draws 7 cards
return condition to false to start loop again
and add the usedcards to usedcards array to avoid using same card again
and same algorithim is used for computer and deck but deck takes 14 cards
*/
void randcards()
{
	srand(time(0));// random function time depends on exceution time
	int counterplayer = 0,flagplayer=FALSE; 
	int countercomputer = 0, flagcomputer = FALSE;
	int counterdeck = 0, flagdeck = FALSE;
	int usedcards[MAX_SIZE] = {0};
	int randnumber;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (counterplayer != MAX_CARDS)
		{
			while (flagplayer == FALSE)
			{
				randnumber = rand() % 28;
				
					if (usedcards[randnumber] == 0)
					{
						flagplayer = TRUE;
					}
				
			}
			playercards[counterplayer] = CARDS_ADDR[randnumber];
			counterplayer++;
			usedcards[randnumber]=1;
			flagplayer = FALSE;
		}
		else if (countercomputer != MAX_CARDS)
		{
			while (flagcomputer == FALSE)
			{
				randnumber = rand() % 28;

				if (usedcards[randnumber] == 0)
				{
					flagcomputer = TRUE;
				}
			}
			computercards[countercomputer] = CARDS_ADDR[randnumber];
			countercomputer++;
			usedcards[randnumber]=1;
			flagcomputer = FALSE;
		}
		else if (counterdeck != MAX_CARDSDECK)
		{
			while (flagdeck == FALSE)
			{
				randnumber = rand() % 28;

				if (usedcards[randnumber] == 0)
				{
					flagdeck = TRUE;
				}
			}
			deckcards[counterdeck] = CARDS_ADDR[randnumber];
			counterdeck++;
			usedcards[randnumber]=1;
			flagdeck = FALSE;
		}
	}
}
/*
Function to print cards after being randomised
it uses same algorithim of random function by passing at player then computer then deck
using cout function only to print all cards
*/
void printrandcards()
{
	int counterplayer = 0;
	int countercomputer = 0;
	int counterdeck = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		
		if (counterplayer != MAX_CARDS)
		{
			cout << "playercard " << counterplayer << " : " << endl;
			cout << playercards[counterplayer]->num1 << " | " << playercards[counterplayer]->num2 << endl;
			counterplayer++;
		}
		else if (countercomputer != MAX_CARDS)
		{
			cout << "computercard " << countercomputer << " : " << endl;
			cout << computercards[countercomputer]->num1 << " | " << computercards[countercomputer]->num2 << endl;
			countercomputer++;
		}
		else if (counterdeck != MAX_CARDSDECK)
		{
			cout << "deckcard " << counterdeck << " : " << endl;
			cout << deckcards[counterdeck]->num1 << " | " << deckcards[counterdeck]->num2 << endl;
			counterdeck++;
		}

	}
}


