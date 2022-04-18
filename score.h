#ifndef score
#define score
#include "playanddraw.h"

int scoreplayer(struct player player1)
{ 
    int sum=0;
    for(int i=0;i<maxplayercompcards;i++)
    {
        if(playedcardsgame[i]==0)
        {
            continue;
        }
    sum=(player1.playercard[i]->num1) +(player1.playercard[i]->num2);
    }
    return sum;
}

int scorecomputer(struct computer computer1)
{ 
    int sum=0;
    for(int i=0;i<maxplayercompcards;i++)
    {
        if(computercardsgame[i]==0)
        {
            continue;
        }
    sum=(computer1.computercard[i]->num1) +(computer1.computercard[i]->num2);
    }
    return sum;
}
#endif