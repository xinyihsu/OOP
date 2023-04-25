/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-20
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-22
 * Description: Output number with the rules
 ************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * Intent: calculate the number of integer part
 * Pre: the target number that need to be formed
 * Post: the number of integer part
 */
int GetIntLength(string number)
{
	int length = 0; //the length of integer part

	//find the point in number
	for (char c : number) {
		if (c == '.') {
			return length;
		}
		length++;
	}
	return length;
}

int main()
{
	string number; //the target number that need to be formed

	//end if reading EOF
	while (cin >> number) {
		int totalLength; //the total length of the output (including negative sign and decimal point)
		int intLength; //number of integer part
		int decimalLength; //number of reserved digits of the decimal part
		int originTotalLength; //the original number total length
		int originIntLength = 0; //the original number integer length
		int index = 0; //the index of the number
		char letter; //letter to be filled when the length is not enough (less than M digits)
		string answer = ""; //the number after calculate

		cin >> totalLength >> decimalLength >> letter;
		originTotalLength = number.length(); //calculate the original number total length
		originIntLength = GetIntLength(number); //calculate the number of integer part

		//calculate the number of integer part
		if (decimalLength > 0) {
			intLength = totalLength - 1 - decimalLength;
		}
		else {
			intLength = totalLength;
		}

		//add the letter into answer
		for (int i = 0; i < intLength - originIntLength; i++) {
			answer += letter;
		}

		//add the integer part into anser
		for (index = 0; index < originIntLength; index++) {
			answer += number[index];

		}

		//if it need to output decimal part
		if (decimalLength > 0) {
			answer += '.';
			index++;

			//add the decimal into answer
			for (int i = index; i < decimalLength + index; i++) {
				//if the decimal we have smaller than it needs, add zero, otherwise add the number of index value
				if (i >= originTotalLength) {
					answer += '0';
				}
				else {
					answer += number[i];
				}
			}
		}

		cout << answer << endl;
	}
	return 0;
}

