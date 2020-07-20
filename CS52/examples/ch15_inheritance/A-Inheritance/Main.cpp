#include <iostream>

#include "Person.h"
#include "Teacher.h"
#include "Student.h"


int main() {
	using namespace std;
	using namespace cs52;

	Person p( "Howie", "Los Angeles" );
	Teacher t( "HowieTeacher", "Santa Monica", "Business" );
	Student s( "Howie", "Los Angeles", "102", "3.5" );

	cout << p << endl;
	cout << t << endl;
	cout << s << endl;

	return( 0 );
}