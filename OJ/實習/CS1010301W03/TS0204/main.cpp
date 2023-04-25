// Name: ®}ªY»ö
// Date: March 14, 2023
// Last Update: March 14, 2023
// Problem statement: Print standard format.

#include <iostream>
#include <iomanip> //setw()
using namespace std;

int main()
{
	int number = 0; //the number of data pairs.

	//end if reading EOF
	while (cin >> number)
	{
		size_t longestWidth[3] = { 0 }; //the longest width in each column
		string data[100][3]; //Each employee attributes (Name, Salary and Bonus)

		//input the data and find the longest width of each column
		for (int i = 0; i < number; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> data[i][j];
			}

			//find the longest width of each column
			if (data[i][0].length() > longestWidth[0] )
			{
				longestWidth[0] = data[i][0].length();
			}
			if (data[i][1].length() > longestWidth[1])
			{
				longestWidth[1] = data[i][1].length();
			}
			if (data[i][2].length() > longestWidth[2])
			{
				longestWidth[2] = data[i][2].length();
			}
		}

		//output the data with standard format
		for (int i = 0; i < number; i++)
		{
			cout << setw(longestWidth[0]) << data[i][0] << "|  ";
			cout << setw(longestWidth[1]) << data[i][1] << "|  ";
			cout << setw(longestWidth[2]) << data[i][2] << endl;
		}
	}
}