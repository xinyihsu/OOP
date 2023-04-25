/*************************************************************************
 * File: Point.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-03
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-05
 * Description: Write a definition of a class named Point that might be used to store and manipulate the location of a point in the plane.
 *************************************************************************/
#include <iostream>
#include "Point.h"

 //constructor
Point::Point()
{
}

/**
 * Intent: a copy constructor used to copy value of other point
 * Pre: a Point object
 */
Point::Point(Point& point)
{
	this->coordinate[0] = point.GetHorizontal();
	this->coordinate[1] = point.GetVertical();
}

//destructor
//to release memory before the instance of class destroyed.
Point::~Point()
{
}

/**
 * Intent: A member function Set that sets the private data after an object of this class is created.
 * Pre: two float that represent the point coordinate
 * Post: void
 */
void Point::Set(float x, float y)
{
	this->coordinate[0] = x;
	this->coordinate[1] = y;
}

/**
 * Intent: A member function Move to move the point along the horizontal and vertical directions specified by the first and second arguments.
 * Pre: two float that represent the unit to move
 * Post: void
 */
void Point::Move(float x, float y)
{
	this->coordinate[0] += x;
	this->coordinate[1] += y;
}

/**
 * Intent: A member function Rotate to rotate the point by 90 degrees clockwise around the origin.
 * Pre: void
 * Post: void
 */
void Point::Rotate(void)
{
	float temp;
	temp = this->coordinate[0];
	this->coordinate[0] = this->coordinate[1];
	this->coordinate[1] = 0 - temp;
}

/**
 * Intent: A member function Reflect to reflect point in the origin.
 * Pre: void
 * Post: void
 */
void Point::Reflect(void)
{
	this->coordinate[0] = 0 - this->coordinate[0];
	this->coordinate[1] = 0 - this->coordinate[1];
}

/**
 * Intent: A const getter functions to retrieve the horizontal of the point.
 * Pre: void
 * Post: return the coordinate of x
 */
float Point::GetHorizontal(void) const
{
	return this->coordinate[0];
}

/**
 * Intent: A const getter functions to retrieve the vertical of the point.
 * Pre: void
 * Post: return the coordinate of y
 */
float Point::GetVertical(void) const
{
	return this->coordinate[1];
}