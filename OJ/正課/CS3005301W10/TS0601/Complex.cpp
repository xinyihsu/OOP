/*************************************************************************
 * File: Complex.cpp
 * Author: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-29
 * Editor: 徐欣儀，B11130008@mail.ntust.edu.tw
 * Update Date: 2023-05-01
 * Description: Define a class for complex numbers named Complex. A complex number is a number formed as a + b * i,
 *				where a and b are numbers of type double, and i is a number that represents the quantity √(−1)
 *************************************************************************/

#include "Complex.h"

 /**
  * Intent: construct a complex number where both realValue and imaginaryValue are 0
  * Pre: void
  */
Complex::Complex(void)
{
	this->realValue = 0;
	this->imaginaryValue = 0;
}

/**
 * Intent: construct a complex number where the realValue is r and the imaginaryValue is 0
 * Pre: a double represent the realValue of complex
 */
Complex::Complex(double r)
{
	this->realValue = r;
	this->imaginaryValue = 0;
}

/**
 * Intent: construct a complex number where the realValue is r and the imaginaryValue is i
 * Pre: two double represent the realValue and the imaginaryValue of comlex
 */
Complex::Complex(double r, double i)
{
	this->realValue = r;
	this->imaginaryValue = i;
}

/**
 * Intent: return the realValue
 * Pre: void
 * Post: a double (realValue)
 */
double Complex::real(void)
{
	return this->realValue;
}

/**
 * Intent: return the imaginaryValue
 * Pre: void
 * Post: a double (imaginaryValue)
 */
double Complex::imag(void)
{
	return this->imaginaryValue;
}

/**
 * Intent: return the value of √( 𝑟𝑒𝑎𝑙𝑉𝑎𝑙𝑢𝑒2 + imaginaryValue2)
 * Pre: void
 * Post: a double (the norm value of the complex)
 */
double Complex::norm(void)
{
	double sum = pow(this->realValue, 2) + pow(this->realValue, 2);
	sum = sqrt(sum);
	return sum;
}

/**
 * Intent: return the realValue of a complex number c
 * Pre: a comlex object
 * Post: a double (realValue)
 */
double real(Complex c)
{
	return c.realValue;
}

/**
 * Intent: return the imaginaryValue of a complex number c
 * Pre: a comlex object
 * Post: a double (imaginaryValue)
 */
double imag(Complex c)
{
	return c.imaginaryValue;
}

/**
 * Intent: return the value of √( 𝑟𝑒𝑎𝑙𝑉𝑎𝑙𝑢𝑒2 + imaginaryValue2) of a complex number c
 * Pre: a comlex object
 * Post: a double (the norm value of the complex)
 */
double norm(Complex c)
{
	double sum = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);
	sum = sqrt(sum);
	return sum;
}

/**
 * Intent: add another complex number
 * Pre: a complex number
 * Post: a complex number after computing
 */
Complex Complex::operator+(Complex c)
{
	return Complex((this->realValue + c.realValue), (this->imaginaryValue + c.imaginaryValue));
}

/**
 * Intent: minus another complex number
 * Pre: a complex number
 * Post: a complex number after computing
 */
Complex Complex::operator-(Complex c)
{
	return Complex((this->realValue - c.realValue), (this->imaginaryValue - c.imaginaryValue));
}

/**
 * Intent: multiply with another complex
 * Pre: a complex number
 * Post: a complex number after computing
 */
Complex Complex::operator*(Complex c)
{
	double tempReal = (this->realValue * c.realValue) - (this->imaginaryValue * c.imaginaryValue);
	double tempImaginary = (this->realValue * c.imaginaryValue) + (this->imaginaryValue * c.realValue);
	return Complex(tempReal, tempImaginary);
}

/**
 * Intent: divide with another complex number or a double type number
 * Pre: a complex number
 * Post: a complex number after computing
 */
Complex Complex::operator/(Complex c)
{
	double tempSum = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);
	double tempReal = (this->realValue * c.realValue) + (this->imaginaryValue * c.imaginaryValue);
	double tempImaginary = (this->imaginaryValue * c.realValue) - (this->realValue * c.imaginaryValue);
	return Complex(tempReal / tempSum, tempImaginary / tempSum);
}

/**
 * Intent: add a double type number
 * Pre: a complex number and a double
 * Post: a complex number after computing
 */
Complex operator+(double d, Complex c)
{
	return Complex((c.realValue + d), c.imaginaryValue);
}

/**
 * Intent: minus another complex number or a double type number
 * Pre: a complex number and a double
 * Post: a complex number after computing
 */
Complex operator-(double d, Complex c)
{
	return Complex((d - c.realValue), -c.imaginaryValue);
}

/**
 * Intent: multiply with another complex number or a double type number
 * Pre: a complex number and a double
 * Post: a complex number after computing
 */
Complex operator*(double d, Complex c)
{
	return Complex((c.realValue * d), (c.imaginaryValue * d));
}

/**
 * Intent: divide with another complex number or a double type number
 * Pre: a complex number and a double
 * Post: a complex number after computing
 */
Complex operator/(double d, Complex c)
{
	double tempSum = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);
	double tempReal = d * c.realValue;
	double tempImaginary = -d * c.imaginaryValue;
	return Complex(tempReal / tempSum, tempImaginary / tempSum);
}

/**
 * Intent: judge if the real and imaginary parts of two complex numbers are equal
 * Pre: two complex object
 * Post: bool
 */
bool operator==(Complex c1, Complex c2)
{
	//if realValue of two complex are not the same
	if (c1.realValue != c2.realValue) {
		return false;
	}

	//if imaginaryValue of two complex are not the same
	if (c1.imaginaryValue != c2.imaginaryValue) {
		return false;
	}

	return true;
}

/**
 * Intent: send complex numbers to the output stream with the format “realValue + imaginaryValue*i”
 * Pre: an output stream and a complex number
 * Post: the output stream
 */
ostream& operator<<(ostream& strm, const Complex& c)
{
	strm << c.realValue << " + " << c.imaginaryValue << "*i";
	return strm;
}

/**
 * Intent: get the value of a complex number from the input stream with the format “x = realValue + imaginaryValue*i”
 * Pre: an input stream and a complex number
 * Post: the input stream
 */
istream& operator>>(istream& strm, Complex& c)
{
	string temp;
	strm >> temp >> temp >> c.realValue >> temp >> c.imaginaryValue >> temp;
	return strm;
}

