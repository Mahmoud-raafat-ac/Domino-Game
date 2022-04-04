
#ifndef showcards
#define showcards
/*
           included libraries
*/
#include "random.h"

/*
                      DEFINITIONS
*/
extern card* playercards[MAX_CARDS];// ADDRESSES Of player cards
extern card* computercards[MAX_CARDS];// ADDRESSES Of computer cards
extern card* deckcards[MAX_CARDSDECK];// ADDRESSES Of deck cards
int usedplayercards[MAX_CARDS] = { 0 };
int usedcomputercards[MAX_CARDS] = { 0 };
int useddeckcards[MAX_CARDSDECK] = { 0 };
/*
                  FUNCTIONS Prototypes
*/
void printplayercards();
void printcomputercards();
void printdeckcards();
#endif