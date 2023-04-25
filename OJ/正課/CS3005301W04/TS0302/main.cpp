/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-17
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-17
 * Description: Generate a text-based histogram for a quiz of students.
 ************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int grade; //the inpute grades
	int gradeScale[6] = { 0 }; //the times of each grade appears
	ifstream inputStream; //the file of input
	ofstream outputStream; //the file og output
	inputStream.open("grade.txt");
	outputStream.open("grades.Output");

	//read the grades from file
	while (inputStream >> grade) {
		gradeScale[grade]++;
	}

	//output the grades and the times of each grade to file
	for (int i = 0; i <= 5; i++) {
		outputStream << gradeScale[i] << " grade(s) of " << i;
		if (i != 5) {
			outputStream << endl;
		}
	}

	inputStream.close();
	outputStream.close();
}