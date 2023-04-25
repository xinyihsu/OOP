/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-30
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-06
 * Description: Write a program that records at most 10 student data by structures.
 *				There are four functions for user to use:
 *				(1)insert (up to 10 records), (2)search, (3) delete, (4) print.
 ************************************************************************/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctype.h>
#define MAX_STUDENT 10
using namespace std;

//a struct to store student data
typedef struct
{
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

int studentNumber = 0; //the number of student have stored
StRec studentData[MAX_STUDENT]; //the data of student


void insertDate(StRec& data);
void deleteDate(StRec& data);
void searchDate(StRec& data);
int ifExist(StRec& data);
bool testIfValid(StRec& data);

/**
 * Intent: to insert data into structore
 * Pre: the input student data (firstName, lastName, phone)
 * Post: void
 */
void insertDate(StRec& data)
{
	//if it is not valid
	if (!testIfValid(data)) {
		cout << "Input Error" << endl;
		return;
	}

	int index = ifExist(data);
	//if it is not digit
	if (index != -1) {
		cout << "Insert Error" << endl;
		return;
	}

	//if the student is out of range(10)
	if (studentNumber >= MAX_STUDENT) {
		cout << "Insert Error" << endl;
		return;
	}

	studentNumber++;
	studentData[studentNumber - 1] = data; //copy in studentData
}

/**
 * Intent: to delete data in structure
 * Pre: the input student data (firstName, lastName, phone)
 * Post: void
 */
void deleteDate(StRec& data)
{
	//if it is not valid
	if (!testIfValid(data)) {
		cout << "Input Error" << endl;
		return;
	}

	int index = ifExist(data);
	//if it is in data then delete it
	if (index != -1) {
		//move data forward
		for (int i = index; i < studentNumber - 1; i++) {
			studentData[i] = studentData[i + 1];
		}

		studentNumber--;
		return;
	}
	else {
		cout << "Delete Error" << endl;
	}
}

/**
 * Intent: to search data in structure
 * Pre: the input student data (firstName, lastName, phone)
 * Post: void
 */
void searchDate(StRec& data)
{
	//if it is not valid
	if (!testIfValid(data)) {
		cout << "Input Error" << endl;
		return;
	}

	int index = ifExist(data);
	//if it is in data then output the index
	if (index != -1) {
		cout << index << endl;
		return;
	}
	else {
		cout << "Search Error" << endl;
	}
}

/**
 * Intent: to test if data is exist
 * Pre: the input student data (firstName, lastName, phone)
 * Post: if data exist return index others return -1
 */
int ifExist(StRec& data)
{
	//judge if the deta exist
	for (int index = 0; index < studentNumber; index++) {
		if (strcmp(studentData[index].firstName, data.firstName) == 0 && strcmp(studentData[index].lastName, data.lastName) == 0 && strcmp(studentData[index].phone, data.phone) == 0) {
			return index;
		}
	}

	//the deta is not exist
	return -1;
}

/**
 * Intent: to test if data is valid (the length and if the phone number is digit)
 * Pre: the input student data (firstName, lastName, phone)
 * Post: if data valid return true others return false
 */
bool testIfValid(StRec& data)
{
	string  firstName, lastName, phone; //the three information we need
	cin >> firstName >> lastName >> phone;

	//if the three information is out of its length
	if (firstName.length() > 25 || lastName.length() > 30 || phone.length() > 15) {
		return false;
	}

	//if it is digit
	for (char c : phone) {
		if (!isdigit(c)) {
			return false;
		}
	}

	//copy the information into data
	strcpy_s(data.firstName, sizeof(data.firstName), firstName.c_str());
	strcpy_s(data.lastName, sizeof(data.lastName), lastName.c_str());
	strcpy_s(data.phone, sizeof(data.phone), phone.c_str());
	return true;
}

int main()
{
	string command; //the command type

	//end if reading EOF
	while (cin >> command) {
		//if command type is print
		if (command == "print") {
			//if there are no student data print error 
			if (studentNumber == 0) {
				cout << "Print Error" << endl;
			}
			else {
				//output the student data
				for (int i = 0; i < studentNumber; i++) {
					cout << studentData[i].firstName << " " << studentData[i].lastName << " " << studentData[i].phone << endl;
				}
			}
		}
		else {
			StRec data; //the data we need to implement (insert, delete, or search)

			//judge the command type
			if (command == "insert")
			{
				insertDate(data); //call insertDate function
			}
			else if (command == "delete")
			{
				deleteDate(data); //call deleteDate function
			}
			else if (command == "search")
			{
				searchDate(data); //call searchDate function
			}
			else
			{
				cout << "Input Error" << endl;
			}
		}
	}
}

