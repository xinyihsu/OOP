/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-18
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-19
 * Description: Cow numbers make use of four symbols: V U C and D.
 *				And there are four possible operations, represented by the symbols A, R, L, and N.
 *				After the operations have been performed on Num1 and Num2 the final value of Num2 is hopefully the value marked on the sixth line of the tablet.
 *************************************************************************/
#include <iostream>
#include <string>
#define MAX_VALUE 100
using namespace std;

int change(char temp[]);

int main()
{
	int runTimes; //describing how many tablets are represented
	cin >> runTimes;
	cout << "COWCULATIONS OUTPUT" << endl;

	//deal with the tables as run times
	for (int i = 0; i < runTimes; i++) {
		int cow1, cow2, cow3; //the value of two input table and the table will be compared
		char temp[MAX_VALUE] = { '\0' }; //the temp variable to store a series of symbols
		char operation; //the operation to calculate 

		cin >> temp;
		cow1 = change(temp);
		cin >> temp;
		cow2 = change(temp);

		//implement operation three times
		for (int j = 0; j < 3; j++) {
			cin >> operation;

			//judge the operation and execute correspondent actions
			switch (operation) {
			case 'A': //add two number
				cow2 += cow1;
				break;
			case 'R': //move right
				cow2 >>= 2;
				break;
			case 'L': //move left
				cow2 <<= 2;
				break;
			}
		}

		cin >> temp;
		cow3 = change(temp);

		//if the two number are the same
		if (cow2 == cow3) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	cout << "END OF OUTPUT" << endl;
}

/**
 * Intent: change a series of symbols into the value
 * Pre: the temp array storing the symbols
 * Post: the value
 */
int change(char temp[])
{
	//V : 00 = 0
	//U : 01 = 1
	//C : 10 = 2
	//D : 11 = 3
	int cow = 0;

	//change the each symbols
	for (int i = 0; i < MAX_VALUE; i++) {
		//judge the symbols
		//if the end have one more symbol
		switch (temp[i]) {
		case 'V': //enlarge (ex. 01 -> 01 00 : 1 -> 4)
			cow = cow * 4;
			break;
		case 'U': //enlarge and add 1
			cow = cow * 4 + 1;
			break;
		case 'C': //enlarge and add 2
			cow = cow * 4 + 2;
			break;
		case 'D': //enlarge and add 3
			cow = cow * 4 + 3;
			break;
		}
	}

	return cow;
}
