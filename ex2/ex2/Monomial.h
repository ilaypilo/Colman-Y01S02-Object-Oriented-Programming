#pragma once

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

// ax^n
class Monomial
{
	int coefficient; // a
	int exponent; // n
public:
	// Constructor
	Monomial(int coeff, int exp = 0) : coefficient(coeff), exponent(exp) {};
	// Default constructor
	Monomial() : coefficient(0), exponent(0) {};

	// getters
	int getExponent() const { return this->exponent; };
	int getCoefficient() const { return this->coefficient; };

	// operator overloading
	const Monomial & operator+=(const Monomial &m);
	const Monomial & operator-=(const Monomial &m);
	Monomial operator*(const Monomial &m) const;
	const Monomial & operator*=(const Monomial &m);

	// check if 2 Monomial are equal
	bool operator==(const Monomial &m) const;
	// negate the coefficient
	void negate() { this->coefficient *= -1; };
	// add the ax^n format to a stream
	friend std::ostream& operator << (std::ostream& out, const Monomial& m);
	// add the ax^n format to a stream
	//friend std::istream& operator >> (std::istream& out, Monomial& m);
	Monomial& operator>>(const char* str);
    // return the Monomial in this format ax^n
    char* stringRepresentation() const;
};

std::ostream& operator << (std::ostream& out, const Monomial& m);