/*************************************************************************
 * File: PrimeNumber.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-29
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-01
 * Description: Define a class named PrimeNumber that stores a prime number
 *************************************************************************/
#include "PrimeNumber.h"

 /**
  * Intent: construct a PrimeNumber where the value is 1
  * Pre: void
  */
PrimeNumber::PrimeNumber(void)
{
	this->value = 1;
}

/**
 * Intent: construct a PrimeNumber where the value is _value
 * Pre: an integer
 */
PrimeNumber::PrimeNumber(int _value)
{
	this->value = _value;
}

/**
 * Intent: return the value of this PrimeNumber
 * Pre: void
 * Post: the integer (PrimeNumber)
 */
int PrimeNumber::get(void)
{
	return this->value;
}

/**
 * Intent: return the next larger prime number (++x)
 * Pre: void
 * Post: a PrimeNumber
 */
PrimeNumber& PrimeNumber::operator++(void)
{
	this->value++;

	//find the first larger prime number
	while (!testIfPrimeNumber(this->value)) {
		this->value++;
	}

	return (*this);
}

/**
 * Intent: return the PrimeNumber and find the next larger prime number (x++)
 * Pre: an integer (not importent)
 * Post: a PrimeNumber
 */
PrimeNumber PrimeNumber::operator++(int)
{
	PrimeNumber temp = (*this);
	this->value++;

	//find the first larger prime number
	while (!testIfPrimeNumber(this->value)) {
		this->value++;
	}

	return temp;
}

/**
 * Intent: return the next smaller prime number (--x)
 * Pre: void
 * Post: a PrimeNumber
 */
PrimeNumber& PrimeNumber::operator--(void)
{
	this->value--;

	//find the first smaller prime number
	while (!testIfPrimeNumber(this->value)) {
		this->value--;
	}

	return (*this);
}

/**
 * Intent: return the PrimeNumber and find the next smaller prime number (x--)
 * Pre: an integer (not importent)
 * Post: a PrimeNumber
 */
PrimeNumber PrimeNumber::operator--(int)
{
	PrimeNumber temp = (*this);
	this->value--;

	//find the first smaller prime number
	while (!testIfPrimeNumber(this->value)) {
		this->value--;
	}

	return temp;
}

/**
 * Intent: to test if the number is prime
 * Pre: an integer number
 * Post: bool
 */
bool testIfPrimeNumber(int num)
{
	//test if the number is a prime number
	for (int i = num - 1; i > 1; i--) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}
