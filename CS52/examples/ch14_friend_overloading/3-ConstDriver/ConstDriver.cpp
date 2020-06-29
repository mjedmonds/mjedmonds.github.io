// ConstDriver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>

#include "Number.h"

using namespace std;

int main(int argc, char* argv[])
{
	Number four = Number( 4 );
	Number five = Number( 5 );
	Number nine = add( four, five );

	cout << "----9----" << endl;
	nine.printRomanNumeral();

	return( 0 );
}

