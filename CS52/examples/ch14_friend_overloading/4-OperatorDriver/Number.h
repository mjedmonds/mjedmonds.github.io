#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <cstdlib>

namespace cs52 {

class Number {
public:
	Number();
	Number( int initValue );

	void setValue( int v );
	int  getValue() const;
	void printRomanNumeral() const;

	friend Number operator + ( const Number& left, const Number& right );
	friend Number operator - ( const Number& left, const Number& right );
	friend bool   operator ==( const Number& left, const Number& right );
	friend Number operator / ( const Number& left, const Number& right );
	friend Number operator * ( const Number& left, const Number& right );
	
private:
	int value;
};

}

#endif