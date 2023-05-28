#pragma once

class PrimeNumber {
public:
	int value;
	int get();
	PrimeNumber(void);
	PrimeNumber(int _value);
	PrimeNumber& operator++(void);
	PrimeNumber operator++(int);
	PrimeNumber& operator--(void);
	PrimeNumber operator--(int);
};

bool testIfPrimeNumber(int);
