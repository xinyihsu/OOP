/*************************************************************************
 * File: Atoi.h
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-14
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-16
 * Description: Write a class that can convert a string into an integer.
 *************************************************************************/
#pragma once
#include <string>
using namespace std;

class Atoi {

private:
	string beTrans;
	bool isNegative; //if the input number is negative (*add by me)

public:
	Atoi();
	Atoi(string s);
	void SetString(string s);
	const string GetString(void);
	int Length(void);
	bool IsDigital(void);
	int StringToInteger(void);
	void ifNegative(void); //judge if the input number is negative (*add by me)
};

/**
 * Intent: construct a class Atoi where beTran is ""
 * Pre: void
 */
Atoi::Atoi()
{
	isNegative = false;
}

/**
 * Intent: construct a class Atoi where beTran is s
 * Pre: an input string
 */
Atoi::Atoi(string s)
{
	this->beTrans = s;
	ifNegative(); //judge if the string is negative
}

/**
 * Intent: set beTran of this class to s
 * Pre: an input string
 * Post: void
 */
void Atoi::SetString(string s)
{
	this->beTrans = s;
	ifNegative();
}

/**
 * Intent: return beTran of this class
 * Pre: void
 * Post: return the input string as a const string
 */
const string Atoi::GetString(void)
{
	return this->beTrans;
}

/**
 * Intent: calculate the length of input string (ignore the negative number)
 * Pre: void
 * Post: return the length of beTran
 */
int Atoi::Length(void)
{
	//if the number is negative then minus one
	//others directly output
	if (this->isNegative) {
		return this->beTrans.length() - 1;
	}
	else {
		return this->beTrans.length();
	}

}

/**
 * Intent: judge if given string can be transformed into an integer
 * Pre: void
 * Post: return true if it can ,otherwise return false
 */
bool Atoi::IsDigital(void)
{
	int i = 0;

	//judge if all the characters in the string is all digital
	for (char c : this->beTrans) {
		//if the first character is negative sign then skip it
		if (i == 0 && c == '-') {
			continue;
		}
		else if (c < '0' || c > '9') { //judge if it is not an integer
			return false;
		}
		i++;
	}

	return true;
}

/**
 * Intent: convert given string to an integer and return
 * Pre: void
 * Post: return integer be tranformed from string
 */
int Atoi::StringToInteger(void)
{
	int integer = 0; //store the integer transformed from string
	int number = 0; //the each character in the given string
	int i = 0;

	//change the character into integer
	for (char c : this->beTrans) {
		//if the first character is negative sign than skip it
		if (i == 0 && c == '-') {
			continue;
		}

		number = c - '0';
		integer = integer * 10 + number;
		i++;
	}

	//if the integer is negative output negative number
	if (this->isNegative) {
		return 0 - integer;
	}
	else {
		return integer;
	}
}

/**
 * Intent: judge if the input number is negative
 * Pre: void
 * Post: void
 */
void Atoi::ifNegative(void)
{
	//if the first character in string is "-"
	if (this->beTrans[0] == '-') {
		this->isNegative = true;
	}
	else {
		this->isNegative = false;
	}
}
