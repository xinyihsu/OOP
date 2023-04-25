/*************************************************************************
 * File: Position.h
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
		   ²øÀR¶²¡AB11115037@mail.ntust.edu.tw
 * Create Date: 2023-04-25
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
		   ²øÀR¶²¡AB11115037@mail.ntust.edu.tw
 * Update Date: 2023-04-25
 * Description: Write a class to calculate position (operator overloading)
 *************************************************************************/
#pragma once
//************************************************************
// The location in the board
//************************************************************
class Position {
public:
	int x, y; // X, y Coordinate

	Position() : x(0), y(0) {}
	Position(int x, int y) : x(x), y(y) {}
	Position(const Position& ref) { *this = ref; }

	// Operator overloading
	/*Please implement your code here*/
	const Position operator +(const Position&);
	Position operator +=(const Position&);
	const Position operator -(const Position&);
	Position operator -=(const Position&);
	const Position operator *(const int&);
	bool operator ==(const Position&) const;
	bool operator!=(const Position&);
	/************************************************************************/
};

/**
 * Intent: add two position
 * Pre: a position to be add
 * Post: a position after add
 */
const Position Position::operator +(const Position& other)
{
	int ansX = this->x + other.x;
	int ansY = this->y + other.y;
	return Position(ansX, ansY);
}

/**
 * Intent: add a position into itself
 * Pre: a position to be add
 * Post: a position after add
 */
Position Position::operator +=(const Position& other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

/**
 * Intent: sub two position
 * Pre: a position to be sub
 * Post: a position after sub
 */
const Position Position::operator -(const Position& other)
{
	int ansX = this->x - other.x;
	int ansY = this->y - other.y;
	return Position(ansX, ansY);
}

/**
 * Intent: sub a position into itself
 * Pre: a position to be sub
 * Post: a position after sub
 */
Position Position::operator -=(const Position& other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

/**
 * Intent: multiply a position by an integer
 * Pre: an integer (to multiply the position)
 * Post: a position after multiply
 */
const Position Position::operator *(const int& num)
{
	int ansX = this->x * num;
	int ansY = this->y * num;
	return Position(ansX, ansY);
}

/**
 * Intent: judge if two position are the same
 * Pre: a position (to compare with the position)
 * Post: bool
 */
bool Position::operator ==(const Position& other) const
{
	if (this->x != other.x) {
		return false;
	}
	if (this->y != other.y) {
		return false;
	}
	return true;
}

/**
 * Intent: judge if two position are different
 * Pre: a position (to compare with the position)
 * Post: bool
 */
bool Position::operator!=(const Position& other)
{
	if (this->x == other.x) {
		return false;
	}
	if (this->y == other.y) {
		return false;
	}
	return true;
}
