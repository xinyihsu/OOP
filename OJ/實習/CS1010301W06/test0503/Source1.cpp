/*************************************************************
 * File : Source.cpp
 * Author : ªL´ð®x¡AB11130037@mail.ntust.edu.tw
 * Creator Date : 2023-04-05
 * Editor : ªL´ð®x¡AB11130037@mail.ntust.edu.tw
 * Update Date : 2023-04-05
 * Description : Write a program that records at most 10 student data by structures.
 *				 There are four functions for user to use: (1) insert (up to 10 records), (2) search, (3) delete, (4) print.
 ************************************************************/
#include<iostream>
#include<string>//for basic string function
#include<sstream>//for istringstream function

using namespace std;

//a student struct to store name and phpine number
typedef struct
{
	char firstName[25];
	char lastName[30];
	char phone[15];
}Student;

//MAX_RECORDS as a const integer to limit to number of studentRecords under 10
const int MAX_RECORDS = 10;
//studentRecord as a struct to store input
Student studentRecords[MAX_RECORDS];
//numRecords as a integer to store how many student records now we input
int numRecords = 0;

//declare the fuction
void insertRecord(string firstName, string lastName, string phone);
//declare the fuction
void deleteRecord(string firstName, string lastName, string phone);
//declare the fuction
void searchRecord(string firstName, string lastName, string phone);
//declare the fuction
void printRecord();

// Intent : to find if input phone is number
// Pre : input string phone
// Post : if it is, return true, if not, return false
// param phone
bool isValidPhoneNumber(string& phone)
{
	//find all char in string phone and check them one by one
	for (char c : phone)
	{
		if (!isdigit(c))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	//input as a string to stire input lines
	string input;

	//getlilne till eof
	while (getline(cin, input))
	{
		//found as a size_t to find if there's a space inside string input
		size_t found = input.find(' ');

		//if there's a space in string input
		if (found != string::npos)
		{
			//isString as a istringstream, use space to cut them 
			istringstream isString(input);
			//command, fisrtName, lastName, phone as string to store input information
			string command, firstName, lastName, phone;
			//use the isString to put input in these string
			isString >> command >> firstName >> lastName >> phone;

			//accord command to use several functions, if ther's no command fits the call, output Input Error
			if (command == "insert")
			{
				insertRecord(firstName, lastName, phone);
			}
			else if (command == "delete")
			{
				deleteRecord(firstName, lastName, phone);
			}
			else if (command == "search")
			{
				searchRecord(firstName, lastName, phone);
			}
			else
			{
				cout << "Input Error" << endl;
			}
		}
		//if there's no space in string input, it has to be command print
		else
		{
			if (input == "print")
			{
				printRecord();
			}
		}
	}
}

void insertRecord(string firstName, string lastName, string phone)
{
	//check if insert is ok
	if (firstName.length() > 25 || lastName.length() > 30 || phone.length() > 15)
	{
		cout << "Input Error" << endl;
		return;
	}

	//check if phone number is number 
	if (isValidPhoneNumber(phone) == false)
	{
		cout << "Input Error" << endl;
		return;
	}

	//check if insert is already exists
	for (int i = 0; i < numRecords; i++)
	{
		if (strcmp(studentRecords[i].firstName, firstName.c_str()) == 0 &&
			strcmp(studentRecords[i].lastName, lastName.c_str()) == 0 &&
			strcmp(studentRecords[i].phone, phone.c_str()) == 0)
		{
			cout << "Insert Error" << endl;
			return;
		}
	}

	//check if number of records over 10
	if (numRecords >= MAX_RECORDS)
	{
		cout << "Insert Error" << endl;
		return;
	}

	//insert record
	strcpy_s(studentRecords[numRecords].firstName, sizeof(studentRecords[numRecords].firstName), firstName.c_str());
	strcpy_s(studentRecords[numRecords].lastName, sizeof(studentRecords[numRecords].lastName), lastName.c_str());
	strcpy_s(studentRecords[numRecords].phone, sizeof(studentRecords[numRecords].phone), phone.c_str());
	numRecords++;
}

// Intent : to delete the student information in struct studentRecords
// Pre : input string firstName and lastName and phone
// Post : if the input three string which length is over their limit, output Input Error
//		  if the input string phone has a digit that not a number, output Input Error
//		  if the input exists, delete it, or output Delete Error		 
// param firstName
// param lastName
// param phone
void deleteRecord(string firstName, string lastName, string phone)
{
	//check if insert is ok
	if (firstName.length() > 25 || lastName.length() > 30 || phone.length() > 15)
	{
		cout << "Input Error" << endl;
		return;
	}

	//check if phone number is number 
	if (isValidPhoneNumber(phone) == false)
	{
		cout << "Input Error" << endl;
		return;
	}

	for (int i = 0; i < numRecords; i++)
	{
		if (strcmp(studentRecords[i].firstName, firstName.c_str()) == 0 &&
			strcmp(studentRecords[i].lastName, lastName.c_str()) == 0 &&
			strcmp(studentRecords[i].phone, phone.c_str()) == 0)
		{
			for (int j = i; j < numRecords - 1; j++)
			{
				studentRecords[j] = studentRecords[j + 1];
			}
			numRecords--;
			return;
		}
	}
	cout << "Delete Error" << endl;
}

// Intent : to search the student information in struct studentRecords
// Pre : input string firstName and lastName and phone
// Post : if the input three string which length is over their limit, output Input Error
//		  if the input string phone has a digit that not a number, output Input Error
//		  if there's a student information fit the input three string, output the index
//		  if there's no the student information fit the input, output Search Error
// param firstName
// param lastName
// param phone
void searchRecord(string firstName, string lastName, string phone)
{
	//check if insert is ok
	if (firstName.length() > 25 || lastName.length() > 30 || phone.length() > 15)
	{
		cout << "Input Error" << endl;
		return;
	}

	//check if phone number is number 
	if (isValidPhoneNumber(phone) == false)
	{
		cout << "Input Error" << endl;
		return;
	}

	for (int i = 0; i < numRecords; i++)
	{
		if (strcmp(studentRecords[i].firstName, firstName.c_str()) == 0 &&
			strcmp(studentRecords[i].lastName, lastName.c_str()) == 0 &&
			strcmp(studentRecords[i].phone, phone.c_str()) == 0)
		{
			cout << i << endl;
			return;
		}
	}
	cout << "Search Error" << endl;
}

// Intent : to print out all student information we store in struct studentRecords
// Pre : no need to input anything
// Post : if there's no iniformation in struct studrntRecords, output Print Error
//		  if there have information in struct studentRecords, output them
void printRecord()
{
	if (numRecords == 0)
	{
		cout << "Print Error" << endl;
		return;
	}
	for (int i = 0; i < numRecords; i++)
	{
		cout << studentRecords[i].firstName << " " << studentRecords[i].lastName << " " << studentRecords[i].phone << endl;
	}
}


