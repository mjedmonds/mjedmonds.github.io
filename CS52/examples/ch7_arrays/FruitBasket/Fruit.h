#ifndef FRUIT_H
#define FRUIT_H

#include <iostream>
#include <string>

namespace cs52 {

enum Size { XTRA_LARGE, LARGE, MEDIUM, SMALL, XTRA_SMALL };

class Fruit {
public:
	Fruit( std::string kind="banana", 
		   double      weight=6,
		   Size        size=MEDIUM );

	double      getWeight();
	Size        getSize();
	std::string getKind();

	friend std::ostream & operator <<( std::ostream & outs, const Fruit & f );
	friend Fruit operator + ( const Fruit & f, int i );
	friend Fruit operator - ( const Fruit & f, int i );
	friend bool  operator < ( const Fruit & f1, const Fruit &f2 );
	friend bool  operator > ( const Fruit & f1, const Fruit &f2 );
	friend bool  operator ==( const Fruit & f1, const Fruit &f2 );

private:
	std::string my_kind;
	Size        my_size;
	double      my_weight;
};


}

#endif