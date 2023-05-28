/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-14
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-15
 * Description: Word game is a popular puzzle game that involves finding words from a grid of randomly generated letters.
 *				Words must be at least three letters long and formed from neighboring letters.
 *				Letters are not allowed to be used more than once in one word, and it is valid to move diagonally.
 *************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#define GRID_SIZE 4
using namespace std;

//intent:if the word can be made from the grid
//pre:the grid this word array of appear and which letter to check
//post:bool
/**
 * Intent: if the word is valid
 * Pre:
 * Post: boolean
 */
bool validWord(char grid[GRID_SIZE][GRID_SIZE], string word, int appear[4][4], int times)
{
	//if the word only has one character
	if (times == word.length() - 1) {
		return true;
	}
	else {
		//run the loop until the end
		for (int i = 0; i < 16; i++) {
			//find where is the character in front of it 
			if (grid[i / 4][i % 4] == word[0 + times] && appear[i / 4][i % 4] == 1) {
				//run the loop of the square
				for (int k = -1; k <= 1; k++) {
					for (int m = -1; m <= 1; m++) {
						//if it haven't appear and the position is valid
						if (i / 4 + k < 4 && i / 4 + k >= 0 && i % 4 + m < 4 && i % 4 + m >= 0
							&& grid[i / 4 + k][i % 4 + m] == word[1 + times] && appear[i / 4 + k][i % 4 + m] == 0) {
							appear[i / 4 + k][i % 4 + m] = 1;
							times++;

							//if the next letter can be find
							if (validWord(grid, word, appear, times)) {
								return true;
							}

							appear[i / 4 + k][i % 4 + m] = 0;
							times--;
						}
					}
				}
			}
		}
		return false;
	}
}

struct Position
{
	int x, y;
};

bool ifNeighbor(Position first, Position second)
{
	int dx = first.x - second.x;
	int dy = first.y - second.y;

	if (dx == 0 && abs(dy) == 1) return true;
	if (dy == 0 && abs(dx) == 1) return true;
	if (abs(dx) == 1 && abs(dy) == 1) return true;

	return false;
}

bool testIfValid(char grid[GRID_SIZE][GRID_SIZE], string word, Position temp, int index)
{
	index++;
	if (index >= sizeof(word)) return true;
	grid[temp.y][temp.x] = '0';

	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (grid[i][j] == word[index]) {
				Position next;
				next.x = j;
				next.y = i;
				if (ifNeighbor(temp, next)) {
					testIfValid(grid, word, next, index);
				}
			}
		}
	}
	return false;
}
//way two: ª½±µ§ä¤E®c®æ

void main()
{
	char grid[GRID_SIZE][GRID_SIZE];
	ifstream inputFile;
	vector<string> words;
	string fileWords;
	//words.clear();
	inputFile.open("words.txt");//, ios::in

	//test if the file open successful
	if (inputFile.is_open()) {
		//end if reading EOF
		while (inputFile >> fileWords) {
			words.push_back(fileWords);
		}
	}


	while (true) {
		//input the grid
		for (int i = 0; i < GRID_SIZE; i++) {
			for (int j = 0; j < GRID_SIZE; j++) {
				cin >> grid[i][j];

				//judge if reading EOF
				if (cin.eof()) {
					return;
				}
			}
		}

		//judge all the words
		for (int i = 0; i < words.size(); i++) {
			int appear[GRID_SIZE][GRID_SIZE] = {};
			char test[GRID_SIZE][GRID_SIZE] = {};
			for (int j = 0; j < GRID_SIZE; j++) {
				for (int k = 0; k < GRID_SIZE; k++) {
					test[j][k] = grid[j][k];
					if (grid[j][k] == words[i][0]) {
						Position temp;
						temp.x = k;
						temp.y = j;
						if (words[i].length() >= 3 && testIfValid(test, words[i], temp, 0)) {
							cout << words[i] << endl;
							break;
						}
					}

					/*if (grid[j][k] == words[i][0]) {
						appear[j][k] = 1;


						if (words[i].length() >= 3 && validWord(grid, words[i], appear, 0)) {
							cout << words[i] << endl;
							break;
						}
					}*/
				}
			}

		}
	}
}

