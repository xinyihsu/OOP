/*************************************************************************
 * File: main.cpp
 * Author: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-07
 * Editor: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-10
 * Description: Here is a translation machine.
 *				You are given the possible translations of letters and a list of pairs of original and deciphered words.
 *				Your task is to verify whether the words in each pair match.
 *				Two words match if they have the same length and if each letter of the first word can be turned into
 *				the corresponding letter of the second word by using the available translations zero or more times.
 *************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/**
 * Intent: test if two letter can match
 * Pre: the translation vector / the letter of origin and answer
 * Post: boolean
 */
bool testIfMatch(vector<vector<bool>>& translation, int origin, int answer)
{
	if (translation[origin][answer]) {
		return true;
	}

	vector<bool> visited(26, false);
	queue<int> myQue;

	// bfs
	myQue.push(origin);
	//test if the letter of origin can link it of the answer
	for (int num; !myQue.empty(); myQue.pop()) {
		num = myQue.front();
		for (int i = 0; i < 26; i++) {
			if (translation[num][i] && !visited[i]) {
				visited[i] = true;
				myQue.push(i);//到下一個節點
			}
		}
	}

	return visited[answer];
}

void main()
{
	int translationNumber, pairsNumber;
	string wordPair;
	vector<vector<bool>> translation(26, vector<bool>(26));
	cin >> translationNumber >> pairsNumber;

	//initial translation vactor
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (i == j) {
				translation[i][j] = true;
			}
			else {
				translation[i][j] = false;
			}
		}
	}

	//end if both are zero
	while (translationNumber != 0 || pairsNumber != 0) {
		//store translation of letters
		for (int i = 0; i < translationNumber; i++) {
			char temp[2];
			cin >> temp[0] >> temp[1];
			translation[temp[0] - 'a'][temp[1] - 'a'] = true;
		}

		//judge the pair of letter
		for (int i = 0; i < pairsNumber; i++) {
			bool ifMatch = true;
			string origin, answer;
			cin >> origin >> answer;

			//if the size of two words are the same
			if (origin.size() == answer.size()) {
				//judge if two words is match
				for (int i = 0; i < origin.size(); i++) {
					if (!testIfMatch(translation, origin[i] - 'a', answer[i] - 'a')) {
						ifMatch = false;
						break;
					}
				}
			}
			else {
				ifMatch = false;
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
