#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

#include "Person.h"

namespace cs52 {

class Student : public Person {
public:
	Student();
	Student( std::string name, std::string address, 
		     std::string id,   std::string gpa );

	std::string getGPA();
	void setGPA( std::string gpa );
	std::string getID();
	void setID( std::string id );


	friend std::ostream& operator<<( std::ostream& outs, 
		                             const Student& s );
	friend std::ostream& operator<<( std::ostream& outs, 
		                             const Student* s );

private:


protected:
	std::string my_ID;
	std::string my_GPA;
};

}
#endif