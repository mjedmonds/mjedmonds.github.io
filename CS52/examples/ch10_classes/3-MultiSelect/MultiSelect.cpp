#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This program demonstrates how to work with cctype functions
// It also uses various multi-select flow of control structures
// like switch statements

void display( bool alpha, bool digit, bool upper, bool lower );
string val( bool b );

int main(int argc, char* argv[])
{
	char c;

	cout << "Please enter a character to study: ";
	cin  >> c;

	if (isalpha( c )) {
		if (isupper( c )) {
			display( true, false, true, false );
		}
		else if (islower( c )) {
			display( true, false, false, true );
		}
	}
	else if (isdigit( c )) {
		display( false, true, false, false );
		switch( c ) {
		case '0':
		case '2':
		case '4':
		case '6':
		case '8':
			cout << "\tdigit appears even!" << endl;
			break;
		default:
			cout << "\tdigit appears odd!" << endl;
			break;
		}
	}

	switch( c ) {
	case '!':
	case '@':
	case '#':
	case '$':
	case '%':
	case '^':
	case '&':
	case '*':
	case '(':
	case ')':
	case '_':
	case '+':
		cout << "\tI think you hit the shift key!" << endl;
		break;
	}

	return( 0 );
}

void display( bool alpha, bool digit, bool upper, bool lower ) {
	cout << "\talphanumeric:" << val(alpha);
	cout << "\tdigit:"        << val(digit);
	cout << "\tuppercase:"    << val(upper);
	cout << "\tlowercase:"    << val(lower);
	cout << endl;
}

string val( bool b ) {
	string s;
	if (b) {
		s = "true";
	}
	else {
		s = "false";
	}
	return( s );
}