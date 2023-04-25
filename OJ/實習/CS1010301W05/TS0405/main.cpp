/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-24
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-24
 * Description: Collatz Conjecture
 ************************************************************************/

#include <iostream>
using namespace std;
/**
 * Intent: Calculate the collatz length
 * Pre: the integer number need to be claculated
 * Post: the collatz length
 */
int CalculateCollatzLength(int number);

int main()
{
	int number[2]; //the two input number

	//if reading EOF
	while (cin >> number[0] >> number[1]) {
		int maximumCycleLength = 0; //the max collatz length
		cout << number[0] << " " << number[1] << " ";

		//change the two number let number[0] smaller than number[1]
		if (number[0] > number[1]) {
			int temp = number[0];
			number[0] = number[1];
			number[1] = temp;
		}

		//run the range from number[0] to number[1]
		for (int i = number[0]; i <= number[1]; i++) {
			maximumCycleLength = max(maximumCycleLength, CalculateCollatzLength(i)); //find the max coooatz length 
		}

		cout << maximumCycleLength << endl;
	}
}

int CalculateCollatzLength(int number)
{
	int count = 1; //the collatz length

	//end if number is 1
	while (number != 1) {
		//judge if the number is even or odd
		//if number is even then divide 2, else if number is odd then multiply 3 and plus 1
		if (number % 2 == 0) {
			number /= 2;
		}
		else {
			number = number * 3 + 1;
		}
		count++;
	}
	return count;
}
