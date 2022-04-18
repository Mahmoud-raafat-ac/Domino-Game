
#ifndef showcards
#define showcards
/*
           included libraries
*/
#include "random.h"

/*
                      DEFINITIONS
*/

int usedplayercards[MAX_CARDS] = { 0 };
int usedcomputercards[MAX_CARDS] = { 0 };
int useddeckcards[MAX_CARDSDECK] = { 0 };

// Function to print all unused cards of player
void printplayercards()
{
	cout << "PLAYER CARDS :" << endl;
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if(usedplayercards[i]==0)
		cout << playercards[i]->num1 <<" | " << playercards[i]->num2 << endl;
	}
}
// Function to print all unused cards of computer
void printcomputercards()
{
	cout << "COMPUTER CARDS :" << endl;
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if (usedcomputercards[i] == 0)
		cout << computercards[i]->num1 << " | " << computercards[i]->num2 << endl;
	}

}
// Function to print all unused cards of deck
void printdeckcards()
{
	cout << "DECK CARDS :" << endl;
	for (int i = 0; i < MAX_CARDSDECK; i++)
	{
		if (useddeckcards[i] == 0)
		cout << deckcards[i]->num1 << " | " << deckcards[i]->num2 << endl;
	}
}


#endif

