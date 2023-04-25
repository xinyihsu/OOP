/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-21
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-22
 * Description: CPU bit growth (find N, that N! is within the CPU calculation range of the current year.)
 ************************************************************************/

#include <iostream>
#include <cmath>
#define ORIGIN 1900
using namespace std;

int main()
{
	int  year; //the year that input
	double largestInteger; //the CPU calculation range of the current year
	double bit = 0; //the bit of CPU
	while (cin >> year) {
		double sum; //the amount of N!
		int N = 0;
		bit = 4 * pow(2, ((year - ORIGIN) / 10));

		//if the number is bigint
		if (year <= 1950) {
			sum = 1;
			largestInteger = pow(2, bit) - 1;

			//find the largest N
			while (sum <= largestInteger) {
				N++;
				sum *= N;
			}
		}
		else {
			//N! < 2^bit - 1 => N! < 2^bit => log(N!) = log(1) + log(2) +...+ log(N) < log(2^bit) = bit * log(2)
			sum = 0;
			largestInteger = bit * log(2);

			//find the largest N
			while (sum <= largestInteger) {
				N++;
				sum += log(N);
			}
		}
		N--;
		cout << N << endl;
	}
}