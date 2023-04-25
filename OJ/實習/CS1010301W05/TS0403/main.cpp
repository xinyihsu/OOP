/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-23
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-24
 * Description: Calculate the greatest common divisor
 ************************************************************************/

#include <iostream>
using namespace std;

/**
 * Intent: Calculate the greatest common divisor
 * Pre: two integer number
 * Post: the greatest common divisor
 */
int GCD(int numberA, int numberB);

int main()
{
	int numberA, numberB; //input two integer

	//end if reading EOF
	while (cin >> numberA) {
		cin >> numberB;
		cout << GCD(numberA, numberB) << endl;
	}
}


int GCD(int numberA, int numberB)
{
	//change the order let the numberA be the smaller
	if (numberB < numberA) {
		int temp = numberA;
		numberA = numberB;
		numberB = temp;
	}

	//if the number A and B can be divisable by i with no remain then i is the greatest common divisor 
	for (int i = numberA; i > 0; i--) {
		if (numberA % i == 0 && numberB % i == 0) {
			return i;
		}
	}
	return 1; //the greatest common divisor of the number A and B is 1
}
