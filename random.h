#ifndef random
#define random
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
/*
                  FUNCTIONS Prototypes
*/
// Function to assign cards for player,computer and deck randomly
void randcards();
// Function to print cards after being randomed
void printrandcards();

#include "random.cpp"

#endif