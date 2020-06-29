#include <iostream>
#include <cstdlib>

#include "Student.h"

using namespace std;


Student::Student() {
	totalGPAValue  = 0.0;
	unitValue = 0.0;
	yearValue = Student::FRESHMAN;
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
	switch( yearValue ) {
	case Student::FRESHMAN:
		yearValue = Student::SOPHOMORE;
		break;
	case Student::SOPHOMORE:
		yearValue = Student::JUNIOR;
		break;
	case Student::JUNIOR:
		yearValue = Student::SENIOR;
		break;
	}
}

double Student::getUnits() {
	return( unitValue );
}

bool Student::testYear( Year y ) {
	return( yearValue == y );
}

bool Student::testGPA( Average avg ) {
	bool result = false;
	double gpa = getGPA();
	switch( avg ) {
	case Student::A_AVG:
		result = (gpa >= 3.50);
		break;
	case Student::B_AVG:
		result = (gpa >= 2.50);
		break;
	case Student::C_AVG:
		result = (gpa >= 1.50);
		break;
	case Student::D_AVG:
		result = (gpa >= 0.50);
		break;
	case Student::F_AVG:
		result = (unitValue != 0.0);
		break;
	case Student::NO_AVG:
		result = (unitValue == 0.0);
		break;
	}	
	return( result );
}

// update the running totals earned
void Student::addGrade( double unit, double gpa ) {
	unitValue += unit;
	totalGPAValue  += gpa * unit;
}
