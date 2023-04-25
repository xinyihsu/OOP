// Name: ®}ªY»ö
// Date: March 10, 2023
// Last Update: March 12, 2023
// Problem statement: Computes the average and standard deviation of input scores.

#include <iostream>
#include <cmath> //sqrt()
using namespace std;
void computes(double s_i[], int n); //computes the averageand standard deviation.

int main()
{
	int n;//the amount of the input scores

	//end if reading EOF.
	while (cin >> n)
	{
		double s_i[100] = { 0 };

		//input the scores n times.
		for (int i = 1; i <= n; i++)
		{
			cin >> s_i[i];
		}
		computes(s_i, n);
	}
}

void computes(double s_i[], int n)
{
	double average = 0; //the average of the input scores
	double standardDeviation = 0;

	//computes the average.
	for (int i = 1; i <= n; i++)
	{
		average += s_i[i];
	}
	average /= n;

	//computes the standard deviation.
	for (int i = 1; i <= n; i++)
	{
		standardDeviation += (s_i[i] - average) * (s_i[i] - average);
	}
	standardDeviation /= n;
	standardDeviation = sqrt(standardDeviation);

	cout << "Average:" << average << "\tStandard deviation:" << standardDeviation << endl;
}