#include "Honda.h"
#include <iostream>

namespace cs52 {

Honda::Honda() : Auto() {
  // empty
}

void Honda::insertKey() {
  using namespace std;
  cout << "HONDA--waking up the mouse..." << endl;
}

void Honda::turn() {
  using namespace std;
  cout << "HONDA--feeding the mouse..." << endl;
}

void Honda::drive() {
  using namespace std;
  cout << "HONDA--mouse is turning the wheels..." << endl;
}

}
