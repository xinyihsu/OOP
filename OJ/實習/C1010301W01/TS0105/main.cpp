// Name: ®}ªY»ö
// Date: February 24, 2023
// Last Update: February 24, 2023
// Problem statement:  compute and output the volume of a sphere

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	const double PI = 3.14159265358979323846;
	double radius;

	// Ends if EOF is inputed. Then, output the volume.
	while (cin >> radius)
	{
		cout << fixed << setprecision(6) << 4 * PI * pow(radius, 3) / 3 << endl;
	}
}