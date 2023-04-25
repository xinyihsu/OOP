/*************************************************************************
 * File: HotDogStand.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-29
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-30
 * Description: Your boss has a hot dog chain in the city, and he needs your help to manage his hot dog stores.
 ************************************************************************/
#include "HotDogStand.h"
#include <iostream>
#include <cstring> //include fuction about string

int HotDogStand::totalSellAmount = 0; //initialize the static integer variable

HotDogStand::HotDogStand()
{
}

/**
 * Intent: Construct a HotDogStand with the given ID and set the sales volume to 0
 * Pre: a char pointer that represent the store id
 * Post: nothing
 */
HotDogStand::HotDogStand(const char* id)
{
	standId = new char(sizeof(id));
	strcpy_s(standId, sizeof(id), id);
	this->hotDogSellAmount = 0;
}

/**
 * Intent: Construct a HotDogStand with the given ID and sales volume
 * Pre: a char pointer that represent the store's id and the store's sales volume(int)
 * Post: nothing
 */
HotDogStand::HotDogStand(const char* id, int amount)
{
	standId = new char(sizeof(id));
	strcpy_s(standId, sizeof(id), id);
	this->hotDogSellAmount = amount;
	this->totalSellAmount += amount;
}

HotDogStand::~HotDogStand()
{
}

/**
 * Intent: Increase the hot dog sales volume by 1
 * Pre: nothing
 * Post: nothing
 */
void HotDogStand::justSold()
{
	this->hotDogSellAmount += 1;
	this->totalSellAmount += 1;
}

/**
 * Intent: print the ID and sales volume of the store separated by spaces
 * Pre: nothing
 * Post: nothing
 */
void HotDogStand::print()
{
	std::cout << this->standId << " " << this->hotDogSellAmount << std::endl;
}

/**
 * Intent: return the sales volume of the store
 * Pre: nothing
 * Post: an integer number
 */
int HotDogStand::thisStandSoldAmount()
{
	return this->hotDogSellAmount;
}

/**
 * Intent: return the total sales volume of all stores
 * Pre: nothing
 * Post: a stactic integer number
 */
int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
