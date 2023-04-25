/************************************************************************
File:   Source.cpp

Author:
  鍾賢廣，ea5878158@gmail.com
Modifier:
  賴祐吉，cheeryuchi@gmail.com
  陳俊宇，JYCReports@gmail.com
  邱嘉興，tbcey74123@gmail.com
Comment:
  基本輸入方向移動功能，w s a d 移動腳色上下左右，空白改變腳色站立之地板字元，
  ESC是離開畫面。同時更新圖版上的資訊。

************************************************************************/
#include <iostream>
#include <math.h>  // pow() and sqrt()
#include <ctime>  // for time loop function
#include <conio.h>  // _getch() <= to read input without enter "ENTER" key
#include <algorithm> // for max and min function

//************************************************************
// The location in the board
//************************************************************
struct Position {
	int x; // X, y Coordinate
	int y;
};

// Check whether the location is a valid one i.e. not a wall
bool isPositionValid(Position& loc);

//************************************************************
// Hero Class, only has requirement part for example
//************************************************************
class Hero {
private:
	Position sPos;   // Hero location
	char sIcon = 'H'; // Hero icon

public:
	// Default constructor
	Hero() {
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sIcon = 'H';
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Incrementally move the elements 
	void move(int deltaX, int deltaY) {
		// Implement Hero controls
		/*Please implement your code here*/

		Position tryMove;
		tryMove.x = this->sPos.x + deltaX;
		tryMove.y = this->sPos.y + deltaY;
		if (isPositionValid(tryMove) == true) {
			this->sPos.x = tryMove.x;
			this->sPos.y = tryMove.y;
		}


		/************************************************************************/
	}
};

// clip algroithm
float clip(float n, float minimun, float maximum);
/*
class Creature {

 // Implement Creature Class
 /*Please implement your code here*/

 /*
 private:
  Position sPos;   // Hero location
  char sIcon = '@'; // Hero icon

 public:
  // Default constructor
  Creature() {
   this->sPos.x = 0;
   this->sPos.y = 0;
   this->sIcon = '@';
  };

  // Set position
  void setPos(Position pos) { this->sPos = pos; }
  void setPos(int x, int y) {
   this->sPos.x = x;
   this->sPos.y = y;
  }

  // Set icon
  void setIcon(char& icon) { this->sIcon = icon; }

  // Get position
  Position getPos(void) { return this->sPos; }

  // Get Icon
  char getIcon(void) { return this->sIcon; }





  bool canSee(Position pos, int& dir_x, int& dir_y) {
   //the dir x and dir y value are call-by-refernce
   dir_x = clip((pos.x - this->sPos.x), -1, 1); //clip the value between -1 m
   dir_y = clip((pos.y - this->sPos.y), -1, 1);
   int count = 0;
   do {
	if (this->sPos.x + dir_x * count == pos.x && this->sPos.y + dir_y * count == pos.y) {
	 return true;
	}
	count++;
   } while (count <= 2); //check the range in 4 units return false;
  }
  void update(Position pos) {
   int dir_x, dir_y;
   if (canSee(pos, dir_x, dir_y)) {
	if (abs(dir_x) == 1 && abs(dir_y) == 1) {
	 int moveDirection = rand() % 2;
	 if (moveDirection == 0) {
	  this->sPos.x += dir_x;
	 }
	 else {
	  this->sPos.y += dir_y;
	 }
	}
	else {
	 this->sPos.x += dir_x;
	 this->sPos.y += dir_y;
	}
   }
   else {
	Position tryMove = sPos;
	do {
	 tryMove = this->sPos;
	 int moveDirection = rand() % 4;
	 switch (moveDirection) {
	 case 0: //up
	  tryMove.y++;
	  break;
	 case 1: //down
	  tryMove.y--;
	  break;
	 case 2: //left
	  tryMove.x++;
	  break;
	 case 3: //right
	  tryMove.x--;
	  break;
	 }
	} while (isPositionValid(tryMove) != true);
	this->sPos.x = tryMove.x;
	this->sPos.y = tryMove.y;
   }
  }






  /************************************************************************/
  //};


class Creature {
private:
	Position sPos; // Creature location
	char sIcon; // Creature icon
public:
	Creature() {
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sIcon = 'C';
	}

	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	void setIcon(char icon) { this->sIcon = icon; }

	Position getPos() { return this->sPos; }
	char getIcon() { return this->sIcon; }

	// Check whether the Hero is within the Creature's range
	bool canSeeHero(Hero& hero) {
		int dx = abs(hero.getPos().x - this->sPos.x);
		int dy = abs(hero.getPos().y - this->sPos.y);

		return (dx <= 4 && dy <= 4);
	}

	// Move the Creature
	void update(Hero& hero) {
		if (canSeeHero(hero)) {
			// Move towards the Hero
			int dx = hero.getPos().x - this->sPos.x;
			int dy = hero.getPos().y - this->sPos.y;

			// Calculate the direction of movement
			int signX = (dx > 0) - (dx < 0);
			int signY = (dy > 0) - (dy < 0);

			// Move the Creature
			Position newPos;
			newPos.x = this->sPos.x + signX;
			newPos.y = this->sPos.y + signY;

			// Check if the new position is valid
			if (isPositionValid(newPos)) {
				// Update the Creature's position
				this->sPos = newPos;
			}
		}
		else {
			// Move randomly
			int dx = rand() % 3 - 1;
			int dy = rand() % 3 - 1;

			// Move the Creature
			Position newPos;
			newPos.x = this->sPos.x + dx;
			newPos.y = this->sPos.y + dy;

			// Check if the new position is valid
			if (isPositionValid(newPos)) {
				// Update the Creature's position
				this->sPos = newPos;
			}
		}
	}
};








// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

const int GWIDTH = 10;
const int GHEIGHT = 10;
const double gTimeLog = 0.033;

// Distance
const int gDistance = 4;

// 用來儲存版面資料
char gBoard[GHEIGHT][GWIDTH];

// 定義六種輸入指令與對應陣列index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	INVALID,
};

Hero gHero;
Creature gCreature;

// function declare
// 偵測輸入狀態
void keyUpdate(bool key[]);
// 判斷位置是否為空
bool isPositionValid(Position& loc);
// 初始化版面
void setupBoard();
// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);

// 程式主驅動函式
void update(bool key[]);

int main(int argc, char** argv)
{
	srand(time(NULL));

	// 用來管理鍵盤輸入狀態的陣列
	bool gKeyState[6];

	// Setup a clear dungeon
	setupBoard();

	// Set the position of Hero
	gHero.setPos(2, 2);

	gCreature.setPos(5, 6);

	// Draw the bord and information
	draw();
	drawInfo();

	// Variable for game loop
	clock_t startT, endT;
	startT = clock();
	endT = clock();

	// Get the press key
	keyUpdate(gKeyState);

	// Run the game loop
	while (!gKeyState[ValidInput::EESC]) {
		// Compute the time lap
		double timeFrame = (double)(endT - startT) / CLOCKS_PER_SEC;

		// Execute the game loop
		if (timeFrame >= gTimeLog) {
			update(gKeyState);
			startT = clock();
		}

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();
	}

	system("pause");
	return 0;
}

//******************************************************************
//
// * 偵測輸入狀態
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++) {
		key[i] = false;
	}
	char input = _getch();
	switch (input) {
	case 'w':
		key[ValidInput::EW] = true;
		break;
	case 's':
		key[ValidInput::ES] = true;
		break;
	case 'a':
		key[ValidInput::EA] = true;
		break;
	case 'd':
		key[ValidInput::ED] = true;
		break;
	case ' ':
		key[ValidInput::ESPACE] = true;
		break;
	case 27:
		key[ValidInput::EESC] = true;
		break;
	default:
		break;
	}
}

//******************************************************************
//
// * 判斷位置是否為空
//==================================================================
bool isPositionValid(Position& pos)
//==================================================================
{
	// Check whether it is an empty space
	if (gBoard[pos.y][pos.x] != GNOTHING)
		return false;

	if (pos.x == gHero.getPos().x && pos.y == gHero.getPos().y)
		return false;

	if (pos.x == gCreature.getPos().x && pos.y == gCreature.getPos().y)
		return false;

	return true;
}

//******************************************************************
//
// * clip algroithm
//==================================================================
float clip(float n, float minimun, float maximum)
//==================================================================
{
	return std::max(minimun, std::min(n, maximum));
}

//******************************************************************
//
// * Setup the board
//==================================================================
void setupBoard()
//==================================================================
{
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			if (i == 0 || i == GHEIGHT - 1) {
				gBoard[i][j] = GWALL;
			}
			else if (j == 0 || j == GWIDTH - 1) {
				gBoard[i][j] = GWALL;
			}
			else {
				gBoard[i][j] = GNOTHING;
			}
		}
	}
}

//******************************************************************
//
// * Draw the board
//==================================================================
void draw()
//==================================================================
{
	// Add the hero into the board
	char drawBoard[GHEIGHT][GWIDTH];

	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

	Position c = gCreature.getPos();
	drawBoard[c.y][c.x] = gCreature.getIcon();

	// Draw the board
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			std::cout << drawBoard[i][j]; //  output
		}
		std::cout << "\n";
	}
}

//******************************************************************
//
// * Output information
//====================================