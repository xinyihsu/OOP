/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-04
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-09
 * Description: Write a program that reads this file and finds the longest word that reverses to a different word.
 *				For example, "stun" reverses to make the word "nuts" but is only four letters long.
 *				Find the longest such word.
 *************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <fstream>
using namespace std;

/**
 * Intent: produce the reverse of words
 * Pre: a string
 * Post: the reverse of the input string
 */
string reverse(const string& words)
{
	string reverseWords = words;

	//store all the character inverted
	for (int i = 0; i < words.size(); i++) {
		reverseWords[i] = words[words.size() - 1 - i];
	}

	return reverseWords;
}

/**
 * Intent: test if two words are the same (ignore upper and lower)
 * Pre: the reverse words and the words input
 * Post: boolean
 */
bool testIfSame(string reverseWords, string inputWords)
{
	//run all characters and compare
	for (int i = 0; i < reverseWords.size(); i++) {
		//judge if the same
		if (reverseWords[i] != inputWords[i] && abs(reverseWords[i] - inputWords[i]) != 32) {
			return false;
		}
	}

	return true;
}


void main()
{
	int longestWordSize = 0;
	string longestWord, tempWord;
	vector<string> wordsVector; //store the words input

	//read the file until EOF
	while (cin >> tempWord) {
		wordsVector.push_back(tempWord);
	}

	//search the longest words
	for (int i = 0; i < wordsVector.size(); i++) {
		for (int j = i + 1; j < wordsVector.size(); j++) {
			string reverseWords = reverse(wordsVector[i]);

			//if the reversed words sized is not the same as input words  
			//if the size is not longer then the logest words 
			//do not need to test if it has the same 
			if (reverseWords.size() == wordsVector[j].size() && reverseWords.size() > longestWordSize) {
				if (testIfSame(reverseWords, wordsVector[j])) {
					longestWordSize = reverseWords.size();
					longestWord = wordsVector[i];
					break;
				}
			}
		}
	}

	cout << longestWord;
}
