/************************************************************************
File:        Trigger.h
Author:	     ���s�Aea5878158@gmail.com
Creat Date:  2023-03-31
Modifier:    �௧�N�Acheeryuchi@gmail.com
			 ���Y���Awindyhuang6@gmail.com
			 ���T�t�AJYCReports@gmail.com
			 ���ſ��Atbcey74123@gmail.com
Editor:	     �}�Y���AB11130008@mail.ntust.edu.tw
			 ���R���AB11115037@mail.ntust.edu.tw
Update date: 2023-04-01
Comment:	 �򥻿�J��V���ʥ\��Aw s a d ���ʸ}��W�U���k�A�ťէ��ܸ}�⯸�ߤ��a�O�r���A��T�W�i�H�W�[�g��
			 ESC�O���}�e���C�P�ɧ�s�Ϫ��W����T�C
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

