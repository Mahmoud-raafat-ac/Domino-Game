
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
/*
                  FUNCTIONS Prototypes
*/
void printplayercards();
void printcomputercards();
void printdeckcards();

#include "showcards.cpp"
#endif