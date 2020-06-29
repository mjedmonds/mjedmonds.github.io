#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstdlib>

using namespace std;

class Student {
public:
	Student();

	enum Year { FRESHMAN = 100, SOPHOMORE = 200, 
 				JUNIOR   = 300, SENIOR    = 400 };

	enum Average { A_AVG = 10, B_AVG = 20, C_AVG = 30, 
				   D_AVG = 40, F_AVG = 50, NO_AVG= 60 };
	
	double getGPA();
	int    getYear();
	void   incYear();
	double getUnits();

	bool   testYear( Year year );
	bool   testGPA( Average avg );

	void   addGrade( double unit, double gpa );  
private:
	double totalGPAValue;   // running total of GPA points earned
	double unitValue;		// running total of units earned
	int    yearValue;
};

#endif