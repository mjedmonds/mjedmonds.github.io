#include <iostream>
#include "Fruit.h"
#include "FruitBasket.h"

using namespace std;

namespace cs52 {

FruitBasket::FruitBasket() {
	numberOccupants = 0;
}

FruitBasket::FruitBasket( Fruit f1 ) {
	numberOccupants = 0;
	addToBasket( f1 );
}

FruitBasket::FruitBasket( Fruit f1, Fruit f2 ) {
	numberOccupants = 0;
	addToBasket( f1 );
	addToBasket( f2 );
}

FruitBasket::FruitBasket( Fruit f1, Fruit f2, Fruit f3 ) {
	numberOccupants = 0;
	addToBasket( f1 );
	addToBasket( f2 );
	addToBasket( f3 );
}

bool FruitBasket::isEmpty() const {
	return( numberOccupants == 0 );
}

void FruitBasket::addToBasket( const Fruit & f ) {
	my_fruits[ numberOccupants++ ] = f;
}

bool FruitBasket::containsFruit( const Fruit & f ) const {
	bool found = false;
	for (int i = 0; i < numberOccupants; i++) {
		if (f == my_fruits[ i ]) {
			found = true;
			break;
		}
	}
	return( found );
}

std::ostream & operator <<( std::ostream & outs, const FruitBasket & fb ) {
	if (fb.isEmpty()) {
		outs << "Basket is empty!" << endl;
	}
	else {
		outs << "Basket contains:" << endl;
		for (int i = 0; i < fb.numberOccupants; i++)
			outs << i << ":\t" << fb.my_fruits[ i ];
	}
	return( outs );
}

// these operators are quite grossly inefficient
// but we don't know any other way in cs52 right now!
FruitBasket operator + ( const FruitBasket & fb, const Fruit & f ) {
	FruitBasket newBasket;
	for (int i = 0; i < fb.numberOccupants; i++) 
		newBasket.addToBasket( fb.my_fruits[i] );
	newBasket.addToBasket( f );
	return( newBasket );
}

FruitBasket operator - ( const FruitBasket & fb, const Fruit & f ) {
	FruitBasket newBasket;
	for (int i = 0; i < fb.numberOccupants; i++) 
		if (!(fb.my_fruits[i] == f))
			newBasket.addToBasket( fb.my_fruits[i] );
	return( newBasket );
}

bool  operator < ( const FruitBasket & fb1, const FruitBasket &fb2 ) {
	return( fb1.numberOccupants < fb2.numberOccupants );
}

bool  operator > ( const FruitBasket & fb1, const FruitBasket &fb2 ) {
	return( fb1.numberOccupants > fb2.numberOccupants );
}

bool  operator ==( const FruitBasket & fb1, const FruitBasket &fb2 ) {
	bool sizeMatch = (fb1.numberOccupants == fb2.numberOccupants);
	bool contentsMatch = true;
	if (sizeMatch) {
		for (int i = 0; i < fb2.numberOccupants; i++) {
			if (!(fb1.containsFruit( fb2.my_fruits[ i ] ))) {
				contentsMatch = false;
				break;
			}
		}
	}
	return( sizeMatch && contentsMatch );
}

}