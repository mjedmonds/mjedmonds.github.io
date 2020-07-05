// Array1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

void fillarraywithinput( int array[], const int& size );

int main(int argc, char* argv[])
{
	int size = 1024;
    	int dataarray[ 1024 ];
	int i;

	// read from cin
	fillarraywithinput( dataarray, size );

	// sort
	for (i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (dataarray[i] < dataarray[j]) {
				int temp = dataarray[ i ];
				dataarray[ i ] = dataarray[ j ];
				dataarray[ j ] = temp;
			}

	// print out
	for (i = 0; i < size; i++) {
		cout << dataarray[i] << " ";
	}
	cout << endl;

	return 0;
}

void fillarraywithinput( int array[], const int& size ) {
	string data;
	int k = 0;
	int startcntr = 0, endcntr = 0;
	cout << "Enter one line of data to sort" << endl;
	getline( cin, data );
	data += " ";  // in case string does not end with whitespace
	for (endcntr = 0; endcntr < data.length(); ++endcntr) {
		if (isspace(data.at(endcntr)) && startcntr <= endcntr) {
			string bit = data.substr( startcntr, endcntr - startcntr + 1 );
			if (isspace( bit.at(0) )) {
				startcntr = endcntr + 1;
				continue;
			}
			int value = atoi( bit.c_str() );
			array[ k++ ] = value;
			startcntr = endcntr + 1;
		}
	}
	size = k;
}
