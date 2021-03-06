/* members team :
(1) Name :  Mahmoud raafat mohamed shaaban               ,    Sec : 4                , B.N : 1
(2) Name :  Ahmed mohamed mohamed ibrahiem               ,    Sec : 1                , B.N : 22 
(3) Name :  Mohamed hisham hammad abdel rahman           ,    Sec : 3                , B.N : 53
(4) Name : Mohamed yahya abdel fattah                    ,    Sec : 3                , B,N : 54 */

/* =============================================
* File: CDominoCollection.h
* Description: Header file for CDominoCollection
*     class. Used as a generic collection to store
*     domino pieces for the table, Boneyard pile,
*     and player hands. Implemented as a doubly
*     linked list.
* ==============================================
*/

#pragma once

#include "CDomino.h"

// Max number of domino pieces displayed as table/game board before hiding middle
#define MAX_DOMINO_DISPLAY 10

// Represents a single node in the linked list
struct DominoListNode
{
	DominoListNode* prevPtr;
	DominoListNode* nextPtr;
	CDomino data;

	DominoListNode(const CDomino &domino);
};

class CDominoCollection
{
private:
	DominoListNode* rootNodePtr; // Pointer to root node in linked list
	int size;                    // Number of nodes in linked list

	DominoListNode* createNode(const CDomino &domino);
	bool remove(DominoListNode* removeNode);
	int randInt(int low, int hi);
public:
	CDominoCollection();
	~CDominoCollection();

	int getSize();
	int find(const CDomino &domino);
	int findWithDots(int dots);
	bool isEmpty();
	bool contains(const CDomino &domino);
	bool getFirst(CDomino &out);
	bool getLast(CDomino &out);
	bool getPiece(int index, CDomino &out);
	bool addToEnd(const CDomino &domino);
	bool addToStart(const CDomino &domino);
	bool remove(const CDomino &domino);
	bool remove(int index);
	void generateAllPieces();
	void shuffle();
	void clear();
	void printAsNumberedList();
	void printAsChainedList();
	int sumall();
	int greatestcardinhand();
};

/* =========================================
*  End of File
*  =========================================
*/