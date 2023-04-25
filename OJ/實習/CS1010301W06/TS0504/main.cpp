/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-30
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-05
 * Description: Test if a 9*9 grid Sudoku is valid.
 ************************************************************************/
#include <iostream>
#include <string>
#define MAX_VALUE 9
using namespace std;

/**
 * Intent: test if the sudoku is follow the rules
 * Pre: the two dimentional array that store the sudoku
 * Post: return true or false
 */
bool testIfValid(int sudoku[MAX_VALUE][MAX_VALUE]);

int main()
{
	char eachLine[MAX_VALUE * 2 - 1]; //the string we get from each line
	int sudoku[MAX_VALUE][MAX_VALUE] = { '\0' }; //the array to store the sudoku 
	char* ptr; //store the string that is get from function strtok
	char* pTmp = NULL; //the remain string of function strtok

	//end if reading EOF
	while (cin >> eachLine) {
		//store each line as an integer array
		for (int i = 0; i < MAX_VALUE; i++) {
			int index = 0; //the index of array that we are going to store the integer

			//input each line besides the first time
			if (i != 0) {
				cin >> eachLine;
			}

			ptr = strtok_s(eachLine, ",", &pTmp); //the first time string token

			//using string token until the string end
			while (ptr != NULL)
			{
				sudoku[i][index] = atoi(ptr); //store the number into array
				index++;
				ptr = strtok_s(NULL, ",", &pTmp); //doing string token function
			}
		}

		//if the sudoku is valid return true, then return false
		if (testIfValid(sudoku)) {
			cout << "True" << endl;
		}
		else {
			cout << "False" << endl;
		}

	}

}

bool testIfValid(int sudoku[MAX_VALUE][MAX_VALUE])
{
	//if the number is out of range return false
	for (int i = 0; i < MAX_VALUE; i++) {
		for (int j = 0; j < MAX_VALUE; j++) {
			if (sudoku[i][j] < 1 || sudoku[i][j] > 9) {
				return false;
			}
		}
	}

	//judge if each row or each column contains each number from 1-9 exactly once
	for (int i = 0; i < MAX_VALUE; i++) {
		for (int j = 0; j < MAX_VALUE - 1; j++) {
			for (int k = j + 1; k < MAX_VALUE; k++) {
				//if the row contain duplicates
				if (sudoku[i][j] == sudoku[i][k]) {
					return false;
				}

				//if the column contain duplicates
				if (sudoku[j][i] == sudoku[k][i]) {
					return false;
				}
			}
		}
	}

	int count[MAX_VALUE + 1] = { 0 }; //the array to count the appeared times of each number from 1~9

	//judge if each 3x3 square contains each number from 1-9 exactly once
	for (int i = 0; i < MAX_VALUE; i += 3) {
		for (int l = 0; l < MAX_VALUE; l += 3) {
			//initialize the count array to zero
			for (int j = 1; j <= MAX_VALUE; j++) {
				count[j] = 0;
			}

			//count the appeared times of each number
			for (int j = i; j < MAX_VALUE / 3 + i; j++) {
				for (int k = l; k < MAX_VALUE / 3 + l; k++) {
					count[sudoku[j][k]] ++;
				}
			}

			//if it contains duplicates return false
			for (int j = 1; j <= MAX_VALUE; j++) {
				if (count[j] != 1) {
					return false;
				}
			}
		}
	}

	return true;
}
