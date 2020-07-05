// Array2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

void dumparray( ostream& out, int array[], int size );
void usage();
void fillarraywithinput( int array[], int& size );
void fillarray( int array[], int size, char * filename ); 
void runsort( int array[], int size );
int getlength( char * filename );
void swap( int array[], int i , int j );


// Command-line has the form
// Array2 [-help] [-print] [-i infile] [-o outfile]
// datafile will be read from cin if not provided
// -print means show sorted array when finished
// by default, runs in no-print mode
int main(int argc, char* argv[])
{
	char * f = new char[ 1024 ];
	char * infile = new char[ 1024 ];
	char * outfile = new char[ 1024 ];
	bool input_provided = false;
	bool output_provided = false;
	bool show_results = false;
	int size = 0;
    int dataarray[ 1024 ];

	for (int i = 1; i < argc; ++i) {
		if (strcmp( argv[i], "-help" ) == 0) {
			usage();
			exit(0);
		}
		if (strcmp( argv[i], "-print" ) == 0) {
			show_results = true;
		}
		else if (input_provided) {
			strcpy( infile, argv[i] );
		}
		else if (output_provided) {
			strcpy( outfile, argv[i] );
		}
		else if (strcmp( argv[i], "-i" ) == 0) {
			input_provided = true;
		}
		else if (strcmp( argv[i], "-o" ) == 0) {
			output_provided = true;
		}
	}
	if (input_provided) {
		size = getlength( infile );
		// cs52 does know about pointers yet
		// so just ignore resizing the array
		// dataarray = new int[ size ];
		fillarray( dataarray, size, infile );
	}
	else {
		size = 128;
		// cs52 does know about pointers yet
		// so just ignore resizing the array
		// dataarray = new int[ 128 ];
		fillarraywithinput( dataarray, size );
	}

	runsort( dataarray, size );

	if (show_results) {
		dumparray( cout, dataarray, size );
	}
	if (output_provided) {
		ofstream out;
		out.open( outfile );
		if (!out.fail()) {
			dumparray( out, dataarray, size );
		}
		else {
			cerr << "Error opening output file" << endl;
			exit( 1 );
		}
	}

	delete( infile );
	delete( outfile );
	//delete( dataarray );
	return 0;
}

void dumparray( ostream& out, int array[], int size ) {
	for (int i = 0; i < size; i++) {
		out << array[i] << " ";
	}
	out << endl;
}

int getlength( char * filename ) {
	ifstream fin;
	int value;
	int size = 0;
	fin.open( filename );
	if (fin.fail()) {
		cout << "Input file opening failed for filename=" << filename << endl;
		exit( 1 );
	}
	while (!fin.eof()) {
		fin >> value;
		size++;
	}
	fin.close();
	return( size - 1 );
}

void fillarray( int array[], int size, char * filename ) {
	ifstream fin;
	int i = 0;
	fin.open( filename );
	if (fin.fail()) {
		cout << "Input file opening failed for filename=" << filename << endl;
		exit( 1 );
	}
	while (!fin.eof()) {
		fin >> array[ i ];
		i++;
	}
	fin.close();
}

void runsort( int array[], int size ) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (array[i] < array[j])
				swap( array, i , j );
}

void swap( int array[], int i , int j ) {
	int temp = array[ i ];
	array[ i ] = array[ j ];
	array[ j ] = temp;
}

void usage() {
	cout << "Array2 [-help|-print] [-i infile] [-o outfile]" << endl;
	cout << "datafile will be read from cin, if not provided" << endl;
	cout << "-print means show sorted array when finished" << endl;
	cout << "by default, runs in silent mode" << endl;
}

void fillarraywithinput( int array[], int& size ) {
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
