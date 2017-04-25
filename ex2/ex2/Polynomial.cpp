#include "Polynomial.h"
#include <fstream>
#include <streambuf>
#include <functional>

// destructor
Polynomial::~Polynomial() 
{
	if (this->monArr != nullptr)
	{
		delete[] this->monArr;
		this->size = 0;
	}
}

// copy constructor
Polynomial::Polynomial(const Polynomial &p) 
{
	this->size = p.size;
	this->monArr = new Monomial[p.size];
	for(auto i=0; i< p.size; i++)
	{
		this->monArr[i] = p.monArr[i];
	}
}

// overload operator = assignment
const Polynomial & Polynomial::operator=(const Polynomial &p) {
	this->size = p.size;
	this->monArr = new Monomial[p.size];
	for (auto i = 0; i< p.size; i++)
	{
		this->monArr[i] = p.monArr[i];
	}
	return *this;
}

int getNextPos(string s)
{
	auto posPlus = s.find('+');
	auto posMinus = s.find('-');
	if (posMinus < posPlus) return posMinus;
	return posPlus;
}

Polynomial& Polynomial::operator>>(const char* str) {
	string s = str;
	Monomial m;
	vector<Monomial> helpArr;
	// append + to the string if needed
	if (s.size() != 0 && s.at(0) != '-')
		s = '+' + s;
	// run until we handle all Monomial
	while(s.size() > 0)
	{
		// find the next Monomial
		auto posNext = getNextPos(s.substr(1, s.size()));
		auto strTemp = s.substr(1, posNext);
		m >> strTemp.c_str();
		if (s.at(0) == '-')
			m.negate();
		// add Monomial to the vector
		//helpArr.insert(helpArr.end(), m);
		*this += m;
		if (posNext == string::npos)
			break;
		// cut the used string
		s = s.substr(posNext+1, s.size());
	}
	//this->setPolynomialAsVector(helpArr);
	return *this;
}

int Polynomial::checkExpPos(int exp) const
{
	for(auto i=0; i<this->size; i++)
	{
		if(this->monArr[i].getExponent() == exp)
		{
			return i;
		}
	}
	return -1;
}

vector<Monomial> Polynomial::getVector() const
{
	vector<Monomial> helpArr;
	
	for (auto i = 0; i < this->size; i++)
	{
		helpArr.insert(helpArr.end(), this->monArr[i]);
	}
	return helpArr;
}

void Polynomial::setPolynomialAsVector(vector<Monomial> helpArr)
{
	// if alloced before, free it
	if (this->monArr != nullptr)
		delete[]this->monArr;
	// set the size
	this->size = helpArr.size();
	// alloc the arr
	this->monArr = new Monomial[helpArr.size()];
	for (size_t i = 0, j=0; i < helpArr.size(); i++)
	{
		if (helpArr.at(i).getCoefficient() != 0)
		{
			this->monArr[j] = helpArr.at(j);
			j++;
		}
	}
}

const Polynomial & Polynomial::operator+=(const Monomial &m)
{
	auto pos = this->checkExpPos(m.getExponent());
	if (pos != -1)
	{
		// check if zerod
		auto temp = this->monArr[pos];
		temp += m;
		if(temp.getCoefficient() != 0)
		{
			this->monArr[pos] += m;
		}
		else
		{
			// if zeroed remove item
			auto helpArr = this->getVector();
			helpArr.erase(helpArr.begin() + pos);
			this->setPolynomialAsVector(helpArr);
		}
	}
	else
	{
		auto helpArr = this->getVector();
		helpArr.insert(helpArr.end(), m);
		this->setPolynomialAsVector(helpArr);
	}
	return *this;
}

const Polynomial & Polynomial::operator+=(const Polynomial &p)
{
	for(auto i=0; i<p.size; i++)
	{
		this->operator+=(p.monArr[i]);
	}
	return *this;
}

const Polynomial & Polynomial::operator-=(const Monomial &m)
{
	auto pos = this->checkExpPos(m.getExponent());
	if (pos != -1)
	{
		// check if zerod
		auto temp = this->monArr[pos];
		temp -= m;
		if (temp.getCoefficient() != 0)
		{
			this->monArr[pos] -= m;
		}
		else
		{
			// if zeroed remove item
			auto helpArr = this->getVector();
			helpArr.erase(helpArr.begin() + pos);
			this->setPolynomialAsVector(helpArr);
		}
	}
	else
	{
		auto helpArr = this->getVector();
		helpArr.insert(helpArr.end(), m);
		// change to minus
		helpArr.end()->negate();
		this->setPolynomialAsVector(helpArr);
	}
	return *this;
}

const Polynomial & Polynomial::operator-=(const Polynomial &p)
{
	for (auto i = 0; i<p.size; i++)
	{
		this->operator-=(p.monArr[i]);
	}
	return *this;
}

const Polynomial & Polynomial::operator*=(const Monomial &m) const
{
	for (auto i = 0; i<this->size; i++)
	{
		this->monArr[i] *= m;
	}
	return *this;
}

const Polynomial & Polynomial::operator*=(const Polynomial &p)
{
	Polynomial clean;
	for (auto i = 0; i<this->size; i++)
	{
		auto temp = *this;
		for (auto j = 0; j < p.size; j++)
		{
			clean += this->monArr[i] * p.monArr[j];
		}
	}
	*this = clean;
	return *this;
}

int Polynomial::operator[](int exp) const
{
	auto pos = this->checkExpPos(exp);
	if (pos == -1) return 0;
	return this->monArr[pos].getCoefficient();
}


void Polynomial::sort() const
{
	for(auto i=0; i<this->size; i++)
	{
		for(auto j=i; j< this->size; j++)
		{
			if(this->monArr[i].getExponent() < this->monArr[j].getExponent())
			{
				// replace the monos
				auto temp = monArr[i];
				this->monArr[i] = this->monArr[j];
				this->monArr[j] = temp;
			}
		}
	}
}


char* Polynomial::getStringRepresentation() const
{
	string strPolynomial = "";
	if (this->size == 0) {
		strPolynomial = "0";
	}
	for(auto i=0; i < this->size; i++)
	{
		// append the mono
		if (this->monArr[i].getCoefficient() > 0) strPolynomial += '+';
		if (this->monArr[i].getCoefficient() != 0)
			strPolynomial += this->monArr[i].stringRepresentation();
	}
	// remove the + on the start
	if (strPolynomial.at(0) == '+')
		strPolynomial = strPolynomial.substr(1, strPolynomial.length());
	auto outStr = new char[strPolynomial.length() + 1];
	// copy the str
	strcpy(outStr, strPolynomial.c_str());
	return outStr;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
	out << p.getStringRepresentation();
	return out;
}

// find the max exp
int Polynomial::maxExp() const
{
	auto max = -1;
	for (auto i = 0; i<this->size; i++)
	{
		if (this->monArr[i].getExponent() > max)
			max = monArr[i].getExponent();
	}
	return max;
}


Polynomial operator+(const Polynomial &p1, const Polynomial &p2)
{
	auto temp = p1;
	return temp += p2;
}
Polynomial operator-(const Polynomial &p1, const Polynomial &p2)
{
	auto temp = p1;
	return temp -= p2;
}
Polynomial operator*(const Polynomial &p1, const Polynomial &p2)
{
	auto temp = p1;
	return temp *= p2;
}
Polynomial operator+(const Polynomial &p, const Monomial &m)
{
	auto temp = p;
	return temp += m;
}
Polynomial operator-(const Polynomial &p, const Monomial &m)
{
	auto temp = p;
	return temp -= m;
}
Polynomial operator*(const Polynomial &p, const Monomial &m)
{
	auto temp = p;
	return temp *= m;
}
Polynomial operator+(const Monomial &m, const Polynomial &p)
{
	return p + m;
}
Polynomial operator-(const Monomial &m, const Polynomial &p)
{
	auto temp = p - m;
	temp.negate();
	return temp;
}
Polynomial operator*(const Monomial &m, const Polynomial &p)
{
	return p * m;
}


void Polynomial::negate() const
{
	for (auto i = 0; i< this->size; i++)
	{
		this->monArr[i].negate();
	}
}
