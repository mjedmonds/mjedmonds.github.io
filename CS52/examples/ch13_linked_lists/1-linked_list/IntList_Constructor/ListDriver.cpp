// ListDriver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>

#include "List.h"
#include "ListNode.h"

enum CHOICE { PRINT1STLIST, PRINT2NDLIST, QUIT, PUSH_BACK, PUSH_FRONT, REMOVE, ISEMPTY, MAKEEMPTY, EQUATE };
CHOICE menu();

int main(int argc, char* argv[])
{
  using namespace cs52;
  using namespace std;

  List l;
  List l2;
  CHOICE c;
  int value;

  do {
    c = menu();
    switch( c ) {
    case PRINT2NDLIST:
      cout << l2;
      break;
    case PRINT1STLIST:
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
      cout << "enter an int to remove:";
      cin  >> value;
      l.remove( value );
      break;
    case EQUATE:
      cout << "doing--> list2 = listl;" << endl;
      l2 = l;
      break;
    }
  } while (c != QUIT);

  return( 0 );
}

CHOICE menu() {
  using namespace std;
  char c;
  CHOICE result;
  cout << "i(S)empty (M)akeEmpty (I)nsert (R)emove Print(1)stList Print(2)ndList (E)quate (Q)uit:";
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
  case '1':
    result = PRINT1STLIST;
    break;
  case '2':
    result = PRINT2NDLIST;
    break;
  case 'Q':
  case 'q':
    result = QUIT;
    break;
  case 'E':
  case 'e':
    result = EQUATE;
    break;
  default:
    result = menu();
  }
  return( result );
}
