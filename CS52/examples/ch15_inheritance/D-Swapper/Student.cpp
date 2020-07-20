#include "Student.h"

using namespace cs52;

namespace cs52 {

Student::Student() {

}

// note the use of an initializer list here
Student::Student( std::string name, std::string address,
				  std::string id,   std::string gpa ) : Person( name, address ), 
				                       my_ID( id ), my_GPA( gpa ) {
}

std::string Student::getGPA() {
	return( my_GPA );
}

void Student::setGPA( std::string gpa ) {
	my_GPA = gpa;
}

std::string Student::getID() {
	return( my_ID );
}

void Student::setID( std::string id ) {
	my_ID = id;
}

std::ostream& operator<<( std::ostream& outs, 
						  const Student& s ) {
	Person p = s;
	outs << p;
	outs << " id=" << s.my_ID << " gpa=" << s.my_GPA;
	return( outs );
}

std::ostream& operator<<( std::ostream& outs, 
						  const Student* s ) {
	if (s == NULL) {
		outs << "NULL pointer";
	}
	else {
		const Person* p = s;
		outs << p;
		outs << " id=" << s->my_ID << " gpa=" << s->my_GPA;
	}
	return( outs );
}

}

