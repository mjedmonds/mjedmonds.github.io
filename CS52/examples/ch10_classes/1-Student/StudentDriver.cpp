// StudentDriver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>

#include "Student.h"

using namespace std;

void dumpStudent( Student s );

int main(int argc, char* argv[])
{
	Student s = Student();

	cout << "====initial====" << endl;
	dumpStudent( s );

	s.addGrade( 4.0, 4.0 );   // add an A
	cout << "====A====" << endl;
	dumpStudent( s );

	s.addGrade( 4.0, 3.0 );   // add a B
	cout << "====A & B====" << endl;
	dumpStudent( s );

	s.addGrade( 4.0, 2.0 );   // add a C
	cout << "====A & B & C====" << endl;
	dumpStudent( s );

	s.incYear();
	cout << "====Sophomore====" << endl;
	dumpStudent( s );

	return( 0 );
}

void dumpStudent( Student s ) {
	if (s.isFreshman()) {
		cout << "Freshman -" ;
	}
	else if (s.isSophomore()) {
		cout << "Sophomore - ";
	}
	else if (s.isJunior()) {
		cout << "Junior - ";
	}
	else {
		cout << "Senior - ";
	}
	cout << "units=" << s.getUnits();
	cout << " gpa="  << s.getGPA();
	cout << endl;
}

