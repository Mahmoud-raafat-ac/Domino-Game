#include "showcards.h"

extern card* playercards[MAX_CARDS];// ADDRESSES Of player cards
extern card* computercards[MAX_CARDS];// ADDRESSES Of computer cards
extern card* deckcards[MAX_CARDSDECK];// ADDRESSES Of deck cards
void printplayercards()
{
	cout << "PLAYER CARDS :" << endl;
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if(usedplayercards[i]!=0)
		cout << playercards[i]->num1 <<" | " << playercards[i]->num2 << endl;
	}
}
void printcomputercards()
{
	cout << "COMPUTER CARDS :" << endl;
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if (usedcomputercards[i] != 0)
		cout << computercards[i]->num1 << " | " << computercards[i]->num2 << endl;
	}

}

void printdeckcards()
{
	cout << "DECK CARDS :" << endl;
	for (int i = 0; i < MAX_CARDSDECK; i++)
	{
		if (useddeckcards[i] != 0)
		cout << deckcards[i]->num1 << " | " << deckcards[i]->num2 << endl;
	}
}


int main()
{

cardinit();
printallcards();
 randcards();
 printrandcards();
	return 0;
}