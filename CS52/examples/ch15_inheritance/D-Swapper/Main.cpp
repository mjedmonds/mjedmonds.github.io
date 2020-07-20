#include <iostream>

#include "Person.h"
#include "Student.h"
#include "Teacher.h"

template <class Object>
void swapper( Object & o, Object & p );


int main() {
  using namespace std;
  using namespace cs52;

  Person p( "howard", "LA" );
  Teacher t( "howard the teacher", "SM", "CS/IS" );
  Student s( "howard the student", "LA", "123123", "4.0" );

  cout << "--- before the swapper ---" << endl;
  cout << p << endl;
  cout << s << endl;
  swapper( p, (Person &)s );    /// conversion is required...
  cout << "--- after the swapper ---" << endl;
  cout << p << endl;
  cout << s << endl;

}

template <class Object>
void swapper( Object & o, Object & p ) {
  Object temp = p;
  p = o;
  o = temp;
}
