// Name: ®}ªY»ö
// Date: February 23, 2023
// Last Update: February 24, 2023
// Problem statement: Convert the format of "seconds" to "hours: minutes: seconds".

#include <iostream>
using namespace std;

int main()
{
	const int SECONDSPERHOUR = 3600, SECONDSPERMINUTE = 60;
	unsigned long long total;

	//Stop until read an EOF.
	while (cin >> total)
	{
		cout << total / SECONDSPERHOUR << " hours ";
		cout << (total % SECONDSPERHOUR) / SECONDSPERMINUTE << " minutes and ";
		cout << total % SECONDSPERMINUTE << " seconds" << endl;
	}
}