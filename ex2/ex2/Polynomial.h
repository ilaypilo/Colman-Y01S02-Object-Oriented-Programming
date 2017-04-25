#pragma once

#include <iostream>
#include <vector>
#include "Monomial.h"


class Polynomial
{
	Monomial* monArr;
	int size;
public:
    Polynomial() : monArr(nullptr), size(0) {};
	// Destructor
	~Polynomial();
	// copy constructor
	Polynomial(const Polynomial &p);
	// overload operator = assignment
	const Polynomial & operator=(const Polynomial &p);

    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);

	// operator overloading
    Polynomial& operator>>(const char* str);
	const Polynomial & operator+=(const Monomial &m);
	const Polynomial & operator+=(const Polynomial &p);
	const Polynomial & operator-=(const Monomial &m);
	const Polynomial & operator-=(const Polynomial &p);
	const Polynomial & operator*=(const Monomial &m) const;
	const Polynomial & operator*=(const Polynomial &p);

	friend Polynomial operator+(const Polynomial &p1, const Polynomial &p2);
	friend Polynomial operator-(const Polynomial &p1, const Polynomial &p2);
	friend Polynomial operator*(const Polynomial &p1, const Polynomial &p2);
	friend Polynomial operator+(const Polynomial &p, const Monomial &m);
	friend Polynomial operator-(const Polynomial &p, const Monomial &m);
	friend Polynomial operator*(const Polynomial &p, const Monomial &m);
	friend Polynomial operator+(const Monomial &m, const Polynomial &p);
	friend Polynomial operator-(const Monomial &m, const Polynomial &p);
	friend Polynomial operator*(const Monomial &m, const Polynomial &p);


	int operator[](int exp) const;
    int maxExp() const;
    void sort() const;
    char* getStringRepresentation() const;
	vector<Monomial> getVector() const;
	void setPolynomialAsVector(vector<Monomial>);
	int checkExpPos(int exp) const;
	void negate() const;
	
};

std::ostream& operator << (std::ostream& out, const Polynomial& p);