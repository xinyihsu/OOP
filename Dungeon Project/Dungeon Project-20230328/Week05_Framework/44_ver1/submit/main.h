/************************************************************************
File:        main.h
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

// Check whether two position is close enough�A�Q�� call-by-referce �N�p��o�쪺��V�^��
bool canSee(Position cPos, Position hPos, Position& pos2);