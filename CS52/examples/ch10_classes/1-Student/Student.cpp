#include <iostream>
#include <cstdlib>

#include "Student.h"

using namespace std;


Student::Student() {
	totalGPAValue  = 0.0;
	unitValue = 0.0;
	yearValue = 1;
}

// calculate the gpa from the running totals earned
double Student::getGPA() {
	double gpa = 0.0;
	if (totalGPAValue != 0.0) {
		gpa = totalGPAValue / unitValue;
	}
	return( gpa );
}

int Student::getYear() {
	return( yearValue );
}

void Student::incYear() {
	++yearValue;
}

double Student::getUnits() {
	return( unitValue );
}

bool Student::isFreshman() {
	return( yearValue == 1 );
}

bool Student::isSophomore() {
	return( yearValue == 2 );
}

bool Student::isJunior() {
	return( yearValue == 3 );
}

bool Student::isSenior() {
	return( yearValue >= 4 );
}

// update the running totals earned
void Student::addGrade( double unit, double gpa ) {
	unitValue += unit;
	totalGPAValue  += gpa * unit;
}
