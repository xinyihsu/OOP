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

/**
 * Intent: if the word is valid
 * Pre: the grid array, the words read in file, the cjharacter use, the index
 * Post: boolean
 */
bool validWord(char grid[GRID_SIZE][GRID_SIZE], string word, int appear[4][4], int index)
{
	//if the word end
	if (index >= word.length() - 1) {
		return true;
	}

	//run the loop until the end
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			//find where is the character in front of it 
			if (grid[i][j] == word[0 + index] && appear[i][j] == 1) {
				//run the square
				for (int k = -1; k <= 1; k++) {
					for (int m = -1; m <= 1; m++) {
						//if the position is valid
						if (i + k < GRID_SIZE && i + k >= 0 && j + m < GRID_SIZE && j + m >= 0 && grid[i + k][j + m] == word[1 + index] && appear[i + k][j + m] == 0) {
							appear[i + k][j + m] = 1;
							index++;

							//if the next letter can be find
							if (validWord(grid, word, appear, index)) return true;

							appear[i + k][j + m] = 0;
							index--;
						}
					}
				}
			}
		}
	}
	return false;
}

void main()
{
	char grid[GRID_SIZE][GRID_SIZE];
	ifstream inputFile;
	vector<string> words;
	string fileWords;
	inputFile.open("words.txt");

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

				//end if reading EOF
				if (cin.eof()) {
					return;
				}
			}
		}

		//judge all the words
		for (int i = 0; i < words.size(); i++) {
			int appear[GRID_SIZE][GRID_SIZE] = {};
			//run the grid
			for (int j = 0; j < GRID_SIZE; j++) {
				for (int k = 0; k < GRID_SIZE; k++) {
					//find the first character
					if (grid[j][k] == words[i][0]) {
						appear[j][k] = 1;

						//find the valid words
						if (words[i].length() >= 3 && validWord(grid, words[i], appear, 0)) {
							cout << words[i] << endl;
							break;
						}
					}
				}
			}
		}
	}
}

