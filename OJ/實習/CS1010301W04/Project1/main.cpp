/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-20
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-22
 * Description:
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int GetIntLength(string number)
{
	int length = 0;

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

	while (cin >> number) {
		int totalLength; //the total length of the output (including negative sign and decimal point)
		int intLength;
		int decimalLength; //number of reserved digits of the decimal part
		int originTotalLength, originIntLength = 0;
		char letter; //letter to be filled when the length is not enough (less than M digits)
		string answer = "";
		cin >> totalLength >> decimalLength;
		letter = getchar();
		letter = getchar();
		originTotalLength = number.length();
		originIntLength = GetIntLength(number);
		//cout << "originIntLength: " << originIntLength << endl;

		if (decimalLength > 0) {
			intLength = totalLength - 1 - decimalLength;
		}
		else {
			intLength = totalLength;
		}
		for (int i = 0; i < intLength - originIntLength; i++) {
			answer += letter;
		}

		int index = 0;
		for (char c : number) {
			if (c == '.') {
				break;
			}
			answer += c;
			index++;
		}
		if (decimalLength > 0) {
			answer += '.';
			index++;

		}
		for (int i = 0; i < decimalLength; i++, index++) {
			if (index >= originTotalLength) {
				answer += '0';
			}
			else {
				answer += number[index];
			}
		}
		cout << answer << endl;
	}
	return 0;
}

for (index = 0; index < originIntLength; index++) {
	answer += number[index];

}

for (int i = index; i < decimalLength + index; i++) {
	if (i >= originTotalLength) {
		answer += '0';
	}
	else {
		answer += number[i];
	}
}