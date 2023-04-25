/*************************************************************************
 * File: Month.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-01
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-03
 * Description: Define a class named Month to display the formatted month.
 ************************************************************************/

#include "Month.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Intent: Construct a Month class that defaults to January
 * Pre: void
 */
Month::Month()
{
	this->month = 1;
}

/**
 * Intent: Use the given abbreviation to construct the Month class, the parameters represent each letter of the abbreviation
 * Pre: three char that is the abbreviation of this month
 */
Month::Month(char first, char second, char third)
{
	bool isValid = false; //if the month is valid
	string months[12] = { "Jan", "Feb", "Mar","Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" }; //the abbreviation of each month
	string thisMonth = ""; //the abbreviation of this month
	thisMonth += first;
	thisMonth += second;
	thisMonth += third;

	//judge the int type of this month
	for (int i = 0; i < 12; i++) {
		if (thisMonth == months[i]) {
			this->month = i + 1;
			isValid = true;
			break;
		}
	}

	//if it is invalid set this month to one
	if (isValid == false) {
		this->month = 1;
	}
}

/**
 * Intent: Construct a Month class with the value of¡§monthInt¡¨.
 *		   If the given value is invalid, please set the month to January
 * Pre: an integer number that represent the month
 */
Month::Month(int monthInt)
{
	//if the month is out of range then set the value to one
	if (monthInt < 1 || monthInt > 12) {
		this->month = 1;
	}
	else {
		this->month = monthInt;
	}
}

Month::~Month()
{
}

/**
 * Intent: Read an int x, and modify the current month to x.
 *		   If x is invalid (x < 1 or x > 12), please set the month value to 1
 * Pre: void
 * Post: void
 */
void Month::inputInt()
{
	int thisMonth;
	cin >> thisMonth;

	//if the month is out of range then set the value to one
	if (thisMonth < 1 || thisMonth >12) {
		this->month = 1;
	}
	else {
		this->month = thisMonth;
	}
}

/**
 * Intent: Read three letters a, b and c (these letters represent each letter of the abbreviation of a month)
 *		   Modify the letters to the corresponding month value. If the input is invalid, set the month value to 1
 * Pre: void
 * Post: void
 */
void Month::inputStr()
{
	bool isValid = false; //if the month is valid
	string months[12] = { "Jan", "Feb", "Mar","Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" }; //the abbreviation of each month
	string thisMonth = ""; //the abbreviation of this month
	char num; //the char that input

	//store the input char into the variable (thisMonth)
	for (int i = 0; i < 3; i++) {
		cin >> num;
		thisMonth += num;
	}

	//judge the int type of this month
	for (int i = 1; i <= 12; i++) {
		if (thisMonth == months[i]) {
			this->month = i + 1;
			isValid = true;
			break;
		}
	}

	//if it is invalid set this month to one
	if (isValid == false) {
		this->month = 1;
	}
}

/**
 * Intent: Print the month value
 * Pre: void
 * Post: void
 */
void Month::outputInt()
{
	cout << this->month;
}

/**
 * Intent: Print the abbreviation of the month
 * Pre: void
 * Post: void
 */
void Month::outputStr()
{
	string months[13] = { "\0", "Jan", "Feb", "Mar","Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" }; //the abbreviation of each month
	cout << months[this->month];
}

/**
 * Intent: Increment month value
 * Pre: void
 * Post: a Month type variable
 */
Month Month::nextMonth()
{
	Month next; //the next month 
	next.month = this->month + 1;

	//if the value of next month is out of range then set the value to one
	if (next.month < 1 || next.month >12) {
		next.month = 1;
	}

	return next;
}
