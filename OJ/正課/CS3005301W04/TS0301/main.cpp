/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-19
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-20
 * Description: Describe what this code is doing primarily in here
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int number; //the input integer
	int countOfNumber[100][2] = { 0 }; //the input number and its apearing times
	int arrayLength = 0; //the length of the array

	//reads a list of numbers
	while (cin >> number) {
		//store the number and count
		countOfNumber[arrayLength][0] = number;
		countOfNumber[arrayLength][1]++;

		//judge if the number is repetition
		for (int i = 0; i < arrayLength; i++) {
			if (number == countOfNumber[i][0]) {
				countOfNumber[i][1]++;
				countOfNumber[arrayLength][1]--;
				arrayLength--;
				break;
			}
		}
		arrayLength++;
	}

	//sort from largest to smallest
	for (int i = 0; i < arrayLength - 1; i++) {
		for (int j = 0; j < arrayLength - i - 1; j++) {
			if (countOfNumber[j][0] < countOfNumber[j + 1][0]) {
				int temp = countOfNumber[j][0];
				countOfNumber[j][0] = countOfNumber[j + 1][0];
				countOfNumber[j + 1][0] = temp;
				temp = countOfNumber[j][1];
				countOfNumber[j][1] = countOfNumber[j + 1][1];
				countOfNumber[j + 1][1] = temp;
			}
		}
	}

	//output the answer
	cout << "N\tcount" << endl;
	for (int i = 0; i < arrayLength; i++) {
		cout << countOfNumber[i][0] << "\t" << countOfNumber[i][1] << endl;
	}
}