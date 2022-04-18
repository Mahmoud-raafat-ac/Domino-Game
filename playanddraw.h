#ifndef playanddraw
#define playanddraw
#include "board.h"

int playedcardsgame[maxplayercompcards]={0};
int computercardsgame[maxplayercompcards]={0};
int deckcardsgame[MAX_CARDSDECK]={0};
int drawcomputer(struct computer computer1);
int drawplayer(struct player player1);

void firstplay(struct player player1,struct computer computer1)
{
  int maxnumberplayer=0,tempplayer=0;
  int maxnumbercomputer=0,tempcomputer=0;
  int indexmaxplayer=0,indexmaxcomputer=0;
    for(int i=0;i<MAX_CARDS;i++)
    {
      if(player1.playercard[i]->num1==player1.playercard[i]->num2)
      {
        tempplayer=player1.playercard[i]->num1;

      }
      if(tempplayer>maxnumberplayer)
 {
          maxnumberplayer=tempplayer;
  indexmaxplayer=i;
    }
}
     for(int i=0;i<MAX_CARDS;i++)
    {
      if(computer1.computercard[i]->num1==computer1.computercard[i]->num2)
      {
        tempcomputer=computer1.computercard[i]->num1;

      }
      if(tempcomputer>maxnumbercomputer)
     {
          maxnumbercomputer=tempcomputer;
    indexmaxcomputer=i;
    }
    }
    if(maxnumbercomputer>maxnumberplayer)
    {
        cout<<"COMPUTER STARTS"<<endl;
        push(computer1.computercard[indexmaxcomputer]->num1,computer1.computercard[indexmaxcomputer]->num2,0);
       computercardsgame[indexmaxcomputer]=1;
    }
    else if(maxnumbercomputer<maxnumberplayer)
    {
        cout<<"player starts"<<endl;
push(player1.playercard[indexmaxplayer]->num1,player1.playercard[indexmaxplayer]->num2,0);
       playedcardsgame[indexmaxplayer]=1;
    }
    else 
    {
        cout<<"player chooses a card to play"<<endl;
    }
   

}


void playplayer(struct player player1)
{
int indexplayer;
int flaggotcard=1;
int indexdrawcard;
cout<<"choose a card to play"<<endl;
int left=0;
int right=0;
for(int i=0;i<maxplayercompcards;i++)
{
if((left==player1.playercard[maxplayercompcards]->num1)||(left==player1.playercard[maxplayercompcards]->num2)||(right==player1.playercard[maxplayercompcards]->num1)||(right==player1.playercard[maxplayercompcards]->num2))
{
    break;
}
flaggotcard=0;
}
while(flaggotcard==0)
{
   indexdrawcard= drawplayer(player1);
   if(indexdrawcard!=-1)
 {
      if((left==player1.playercard[indexdrawcard]->num1)||(left==player1.playercard[indexdrawcard]->num2)||(right==player1.playercard[indexdrawcard]->num1)||(right==player1.playercard[indexdrawcard]->num2))
{
    flaggotcard=1;
}
 }
 else 
 {
 cout<<"player skipped: computer turn"<<endl;
 return;
 }
}
// hena hui lama yedos 3ala war2a a5od index beta3ha indexplayer=
if(left==player1.playercard[indexplayer]->num1)
{
   append(player1.playercard[indexplayer]->num1,player1.playercard[indexplayer]->num2,1);
}
else 
if(left==player1.playercard[indexplayer]->num2)
{
append(player1.playercard[indexplayer]->num1,player1.playercard[indexplayer]->num2,0);
}
else 
if(right==player1.playercard[indexplayer]->num1)
{
   push(player1.playercard[indexplayer]->num1,player1.playercard[indexplayer]->num2,0);
}
else 
if(right==player1.playercard[indexplayer]->num2)
{
append(player1.playercard[indexplayer]->num1,player1.playercard[indexplayer]->num2,1);
}
playedcardsgame[indexplayer]=1;
}

void playcomputer(struct computer computer1)
{
int indexcomputer;
int flaggotcard=1;
int indexdrawcard;
int left=0;
int right=0;
for(int i=0;i<maxplayercompcards;i++)
{
if((left==computer1.computercard[maxplayercompcards]->num1)||(left==computer1.computercard[maxplayercompcards]->num2)||(right==computer1.computercard[maxplayercompcards]->num1)||(right==computer1.computercard[maxplayercompcards]->num2))
{
    break;
}
flaggotcard=0;
}
while(flaggotcard==0)
{
   indexdrawcard= drawcomputer(computer1);
   if(indexdrawcard!=-1)
 {
      if((left==computer1.computercard[indexdrawcard]->num1)||(left==computer1.computercard[indexdrawcard]->num2)||(right==computer1.computercard[indexdrawcard]->num1)||(right==computer1.computercard[indexdrawcard]->num2))
{
    flaggotcard=1;
}
 }
 else 
 {
 cout<<"computer skipped: player turn"<<endl;
 return;
 }
}
// hena Gui lama yedos 3ala war2a a5od index beta3ha indexplayer=
if(left==computer1.computercard[indexcomputer]->num1)
{
   append(computer1.computercard[indexcomputer]->num1,computer1.computercard[indexcomputer]->num2,1);
}
else 
if(left==computer1.computercard[indexcomputer]->num2)
{
append(computer1.computercard[indexcomputer]->num1,computer1.computercard[indexcomputer]->num2,0);
}
else 
if(right==computer1.computercard[indexcomputer]->num1)
{
   push(computer1.computercard[indexcomputer]->num1,computer1.computercard[indexcomputer]->num2,0);
}
else 
if(right==computer1.computercard[indexcomputer]->num2)
{
append(computer1.computercard[indexcomputer]->num1,computer1.computercard[indexcomputer]->num2,1);
}
computercardsgame[indexcomputer]=1;
}
int drawplayer(struct player player1)
{
for(int i=0;i<MAX_CARDSDECK;i++)
{
    if(deckcardsgame[i]==0)
    {
        player1.playercard[i+7]=deckcards[i];
        deckcardsgame[i]=1;
        return i+7;
    }
}
return -1;
}

int drawcomputer(struct computer computer1)
{
for(int i=0;i<MAX_CARDSDECK;i++)
{
    if(deckcardsgame[i]==0)
    {
          computer1.computercard[i+7]=deckcards[i];
        deckcardsgame[i]=1;
        return i+7;
    }
}
return -1;
}

#endif 