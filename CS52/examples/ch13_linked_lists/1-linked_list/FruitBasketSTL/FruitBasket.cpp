#include <iostream>
#include "Fruit.h"
#include "FruitBasket.h"
#include <algorithm>

namespace cs52 {

FruitBasket::FruitBasket() : listOfFruit() {
}

FruitBasket::FruitBasket( Fruit f1 ) {
	addToBasket( f1 );
}

FruitBasket::FruitBasket( Fruit f1, Fruit f2 ) {
	addToBasket( f1 );
	addToBasket( f2 );
}

FruitBasket::FruitBasket( Fruit f1, Fruit f2, Fruit f3 ) {
	addToBasket( f1 );
	addToBasket( f2 );
	addToBasket( f3 );
}

bool FruitBasket::isEmpty() const {
	return( listOfFruit.empty() );
}

void FruitBasket::addToBasket( const Fruit & f ) {
	listOfFruit.push_front( f );
}

bool FruitBasket::containsFruit( const Fruit & f ) const {
	using namespace std;
	bool found = false;
	list< Fruit >::const_iterator resultIter = find( listOfFruit.begin(), listOfFruit.end(), f );
	if (resultIter != listOfFruit.end()) {
	   found = true;
	}
	return( found );
}

std::ostream & operator <<( std::ostream & outs, const FruitBasket & fb ) {
	using namespace std;
	if (fb.isEmpty()) {
		outs << "Basket is empty!" << std::endl;
	}
	else {
		ostream_iterator< Fruit > outputIterator( outs, "\n" );
		copy( fb.listOfFruit.begin(), fb.listOfFruit.end(), outputIterator );
	}
	return( outs );
}

FruitBasket operator + ( const FruitBasket & fb, const Fruit & f ) {
	using namespace std;
	FruitBasket newBasket;
	newBasket.addToBasket( f );
	copy( fb.listOfFruit.begin(), fb.listOfFruit.end(), front_inserter( newBasket.listOfFruit ) );
	return( newBasket );
}

FruitBasket operator - ( const FruitBasket & fb, const Fruit & f ) {
	using namespace std;
	FruitBasket newBasket;
	remove_copy( fb.listOfFruit.begin(), fb.listOfFruit.end(), front_inserter( newBasket.listOfFruit ), f );
	return( newBasket );
}

bool  operator < ( const FruitBasket & fb1, const FruitBasket &fb2 ) {
	return( fb1.listOfFruit.size() < fb2.listOfFruit.size() );
}

bool  operator > ( const FruitBasket & fb1, const FruitBasket &fb2 ) {
	return( fb1.listOfFruit.size() > fb2.listOfFruit.size() );
}

bool  operator ==( const FruitBasket & fb1, const FruitBasket &fb2 ) {
	using namespace std;
	bool result = false;
	// throws an error if fb2 is empty or not as long as fb1
	try {
		result = equal( fb1.listOfFruit.begin(), fb1.listOfFruit.end(),
						fb2.listOfFruit.begin() );
	} catch(...) {

	}
	return( result );
}

}