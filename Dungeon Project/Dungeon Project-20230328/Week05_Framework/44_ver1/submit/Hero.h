/************************************************************************
File:        Hero.h
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
#include "Position.h"
#include "main.h"
//************************************************************
// Hero Class, only has requirement part for example
//************************************************************

class Hero {

private:
	Position	sPos;			// Hero location
	char sIcon = 'H';	// Hero icon
	int			hp;
	int			sLevel = 1;     // Level
	int			sMaxExp;		// Level update experience
	int			sCurrentExp;	// current exp hero has

public:
	// Default constructor
	Hero() {
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sLevel = 1;
		this->sCurrentExp = 0;
		this->sMaxExp = 15;
		this->sIcon = 'H';
		this->hp = 100;
	};
	// Setting constructor
	Hero(int x, int y, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100) {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sLevel = level;
		this->sCurrentExp = currentExp;
		this->sMaxExp = maxExp;
		this->sIcon = icon;
		this->hp = hp;
	};

	// Setting constructor
	Hero(Position& pos, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100) {
		this->sPos = pos;
		this->sLevel = level;
		this->sCurrentExp = currentExp;
		this->sMaxExp = maxExp;
		this->sIcon = icon;
		this->hp = hp;
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Set level
	void setLevel(int level) { this->sLevel = level; }

	// Set exp
	void setExp(int exp) { this->sCurrentExp = exp; }

	// Set MaxExp
	void SetMaxExp(int maxexp) { this->sMaxExp = maxexp; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Get level
	int getLevel(void) { return this->sLevel; }

	// Get Exp
	int getExp(void) { return this->sCurrentExp; }

	// Get Max
	int getMaxExp(void) { return this->sMaxExp; }

	int getHP() const { return this->hp; }

	// Incrementally move the elements 
	void move(int x, int y) {
		// Compute the next position
		Position next;
		next.x = this->sPos.x + x;
		next.y = this->sPos.y + y;

		if (isPositionValid(next))
			this->sPos = next;
		else {
			std::cout << "Invalid location\n";
		}
	}

	// Calculate Gain of EXP
	void gainEXP(int points) {
		// Implement Gain of EXP
		/*Please implement your code here*/
		this->sCurrentExp += points; // add points(exp)

		while (this->sCurrentExp >= 15) { // greater than upgrade points
			this->sCurrentExp -= this->sMaxExp; // Recalculate (minus exp)
			this->sLevel++; // upgrade
		}
		/************************************************************************/
	}

	//when hero meet the creature 
	void damage(int points) {
		// Implement Damage done to Hero
		/*Please implement your code here*/
		this->hp -= points; // Minus points(hp)
		/************************************************************************/
	}
};