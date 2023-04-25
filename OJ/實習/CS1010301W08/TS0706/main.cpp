/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-17
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-19
 * Description: Determine whether the given pair is legal according to the Shisensho's rules.
 *************************************************************************/
#include <iostream>
#define MAX_VALUE 6
#define MAX_TURNS 2
using namespace std;

//a structure to store position
struct Position
{
	int x, y;
};

bool testIfValid(int gameBoard[MAX_VALUE + 2][MAX_VALUE + 2], Position current, Position target, int turns, int faces);

int main()
{
	int gameBoard[MAX_VALUE + 2][MAX_VALUE + 2] = { 0 }; //the game board 
	Position current, target; //two position

	//initialize the game board
	for (int i = 1; i <= MAX_VALUE; i++) {
		for (int j = 1; j <= MAX_VALUE; j++) {
			cin >> gameBoard[i][j];
		}
	}

	//end if reading EOF
	while (cin >> current.x >> current.y >> target.x >> target.y) {
		current.x++;
		current.y++;
		target.x++;
		target.y++;
		int symbol1 = gameBoard[current.y][current.x];
		int symbol2 = gameBoard[target.y][target.x];

		//if two symbol are the same and not zero
		//if two positition are not same
		//and test if it is valid
		if (symbol1 == symbol2 && testIfValid(gameBoard, current, target, 0, -1) && symbol1 != 0 && symbol2 != 0 && (current.x != target.x || current.y != target.y)) {
			gameBoard[current.y][current.x] = 0;
			gameBoard[target.y][target.x] = 0;
			cout << "pair matched" << endl;
		}
		else {
			cout << "bad pair" << endl;
		}
	}

}

/**
 * Intent: test if it is valid and can connect
 * Pre: gamboard, two position, the turns taked, and the direction face now
 * Post: valid then return true
 */
bool testIfValid(int gameBoard[MAX_VALUE + 2][MAX_VALUE + 2], Position current, Position target, int turns, int faces)
{
	int delta[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; //the four direction to move

	//judge if current position is out of range
	if (current.x < 0 || current.x > MAX_VALUE + 1 || current.y < 0 || current.y > MAX_VALUE + 1) {
		return false;
	}

	//judge if target position is out of range
	if (target.x < 0 || target.x > MAX_VALUE + 1 || target.y < 0 || target.y > MAX_VALUE + 1) {//???
		return false;
	}

	//judge if target symbol is zero
	//if take turns more
	if (gameBoard[target.y][target.x] == 0 || turns > MAX_TURNS) {
		return false;
	}

	//if arrive targe position and does not take more turns
	if (current.x == target.x && current.y == target.y && turns <= 2) {
		return true;
	}

	//run the four direction
	for (int i = 0; i < 4; i++) {
		Position next;
		next.x = current.x + delta[i][0];
		next.y = current.y + delta[i][1];

		//if next position is out of range
		if (next.x >= 0 && next.x <= MAX_VALUE + 1 && next.y >= 0 && next.y <= MAX_VALUE + 1) {
			//judge if next symbol is zero and the next position are same with target
			if (gameBoard[next.y][next.x] == 0 || next.x == target.x && next.y == target.y) {
				//test if next is valid
				if (testIfValid(gameBoard, next, target, turns + ((faces == i || faces == -1) ? 0 : 1), i)) {
					return true;
				}
			}
		}
	}
	return false;
}
