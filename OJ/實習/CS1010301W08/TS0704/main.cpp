/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-17
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-18
 * Description: Input a series of words, each two words is a set. Then, find the Levenshtein distance of them.
 *************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string words1, words2; //the input string and the target string

	//enf if reading EOF
	while (getline(cin, words1) && getline(cin, words2)) {
		int length1 = words1.length(); //the length of words1
		int length2 = words2.length(); //the length of words2
		vector<vector<int>> distance(length1 + 1, vector<int>(length2 + 1, 0)); //row : length1 + 1, col : length2 + 1

		//initialize the first column to the smallest distence that change the sting into null
		for (int i = 0; i <= length1; i++) {
			distance[i][0] = i;
		}

		//initialize the first row to the smallest distence that change the sting into null
		for (int i = 0; i <= length2; i++) {
			distance[0][i] = i;
		}

		//calculate the smallest distance
		for (int i = 1; i <= length1; i++) {
			for (int j = 1; j <= length2; j++) {
				//if the two char is the same
				if (words1[i - 1] == words2[j - 1]) {
					distance[i][j] = distance[i - 1][j - 1];
				}
				else {
					//find the smallest of three way
					//distance[i - 1][j - 1] + editCost: replace
					//distance[i - 1][j] + 1: delete
					//distance[i][j - 1] + 1: insert
					distance[i][j] = min(distance[i - 1][j - 1], min(distance[i - 1][j], distance[i][j - 1])) + 1;
				}
			}
		}

		cout << distance[length1][length2] << endl;
	}
}
