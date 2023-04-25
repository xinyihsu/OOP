/*************************************************************************
 * File: main.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-22
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-24
 * Description: Write a program to simulate the process of writing and reading memory data.
 *************************************************************************/
#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;

int main()
{
	int memory, commandNumber;
	cin >> memory >> commandNumber;
	vector<unsigned char> hex(memory, 0);

	//run according command number
	for (int i = 0; i < commandNumber; i++)
	{
		string command, type;
		int index;
		cin >> command >> index >> type;

		//if input data type is char
		if (type == "char") {
			//if input command is set
			if (command == "Set") {
				unsigned int value;
				cin >> value;

				//if out of ascii
				if (value > 255) {
					value = 255;
				}

				//if out of range
				if (index + 1 > memory) {
					cout << "Violation Access." << endl;
				}

				//store in memory (vector hex)
				if (index < memory) {
					hex[index] = (char)value;
				}
			}
			//if input command is get
			else if (command == "Get") {
				//if out of range
				if (index + 1 > memory) {
					cout << "Violation Access.\n";
					continue;
				}

				cout << (int)hex[index] << endl;
			}
		}
		//if input data type is short
		else if (type == "short")
		{
			//if input command is set
			if (command == "Set") {
				unsigned short value;
				cin >> value;

				//if out of range
				if (index + 2 > memory) {
					cout << "Violation Access." << endl;
				}

				//store in memory (vector hex)
				for (int i = index; value; value >>= 8, i++) {
					//if out of memory size
					if (i < memory) {
						hex[i] = (char)(value & 0xff);
					}
				}
			}
			//if input command is get
			else if (command == "Get") {
				unsigned short data(0);

				//if out of range
				if (index + 2 > memory) {
					cout << "Violation Access.\n";
					continue;
				}

				//change into short
				for (int i = 0, base = 1; i < 2; i++, base <<= 8) {
					data += (unsigned short)hex[i + index] * base;
				}

				cout << data << endl;
			}
		}
		//if input data type is int
		else if (type == "int") {
			//if input command is set
			if (command == "Set") {
				unsigned int value;
				cin >> value;

				//if out of range
				if (index + 4 > memory) {
					cout << "Violation Access." << endl;
				}

				//store in memory (vector hex)
				for (int i = index; value; value >>= 8, i++) {
					//if out of memory size
					if (i < memory)
						hex[i] = (char)(value & 0xff);
				}
			}
			//if input command is get
			else if (command == "Get") {
				unsigned int data(0);

				//if out of range
				if (index + 4 > memory) {
					cout << "Violation Access.\n";
					continue;
				}

				//chage into integer
				for (int i = 0, base = 1; i < 4; i++, base <<= 8) {
					data += (unsigned int)hex[i + index] * base;
				}

				cout << data << endl;
			}
		}
		//if input data type is string
		else if (type == "String") {
			//if input command is set
			if (command == "Set") {
				string value;
				cin.get(); //delete space between type and value
				getline(cin, value);

				//if out of range
				if (index + value.size() > memory) {
					cout << "Violation Access." << endl;
				}

				//store in memory (vector hex)
				for (int i = 0; i < value.size(); i++) {
					//if not out of range
					if (i + index < memory) {
						hex[i + index] = value[i];
					}
				}
			}
			//if input command is get
			else if (command == "Get") {
				//if out of range
				if (index + 1 > memory) {
					cout << "Violation Access." << endl;
				}

				//output
				for (int i = index; hex[i] && i < hex.size(); i++) {
					cout << hex[i];
				}

				cout << endl;
			}
		}
	}
}