
#ifndef carddefinitions
#define carddefinitions

/*
           included libraries
*/

#include <iostream>
using namespace std;

/*
                      DEFINITIONS
*/
#define MAX_SIZE 28 // Number of all cards
#define TRUE 1
#define FALSE 0

// card definition which consists of 2 numbers
struct card
{
	int num1, num2;

};
card* CARDS_ADDR[MAX_SIZE];

/*
                  FUNCTIONS Prototypes
*/

// Function to initialize values of cards
void cardinit();
// function to print cards and display them
void printallcards();


#include "carddefinitions.cpp"
#endif