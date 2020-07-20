#ifndef FRUITBASKET_H
#define FRUITBASKET_H

#include <iostream>
#include <string>
#include "Fruit.h"
#include <list>

namespace cs52 {

class FruitBasket {
public:
	FruitBasket();
	FruitBasket( Fruit f1 );
	FruitBasket( Fruit f1, Fruit f2 );
	FruitBasket( Fruit f1, Fruit f2, Fruit f3 );

	bool isEmpty() const;
	void addToBasket( const Fruit & f );
	bool containsFruit( const Fruit & f ) const;

	friend std::ostream & operator <<( std::ostream & outs, const FruitBasket & fb );
	friend FruitBasket operator + ( const FruitBasket & fb, const Fruit & f );
	friend FruitBasket operator - ( const FruitBasket & fb, const Fruit & f );
	friend bool  operator < ( const FruitBasket & fb1, const FruitBasket &fb2 );
	friend bool  operator > ( const FruitBasket & fb1, const FruitBasket &fb2 );
	friend bool  operator ==( const FruitBasket & fb1, const FruitBasket &fb2 );

private:
	std::list < Fruit > listOfFruit;
};


}

#endif