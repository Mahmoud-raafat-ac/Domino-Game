
#include "carddefinitions.h"
/*
* Array to store addresses of all cards
  ARR[0]=6|6
  ARR[1]=6|5
  ARR[2]=6|4
  ARR[3]=6|3
  ARR[4]=6|2
  ARR[5]=6|1
  ARR[6]=6|0
  ARR[7]=5|5
  ARR[8]=5|4
  ARR[9]=5|3
  ARR[10]=5|2
  ARR[11]=5|1
  ARR[12]=5|0
  ARR[13]=4|4
  ARR[14]=4|3
  ARR[15]=4|2
  ARR[16]=4|1
  ARR[17]=4|0
  ARR[18]=3|3
  ARR[19]=3|2
  ARR[20]=3|1
  ARR[21]=3|0
   ARR[22]=2|1
   ARR[23]=2|0
    ARR[24]=2|0
     ARR[25]=1|1
    ARR[26]=1|0
    ARR[27]=0|0
*/
card* CARDS_ADDR[MAX_SIZE]; 
//Function to initialize card and store their addresses in array of maximum size 28 which is whole number of cards
void cardinit()
{
	int counter = 0;
	for (int i = 7; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
		{ 
		
			CARDS_ADDR[counter]=new card();
			CARDS_ADDR[counter]->num1 = i-1;
			CARDS_ADDR[counter]->num2 = j-1;
			counter++;
		}

	}
}
// function to print all cards
void printallcards()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << CARDS_ADDR[i]->num1 << "|" << CARDS_ADDR[i]->num2 << endl;
		
	}
}


