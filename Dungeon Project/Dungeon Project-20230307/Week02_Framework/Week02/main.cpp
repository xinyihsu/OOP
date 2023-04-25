/************************************************************************
File:   main.cpp

Author:
		®}ªY»ö¡AB11130008@mail.ntust.edu.tw
		²øÀR¶²¡AB11115037@mail.ntust.edu.tw
Comment:
		Output character position after W,A,S,D input.
		Output invalid if destination out of boundary.
		ESC to stop process.

************************************************************************/
#include <iostream>	// For print out information
#include <conio.h>	// For getch() function
using namespace std;

bool tryMove(int deltaX, int deltaY);
bool checkValidDst(int x, int y);

int posX = 0, posY = 0; // global param to keep the character position
const int DUNGEN_SIZE = 5; // For each dimension, -DUNGEN_SIZE < pos < DUNGEN_SIZE

int main() {
	// Obtain and update the input using a loop
	while (true) {
		char input = _getch();
		/************************************************************************/
		/*Please implement your code here*/
		if (input == 27) // if the input is ESC, end the program
		{
			break;
		}

		//As W,A,S,D input, call tryMove function.
		bool moveSuccessful = true;
		switch (input)
		{
			case 'W':
			case 'w':
				moveSuccessful = tryMove(0, 1);
				break;
			case 'S':
			case 's':
				moveSuccessful = tryMove(0, -1);
				break;
			case 'A':
			case 'a':
				moveSuccessful = tryMove(-1, 0);
				break;
			case 'D':
			case 'd':
				moveSuccessful = tryMove(1, 0);
				break;
			default:
				continue;
		}

		if (moveSuccessful == true) //if the position is valid.
		{
			cout << "Character position: (" << posX << "," << posY << ")" << endl;
		}
		else
		{
			cout << "Failed to move" << endl;
			cout << "Character position: (" << posX << "," << posY << ")" << endl;
		}
		
		/************************************************************************/
	}
}

//******************************************************************
//
// * Move character with input delta, return true if successful otherwise false
//==================================================================
bool tryMove(int deltaX, int deltaY) {
	/************************************************************************/
	/*Please implement your code here*/
	posX += deltaX;
	posY += deltaY;
	return checkValidDst(posX, posY);
	/************************************************************************/
}
//******************************************************************
//
// * Check if given position is a valid destination, return true if valid otherwise false
//==================================================================
bool checkValidDst(int x, int y) {
	/************************************************************************/
	/*Please implement your code here*/
	//Judge if the destination is valid. 
	if (x >= DUNGEN_SIZE)
	{
		posX--;
		return false;
	}
	else if (x <= -DUNGEN_SIZE)
	{
		posX++;
		return false;
	}
	else if (y >= DUNGEN_SIZE)
	{
		posY--;
		return false;
	}
	else if (y <= -DUNGEN_SIZE)
	{
		posY++;
		return false;
	}
	
	return true;
	/************************************************************************/
}
