#include "Auto.h"
#include <iostream>

namespace cs52 {

Auto::Auto() {
  // empty
}

void Auto::insertKey() {
  using namespace std;
  cout << "AUTO--inserting the key" << endl;
}

void Auto::turn() {
  using namespace std;
  cout << "AUTO--turning the key" << endl;
}

void Auto::drive() {
  using namespace std;
  cout << "AUTO--driving the car" << endl;
}

}
