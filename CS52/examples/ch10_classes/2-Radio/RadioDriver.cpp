// RadioDriver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>

#include "Radio.h"

void dumpRadio( Radio r );

int main(int argc, char* argv[])
{
	Radio myRadio = Radio();
	Radio yourRadio = Radio( true, 90.9, 10 );

	cout << "===myRadio===" << endl;
	dumpRadio( myRadio );
	cout << "===yourRadio===" << endl;
	dumpRadio( yourRadio );

	return( 0 );
}

void dumpRadio( Radio r ) {
	if (r.isOnAM()) {
		cout << "AM:";	
	}
	else {
		cout << "FM:";
	}
	cout << r.getStation();
	cout << "\tvolume=" << r.getVolume();
	cout << endl;
}