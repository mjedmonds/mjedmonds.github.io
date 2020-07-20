// ListDriver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>

#include "List.h"
#include "ListNode.h"

enum CHOICE { PRINT, QUIT, PUSH_BACK, PUSH_FRONT, REMOVE, ISEMPTY, MAKEEMPTY };
CHOICE menu();

int main(int argc, char* argv[])
{
  using namespace cs52;
  using namespace std;

  List l;
  CHOICE c;
  int value;

  do {
    c = menu();
    switch( c ) {
    case PRINT:
      cout << l;
      break;
    case ISEMPTY:
      if (l.isEmpty()) {
        cout << "list is empty" << endl;
      }
      else {
        cout << "list is not empty" << endl;
      }
      break;
    case MAKEEMPTY:
      l.makeEmpty();
      break;
    case PUSH_BACK:
      cout << "enter an int to insert at the back of the list: ";
      cin  >> value;
      l.push_back( value );
      break;
    case PUSH_FRONT:
      cout << "enter an int to insert at the front of the list: ";
      cin  >> value;
      l.push_front( value );
      break;
    case REMOVE:
      cout << "enter an int to remove: ";
      cin  >> value;
      l.remove( value );
      break;
    }
  } while (c != QUIT);

  return( 0 );
}

CHOICE menu() {
  using namespace std;
  char c;
  CHOICE result;
  cout << "i(S)empty (M)akeEmpty Push(F)ront Push(B)ack (R)emove (P)rint (Q)uit: ";
  cin  >> c;
  switch( c ) {
  case 'S':
  case 's':
    result = ISEMPTY;
    break;
  case 'M':
  case 'm':
    result = MAKEEMPTY;
    break;
  case 'B':
  case 'b':
    result = PUSH_BACK;
    break;
  case 'F':
  case 'f':
    result = PUSH_FRONT;
    break;
  case 'R':
  case 'r':
    result = REMOVE;
    break;
  case 'P':
  case 'p':
    result = PRINT;
    break;
  case 'Q':
  case 'q':
    result = QUIT;
    break;
  default:
    result = menu();
  }
  return( result );
}
