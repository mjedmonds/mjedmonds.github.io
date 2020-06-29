// OperatorDriver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>

#include "Number.h"

int main(int argc, char* argv[])
{
	using namespace std;
	using namespace cs52;

	Number four = Number( 4 );
	Number five = Number( 5 );

	cout << "----9----" << endl;
	Number nine = four + five;
	nine.printRomanNumeral();

	cout << "----1----" << endl;
	Number one = five - four;
	one.printRomanNumeral();

	if (four == five) {
		cout << "four equals five" << endl;
	}
	else {
		cout << "four does not equal five" << endl;
	}

	return( 0 );
}

