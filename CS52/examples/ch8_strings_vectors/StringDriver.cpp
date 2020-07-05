#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

void analyze( string s );
void peek( string s );

int main() {
	// Let's play with string variables
	// They are *so* much nicer than char *
	string s;

	cout << "Gimme a line of data to read" << endl;
	getline( cin, s );
	analyze( s );

	return( 0 );
}

void analyze( string s ) {
	int i = 0;

	while (i < s.length() ) {
		int locationOfSpace = s.find_first_of( " ", i + 1 );
		if ( i == 0 )
			peek( s.substr( i, locationOfSpace - i ) );
		else 
			peek( s.substr( i + 1, locationOfSpace - i ) );
		i = locationOfSpace;
	}
}

void peek( string s ) {
	bool isNumber = true;
	bool isAlpha = true;
	bool isUCase = true;
	bool isLCase = true;
	cout << s << "\t----> ";
	for (int i = 1; i < s.length(); i++) {
		if (isdigit( s.at( i ) ) || s.at(i) == '.' ) {
			isNumber = (isNumber && true);
			isAlpha  = false;
			isLCase  = false;
			isUCase  = false;
		}
		else if (isalpha( s.at( i ) )) {
			isNumber = false;
			isAlpha  = (isAlpha && true);
			if (isupper( s.at(i) )) {
				isUCase = (isUCase && true);
				isLCase = false;
			}
			if (islower( s.at(i) )) {
				isLCase = (isLCase && true);
				isUCase = false;
			}
		}
	}
	if (isAlpha) {
		cout << "looks ";
		if (isLCase)
			cout << "lowercase ";
		else if (isUCase)
			cout << "uppercase ";
		else
			cout << "mixed case ";
		cout << "alphanumeric" << endl;
	}
	else if (isNumber) {
		cout << "looks numeric" << endl;
	}
	else {
		cout << " i can't make heads or tails of it!" << endl;
	}
}