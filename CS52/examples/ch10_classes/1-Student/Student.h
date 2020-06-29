#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstdlib>

using namespace std;

class Student {
public:
	Student();

	double getGPA();
	int    getYear();
	void   incYear();
	double getUnits();

	bool   isFreshman();
	bool   isSophomore();
	bool   isJunior();
	bool   isSenior();

	void   addGrade( double unit, double gpa );  
private:
	double totalGPAValue;   // running total of GPA points earned
	double unitValue;		// running total of units earned
	int    yearValue;
};

#endif