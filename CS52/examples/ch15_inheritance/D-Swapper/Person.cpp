#include "Person.h"

using namespace cs52;

namespace cs52 {

Person::Person() {

}

// note the use of an initializer list here
Person::Person( std::string name, std::string address ) : my_name( name ),
														  my_address( address ) {

}

std::string Person::getName() {
	return( my_name );
}

std::string Person::getAddress() {
	return( my_address );
}

void Person::setName( std::string name ) {
	my_name = name;
}

void Person::setAddress( std::string address ) {
	my_address = address;
}

std::ostream& operator<<( std::ostream& outs, 
						  const Person& p ) {
	outs << "name=";
	outs << p.my_name;
	outs << " address=";
	outs << p.my_address;
	return( outs );
}

std::ostream& operator<<( std::ostream& outs, 
						  const Person* p ) {
	if (p == NULL) {
		outs << "NULL pointer";
	}
	else {
		outs << "name=";
		outs << p->my_name;
		outs << " address=";
		outs << p->my_address;
	}
	return( outs );
}

}

