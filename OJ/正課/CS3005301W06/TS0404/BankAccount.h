/*************************************************************************
 * File: BankAccount.h
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-29
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-30
 * Description: Define a class named BankAccount to simulate bank deposits.
 ************************************************************************/

class BankAccount {
private:
	int balance; //store the money amount of this account
	static int total; //store the total money amount of all accounts in the bank
public:
	BankAccount();
	BankAccount(int input);
	void withdraw(int output);
	void save(int input);
	int getBalance();
	static int getAllMoneyInBank();
};

int BankAccount::total = 0; //initialize the static variable total

/**
 * Intent:construct a BankAccount where the balance is 0
 * Pre: nothing
 * Post:nothing
 */
BankAccount::BankAccount()
{
	this->balance = 0;
}

/**
 * Intent: construct a BankAccount where the balance is input
 * Pre: an integer veriable input
 * Post: nothing
 */
BankAccount::BankAccount(int input)
{
	this->balance = input;
	this->total += input;
}

/**
 * Intent: withdraw money in the bank with the value of output
 * Pre: an integer veriable output
 * Post: nothing
 */
void BankAccount::withdraw(int output)
{
	this->balance -= output;
	this->total -= output;
}

/**
 * Intent: save money in the bank with the value of input
 * Pre: an integer veriable input
 * Post: nothing
 */
void BankAccount::save(int input)
{
	this->balance += input;
	this->total += input;
}

/**
 * Intent: return the current balance of this account
 * Pre: nothing
 * Post: the integer balance
 */
int BankAccount::getBalance()
{
	return this->balance;
}

/**
 * Intent: return the value of the total money amount in the bank
 * Pre: nothing
 * Post: the static integer total
 */
int BankAccount::getAllMoneyInBank()
{
	return total;
}

