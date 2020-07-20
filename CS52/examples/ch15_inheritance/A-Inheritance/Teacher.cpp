#include "Teacher.h"

using namespace cs52;

namespace cs52 {

Teacher::Teacher() {

}

// note the use of an initializer list here
Teacher::Teacher( std::string name, std::string address,
				  std::string dept ) : Person( name, address ), 
				                       my_department( dept ) {
}

std::string Teacher::getDepartment() {
	return( my_department );
}

void Teacher::setDepartment( std::string dept ) {
	my_department = dept;
}

std::ostream& operator<<( std::ostream& outs, 
						  const Teacher& t ) {
	Person p = t;
	outs << p;
	outs << " department=" << t.my_department;
	return( outs );
}

}

