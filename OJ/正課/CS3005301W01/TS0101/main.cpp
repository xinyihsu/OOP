// Name: ®}ªY»ö
// Date: February 24, 2023
// Last Update: February 24, 2023
// Problem statement: Compute the square root.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double number, guess, r, newGuess;

	//Stop until read an EOF.
	while (cin >> number) {
		guess = number / 2;
		r = number / guess;
		newGuess = (guess + r) / 2;

		//Stop until the guss differ less than 0.01
		while (guess - newGuess >= 0.01)
		{
			guess = newGuess;
			r = number / guess;
			newGuess = (guess + r) / 2;
		}

		cout << fixed << setprecision(2) << newGuess << endl;
	}
	
}