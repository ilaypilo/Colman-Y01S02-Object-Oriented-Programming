#include "Monomial.h"

// overload operator +=
const Monomial & Monomial::operator+=(const Monomial &m) {
	if (m.exponent != this->exponent) {
		throw "different exponents";
	}
	this->coefficient += m.coefficient;
	return *this;
}
// overload operator -=
const Monomial & Monomial::operator-=(const Monomial &m) {
	if (m.exponent != this->exponent) {
		throw "different exponents";
	}
	this->coefficient -= m.coefficient;
	return *this;
}

// overload operator *=
const Monomial & Monomial::operator*=(const Monomial &m) {
	this->coefficient *= m.coefficient;
	this->exponent += m.exponent;
	return *this;
}
// overload operator *
Monomial Monomial::operator*(const Monomial &m) const {
	return Monomial(this->coefficient * m.coefficient, this->exponent + m.exponent);
}
// overload operator ==
bool Monomial::operator==(const Monomial &m) const {
	return (this->coefficient == m.coefficient && this->exponent == m.exponent);
}
// present the Monomial as ax^n
char* Monomial::stringRepresentation() const {
	string strMonomial = "";
	// retrun 0
	if (this->coefficient == 0) {
		strMonomial = to_string(0);
	}
	else {
		if (this->coefficient != 1 || this->coefficient == 1 && this->exponent == 0) {
			// Append the coefficient
			strMonomial += to_string(this->coefficient);
		}
		if (this->exponent != 0) {
			// Append the x 
			strMonomial += "x";
			if (this->exponent != 1) {
				// Append the exponent 
				strMonomial += "^" + to_string(this->exponent);
			}
		}
	}
	auto outStr = new char[strMonomial.length() + 1];
	// copy the str 
	strcpy(outStr, strMonomial.c_str());
	return outStr;
}

std::ostream& operator<<(std::ostream& out, const Monomial& m) {
	out << m.stringRepresentation();
	return out;
}

//std::istream& operator>>(std::istream& in, Monomial& m) {
Monomial& Monomial::operator>>(const char* str){
	string s = str, strExpo = "1", strCoeff = "1";
	auto posCoeff = s.find('x');
	auto posExpo = s.find('^');
	if (posCoeff == string::npos)
	{
		this->coefficient = stoi(s);
		this->exponent = 0;
	}
	else
	{
		if (posCoeff != 0)
			strCoeff = s.substr(0, posCoeff);
		if (strCoeff.at(0) == '-' && strCoeff.at(1) == 'x') strCoeff += '1';
		if (posExpo != string::npos)
			strExpo = s.substr(posExpo + 1, s.size());
		this->coefficient = stoi(strCoeff);
		this->exponent = stoi(strExpo);
	}
	return *this;
}