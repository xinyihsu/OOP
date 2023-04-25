/*************************************************************************
 * File: Point.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-23
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-23
 * Description: Implement a class named Point to store and manipulate the position of the point on the screen.
 ************************************************************************/
#include "Point.h"

 /**
  * Intent: reset the coordinate position of the point by the given the x and y
  * Pre: the given the x and y
  * Post: nothing
  */
void Point::Set(int vertical, int horizontal)
{
	this->vertical = vertical;
	this->horizontal = horizontal;
}

/**
 * Intent: move the current point x pixels on the x-axis and y pixels on the y-axis.
 * Pre: displacement of X and Y coordinates
 * Post: nothing
 */
void Point::Move(int x, int y)
{
	vertical += x;
	horizontal += y;
}

/**
 * Intent: rotate this point 90 degrees clockwise from the origin.
 * Pre: nothing
 * Post: nothing
 */
void Point::Rotate()
{
	//change the x and y coordinates
	int temp = vertical;
	vertical = horizontal;
	horizontal = temp;
	horizontal = 0 - horizontal; //change the signs of y coordinates
}
