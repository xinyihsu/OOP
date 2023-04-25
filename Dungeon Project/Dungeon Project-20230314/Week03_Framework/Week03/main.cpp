/************************************************************************
File:   main.cpp

Author:	Áé½å¼s¡Aea5878158@gmail.com
Creat Date: 2023-03-17

Editor:	®}ªY»ö¡AB11130008@mail.ntust.edu.tw
		²øÀR¶²¡AB11115037@mail.ntust.edu.tw
Update date: 2023-03-17

Comment:
		Draw and print out the canvas.

************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

void drawBoard(); //Function to draw board
void makeBoard(); //Function to make board
void modifyBoard();	//Function to modify board

const int DUNGEN_ROW = 10, DUNGEN_COL = 20;
char dungenMap[DUNGEN_ROW][DUNGEN_COL];

int main(int argc, char** argv)
{
	makeBoard();
	drawBoard();
	modifyBoard();
	drawBoard();
}

void drawBoard()
//==================================================================
{
	// Draw out the whole board
	/************************************************************************/
	/*Please implement your code here*/
	//output dungenMap
	for (int i = 0; i < DUNGEN_ROW; i++)
	{
		for (int j = 0; j < DUNGEN_COL; j++)
		{
			cout << dungenMap[i][j];
		}
		cout << endl;
	}
	cout << endl;
	/************************************************************************/
}

void makeBoard()
//==================================================================
{
	// Enter symbol for wall and blank then create array
	/************************************************************************/
	/*Please implement your code here*/
	char symbol[2]; //symbol of wall and blank
	cout << "Enter symbol for wall: ";
	cin >> symbol[0];
	cout << "Enter symbol for blank: ";
	cin >> symbol[1];

	//initialize the map
	for (int i = 0; i < DUNGEN_ROW; i++)
	{
		for (int j = 0; j < DUNGEN_COL; j++)
		{
			dungenMap[i][j] = symbol[1];
		}
	}

	//modify the wall
	for (int i = 0; i < DUNGEN_COL; i++)
	{
		dungenMap[0][i] = symbol[0];
		dungenMap[DUNGEN_ROW - 1][i] = symbol[0];
	}
	for (int i = 0; i < DUNGEN_ROW; i++)
	{
		dungenMap[i][0] = symbol[0];
		dungenMap[i][DUNGEN_COL - 1] = symbol[0];
	}
	
	/************************************************************************/
}

void modifyBoard()
//==================================================================
{
	// Function for modifying board given position and char to change
	/************************************************************************/
	/*Please implement your code here*/
	char symbol; //the symbol of modifying position
	int posXY[2]; //the modifying position of X and Y
	cout << "Enter symbol for modifying position: ";
	cin >> symbol;
	cout << "Enter X of modifying position: ";
	cin >> posXY[0];
	cout << "Enter Y of modifying position: ";
	cin >> posXY[1];

	//judge if valid and modify the map
	if ((posXY[0] > 0 && posXY[0] < DUNGEN_COL - 1) || (posXY[1] > 0 && posXY[1] < DUNGEN_ROW - 1))
	{
		dungenMap[posXY[0]][posXY[1]] = symbol;
	}
	else
	{
		cout << "Invalid input" << endl;
	}
	/************************************************************************/
}