///***********************************************************************
// * File: Source.cpp
// * Author: Name: 四資工一 B11115037 莊靜雯
// * Create Date: 2023/04/16
// * Editor: Name: 四資工一 B11115037 莊靜雯
// * Update Date: 2023/04/18
// * Description: Shisensho(四川省) is a classic tile-matching game. The objective of the game is to match all the pairs and clear the board.
//				Rules: Player choose a pair of identical tiles to connect, and the connection path must not exceed two turns. If the requirements are met, two tiles will be eliminated. The player’s task is to eliminate all the tiles on the board. The game is over if future moves are not possible and tiles are left on the board, or the player successfully removes all the tiles. Some legal patterns of connection path are shown as follow:
//				To simplify the game, we start the game with a 6*6 board and only have 9 different symbols (represented by characters :‘1’, ‘2’, ‘3’, … , ‘9’).
//				Your quest is to determine whether the given pair is legal according to the rules shown above. If it is legal, eliminate the pair and print out “pair matched”. If it is not legal, do nothing and print out “bad pair”.
//				The status of the board (the remaining tiles) should always be updated when you receive a legal pair, which means the same input might have different results over time.
//***********************************************************************/
//
//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Shisensho
//{
//public:
//	int x;
//	int y;
//
//	// constructor
//	Shisensho(int = 0, int = 0);
//
//	// if pos in range
//	bool inRange(int size)
//	{
//		if (x < 0 || x >= size)
//		{
//			return false;
//		}
//		if (y < 0 || y >= size)
//		{
//			return false;
//		}
//
//		return true;
//	}
//};
//
//// constructor
//Shisensho::Shisensho(int x, int y)
//{
//	this->x = x;
//	this->y = y;
//}
//
//// Binary operator '==': 'Shisensho' does not define acceptable type conversions for this operator or predefined operators
//// if no this, Compile Error
//bool operator==(const Shisensho& x1, const Shisensho& x2)
//{
//	if (x1.x == x2.x && x1.y == x2.y)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//// Binary operator '+': 'Shisensho' does not define acceptable type conversions for this operator or predefined operators
//// if no this, Compile Error
//Shisensho operator+(const Shisensho& x1, const Shisensho& x2)
//{
//	return Shisensho(x1.x + x2.x, x1.y + x2.y);
//}
//
//enum class direction :int { UP, DOWN, LEFT, RIGHT };
//
//// Return according to different direction
//Shisensho mapDirection(direction dir)
//{
//	switch (dir)
//	{
//	case direction::UP:
//		return Shisensho(0, -1);
//	case direction::DOWN:
//		return Shisensho(0, 1);
//	case direction::LEFT:
//		return Shisensho(-1, 0);
//	case direction::RIGHT:
//		return Shisensho(1, 0);
//	}
//}
//
//// Intent: reset the path that has been traveled
//// Pre: Second Dimension vector
//// Post: void
//void resetBoard(vector<vector<int>>& board)
//{
//	for (auto& i : board)
//	{
//		for (auto& j : i)
//		{
//			if (j == -1)
//			{
//				j = 0;
//			}
//		}
//	}
//}
//
//// Intent: depthFirstSearch
//// Pre: Second Dimension vector, two class Shisensho, enum
//// Post: bool
//bool depthFirstSearch(vector<vector<int>>& board, Shisensho nowPos, Shisensho& endPos, direction currentDir, int turnCount)
//{
//	vector<direction> directions = { direction::UP, direction::DOWN, direction::LEFT, direction::RIGHT };
//
//	for (const auto& dir : directions)
//	{
//		Shisensho temp = nowPos + mapDirection(dir);
//
//		// Count the number of turns passed during a depth-first search
//		int turnTemp = (int)(dir != currentDir) + turnCount;
//
//		// arrive endPos
//		if (temp == endPos)
//		{
//			resetBoard(board);
//
//			if (turnTemp <= 2)
//			{
//				return true; // Search succeeded
//			}
//			else
//			{
//				return false; // search failed
//			}
//		}
//
//		// not arrive endPos
//		if (temp.inRange(8) && board[temp.y][temp.x] == 0 && turnTemp <= 2)
//		{
//			board[temp.y][temp.x] = -1;
//
//			// if next step can arrive end, Search succeeded
//			if (depthFirstSearch(board, temp, endPos, dir, turnTemp))
//			{
//				resetBoard(board);
//
//				return true;
//			}
//		}
//	}
//
//	resetBoard(board);
//
//	return false;
//}
//
//int main()
//{
//	Shisensho pos1, pos2;
//	vector<vector<int>> board(8, vector<int>(8, 0));
//
//	// input
//	for (int i = 1; i < 7; i++)
//	{
//		for (int j = 1; j < 7; j++)
//		{
//			cin >> board[i][j];
//		}
//	}
//
//	// input match
//	while (cin >> pos1.x >> pos1.y >> pos2.x >> pos2.y)
//	{
//		pos1.x += 1;
//		pos1.y += 1;
//		pos2.x += 1;
//		pos2.y += 1;
//
//		// if out of range
//		if (pos1.x < 0 || pos1.x > 7 || pos1.y < 0 || pos1.y > 7 || pos2.x < 0 || pos2.x > 7 || pos2.y < 0 || pos2.y > 7)
//		{
//			cout << "bad pair\n";
//			continue;
//		}
//
//		// if the same
//		if (pos1.x == pos2.x && pos1.y == pos2.y)
//		{
//			cout << "bad pair\n";
//			continue;
//		}
//
//		// if empty or not match
//		if (board[pos1.y][pos1.x] == 0 || board[pos2.y][pos2.x] == 0 || board[pos1.y][pos1.x] != board[pos2.y][pos2.x])
//		{
//			cout << "bad pair\n";
//			continue;
//		}
//
//		bool flag = false;
//
//		vector<direction> directions = { direction::UP, direction::DOWN, direction::LEFT, direction::RIGHT };
//
//		// find effective path
//		for (auto& dir : directions)
//		{
//			Shisensho temp = pos1 + mapDirection(dir);
//
//			// Is it a space that can go
//			if (board[temp.y][temp.x] == 0)
//			{
//				// mark
//				board[temp.y][temp.x] = -1;
//
//				// find valid path
//				if (depthFirstSearch(board, temp, pos2, dir, 0))
//				{
//					flag = true;
//				}
//			}
//			// find valid path
//			else if (temp == pos2)
//			{
//				flag = true;
//			}
//		}
//
//		// if match
//		if (flag)
//		{
//			// delete matched
//			board[pos1.y][pos1.x] = 0;
//			board[pos2.y][pos2.x] = 0;
//
//			cout << "pair matched\n";
//		}
//		else
//			cout << "bad pair\n";
//	}
//
//	return 0;
//}

#define MAX 6
#define TURN_MAX 2
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//set the board
vector<vector<int>> gameBoard(MAX + 2, vector<int>(MAX + 2, 0));
//set the position
struct Pos
{
	int x, y;
};
//Intent:delet tile
//Pre:input current and target tile with Pos struct
//Post:delet tile
void deleTile(Pos cur, Pos target)
{
	gameBoard[cur.y][cur.x] = 0;
	gameBoard[target.y][target.x] = 0;
}
//Intent:init board
void initGameBoard()
{
	for (int i = 1; i < MAX + 1; i++)
	{
		for (int j = 1; j < MAX + 1; j++)
		{
			cin >> gameBoard[i][j];
		}
	}
}
//Intnet:check the next step valid
//Pre:input next step Pos and target Pos
//Post:return true if valid ,or false
bool nextValid(Pos next, Pos target)
{
	if (next.x<0 || next.x>MAX + 1 || next.y<0 || next.y>MAX + 1) return false;
	if (gameBoard[next.y][next.x] == 0 || next.x == target.x && next.y == target.y) return true;
	return false;
}
//Intnet:check the cur  valid
//Pre:input cur  Pos and target Pos
//Post:return true if valid ,or false
bool isValid(Pos cur, Pos target, int turns, int dir)
{
	if (gameBoard[target.y][target.x] == 0 ||
		cur.x<0 || cur.x>MAX + 1 || cur.y<0 || cur.y>MAX + 1 ||
		target.x<1 || target.x>MAX + 1 || target.y<0 || target.y>MAX + 1 ||
		turns > TURN_MAX)return false;
	if (cur.x == target.x && cur.y == target.y && turns <= TURN_MAX)return true;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	for (int i = 1; i <= 4; i++)
	{
		Pos next;
		next.x = cur.x + dx[i - 1];
		next.y = cur.y + dy[i - 1];
		if (nextValid(next, target))
		{
			if (isValid(next, target, turns + ((dir == i || dir == 5) ? 0 : 1), i))return true;
		}
	}
	return false;
}
//Intent:check the style is same and if same return true ,or false
//Pre:input Pos cur and target
//Post:check the style is same and if same return true ,or false
bool isSameStyle(Pos cur, Pos target)
{
	if ((gameBoard[cur.y][cur.x] == gameBoard[target.y][target.x]) &&
		(cur.x != target.x || cur.y != target.y))
	{
		return true;
	}
	return false;
}

int main()
{
	initGameBoard();
	Pos cur, target;
	int curX, curY, targetX, targetY;
	while (cin >> curX >> curY >> targetX >> targetY)
	{
		cur.x = curX + 1;
		cur.y = curY + 1;
		target.x = targetX + 1;
		target.y = targetY + 1;
		//check the step valid ,if true ,delet Tile and print pair matched ,or print bad pair 
		if (isSameStyle(cur, target) && isValid(cur, target, 0, 5))
		{
			deleTile(cur, target);
			cout << "pair matched";
		}
		else
		{
			cout << "bad pair";
		}
		cout << endl;
	}
	return 0;
}
