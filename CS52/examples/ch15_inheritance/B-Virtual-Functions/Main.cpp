#include "Auto.h"
#include "Honda.h"
#include <iostream>


int main() {
  using namespace std;
  using namespace cs52;

  cout << "------AUTO------" << endl;
  Auto a;
  a.insertKey();
  a.turn();
  a.drive();

  cout << "------HONDA------" << endl;
  Honda h;
  h.insertKey();
  h.turn();
  h.drive();

  cout << "doing the same thing with pointer variables..." << endl;
  Auto * ptrAuto = NULL;
  ptrAuto = &a;
  cout << "------PTRAUTO POINTING AT AN AUTO------" << endl;
  ptrAuto->insertKey();
  ptrAuto->turn();
  ptrAuto->drive();

  ptrAuto = &h;
  cout << "------PTRAUTO POINTING AT AN HONDA------" << endl;
  // This is where the magic happens.
  // remember ptrAuto is a pointer to an Auto, not to a Honda
  // But since Auto has these marked as virtual functions,
  // the derived class's (Honda) functions are called!
  ptrAuto->insertKey();
  ptrAuto->turn();
  ptrAuto->drive();

    return 0;
}
