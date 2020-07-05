#include <iostream>
#include <string>
using namespace std;

//#define ITERATIVE          // take this out for recursive solution

void fill_array( int dataArray[], int maxSize, int& filledSlots );
int find_in_array( int dataArray[], int maxSize, int searchValue );
int find_in_array( int dataArray[], int maxSize, int searchValue, int position );
void print_array( int dataArray[], int filledSlots );

int main() {
	int a[ 50 ];
	const int SIZE = 50;
	int filledSlots;
	int value;
	int position;

	cout << "Please provide a pile of integers:";
	fill_array( a, SIZE, filledSlots );
	print_array( a, filledSlots );

	cout << "Please provide a value to search for:";
	cin  >> value;
	position = find_in_array( a, filledSlots, value );
	if (position != -1) {
		cout << value << " was found at position=" << position;
	}
	else {
		cout << "YOU SILLY.... " << value << " was not found in the array";
	}
	cout << endl;
	return( 0 );
}


void fill_array( int dataArray[], int maxSize, int& filledSlots ) {
	string s, part;
	getline( cin, s );
	int index = 0;
	int start = 0, space = 0;
	bool nomorespaces = false;
	while (!nomorespaces) {
		space = s.find( " ", start );
		if (space > 0) {
			part = s.substr( start, space - start );
		}
		else {
			part = s.substr( start, s.length() - start );
			nomorespaces = true;   /// ends the loop
		}
		dataArray[ index ] = atoi( part.c_str() );
		index++;
		space++;
		start = space;
	}
	filledSlots = index;
}

int find_in_array( int dataArray[], int maxSize, int searchValue ) {
	int position = 0;
#ifdef ITERATIVE
	for (position = 0; position < maxSize; ++position) {
		if (dataArray[ position ] == searchValue) {
			break;
		}
	}
	if (position == maxSize)
		position = -1;
	return( position );
#else
	return( find_in_array( dataArray, maxSize, searchValue, position ) );
#endif
}

int find_in_array( int dataArray[], int maxSize, int searchValue, int position ) {
	// base case: position > maxSize
	if (position >= maxSize) 
		return -1;
	// base case: searchValue = dataArray[ position ]
	else if (searchValue == dataArray[ position ]) 
		return( position );
	// recursive case: keep looking further down the array
	else
		return find_in_array( dataArray, maxSize, searchValue, ++position );
}

void print_array( int dataArray[], int filledSlots ) {
	for (int i = 0; i < filledSlots; i++) {
		cout << "array[" << i << "] = " << dataArray[i] << endl;
	}
}


