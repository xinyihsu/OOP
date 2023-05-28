/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-07
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-09
 * Description: Here is a translation machine.
 *				You are given the possible translations of letters and a list of pairs of original and deciphered words.
 *				Your task is to verify whether the words in each pair match.
 *				Two words match if they have the same length and if each letter of the first word can be turned into
 *				the corresponding letter of the second word by using the available translations zero or more times.
 *************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool testIfMatch(int index, string origin, const string& answer, const vector<vector<char>> translation)
{
	if (index == origin.size()) {
		return true;
	}

	if (origin[index] != answer[index]) {
		for (int i = 0; i < translation.size(); i++) {
			if (translation[i].size() > 2) {

			}
			if (origin[index] == translation[i][0]) {
				origin[index] = translation[i][1];
				if (!testIfMatch(index, origin, answer, translation)) {

				}
			}
		}
	}
	else {
		return testIfMatch(index + 1, origin, answer, translation);
	}

	return false;
}

void main()
{
	int translationNumber, pairsNumber;
	string wordPair;
	vector<vector<char>> translation;
	cin >> translationNumber >> pairsNumber;

	//end if both are zero
	while (translationNumber != 0 || pairsNumber != 0) {
		//store translation of letters
		for (int i = 0; i < translationNumber; i++) {
			bool ifDuplicate = false;
			vector<char> temp(2);
			cin >> temp[0] >> temp[1];

			//judge if duplicate
			for (int j = 0; j < translation.size(); j++) {
				if (temp[0] == translation[i][0]) {
					translation[i].push_back(temp[1]);
					ifDuplicate = true;
					break;
				}
			}

			//if the words is not duplication
			if (!ifDuplicate) {
				translation.push_back(temp);
			}
		}

		//judge the pair of letter
		for (int i = 0; i < pairsNumber; i++) {
			bool ifMatch = false;
			string origin, answer;
			cin >> origin >> answer;

			//if the size of two words are the same
			if (origin.size() == answer.size()) {
				//judge if two words is match
				if (testIfMatch(0, origin, answer, translation)) {
					ifMatch = true;
				}
			}

			//judge if match an output yes or no
			if (ifMatch) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}

		cin >> translationNumber >> pairsNumber;
	}

}
