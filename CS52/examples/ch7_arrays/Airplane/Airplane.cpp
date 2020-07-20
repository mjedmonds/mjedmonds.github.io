#include "Airplane.h"
#include <stdexcept>

namespace cs52  {

Airplane::Airplane() : myNumberOfPassengersSeenSoFar( 0 ) {
	
}

int  Airplane::getMaxSize() const {
	return( 100 );
}

void Airplane::addPassenger( Passenger p ) {
	if (myNumberOfPassengersSeenSoFar >= getMaxSize()) {
		throw( std::logic_error( "bounds exceeded" ) );
	}
	myPassengers[ myNumberOfPassengersSeenSoFar ] = p;
	myNumberOfPassengersSeenSoFar++;
}

std::ostream & operator <<( std::ostream & outs,
						    const Airplane & a ) {
	outs << "Airplane- max=" << a.getMaxSize() << std::endl;
	for (int i = 0; i < a.myNumberOfPassengersSeenSoFar; i++) {
		outs << "[" << i << "]-";
		outs << a.myPassengers[ i ];
	}
	return( outs );
}

}

