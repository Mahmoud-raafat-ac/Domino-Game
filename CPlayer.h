/* members team :
(1) Name :  Mahmoud raafat mohamed shaaban               ,    Sec : 4                , B.N : 1
(2) Name :  Ahmed mohamed mohamed ibrahiem               ,    Sec : 1                , B.N : 22 
(3) Name :  Mohamed hisham hammad abdel rahman           ,    Sec : 3                , B.N : 53
(4) Name : Mohamed yahya abdel fattah                    ,    Sec : 3                , B,N : 54 
=============================================
 File: CPlayer.h
 Description: Header file for the CPlayer class.
 Stores player information and the dominoes
 in their hand. Manages logic for playing
 and drawing pieces. Manages player menu and
 AI logic.
==============================================
*/

#pragma once

#include <string>
#include "CDominoCollection.h"

class CPlayer
{
private:
	std::string name; // Name of player
	bool isAI;        // True if player is AI controlled.
	int stat_PiecesPlayed; // Track number of pieces player has played
	int stat_PiecesDrawn;  // Track number of pieces player has drawn
	CDominoCollection hand;

	bool processAITurn(CDominoCollection &table, CDominoCollection &pile);
	bool showPlayerMenu(CDominoCollection &table, CDominoCollection &pile);
	bool showPlayPieceMenu(CDominoCollection &table);
	bool playPiece(CDominoCollection &table, CDomino &domino, bool askSide);
	bool canPlayPiece(CDominoCollection &table);
	int findPlayablePiece(CDominoCollection &table);
	bool drawPiece(CDominoCollection &pile, CDomino &drawnDomino);
public:
	CPlayer();
	CPlayer(std::string name, bool isAI);
	~CPlayer();
	std::string getName();
	int getPiecesPlayed();
	int getPiecesDrawn();
	int getPiecesInHand();
	int fillHand(CDominoCollection &pile);
	bool isHandEmpty();
	bool processTurn(CDominoCollection &table, CDominoCollection &pile);
	void printHand();
	int sumhand();
	int maxcard();

};


/* =========================================
*  End of File
*  =========================================
*/