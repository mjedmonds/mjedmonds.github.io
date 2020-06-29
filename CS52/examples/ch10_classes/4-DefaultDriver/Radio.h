#ifndef RADIO_H
#define RADIO_H
#include <iostream>
#include <cstdlib>

using namespace std;

class Radio {
public:
	// note use of default parameter values
	Radio( bool   tuneToAM = false,
		   double station = 88.5,
		   int    volumeValue = 5);
	
	void   tuneToAM();
	void   tuneToFM();
	bool   isOnAM();
	void   setStation( double station );
	double getStation();
	void   incVolume();
	void   decVolume();
	int    getVolume();
private:
	int    volume;
	double stationValue;
	bool   tunedOnAM;
};

#endif