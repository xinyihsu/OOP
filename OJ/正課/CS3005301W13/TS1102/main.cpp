/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-05-18
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-18
 * Description: Write a program to calculate matrix multiplication.
 *************************************************************************/
#include <iostream>
#define MAX_VALUE 100
using namespace std;

int main()
{
	int matrixA[MAX_VALUE][MAX_VALUE] = { 0 }; //the matrixA
	int matrixB[MAX_VALUE][MAX_VALUE] = { 0 }; //the matrix B
	int matrixAB[MAX_VALUE][MAX_VALUE] = { 0 }; //the matrix multiplying A and B
	int matrixSize[3][2] = { 0 };//row : 0 -> size of A, 1 -> size of B, 2 -> size of C

	cin >> matrixSize[0][0] >> matrixSize[0][1];
	cin >> matrixSize[1][0] >> matrixSize[1][1];

	//if A and B can not be multiplied (the matrixA's columns must equal to the matrixB's rows)
	if (matrixSize[0][1] != matrixSize[1][0]) {
		cout << "Matrix multiplication failed.";
		return 0;
	}

	//the size of matrix by multiplying A and B
	matrixSize[2][0] = matrixSize[0][0];
	matrixSize[2][1] = matrixSize[1][1];

	//input the matrix A
	for (int i = 0; i < matrixSize[0][0]; i++) {
		for (int j = 0; j < matrixSize[0][1]; j++) {
			cin >> matrixA[i][j];
		}
	}

	//input the matrix B
	for (int i = 0; i < matrixSize[1][0]; i++) {
		for (int j = 0; j < matrixSize[1][1]; j++) {
			cin >> matrixB[i][j];
		}
	}

	//calculate the matrix AB by multiplying A and B
	for (int i = 0; i < matrixSize[2][0]; i++) {
		for (int j = 0; j < matrixSize[2][1]; j++) {
			for (int k = 0; k < matrixSize[0][1]; k++) {
				matrixAB[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}

	//output the matrixAB
	for (int i = 0; i < matrixSize[2][0]; i++) {
		for (int j = 0; j < matrixSize[2][1]; j++) {
			cout << matrixAB[i][j];

			//seperate by space besides the end
			if (j != matrixSize[2][1] - 1) {
				cout << " ";
			}
			else {
				cout << endl;
			}
		}
	}
}
