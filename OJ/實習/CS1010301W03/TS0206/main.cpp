// Name: ®}ªY»ö
// Date: March 11, 2023
// Last Update: March 11, 2023
// Problem statement: Input the income, and compute the tax.

#include <iostream>
#include <iomanip> //include the setprecision function.
using namespace std;

int main()
{
	float income;

	//end the program if the input is EOF.
	while (cin >> income)
	{
		//judge the income range.
		if (income <= 750)
		{
			cout << fixed << setprecision(2) << income * 0.01 <<endl;
		}
		else if (income <= 2250)
		{
			cout << fixed << setprecision(2) << (income - 750) * 0.02 + 7.5 << endl;
		}
		else if (income <= 3750)
		{
			cout << fixed << setprecision(2) << (income - 2250) * 0.03 + 37.5 << endl;
		}
		else if (income <= 5250)
		{
			cout << fixed << setprecision(2) << (income - 3750) * 0.04 + 82.5 << endl;
		}
		else if (income <= 7000)
		{
			cout << fixed << setprecision(2) << (income - 5250) * 0.05 + 142.5 << endl;
		}
		else
		{
			cout << fixed << setprecision(2) << (income - 7000) * 0.06 + 230 << endl;
		}
	}
}