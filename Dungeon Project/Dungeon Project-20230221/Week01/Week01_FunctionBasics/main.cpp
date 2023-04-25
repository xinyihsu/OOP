/************************************************************************
File:   main.cpp

Author:
		²øÀR¶²
		®}ªY»ö¡AB11130008@mail.ntust.edu.tw
Date:
		February 21, 2023
Last Update:
		February 22, 2023
Comment:
		Use clock to count time (And output) for following input tasks

************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char** argv)
{
	clock_t startT, endT; // Variable to store the start of the gameloop
	startT = clock();
	endT = clock();
	clock_t globalStartT = startT;

	// Start the game loop
	/************************************************************************/
	/*Please implement your code here*/
	int time = 0; //Variable to store the time program run
	//if the program run enough times
	while (time != 15)
	{
		endT = clock();
		//through one second
		while ((endT - startT) / CLOCKS_PER_SEC == 1)
		{
			cout << "Total time " << time << " at " << (double)(endT - globalStartT) / CLOCKS_PER_SEC << endl;
			startT = endT;
			time ++;
		}
	}


	/************************************************************************/

}
