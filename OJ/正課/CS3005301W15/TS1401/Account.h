/*************************************************************************
 * File: Account.h
 * Author: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-31
 * Editor: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-31
 * Description: A function that returns a special error code is usually accomplished by throwing an exception.
 *				Rewrite the class so that it throws appropriate exceptions instead of returning -1 as an error code.
 *************************************************************************/
#pragma once
#include "InsufficientFunds.h"
#include "NegativeDeposit.h"

class Account
{
private:
	double balance;
public:
	Account() { balance = 0; }
	Account(double initialDeposit) { balance = initialDeposit; }

	double getBalance(void);
	double deposit(double);
	double withdraw(double);
};
