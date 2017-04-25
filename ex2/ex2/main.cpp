#include "Monomial.h"
#include "Polynomial.h"


int main2() {
	//Monomial m1(3,4);
	//Monomial m2(2, 4);
	//m1 += m2;
	//m1 *= m2;
	//Monomial m3(10, 8);
	//auto check = (m1 == m3);
	//m3.negate();

	//Monomial m4(0, 10);
	//Monomial m5(1, 10);
	//Monomial m6(1, 0);
	//Monomial m7(1, 1);
	//Monomial m8(1, 2);
	//Monomial m9(2, 2);
	//cout << m4.stringRepresentation() << endl;
	//cout << m5.stringRepresentation() << endl;
	//cout << m6.stringRepresentation() << endl;
	//cout << m7.stringRepresentation() << endl;
	//cout << m8.stringRepresentation() << endl;
	//cout << m9 << endl;
	//m9 >> "4x";
	//cout << m9 << endl;

	//Polynomial p1,p2;
	//p1 >> "-2x+5x^2-3";
	//cout << p1[3] << endl;
	//p1.sort();
	//cout << (p2 >> "-5") << endl;
	//cout << p2.maxExp() << endl;
	//Monomial m10(3, 2);
	//p2 = m10 + p1;
	//p2 = p1 + m10;
	//p1 = p1 + p1;
	//Monomial m1(3, 2);
	//Monomial m2(3, 2);
	//Monomial m3(3, 2);
	//m3 = m2 * m1;



	Polynomial p1;
	cout << (p1 >> "5x^2-5x+5+7x^3+9x+8x^4-6") << endl;
	p1.sort();
	cout << p1 << endl;
	//8x^4+7x^3+5x^2+4x-1
	auto p2 = p1;
	p2 -= p1;
	//cout << p2 << endl;

	return 0;
}
