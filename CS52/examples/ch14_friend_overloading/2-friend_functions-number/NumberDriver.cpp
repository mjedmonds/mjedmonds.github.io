// NumberDriver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>

#include "Number.h"

using namespace std;

Number add( Number left, Number right );

int main(int argc, char* argv[])
{
	cout << "----120----" << endl;
	Number n = Number( 120 );
	n.printRomanNumeral();

	cout << "----99----" << endl;
	n.setValue( 99 );
	n.printRomanNumeral();

	Number four = Number( 4 );
	Number five = Number( 5 );
	Number nine = add( four, five );

	cout << "----9----" << endl;
	nine.printRomanNumeral();

	return( 0 );
}


