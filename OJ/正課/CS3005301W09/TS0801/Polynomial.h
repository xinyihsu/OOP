/*************************************************************************
 * File: Polynomial.h
 * Author: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Create Date: 2023-04-22
 * Editor: ®}ªY»ö¡AB11130008@mail.ntust.edu.tw
 * Update Date: 2023-04-24
 * Description: Implement a class called Polynomial to handle one-dimensional polynomials.
				This class needs to be able to store the coefficients and implement operations
				such as addition, subtraction, multiplication, and assignment.
 *************************************************************************/
#pragma once
#include <string>
#include <vector>
using namespace std;

class Polynomial
{
private:
	vector<double> poly;
	int size;
public:
	Polynomial();
	Polynomial(double*, int);
	Polynomial(const Polynomial&);
	~Polynomial();

	const Polynomial operator+ (const Polynomial&);
	const Polynomial operator+(const double&);
	friend const Polynomial operator+(const double&, const Polynomial&);

	const Polynomial operator- (const Polynomial&);
	const Polynomial operator-(const double&);
	friend const Polynomial operator-(const double&, const Polynomial&);

	const Polynomial operator* (const Polynomial&);
	const Polynomial operator*(const double&);
	friend const Polynomial operator*(const double&, const Polynomial&);

	Polynomial& operator= (const Polynomial&);
	double& operator[] (int);
	int mySize();
	friend double evaluate(const Polynomial&, const double&);
};

/**
 * Intent: construct a zero polynomial
 * Pre: void
 */
Polynomial::Polynomial()
{
	poly.push_back(0);
	this->size = 0;
}

/**
 * Intent: deconstructor
 * Pre: void
 */
Polynomial::~Polynomial()
{

}

/**
 * Intent: construct a one-dimensional polynomial based on the given coefficients
 * Pre: the coefficients and its size
 */
Polynomial::Polynomial(double* param, int size)
{
	//add coefficients into vector
	for (int i = 0; i < size; i++) {
		poly.push_back(param[i]);
	}

	this->size = size;

	//if the end is zero then delete it
	while (poly.back() == 0) {
		poly.pop_back();
		this->size--;
	}
}

/**
 * Intent: copy another object (copy constructure)
 * Pre: an other class object
 */
Polynomial::Polynomial(const Polynomial& other)
{
	this->size = other.size;
	this->poly = other.poly;
}

/**
 * Intent: return the number of terms of the polynomial
 * Pre: void
 * Post: the size
 */
int Polynomial::mySize()
{
	//if the end is zero then delete it
	while (poly.back() == 0) {
		poly.pop_back();
	}

	return poly.size();
}

/**
 * Intent: Return the value of the polynomial after substituting var into the variables
 * Pre: polynomial and the number
 * Post: the answer (double)
 */
double evaluate(const Polynomial& other, const double& var)
{
	double sum = 0;

	//calculate
	for (int i = 0; i < other.size; i++) {
		sum += other.poly[i] * pow(var, i);
	}

	return sum;
}

/**
 * Intent: implement the addition of two polynomials or a polynomial and a constant number
 * Pre: a Polynomial
 * Post: a Polinomial after calculate
 */
const Polynomial Polynomial::operator+ (const Polynomial& other)
{
	vector<double> answer; //the answer after operator
	int max = this->size;
	int min = other.size;

	//get the max size
	if (this->size < other.size) {
		swap(max, min);
	}

	//add two vector
	for (int i = 0; i < min; i++) {
		answer.push_back(this->poly[i] + other.poly[i]);
	}

	//add the remain
	for (int i = min; i < max; i++) {
		answer.push_back(max == this->size ? this->poly[i] : other.poly[i]);
	}

	return Polynomial(answer.data(), answer.size());
}

/**
 * Intent: implement the addition of two polynomials or a polynomial and a constant number
 * Pre: a number add to polynomial
 * Post: a Polinomial after calculate
 */
const Polynomial Polynomial::operator+(const double& num)
{
	vector<double> answer; //the answer after operator

	//copy the polynomial into answer
	for (int i = 0; i < this->size; i++) {
		answer.push_back(this->poly[i]);
	}

	answer[0] += num;
	return Polynomial(answer.data(), answer.size());
}

/**
 * Intent: implement the addition of two polynomials or a polynomial and a constant number
 * Pre: a number add to polynomial and the polynomial
 * Post: a Polinomial after calculate
 */
const Polynomial operator+(const double& num, const Polynomial& other)
{
	vector<double> answer; //the answer after operator

	//copy the polynomial into answer
	for (int i = 0; i < other.size; i++) {
		answer.push_back(other.poly[i]);
	}

	answer[0] += num;
	return Polynomial(answer.data(), answer.size());
}

/**
 * Intent: implement the subtraction of two polynomials or a polynomial and a constant number
 * Pre: a Polynomial
 * Post: a Polinomial after calculate
 */
const Polynomial Polynomial::operator- (const Polynomial& other)
{
	vector<double> answer; //the answer after operator
	int max = this->size;
	int min = other.size;

	//find the max size
	if (this->size < other.size) {
		swap(max, min);
	}

	//subtract two vector
	for (int i = 0; i < min; i++) {
		answer.push_back(this->poly[i] - other.poly[i]);
	}

	//sub the remain
	for (int i = min; i < max; i++) {
		answer.push_back(max == this->size ? this->poly[i] : -other.poly[i]);
	}

	return Polynomial(answer.data(), answer.size());
}

/**
 * Intent: implement the subtraction of two polynomials or a polynomial and a constant number
 * Pre: a number sub polynomial
 * Post: a Polinomial after calculate
 */
const Polynomial Polynomial::operator-(const double& num)
{
	vector<double> answer; //the answer after operator

	//copy the polynomial into answer
	for (int i = 0; i < this->size; i++) {
		answer.push_back(this->poly[i]);
	}

	answer[0] -= num;
	return Polynomial(answer.data(), answer.size());
}

/**
 * Intent: implement the subtraction of two polynomials or a polynomial and a constant number
 * Pre: a number sub polynomial and the polynomial
 * Post: a Polinomial after calculate
 */
const Polynomial operator-(const double& num, const Polynomial& other)
{
	vector<double> answer; //the answer after operator

	//sub the polynomial
	for (int i = 0; i < other.size; i++) {
		answer.push_back(-other.poly[i]);
	}

	answer[0] += num;
	return Polynomial(answer.data(), answer.size());
}


/**
 * Intent: implement the multiplication of two polynomials or a polynomial and a constant number
 * Pre: a Polynomial
 * Post: a Polinomial after calculate
 */
const Polynomial Polynomial::operator* (const Polynomial& other)
{
	int ansSize = this->size + other.size - 1;
	vector<double> answer(ansSize, 0); //the answer after operator

	//multiply two vector
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < other.size; j++) {
			answer[i + j] += this->poly[i] * other.poly[j];
		}
	}

	return Polynomial(answer.data(), ansSize);
}

/**
 * Intent: implement the multiplication of two polynomials or a polynomial and a constant number
 * Pre: a number multiply to polynomial
 * Post: a Polinomial after calculate
 */
const Polynomial Polynomial::operator*(const double& num)
{
	vector<double> answer; //the answer after operator

	//multiply all coefficients
	for (int i = 0; i < this->size; i++) {
		answer.push_back(this->poly[i] * num);
	}

	return Polynomial(answer.data(), answer.size());
}

/**
 * Intent: implement the multiplication of two polynomials or a polynomial and a constant number
 * Pre: a number multiply to polynomial and the polynomial
 * Post: a Polinomial after calculate
 */
const Polynomial operator*(const double& num, const Polynomial& other) {
	vector<double> answer; //the answer after operator

	//multiply all coefficients
	for (int i = 0; i < other.size; i++) {
		answer.push_back(other.poly[i] * num);
	}

	return Polynomial(answer.data(), answer.size());
}

/**
 * Intent: assign the value from a polynomial to another polynomial
 * Pre: a Polynomial
 * Post: a Polinomial after calculate
 */
Polynomial& Polynomial::operator= (const Polynomial& other)
{
	this->size = other.size;
	this->poly = other.poly;
	return *this;
}

/**
 * Intent: return the coefficient of the certain power variable in the polynomial
 * Pre: the index
 * Post: the value of index
 */
double& Polynomial::operator[] (int index)
{
	//if the index out of range
	if (index > this->size - 1) {
		poly[index] = 0;
		this->size = index + 1;
	}

	return poly[index];
}
