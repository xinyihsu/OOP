/*************************************************************************
 * File: Fraction.cpp
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-03-23
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-03-24
 * Description: Represent a ratio of two integers by two way (first is decimal type, second is fraction type)
 ************************************************************************/
#include "Fraction.h"

 /**
  * Intent: set the numerator number
  * Pre: a integer number
  * Post: nothing
  */
void Fraction::setNumerator(int nu)
{
	numerator = nu;
}

/**
 * Intent: set the denominate
 * Pre: a integer number
 * Post: nothing
 */
void Fraction::setDenominator(int de)
{
	denominator = de;
}

/**
 * Intent: calculate the value of the numerator divided by the denominator as a double,
 *		   but if the value can only represent by an integer, then it should be represented integer
 * Pre: nothing
 * Post: nothing
 */
void Fraction::getDouble()
{
	double ratio = (double)numerator / denominator; //the number that numerator devide denominator

	//if the numerator equal to zero then the answer will be zero
	if (numerator == 0) {
		cout << "0" << endl;
	}
	else if (ratio - (int)ratio != 0) { //judge if the ratio is an integer 
		cout << fixed << setprecision(6) << ratio << endl;
	}
	else {//the ratio is an integer
		cout << fixed << setprecision(0) << (int)ratio << endl;
	}

}

/**
 * Intent: outputs the value of the fraction reduced to lowest terms.
 * Pre: nothing
 * Post: nothing
 */
void Fraction::outputReducedFraction()
{
	int highestCommonFactor; //the highest common factor of numerator and denominater

	//if the numerator equal to zero then the answer will be zero
	if (numerator == 0) {
		cout << "0" << endl;
	}
	else {
		//find the highest common factor
		for (highestCommonFactor = numerator; highestCommonFactor > 0; highestCommonFactor--) {
			//judge if the numerator and denominator can de deviable by the number with no remains then the number is the HCF
			if (numerator % highestCommonFactor == 0 && denominator % highestCommonFactor == 0) {
				break;
			}
		}

		numerator /= highestCommonFactor;
		denominator /= highestCommonFactor;

		//judge if the denominator is zero, if it is then output integer
		if (denominator == 1) {
			cout << numerator << endl;
		}
		else {
			cout << numerator << "/" << denominator << endl;
		}
	}
}



