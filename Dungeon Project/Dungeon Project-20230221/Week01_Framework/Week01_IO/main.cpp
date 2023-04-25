/************************************************************************
File:   main.cpp
		
Author: 
		®}ªY»ö¡AB11130008@mail.ntust.edu.tw
		²øÀR¶²¡AB11115037@mail.ntust.edu.tw
Date:
		February 22, 2023
Last Update:
		February 22, 2023
Comment:
		Output W,A,S,D after input, ESC to stop process.

************************************************************************/
#include <iostream>	// For print out information
#include <conio.h>	// For getch() function
using namespace std;

// Define inputs and its index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5, //ASCII code 27
	INVALID = 6,
};

// Detect state of input
void keyUpdate(bool key[]);

int main()
{
	//Initialize state of key
	bool gKeyState[ValidInput::INVALID];

	// Obtain and update the input using a loop
	/************************************************************************/
	/*Please implement your code here*/
	keyUpdate(gKeyState);
	
	while (gKeyState[ValidInput::EESC] != true)  //if the input is ESC, end the program
	{
		if (gKeyState[ValidInput::EW] == true)
			cout << "Key W is impressed." << endl;	
		else if (gKeyState[ValidInput::ES] == true)
			cout << "Key S is impressed." << endl;
		else if (gKeyState[ValidInput::EA] == true)
			cout << "Key A is impressed." << endl;
		else if (gKeyState[ValidInput::ED] == true)
			cout << "Key D is impressed." << endl;
		keyUpdate(gKeyState);
	}

	cout << "Key ESC is impressed. End program.";
	/************************************************************************/
}

//******************************************************************
//
// * °»´ú¿é¤Jª¬ºA
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++)
	{
		key[i] = false;
	}
	char input = _getch();

	// Implement a switch for output calls
	/************************************************************************/
	/*Please implement your code here*/

	//distinguish the input character, then change the bool
	switch (input)
	{
		case 'w':
			key[0] = true;
			break;
		case 's':
			key[1] = true;
			break;
		case 'a':
			key[2] = true;
			break;
		case 'd':
			key[3] = true;
			break;
		case 27:
			key[5] = true;
			break;
	}
	/************************************************************************/
}