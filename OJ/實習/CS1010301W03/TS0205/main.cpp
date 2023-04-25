// Name: ®}ªY»ö
// Date: March 14, 2023
// Last Update: March 15, 2023
// Problem statement: Adding large numbers.

#include <iostream>
#include <string> // the function of length()
using namespace std;

struct BigInt //input integers
{
	string number;
	size_t len = 0; //the length og the integer
};

//to sum the two integers
//call with two structure
//return a structure of the sum
BigInt Add(BigInt& lhs, BigInt& rhs);

int main()
{
	int number; //the number of data pairs.
	bool valid = true; //if the input is valid
	BigInt intA, intB, answer; //the two integer, and the sum of two
	cin >> number;

	//there are several data pairs and run several times
	for (int i = 0; i < number; i++)
	{
		valid = true;
		cin >> intA.number >> intB.number;

		//if intB longer than intA change them
		if (intB.number.length() > intA.number.length())
		{
			string temp = intB.number;
			intB.number = intA.number;
			intA.number = temp;
		}
		intA.len = intA.number.length();
		intB.len = intB.number.length();

		//judge if the integer is valid
		for (int j = 0; j < intA.len; j++)
		{
			if (intA.number[j] < '0' || intA.number[j] > '9')
			{
				valid = false;
			}
		}
		
		//judge if the integer is valid
		if (valid == true)
		{
			for (int j = 0; j < intB.len; j++)
			{
				if (intB.number[j] < '0' || intB.number[j] > '9')
				{
					valid = false;
				}
			}
		}

		//output the answer
		if (valid == false)
		{
			cout << "Not a valid number, please try again." << endl;
		}
		else if (valid == true)
		{
			answer = Add(intA, intB);
			cout << answer.number << endl;
		}
	}
}

BigInt Add(BigInt& lhs, BigInt& rhs)
{
	int tempL, tempR; //lhs and rhs temp number
	int temp = 0; //the temp number

	//plus the two interger 
	while (rhs.len != 0)
	{
		tempL = lhs.number[lhs.len - 1] - '0';
		tempR = rhs.number[rhs.len - 1] - '0';

		tempL = tempL + tempR + temp;
		temp = tempL / 10;
		tempL %= 10;
		lhs.number[lhs.len - 1] = tempL + '0';
		lhs.len--;
		rhs.len--;
	}

	//calculate the remain number (the lhs longer part)  
	while (lhs.len != 0)
	{
		tempL = lhs.number[lhs.len - 1] - '0';
		tempL += temp;
		temp = tempL / 10;
		tempL %= 10;
		lhs.number[lhs.len - 1] = tempL + '0';
		lhs.len--;
	}

	//if it will carry, add one in front of the number
	if (temp == 1)
	{
		lhs.number = "1" + lhs.number;
	}
	
	return lhs;
}