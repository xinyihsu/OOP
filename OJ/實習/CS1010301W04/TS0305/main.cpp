/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-20
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-22
 * Description: Draw square, isosceles right triangle and lines on the console
 ************************************************************************/
#include <iostream>
using namespace std;
#define MAX_VALUE 100

int main()
{
	int columns, rows; //the size of the drawing board
	int width; //the figure width
	int coordinates[2] = { 0 }; //the coordinates of the figure
	char board[MAX_VALUE][MAX_VALUE] = { '\0' }; //the drawing board
	string figure; //the type of the figure
	bool ifValid = true; //if the input is out of the range

	cin >> columns >> rows;

	//initialize the drawing board
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			board[i][j] = '*';
		}
	}

	//end if reading EOF
	while (cin >> figure) {
		ifValid = true;

		//the figure type is square
		if (figure == "S") {
			cin >> width;
			cin >> coordinates[0] >> coordinates[1];
			//judge if the figure is out of range
			for (int i = 0; i < width; i++) {
				for (int j = 0; j < width; j++) {
					if (coordinates[0] + j >= columns || coordinates[1] + i >= rows) {
						ifValid = false;
						break;
					}
				}
			}
			if (ifValid == true) {
				//for figures, fill with Upper X
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < width; j++) {
						board[coordinates[1] + i][coordinates[0] + j] = 'X';
					}
				}
			}
		}
		//the figure type is triangle
		else if (figure == "T") {
			string triangleFaces; //the triangle facing direction
			cin >> width;
			cin >> coordinates[0] >> coordinates[1];
			cin >> triangleFaces;

			//depending on the direction of the triangle, drawing different way
			if (triangleFaces == "LU") {
				//judge if the figure is out of range
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < width; j++) {
						if (coordinates[0] - j >= columns || coordinates[1] - i >= rows || coordinates[0] - j < 0 || coordinates[1] - i < 0) {
							ifValid = false;
							break;
						}
					}
				}
				//if the figure is valid
				if (ifValid == true) {
					//for figures, fill with Upper X
					for (int i = 0; i < width; i++) {
						for (int j = 0; j < width - i; j++) {
							board[coordinates[1] - i][coordinates[0] - j] = 'X';
						}
					}
				}
			}
			else if (triangleFaces == "LD") {
				//judge if the figure is out of range
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < width; j++) {
						if (coordinates[0] - j >= columns || coordinates[1] + i >= rows || coordinates[0] - j < 0 || coordinates[1] + i < 0) {
							ifValid = false;
							break;
						}
					}
				}
				//if the figure is valid
				if (ifValid == true) {
					//for figures, fill with Upper X
					for (int i = 0; i < width; i++) {
						for (int j = 0; j < width - i; j++) {
							board[coordinates[1] + i][coordinates[0] - j] = 'X';
						}
					}
				}
			}
			else if (triangleFaces == "RU") {
				//judge if the figure is out of range
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < width; j++) {
						if (coordinates[0] + j >= columns || coordinates[1] - i >= rows || coordinates[0] + j < 0 || coordinates[1] - i < 0) {
							ifValid = false;
							break;
						}
					}
				}
				//if the figure is valid
				if (ifValid == true) {
					//for figures, fill with Upper X
					for (int i = 0; i < width; i++) {
						for (int j = 0; j < width - i; j++) {
							board[coordinates[1] - i][coordinates[0] + j] = 'X';
						}
					}
				}
			}
			else if (triangleFaces == "RD") {
				//judge if the figure is out of range
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < width; j++) {
						if (coordinates[0] + j >= columns || coordinates[1] + i >= rows || coordinates[0] + j < 0 || coordinates[1] + i < 0) {
							ifValid = false;
							break;
						}
					}
				}
				//if the figure is valid
				if (ifValid == true) {
					//for figures, fill with Upper X
					for (int i = 0; i < width; i++) {
						for (int j = 0; j < width - i; j++) {
							board[coordinates[1] + i][coordinates[0] + j] = 'X';
						}
					}
				}
			}
		}
		//the figure type is line
		else if (figure == "L") {
			int coordinates2[2] = { 0 };
			cin >> coordinates[0] >> coordinates[1];
			cin >> coordinates2[0] >> coordinates2[1];

			//if it is out of range
			if (coordinates[0] >= columns || coordinates[1] >= rows || coordinates2[0] >= columns || coordinates2[1] >= rows) {
				ifValid = false;
			}
			else {
				//line leftup to rightdown
				if (coordinates2[0] > coordinates[0] && coordinates2[1] > coordinates[1]) {
					//for figures, fill with Upper X
					while (coordinates2[1] != coordinates[1]) {
						board[coordinates2[1]][coordinates2[0]] = 'X';
						coordinates2[0]--;
						coordinates2[1]--;
					}
					board[coordinates[1]][coordinates[0]] = 'X';
				}
				//line rightup to leftdown
				else if (coordinates2[0] > coordinates[0] && coordinates2[1] < coordinates[1]) {
					//for figures, fill with Upper X
					while (coordinates2[1] != coordinates[1]) {
						board[coordinates2[1]][coordinates2[0]] = 'X';
						coordinates2[0]--;
						coordinates2[1]++;
					}
					board[coordinates[1]][coordinates[0]] = 'X';
				}
				//straight line
				else {
					//for figures, fill with Upper X
					for (int i = coordinates[1]; i <= coordinates2[1]; i++) {
						for (int j = coordinates[0]; j <= coordinates2[0]; j++) {
							board[i][j] = 'X';
						}
					}
				}
			}
		}
		//exit the loop
		else if (figure == "EXIT") {
			break;
		}

		//if the input range is valid
		if (ifValid == true) {
			//output the drawing board
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					cout << board[i][j];
				}
				cout << endl;
			}
		}
		else {
			cout << "Out of range." << endl;
		}
		cout << endl;
	}


}