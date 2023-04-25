/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-30
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-05
 * Description: Write a program that records at most 10 student data by structures.
 *				There are four functions for user to use:
 *				(1)insert (up to 10 records), (2)search, (3) delete, (4) print.
 ************************************************************************/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctype.h>
#define MAX_VALUE 100
using namespace std;

typedef struct
{
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

bool testIfValid(StRec& data);

int main()
{
	string command;
	StRec studentData[10];
	int studentNumber = 0;
	while (cin >> command) {
		if (command == "print") {
			if (studentNumber == 0) {
				cout << "Print Error" << endl;
			}
			else {
				for (int i = 0; i < studentNumber; i++) {
					cout << studentData[i].firstName << " " << studentData[i].lastName << " " << studentData[i].phone << endl;
				}
			}
		}
		else {
			StRec data;
			//data.firstName = { '\0' };
			//cin >> data.firstName >> data.lastName >> data.phone;
			//if (testIfValid(data)) {
			bool ifExist = false;
			int index;
			if (command == "insert") {
				studentNumber++;
				if (studentNumber > 10) {
					cout << "Insert Error" << endl;
					studentNumber--;
				}
				else if (!testIfValid(data)) {
					cout << "Input Error" << endl;
				}
				else {
					for (index = 0; index < studentNumber; index++) {
						if (strcmp(studentData[index].firstName, data.firstName) == 0 && strcmp(studentData[index].lastName, data.lastName) == 0 && strcmp(studentData[index].phone, data.phone) == 0) {
							ifExist = true;
							break;
						}
					}
					if (ifExist == true) {
						cout << "Insert Error" << endl;
						studentNumber--;
					}
					else {
						studentData[studentNumber - 1] = data;
						//cout << studentNumber << endl;
					}
				}
			}
			else {
				if (!testIfValid(data)) {
					cout << "Input Error" << endl;
				}
				else {
					for (index = 0; index < studentNumber; index++) {
						if (strcmp(studentData[index].firstName, data.firstName) == 0 && strcmp(studentData[index].lastName, data.lastName) == 0 && strcmp(studentData[index].phone, data.phone) == 0) {
							ifExist = true;
							break;
						}
					}
					if (command == "delete") {
						if (ifExist == true) {
							for (int i = index; i < studentNumber - 1; i++) {
								studentData[i] = studentData[i + 1];
							}
							studentNumber--;
						}
						else {
							cout << "Delete Error" << endl;
						}
					}
					else if (command == "search") {
						if (ifExist == true) {
							cout << index << endl;
						}
						else {
							cout << "Search Error" << endl;
						}
					}
					else {
						cout << "Input Error" << endl;
					}
				}
			}
			//}
			/*else {
				cout << "Input Error" << endl;
			}*/
		}
	}
}
bool testIfValid(StRec& data)
{
	string number = { "\0" };
	bool isNumber = true;
	cin >> number;
	if (number.length() <= 25) {
		strcpy_s(data.firstName, number.c_str());
		cin >> number;
		if (number.length() <= 30) {
			strcpy_s(data.lastName, number.c_str());
			cin >> number;
			if (number.length() <= 15) {
				strcpy_s(data.phone, number.c_str());
				for (int i = 0; i < strlen(data.phone); i++) {
					if (!isdigit(data.phone[i])) {
						isNumber = false;
					}
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	if (isNumber) {
		return true;
	}
	else {
		return false;
	}
}
