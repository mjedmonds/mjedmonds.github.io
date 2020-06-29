#include <iostream>
#include <cstdlib>

#include "Radio.h"

using namespace std;

Radio::Radio() {
	tuneToFM();
	setStation( 88.5 );
	volume = 5; 
}

Radio::Radio( bool   tuneToAM,
			  double station,
			  int    volumeValue ) {
	tunedOnAM = tuneToAM,
	setStation( station );
	volume = volumeValue;
}
	
void Radio::tuneToAM() {
	if (!tunedOnAM) {
		tunedOnAM = true;
		setStation( 590.0 );
	}
}

void Radio::tuneToFM() {
	if (tunedOnAM) {
		tunedOnAM = false;
		setStation( 88.5 );
	}
}
bool Radio::isOnAM() {
	return( tunedOnAM );
}

void Radio::setStation( double station ) {
	stationValue = station;
}

double Radio::getStation() {
	return( stationValue );
}

void Radio::incVolume() {
	volume++;
}

void Radio::decVolume() {
	volume--;
}

int Radio::getVolume() {
	return( volume );
}

