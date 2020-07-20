#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

namespace cs52 {

class Person {
public:
	Person();
	Person( std::string name, std::string address );

	std::string getName();
	std::string getAddress();
	void setName( std::string name );
	void setAddress( std::string address );

	friend std::ostream& operator<<( std::ostream& outs, 
		                             const Person& p );
	friend std::ostream& operator<<( std::ostream& outs, 
		                             const Person* p );

private:


protected:
	std::string my_name;
	std::string my_address;

};

}
#endif