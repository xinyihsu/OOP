// Name: ®}ªY»ö
// Date: March 12, 2023
// Last Update: March 13, 2023
// Problem statement: Try to put the input messages into a n*n square.

#include <iostream>
#include <string> //the function of strlen()
#define MAX 100
using namespace std;

int main()
{
	char messages[MAX] = { 0 };
	int messageLength = 0;
	int square = 0;

	//end if reading EOF
	while (cin >> messages)
	{
		messageLength = strlen(messages); //calculate the lenth of messages

		//calculate the square length
		for (square = messageLength; square > 0; square--)
		{
			if (square * square < messageLength)
			{
				break;
			}
		}
		square++;

		//output the messages perline
		for (int i = 0; i < square; i++)
		{
			for (int j = i; j <= square * square; j += square)
			{
				if (messages[j] == 0)
				{
					break;
				}
				cout << messages[j];
				//messages[j] = '\0';
			}
			cout << endl;
		}
	}
}