/************************************************************************
File:   main.cpp

Author:
  鍾賢廣，ea5878158@gmail.com
Modifier:
  賴祐吉，cheeryuchi@gmail.com
  陳俊宇，JYCReports@gmail.com
  邱嘉興，tbcey74123@gmail.com

Editor: 徐欣儀，B11130008@mail.ntust.edu.tw
  莊靜雯，B11115037@mail.ntust.edu.tw
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
        Position tryMove; //the position that we expect to move
        tryMove.x = this->sPos.x + deltaX;
        tryMove.y = this->sPos.y + deltaY;

        //judge if the position is valid, if it is then move on it
        if (isPositionValid(tryMove) == true) {
            this->sPos.x = tryMove.x;
            this->sPos.y = tryMove.y;
        }
        /************************************************************************/
    }
};

Hero gHero;
// clip algroithm
int clip(int n, int minimun, int maximum);

class Creature {

    // Implement Creature Class
    /*Please implement your code here*/
private:
    Position sPos;   // Creature location
    char sIcon = '@'; // Creature icon

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

    // Get position
    Position getPos(void) { return this->sPos; }

    // Get icon
    char getIcon(void) { return this->sIcon; }

    //judge if the creature can see the hero
    bool canSee(Position pos, int& dir_x, int& dir_y) {
        //the dir x and dir y value are call-by-refernce
        dir_x = clip((pos.x - this->sPos.x), -1, 1); //clip the value between -1 mand 1
        dir_y = clip((pos.y - this->sPos.y), -1, 1);
        int count = 0;

        //check the range that if it can see the creature
        do {
            if (this->sPos.x + dir_x * count == pos.x && this->sPos.y + dir_y * count == pos.y) {
                return true;
            }
            count++;
        } while (count <= 2); //check the range in 2 units
    }

    //move the element
    void update(Position pos) {
        int dirX, dirY; //
        Position tryMove = this->sPos; //the position that we expect to move

        //judge if creature can see the hero
        if (canSee(pos, dirX, dirY)) {
            //if the creature and hero are not in a line then random move single direction
            if (abs(dirX) == 1 && abs(dirY) == 1) {
                int moveDirection = rand() % 2; //get a random number from 0 to 1
                
                //as different number then move to different direction
                if (moveDirection == 0) {
                    tryMove.x += dirX;
                }
                else {
                    tryMove.y += dirY;
                }
            }
            else { //the creature and the hero are in a line
                tryMove.x += dirX;
                tryMove.y += dirY;
            }
        }
        else {
            int moveDirection = rand() % 4; //get a random number from 0 to 3

            //as the different number then move to different direction
            switch (moveDirection) {
            case 0: //go up
                tryMove.y++;
                break;
            case 1: //go down
                tryMove.y--;
                break;
            case 2: //go left
                tryMove.x++;
                break;
            case 3: //go right
                tryMove.x--;
                break;
            }
        }

        //judge if the position is valid, if it is then move on it
        if (isPositionValid(tryMove)) {
            this->sPos.x = tryMove.x;
            this->sPos.y = tryMove.y;
        }
    }
    /************************************************************************/
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
int clip(int n, int minimun, int maximum)
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
//==================================================================
//******************************************************************
//
// * Output information
//==================================================================
void drawInfo(void)
//==================================================================
{
    // Print Outputs
    /*Please implement your code here*/
    //get the two alaments' position
    Position h = gHero.getPos();
    Position c = gCreature.getPos();

    //jude if they distance two units
    if (abs(h.x - c.x) <= 2 && abs(h.y - c.y) <= 2)
    {
        std::cout << "Creature found Hero!" << std::endl;
    }

    /************************************************************************/

    std::cout << "Use wsad key to move Hero " << gHero.getIcon() << std::endl;
    std::cout << "Press ESC key to exit" << std::endl;
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
    // 清除版面
    system("CLS");

    // 是否有input
    bool hasInput = false;
    if (key[ValidInput::EW]) {
        gHero.move(0, -1);
        hasInput = true;
    }
    else if (key[ValidInput::ES]) {
        gHero.move(0, 1);
        hasInput = true;
    }
    else if (key[ValidInput::EA]) {
        gHero.move(-1, 0);
        hasInput = true;
    }
    else if (key[ValidInput::ED]) {
        gHero.move(1, 0);
        hasInput = true;
    }
    else {
        std::cout << "invalid input\n";
    }
    //Calculate and Initiate Move
    gCreature.update(gHero.getPos());
    draw();
    drawInfo();
}