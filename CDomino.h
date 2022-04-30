/* members team :
(1) Name :  Mahmoud raafat mohamed shaaban               ,    Sec : 4                , B.N : 1
(2) Name :  Ahmed mohamed mohamed ibrahiem               ,    Sec : 1                , B.N : 22 
(3) Name :  Mohamed hisham hammad abdel rahman           ,    Sec : 3                , B.N : 53
(4) Name : Mohamed yahya abdel fattah                    ,    Sec : 3                , B,N : 54 */

/* =============================================
* File: CDomino.h
* Description: Header file for CDomino class.
*     Represents a single domino piece. Includes
*     various helper methods. Conditional == and
*     != operators have been overridden to ensure
*     two domino pieces that have been reversed
*     are still considered equal. Ex: [5|6]==[6|5]
* ==============================================
*/

#pragma once

class CDomino
{
private:
	int left;  // # left side dots
	int right; // # right side dots
public:
	CDomino();
	CDomino(int left, int right);
	CDomino(const CDomino &other);
	~CDomino();
	int getLeft();
	int getRight();
	bool isDouble();
	int hasSide(int dots);
	void swap();
	void print();
    int sum();
	bool operator==(const CDomino &other) const;
	bool operator!=(const CDomino &other) const;
};

/* =========================================
*  End of File
*  =========================================
*/