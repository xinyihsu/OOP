#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <vector>

#define MAX_VALUE 100

using namespace std;

////output in file
//ofstream out("output4.txt");

class MineSweeper
{
private:
	char inputboard[MAX_VALUE][MAX_VALUE];
	char gameBoard[MAX_VALUE][MAX_VALUE];
	char answerBoard[MAX_VALUE][MAX_VALUE];
	bool loadPerfect = false;
	int row, col; //the row and column amount of gameboard
	int gameState = 0; //�ݾ�=0,�C��=1,����=2
	int bombCount = 0;
	int flagCount = 0;
	int openBlankCount = 0;
	int remainBlankCount;

public:
	MineSweeper();
	~MineSweeper();
	void Load(vector<string> inputString);
	void StartGame();
	void Print(vector<string> inputString);
	void LeftClick(vector<string> inputString);
	void RightClick(vector<string> inputString);
	void Replay();
	void Quit();
	void spaceMaker(int a, int b, int count);
};


MineSweeper::MineSweeper()
{

}

MineSweeper::~MineSweeper()
{

}


void MineSweeper::Load(vector<string> inputString)
{
	//string command, string filePath, string appointCol, string appointMine
	if (gameState == 0) // �ݾ�
	{
		string command = inputString[2];

		char board[MAX_VALUE][MAX_VALUE];

		if (command == "BoardFile")
		{
			string filePath = inputString[3];

			//int row, col;
			ifstream input;

			input.open(filePath);

			input >> row >> col;

			//read the file
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					input >> board[i][j];
				}
			}
		}
		else if (command == "RandomCount" || command == "RandomRate")
		{
			this->row = atoi(inputString[3].c_str());
			this->col = atoi(inputString[4].c_str());
			double appointMine = stod(inputString[5]);
			int mineRand[2]; //�H�����u����m

			//��l
			for (int i = 0; i < this->row; i++)
			{
				for (int j = 0; j < this->col; j++)
				{
					board[i][j] = 'O';
				}
			}

			//�p�⬵�u��
			if (command == "RandomRate")
			{
				appointMine = appointMine * this->row * this->col;
			}
			//�H�����ͬ��u
			for (int i = 0; i < (int)appointMine; i++)
			{
				int tempY = rand() % this->row;
				int tempX = rand() % this->col;
				if (board[tempY][tempX] == 'X')
				{
					i--;
				}
				else
				{
					board[tempY][tempX] = 'X';
				}
			}
		}

		//����answer board
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (board[i][j] == 'O')
				{
					int count = 0;
					for (int m = i - 1; m <= i + 1; m++) //row
					{
						for (int n = j - 1; n <= j + 1; n++) //col
						{
							if (board[m][n] == 'X' && m >= 0 && m < this->row && n >= 0 && n < this->col)
							{
								count++;
							}
						}
					}
					answerBoard[i][j] = '0' + count;
				}
				else if (board[i][j] == 'X')
				{
					answerBoard[i][j] = 'X';
					bombCount++;
				}
			}
		}

		//����game board
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				gameBoard[i][j] = '#';
			}
		}

		this->loadPerfect = true;
		cout << "<" << inputString[0] << "> : Success" << endl;
	}
	else
	{
		cout << "<" << inputString[0] << "> : Failed" << endl;
	}
}

void MineSweeper::StartGame()
{
	if (gameState == 0 && this->loadPerfect)
	{
		this->gameState = 1; //�ܦ��C�����A
		cout << "<StartGame> : Success" << endl;
	}
	else
	{
		cout << "<StartGame> : Failed" << endl;
	}
}

void MineSweeper::Print(vector<string> inputString)
{
	string infor = inputString[2];

	if (infor == "GameBoard")
	{
		cout << "<Print " << infor << "> : " << endl;
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				cout << gameBoard[i][j] << " ";
			}
			cout << endl;
		}
	}
	else if (infor == "GameState")
	{
		switch (this->gameState)
		{
		case 0:

			cout << "<Print " << infor << "> : " << "Standby" << endl;
			break;
		case 1:
			cout << "<Print " << infor << "> : " << "Playing" << endl;
			break;
		case 2:
			cout << "<Print " << infor << "> : " << "GameOver" << endl;
			break;
		}
	}
	else if (infor == "GameAnswer")
	{
		cout << "<Print " << infor << "> : " << endl;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << answerBoard[i][j] << " ";
			}
			cout << endl;

		}
	}
	else if (infor == "BombCount")
	{
		cout << "<Print " << infor << "> : " << bombCount << endl;
	}
	else if (infor == "FlagCount")
	{
		cout << "<Print " << infor << "> : " << flagCount << endl;
	}
	else if (infor == "OpenBlankCount")
	{
		cout << "<Print " << infor << "> : " << openBlankCount << endl;
	}
	else if (infor == "RemainBlankCount")  //����
	{
		cout << "<Print " << infor << "> : " << remainBlankCount << endl;
	}
}

void MineSweeper::LeftClick(vector<string> inputString)
{
	//cout << inputString[0];
	if (this->gameState == 1)
	{
		//input1 input2��Ʀr (a,b) = (row,col)
		//int a = inputString[2][0] - '0', b = inputString[3][0] - '0';
		int a = stoi(inputString[2]);
		int b = stoi(inputString[3]);

		//�P�_��J���L�W���A���L(�ݸ�)�B�X�m�B�Q�}��(�Ʀr)
		if (a > this->row - 1 || b > this->col - 1 || a < 0 || b < 0 || gameBoard[a][b] == 'f' || isdigit(gameBoard[a][b]))
		{
			cout << "<" << inputString[0] << "> : Failed" << endl;
			return;
		}
		//�P�_�p�G���צ�m�����u�A���h
		if (answerBoard[a][b] == 'X')
		{
			cout << "<" << inputString[0] << "> : Success" << endl;
			cout << "You lose the game" << endl;
			this->gameState = 2;
			return;
		}
		//�p�G���Ů�A�}�ҪŮ�
		else
		{
			spaceMaker(a, b, 0);
		}

		cout << "<" << inputString[0] << "> : Success" << endl;

		//�p��ѤU��l��
		int countRemainBlank = 0;
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				if (answerBoard[i][j] != 'X' && !isdigit(gameBoard[i][j]))
				{
					countRemainBlank++;
				}
			}
		}
		this->remainBlankCount = countRemainBlank;

		if (this->remainBlankCount == 0)
		{
			cout << "You win the game" << endl;
			this->gameState = 2;
		}
	}
	else
	{
		cout << "<" << inputString[0] << "> : Failed" << endl;
	}
}

void MineSweeper::spaceMaker(int a, int b, int count)
{
	gameBoard[a][b] = answerBoard[a][b]; //�}�Ү�l 
	openBlankCount += 1; //�}�Ү�l�ƶq+1

	if (answerBoard[a][b] != '0' && count == 0)
	{
		return;
	}
	else
	{
		for (int i = a - 1; i <= a + 1; i++)
		{
			for (int j = b - 1; j <= b + 1; j++)
			{
				if (i < 0 || i >= row || j < 0 || j >= col)
				{
					continue;
				}


				//�u��}�ҨS�}�L��
				if (gameBoard[i][j] == '#')
				{
					//��0���j
					if (answerBoard[i][j] == '0')
					{
						spaceMaker(i, j, count + 1);
					}
					//����0�¶}��
					else if (answerBoard[i][j] != 'X')
					{
						gameBoard[i][j] = answerBoard[i][j];
						openBlankCount += 1;
					}
				}
			}
		}
	}
}

void MineSweeper::RightClick(vector<string> inputString)
{
	//input1 input2��Ʀr
	int a = stoi(inputString[2]), b = stoi(inputString[3]);

	//�P�_gameBoard[a][b]���Ÿ����X�۹����ʧ@
	if (gameState == 1 && !isdigit(gameBoard[a][b]))
	{
		if (gameBoard[a][b] == 'f')
		{
			gameBoard[a][b] = '?';
			flagCount -= 1;
		}
		else if (gameBoard[a][b] == '?')
		{
			gameBoard[a][b] = '#';
		}
		else if (gameBoard[a][b] == '#')
		{
			gameBoard[a][b] = 'f';
			flagCount += 1;
		}
		cout << "<" << inputString[0] << "> : Success" << endl;
	}
	else
	{
		cout << "<" << inputString[0] << "> : Failed" << endl;
	}
}

void MineSweeper::Replay()
{
	//�b�C���������A�U
	if (gameState == 2)
	{
		this->inputboard[MAX_VALUE][MAX_VALUE] = { 0 };
		this->gameBoard[MAX_VALUE][MAX_VALUE] = { 0 };
		this->answerBoard[MAX_VALUE][MAX_VALUE] = { 0 };
		this->loadPerfect = false;
		this->row = 0;
		this->col = 0;
		this->gameState = 0;
		this->bombCount = 0;
		this->flagCount = 0;
		this->openBlankCount = 0;
		cout << "<Replay> : Success" << endl;
	}
	else
	{
		cout << "<Replay> : Failed" << endl;
	}
}
void MineSweeper::Quit()
{
	if (gameState == 2)
	{
		cout << "<Quit> : Success" << endl;
		exit(0);
	}
	else
	{
		cout << "<Quit> : Failed" << endl;
	}
}
