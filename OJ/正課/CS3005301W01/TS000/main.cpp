// Name: ®}ªY»ö
// Date: February 23, 2023
// Last Update: February 24, 2023
// Problem statement: Output string "Hello World!" for n times.

#include <iostream>
using namespace std;

int main()
{
	int time = 0;

	//keep reading until EOF flag is met
	while (cin >> time) {
		//output words for several times
		for (int i = 0; i < time; i++)
		{
			cout << "Hello World!" << endl;
		}
	}
}