#include <string>
#include <iostream>
#include "Airplane.h"
#include "Passenger.h"

enum MENU { PRINT, QUIT, ADDPASSENGER, NEWPLANE };
MENU menu();

void main() {
	using namespace cs52;
	using namespace std;

	// Here's the airplane we will fool around with...
	Airplane a;
	Passenger p;
	std::string name;
	MENU choice = QUIT;
	do {
		choice = menu();
		switch( choice ) {
		case NEWPLANE:
			// throw away the existing airplane...
			a = Airplane();
			break;
		case PRINT:
			cout << a;
			break;
		case ADDPASSENGER:
			cout << "Gimme a passenger name:";
			cin >> name;
			Passenger p( name );
			try {
				a.addPassenger( p );
			} catch( std::logic_error le ) {
				cout << "addPassenger was refused... plane is full!" << endl;
			}
			break;
		}
	} while (choice != QUIT);
}

MENU menu() {
	using namespace std;
	MENU result = QUIT;
	char c;
	cout << "(N)ewPlane (A)ddPassenger (P)rint (Q)uit:";
	cin >> c;
	switch( c ) {
	case 'N':
	case 'n':
		result = NEWPLANE;
		break;
	case 'A':
	case 'a':
		result = ADDPASSENGER;
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
		break;
	}
	return( result );
}