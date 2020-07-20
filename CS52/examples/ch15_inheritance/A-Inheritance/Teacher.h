#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>

#include "Person.h"

namespace cs52 {

class Teacher : public Person {
public:
	Teacher();
	Teacher( std::string name, std::string address, 
		     std::string dept );

	std::string getDepartment();
	void setDepartment( std::string dept );

	friend std::ostream& operator<<( std::ostream& outs, 
		                             const Teacher& t );
private:


protected:
	std::string my_department;

};

}
#endif