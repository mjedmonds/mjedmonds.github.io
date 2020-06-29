#ifndef RADIO_H
#define RADIO_H
#include <iostream>
#include <cstdlib>

using namespace std;

class Radio {
public:
	Radio();
	Radio( bool   tuneToAM,
		   double station,
		   int    volumeValue );
	
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