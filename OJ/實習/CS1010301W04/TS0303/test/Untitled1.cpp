/*************************************************************************
 * File: main.cpp
 * Author: 畗猋祸B11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-20
 * Editor: 畗猋祸B11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-22
 * Description:
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string number; //the target number that need to be formed
	size_t totalLength; //the total length of the output (including negative sign and decimal point)
	size_t decimalLength; //number of reserved digits of the decimal part
	size_t originTotalLength, originDecimalIndex = 0;
	char letter; //letter to be filled when the length is not enough (less than M digits)
	bool decimalPoint = false;

	while (cin >> number) {
		decimalPoint = false;
		cin >> totalLength >> decimalLength >> letter;
		originTotalLength = number.length();
		for (originDecimalIndex = 0; originDecimalIndex < originTotalLength; originDecimalIndex++) {
			if (number[originDecimalIndex] == '.') {
				decimalPoint = true;
				break;
			}
		}
		size_t originDecimalLength = originTotalLength - originDecimalIndex - 1;
		if (decimalLength == 0) { //ぃノ计
			if (decimalPoint == true) {
				number.erase(originDecimalIndex, originTotalLength);
				for (size_t i = 0; i < (totalLength - originDecimalIndex); i++) {
					cout << letter;
				}
			}
			else if (decimalPoint == false) {
				for (size_t i = 0; i < (totalLength - originTotalLength); i++) {
					cout << letter;
				}
			}
			cout << number;
		}
		else { //璶Τ计
			if (decimalPoint == true) {
				size_t originDecimalLength = originTotalLength - originDecimalIndex - 1;
				for (size_t i = 0; i < (totalLength - decimalLength - originDecimalIndex - 1); i++) {
					cout << letter;
				}
				if (originDecimalLength >= decimalLength) {
					number.erase(originDecimalIndex + decimalLength + 1, originDecimalLength - 1);
					cout << number;
				}
				else {//**********
					cout << number;
					for (size_t i = originDecimalLength; i < decimalLength; i++) {
						cout << "0";
					}
				}
			}
			else if (decimalPoint == false) {
				for (size_t i = 0; i < (totalLength - decimalLength - originDecimalIndex - 1); i++) {
					cout << letter;
				}
				cout << number;
				cout << ".";
				for (size_t i = 0; i < decimalLength; i++) {
					cout << "0";
				}
			}
		}

		cout << endl;
	}
}


/*************************************************************************
 * File: main.cpp
 * Author: 畗猋祸B11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-20
 * Editor: 畗猋祸B11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-22
 * Description:
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string number; //the target number that need to be formed
	size_t totalLength; //the total length of the output (including negative sign and decimal point)
	size_t decimalLength; //number of reserved digits of the decimal part
	size_t originTotalLength, originDecimalIndex = 0;
	char letter; //letter to be filled when the length is not enough (less than M digits)
	bool decimalPoint = false;

	while (cin >> number) {
		decimalPoint = false;
		cin >> totalLength >> decimalLength >> letter;
		originTotalLength = number.length();

		for (originDecimalIndex = 0; originDecimalIndex < originTotalLength; originDecimalIndex++) {
			if (number[originDecimalIndex] == '.') {
				decimalPoint = true;
				break;
			}
		}
		size_t originDecimalLength = originTotalLength - originDecimalIndex - 1;

		if (decimalLength == 0) { //ぃノ计
			if (decimalPoint == true) {
				number.erase(originDecimalIndex, originTotalLength);
				originTotalLength = number.length();
			}
			for (size_t i = 0; i < (totalLength - originTotalLength); i++) {
				cout << letter;
			}
			cout << number;
		}
		else { //璶Τ计
			if (decimalPoint == true) {
				if (originDecimalLength >= decimalLength) {
					number.erase(originDecimalIndex + decimalLength + 1, originDecimalLength - 1);
					originTotalLength = number.length();
				}
				for (size_t i = 0; i < (totalLength - decimalLength - originDecimalIndex - 1); i++) {
					cout << letter;
				}
				size_t originDecimalLength = originTotalLength - originDecimalIndex - 1;
				cout << number;
				for (size_t i = originDecimalLength; i < decimalLength; i++) {
					cout << "0";
				}

			}
			else if (decimalPoint == false) {
				for (size_t i = 0; i < (totalLength - decimalLength - originDecimalIndex - 1); i++) {
					cout << letter;
				}
				cout << number;
				cout << ".";
				for (size_t i = 0; i < decimalLength; i++) {
					cout << "0";
				}
			}
		}

		cout << endl;
	}
}
	//else { //璶Τ计
	//if (decimalPoint == true) {
	//	size_t originDecimalLength = originTotalLength - originDecimalIndex - 1;
	//	for (size_t i = 0; i < (totalLength - decimalLength - originDecimalIndex - 1); i++) {
	//		cout << letter;
	//	}
	//	if (originDecimalLength >= decimalLength) {
	//		number.erase(originDecimalIndex + decimalLength + 1, originDecimalLength - 1);
	//		cout << number;
	//	}
	//	else {//**********
	//		cout << number;
	//		for (size_t i = originDecimalLength; i < decimalLength; i++) {
	//			cout << "0";
	//		}
	//	}
	//}
	//else if (decimalPoint == false) {
	//	for (size_t i = 0; i < (totalLength - decimalLength - originDecimalIndex - 1); i++) {
	//		cout << letter;
	//	}
	//	cout << number;
	//	cout << ".";
	//	for (size_t i = 0; i < decimalLength; i++) {
	//		cout << "0";
	//	}
	//}
	//	}
