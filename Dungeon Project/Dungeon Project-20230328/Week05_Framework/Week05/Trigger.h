/************************************************************************
File:        Trigger.h
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

#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"


//************************************************************
// Trigger Class
//************************************************************
class Trigger {
	// Implement Trigger Class
	/*Please implement your code here*/
private:
	Position sPos; // Trigger location
	int expAmount; // Trigger exp amount
	char sIcon = 'T'; // Trigger icon

public:
	//initialize the position and expAmount of this class (constructure)
	Trigger(int x, int y, int expAmount) {
		sPos.x = x;
		sPos.y = y;
		this->expAmount = expAmount;
	}

	// Get position
	Position getPos(void) {
		return this->sPos;
	}

	// Get Icon
	char getIcon(void) {
		return this->sIcon;
	}

	// Get exp amount
	int getExpAmount(void) {
		return this->expAmount;
	}

	// class creature's update
	void update(Hero& hero) {
		Position heroPos = hero.getPos();
		// If Trigger and hero are in the same location
		if (heroPos.x == this->sPos.x && heroPos.y == this->sPos.y) {
			hero.gainEXP(this->expAmount); // add exp amount into hero.gainEXP
		}
	}
	/************************************************************************/
};

