/*************************************************************************
 * File: PrintCombination.h
 * Author: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-13
 * Editor: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-15
 * Description: Please write a recursive function to enumerate all combinations of 𝐂(𝐧, 𝐫).
 *************************************************************************/
#pragma once
#include <iostream>
using namespace std;

/**
 * Intent: print all the combination
 * Pre: array, the element number for combination, and the number of dlementsForChoice
 * Post: void
 */
void PrintCombination(int* arrayPtr, int elementForCombination, int dlementsForChoice)
{
	static bool ifOrigin = false;

	//if it is the origin array
	if (!ifOrigin) {
		int* origin = new int[elementForCombination];

		//copy the input array
		for (int i = 0; i < elementForCombination; i++) {
			origin[i] = arrayPtr[i];
		}

		ifOrigin = true;

		//let remain be zero
		for (int i = dlementsForChoice; i < elementForCombination; i++) {
			arrayPtr[i] = 0;
		}

		arrayPtr[elementForCombination - 1] = -1;
		PrintCombination(arrayPtr, dlementsForChoice, dlementsForChoice - 1);
		ifOrigin = false;

		//reset the array to origin
		for (int i = 0; i < elementForCombination; i++) {
			arrayPtr[i] = origin[i];
		}

		delete[] origin;
		return;
	}

	int num = 0, index = -1;

	//find the index and number
	for (int i = 0; true; i++) {
		//calculate index
		if (arrayPtr[i] <= 0 && index == -1) {
			index = i - 1;
		}

		//calculate num
		if (arrayPtr[i] == -1) {
			num = i + 1;
			break;
		}
	}

	//recursive the remain
	for (int i = index; i >= dlementsForChoice; i--) {
		arrayPtr[i] = elementForCombination + (i - dlementsForChoice);
		//if true doing recursive
		if (arrayPtr[i] > (i + num - index)) {
			//end
			if (dlementsForChoice == 0) return;
			PrintCombination(arrayPtr, arrayPtr[dlementsForChoice - 1] + 1, dlementsForChoice - 1);
			return;
		}
	}

	//output the combination
	for (int i = 0; i <= index; i++) {
		cout << arrayPtr[i];
		if (i != index) cout << " ";
	}

	cout << endl;
	PrintCombination(arrayPtr, arrayPtr[index] + 1, index);
}
