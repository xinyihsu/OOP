/*************************************************************************
 * File: Form.h
 * Author:®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-15
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-16
 * Description: Write a program that lets the user set a word and then output all the words
				contained in the file words.txt that can be formed from the letters of the set word.
 *************************************************************************/
#include <iostream>
#include <ctype.h> // tolower()
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Form
{
private:
	string input;
	string fileName;
	vector<string> validWords; //store the valid words (*add by me)
public:
	void SetInputWord(string inputWord); // set input
	void ProcessInputWord(void); // process input
	void SetFileName(string fileName); // set file name
	void Load_CompareWord(void); // read-in data and compare
	void PrintFoundWords(void); // print answers
};

/**
 * Intent: Set the given word of the game.
 * Pre: a string user input
 * Post: void
 */
void Form::SetInputWord(string inputWord)
{
	this->input = inputWord;
}

/**
 * Intent: pre-process of the given word thst transition upper to lower case
 * Pre: void
 * Post: void
 */
void Form::ProcessInputWord(void)
{
	//change all the letter into lower case
	for (int i = 0; i < this->input.length(); i++) {
		this->input[i] = tolower(this->input[i]);
	}
}

/**
 * Intent: Set the file name of the file that contains all the valid words.
 * Pre:
 * Post:
 */
void Form::SetFileName(string fileName)
{
	this->fileName = fileName;
}

/**
 * Intent: load the valid words from the file,
			and find out all the valid words composed by the letters in the given word
 * Pre: void
 * Post: void
 */
void Form::Load_CompareWord(void)
{
	int countLetter[26] = { 0 }; //store the appeared times of each letter of input words
	string eachWords; //the each words in the file
	ifstream words; //the file we want to open
	words.open(this->fileName);

	//count the letter of given words
	for (char c : this->input) {
		countLetter[c - 'a']++;
	}

	//read each words in the file
	while (words >> eachWords) {
		int countWords[26] = { 0 }; //store the appeared times of each letter of the words in the file
		bool ifValid = true; //if the words in the file is valid (can be composd by given words)

		//count the letter of words in the file
		for (char c : eachWords) {
			countWords[c - 'a']++;
		}

		//test if the words is valid
		for (int i = 0; i < 26; i++) {
			//judge if the words can be compose by the given words
			if (countWords[i] > countLetter[i]) {
				ifValid = false;
				break;
			}
		}

		//if the words in the file is valid then store it in a vector
		if (ifValid) {
			this->validWords.push_back(eachWords);
		}
	}

	words.close(); //close the file
}

/**
 * Intent: print the words found in the function Load_CompareWord()
 * Pre: void
 * Post: void
 */
void Form::PrintFoundWords(void)
{
	//output the valid words in order
	for (int i = 0; i < this->validWords.size(); i++) {
		cout << this->validWords[i] << endl;
	}
}
