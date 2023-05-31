/*************************************************************************
 * File: Account.cpp
 * Author: xinyiHsu，B11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-31
 * Editor: xinyiHsu，B11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-31
 * Description: The function of Account.h
 *************************************************************************/
#pragma once
#include "Account.h"

 //to get the value of balance
double Account::getBalance(void) { return balance; }

//returns new balance or -1 if error 
double Account::deposit(double amount)
{
	//test if negative
	if (amount > 0) balance += amount;
	else throw NegativeDeposit();

	return balance;
}

//return new balance or -1 if invalid amount 
double Account::withdraw(double amount)
{
	//test if invalid
	if ((amount > balance) || (amount < 0)) throw InsufficientFunds();
	else balance -= amount;

	return balance;
}
