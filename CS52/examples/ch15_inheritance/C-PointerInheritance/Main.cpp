#include <iostream>

#include "Person.h"
#include "Teacher.h"
#include "Student.h"


int main() {
	using namespace std;
	using namespace cs52;

	Person* p = new Person( "Howie", "Los Angeles" );
	Teacher* t = new Teacher( "HowieTeacher", "Santa Monica", "Business" );
	Student* s = new Student( "Howie", "Los Angeles", "102", "3.5" );

	cout << p << endl;
	cout << t << endl;
	cout << s << endl;

	delete( p );
	delete( t );
	delete( s );
	
	return( 0 );
}