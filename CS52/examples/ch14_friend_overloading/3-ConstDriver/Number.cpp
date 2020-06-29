#include <iostream>
#include <cstdlib>

#include "Number.h"

using namespace std;

// note the friend function is not a member function
// note the use of the const modifier
Number add( const Number& left, const Number& right ) {
	Number temp = Number( left.value + right.value );
	return( temp );
}

Number::Number() {
	value = 0;
}

Number::Number( int initValue ) {
	value = initValue;
}

void Number::setValue( int v ) {
	value = v;
}

// note the use of the const modifier
int  Number::getValue() const {
	return( value );
}

// note the use of the const modifier
void Number::printRomanNumeral() const {
	// uses cout
	int remainder = value;
	int thousands = remainder / 1000;
	remainder -= thousands * 1000;
	int fivehundreds = remainder / 500;
	remainder -= fivehundreds * 500;
	int hundreds = remainder / 100;
	remainder -= hundreds * 100;
	int fiftys = remainder / 50;
	remainder -= fiftys * 50;
	int tens = remainder / 10;
	remainder -= tens * 10;
	int fives = remainder / 5;
	remainder -= fives * 5;
	int ones = remainder;

	int i;

	for (i = 1; i <= thousands; ++i)
		cout << "M";
	if (fivehundreds == 1 && hundreds == 4) {
		cout << "CM";
		fivehundreds = 0;
		hundreds = 0;
	}
	for (i = 1; i <= fivehundreds; ++i)
		cout << "D";
	if (hundreds == 4) {
		cout << "CD";
		hundreds = 0;
	}
	for (i = 1; i <= hundreds; ++i)
		cout << "C";
	if (fiftys == 1 && tens == 4) {
		cout << "XC";
		fiftys = 0;
		tens = 0;
	}
	for (i = 1; i <= fiftys; ++i)
		cout << "L";
	if (tens == 4) {
		cout << "XL";
		tens = 0;
	}
	for (i = 1; i <= tens; ++i)
		cout << "X";
	if (fives == 1 && ones == 4) {
		cout << "IX";
		ones = 0;
		fives = 0;
	}
	for (i = 1; i <= fives; ++i)
		cout << "V";
	if (ones == 4) {
		cout << "IV";
		ones = 0;
	}
	for	(i = 1; i <= ones; ++i)
		cout << "I";
	cout << endl;
}


