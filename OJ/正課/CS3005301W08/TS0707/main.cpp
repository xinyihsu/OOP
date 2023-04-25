/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-15
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-17
 * Description: Perform addition, subtraction, and multiplication to two large number.
 *************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sum(string largeNumber1, string largeNumber2);
void difference(string largeNumber1, string largeNumber2);
void product(string largeNumber1, string largeNumber2);
void print(vector<int> answer);

int main()
{
	string largeNumber1 = "", largeNumber2 = ""; //two input large number

	//end if reading EOF
	while (cin >> largeNumber1 >> largeNumber2) {
		sum(largeNumber1, largeNumber2);
		difference(largeNumber1, largeNumber2);
		product(largeNumber1, largeNumber2);
	}
}

/**
 * Intent: the sum of two large number
 * Pre: two large number
 * Post: void
 */
void sum(string largeNumber1, string largeNumber2)
{
	int carry = 0; //the carry number (each digit)
	int sum = 0; //the sum of two number (each digit)
	vector<int> answer; //store the sum of two number
	int length1 = largeNumber1.length(), length2 = largeNumber2.length(); //the length of two large number

	//if the first large number shorten than second then change them
	if (length1 < length2) {
		swap(largeNumber1, largeNumber2); //change two large number
		length1 = largeNumber1.length();
		length2 = largeNumber2.length();
	}

	//calculate if two large number both have number in correspondent digit
	for (int i = length2 - 1; i >= 0; i--) {
		sum = largeNumber1[i + length1 - length2] - '0' + largeNumber2[i] - '0' + carry;
		carry = sum / 10;
		sum %= 10;
		answer.push_back(sum); //add the sum into answer
	}

	//calculate the remain digit
	for (int i = length1 - length2 - 1; i >= 0; i--) {
		sum = largeNumber1[i] - '0' + carry;
		carry = sum / 10;
		sum %= 10;
		answer.push_back(sum); //add the sum into answer
	}

	//if the sum of two still have carry then add into answer
	if (carry) {
		answer.push_back(carry);
	}

	print(answer); //print the sum of two large number
}

/**
 * Intent: the difference of two large number
 * Pre: two large number
 * Post: void
 */
void difference(string largeNumber1, string largeNumber2)
{
	int carry = 0; //the carry number (each digit)
	int dif = 0; //the sum of two number (each digit)
	int length1 = largeNumber1.length(), length2 = largeNumber2.length(); //the length of two large number
	bool ifSame = false; //test if to large number is same
	vector<int> answer; //store the sum of two number

	//if the first large number shorten than second then change them
	if (length1 < length2) {
		swap(largeNumber1, largeNumber2); //change two large number
		cout << "-";
	}
	else if (length1 == length2) { //if the first large number and the second have the same length
		//judge if two large number if same
		for (int i = 0; i < length1; i++) {
			//compare each digit
			if (largeNumber1[i] == largeNumber2[i]) {
				ifSame = true;
			}
			else {
				ifSame = false;
				break;
			}
		}

		//if they are same then output zero
		if (ifSame) {
			cout << "0" << endl;
			return;
		}

		//if the first large number is smaller then the second
		if (largeNumber1[0] < largeNumber2[0]) {
			swap(largeNumber1, largeNumber2); //change two large number
			cout << "-";
		}
	}

	length1 = largeNumber1.length();
	length2 = largeNumber2.length();

	//calculate the dif if two large number both have number in correspondent digit
	for (int i = length2 - 1; i >= 0; i--) {
		dif = (largeNumber1[i + length1 - length2] - '0') - (largeNumber2[i] - '0') - carry;

		//if the difference is a negative number
		if (dif < 0) {
			dif += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}

		answer.push_back(dif); //add the dif into answer
	}

	//calculate the remain digit
	for (int i = length1 - length2 - 1; i >= 0; i--) {
		dif = largeNumber1[i] - '0' - carry;

		//if the difference is a negative number
		if (dif < 0) {
			dif += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}

		answer.push_back(dif); //add the dif into answer
	}

	//if the end number of the answer is zero then delete it
	while (answer.back() == 0 && answer.size() > 1) {
		answer.pop_back();
	}

	print(answer); //print the difference of two large number
}

/**
 * Intent: the product of two large number
 * Pre: two large number
 * Post: void
 */
void product(string largeNumber1, string largeNumber2)
{
	int carry = 0; //the carry number (each digit)
	int sum = 0; //the sum of two number (each digit)
	int length1 = largeNumber1.length(), length2 = largeNumber2.length(); //the length of two large number
	vector<int> large1(length1), large2(length2); //the two large number
	vector<int> answer(length1 + length2, 0); //store the sum of two number

	//if one of large number is zero then output zero
	if (largeNumber1 == "0" || largeNumber2 == "0") {
		cout << "0" << endl;
		return;
	}

	//change the first large number into vector (be reversed)
	for (int i = 0; i < length1; i++) {
		large1[i] = largeNumber1[length1 - 1 - i] - '0';
	}

	//change the second large number into vector (be reversed)
	for (int i = 0; i < length2; i++) {
		large2[i] = largeNumber2[length2 - 1 - i] - '0';
	}

	//calculate the product of each digit
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++) {
			answer[i + j] += large1[i] * large2[j];
			answer[i + j + 1] += answer[i + j] / 10;
			answer[i + j] %= 10;
		}
	}

	//if the end number of the answer is zero then delete it
	while (answer.back() == 0 && answer.size() > 1) {
		answer.pop_back();
	}

	print(answer); //print the product of two large number
}

/**
 * Intent: print the vector
 * Pre: a vector called answer
 * Post: void
 */
void print(vector<int> answer)
{
	//output number
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i];
	}
	cout << endl;
}
