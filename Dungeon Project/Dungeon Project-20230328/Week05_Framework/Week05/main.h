/************************************************************************
File:        main.h
Author:	     鍾賢廣，ea5878158@gmail.com
Creat Date:  2023-03-31
Modifier:    賴祐吉，cheeryuchi@gmail.com
			 黃欣云，windyhuang6@gmail.com
			 陳俊宇，JYCReports@gmail.com
			 邱嘉興，tbcey74123@gmail.com
Editor:	     徐欣儀，B11130008@mail.ntust.edu.tw
			 莊靜雯，B11115037@mail.ntust.edu.tw
Update date: 2023-04-01
Comment:	 基本輸入方向移動功能，w s a d 移動腳色上下左右，空白改變腳色站立之地板字元，到T上可以增加經驗
			 ESC是離開畫面。同時更新圖版上的資訊。
************************************************************************/

// No change

#include <iostream>
#include <math.h>		// pow() and sqrt()
#include <ctime>		// for time loop function
#include <conio.h>		// _getch() <= to read input without enter "ENTER" key
#include <algorithm>	// for max and min function
#include "Position.h"
#include "Trigger.h"
// Check whether the location is a valid one i.e. not a wall
bool isPositionValid(Position& loc);
// clip algroithm
float clip(float n, float minimun, float maximum);

// Check whether two position is close enough，利用 call-by-referce 將計算得到的方向回傳
bool canSee(Position cPos, Position hPos, Position& pos2);