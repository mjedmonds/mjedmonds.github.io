#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <cstdlib>

using namespace std;


class Number {
public:
	Number();
	Number( int initValue );

	void setValue( int v );
	int  getValue() const;
	void printRomanNumeral() const;

	friend Number add( const Number& left, const Number& right );
private:
	int value;
};

#endif