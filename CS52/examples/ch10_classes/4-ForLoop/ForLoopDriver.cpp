#include <iostream>
#include <string>

using namespace std;

// This program demonstrates how to work with for loops

int main(int argc, char* argv[])
{
	int i, num;
	string s, name;

	cout << "How many students are watching? ";
	cin  >> num;

	for (i = 1; i <= num; i++) {
		cout << "Enter Student # " << i << "'s Name: ";
		cin  >> s;
		if (i == 1)
			name = s;
		else
			if (s < name) 
				name = s;
	}

	cout << "My favorite name is: " << name << endl;

	return( 0 );
}

