// InsertExtract.cpp : Defines the entry point for the console application.
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
	Number n;

	cout << "---9---" << endl;
	cout << four + five;

	cout << "Enter an integer:";
	cin  >> n;
	cout << "-------" << endl;
	cout << n;

	return( 0 );
}

