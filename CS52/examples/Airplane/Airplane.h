#ifndef AIRPLANE_H
#define AIRPLANE_H
#include "Passenger.h"

namespace cs52  {

class Airplane {
public:
	Airplane();

	void addPassenger( Passenger p );
	int  getMaxSize() const;
	friend std::ostream & operator <<( std::ostream & outs,
									   const Airplane & a );

private:
	// every airplane is identical
	// each one has exactly 100 seats   kinda unrealistic...
	Passenger myPassengers[100];
	int myNumberOfPassengersSeenSoFar;
};

}

#endif