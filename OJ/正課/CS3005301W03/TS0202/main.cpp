// Name: ®}ªY»ö
// Date: March 10, 2023
// Last Update: March 11, 2023
// Problem statement: Output the names and scores of top three players.

#include <iostream>
#include <fstream> //include the functions about file.
#include <string> //include the string functions.
using namespace std;
void getHighScores(string player[], int score[]); //scan through the file and judge the top three players and scores.


int main()
{
	string player[3]; //the top three players.
	int score[3] = { 0 }; //the top three scores.
	getHighScores(player, score);

	//output the top three players and scores.
	for (int i = 0; i < 3; i++)
	{
		cout << player[i] << endl << score[i] << endl;
	}
}

void getHighScores(string player[], int score[])
{
	ifstream file;
	string tempPeople; //the name of the current player.
	int tempScore;
	file.open("scores.txt"); //read the content of file.

	//end if reading EOF.
	while (file >> tempPeople)
	{
		file >> tempScore;

		//judge if the scores of current player win the temp top three.
		if (tempScore > score[0])
		{
			score[2] = score[1];
			player[2] = player[1];
			score[1] = score[0];
			player[1] = player[0];
			score[0] = tempScore;
			player[0] = tempPeople;
		}
		else if (tempScore > score[1])
		{
			score[2] = score[1];
			player[2] = player[1];
			score[1] = tempScore;
			player[1] = tempPeople;
		}
		else if (tempScore > score[2])
		{
			score[2] = tempScore;
			player[2] = tempPeople;
		}
	}

	file.close();
}