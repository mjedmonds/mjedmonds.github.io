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
	int  getValue();
	void printRomanNumeral();

	friend Number add( Number left, Number right );
private:
	int value;
};

#endif