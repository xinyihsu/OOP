// Name: ®}ªY»ö
// Date: February 24, 2023
// Last Update: February 26, 2023
// Problem statement: Output integer if the number of characters is less than 10 digits, fill in the space at the beginning

#include <iostream>
#include <iomanip> //include setw function
#include <string> //include size function
using namespace std;

int main()
{
	string input;
	size_t characterNumber = 0; //the number of characters

	//ends if EOF is read
	while (cin >> input)
	{
		characterNumber = input.size();

		//if the input less than 10 characters, fill in the space at the beginning
		if (characterNumber < 10)
		{
			for (int i = 10; i > characterNumber; i--)
			{
				cout << " ";
			}
		}
		cout << input << endl;
	}
	
	
}