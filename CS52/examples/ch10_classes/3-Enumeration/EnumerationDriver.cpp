// EnumerationDriver.cpp : Defines the entry point for the console application.
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
	switch( s.getYear() ) {
	case Student::FRESHMAN:
			cout << "Freshman -" ;
			break;
	case Student::SOPHOMORE:
			cout << "Sophomore -";
			break;
	case Student::JUNIOR:
			cout << "Junior -";
			break;
	case Student::SENIOR:
			cout << "Senior -";
			break;
	}
	cout << " units=" << s.getUnits();
	cout << " gpa="  << s.getGPA();
	cout << " letterGrade=";

	if (s.testGPA( Student::A_AVG )) {
		cout << "A";
	}
	else if (s.testGPA( Student::B_AVG )) {
		cout << "B";
	}
	else if (s.testGPA( Student::C_AVG )) {
		cout << "C";
	}
	else if (s.testGPA( Student::D_AVG )) {
		cout << "D";
	}
	else if (s.testGPA( Student::F_AVG )) {
		cout << "F";
	}
	else if (s.testGPA( Student::NO_AVG )) {
		cout << "No Average Earned Yet";
	}


	cout << endl;
}



