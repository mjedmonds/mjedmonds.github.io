#include <iostream>
#include "Fruit.h"

using namespace std;

namespace cs52 {

Fruit::Fruit( std::string kind, 
			  double      weight,
			  Size        size ) {
	my_kind   = kind;
	my_weight = weight;
	my_size   = size;
}

string Fruit::getKind() {
	return( my_kind );		
}

Size Fruit::getSize()
{
	return( my_size );
}

double Fruit::getWeight()
{
	return( my_weight );
}

Fruit operator +( const Fruit & f, int i ) {
	Fruit newF = Fruit( f.my_kind, f.my_weight + i, f.my_size );
	return( newF );
}

Fruit operator -( const Fruit & f, int i ) {
	Fruit newF = Fruit( f.my_kind, f.my_weight - i, f.my_size );
	return( newF );
}

std::ostream & operator <<( std::ostream & outs, const Fruit & f ) {
	outs << "A lovely, ";
	switch( f.my_size ) {
	case XTRA_LARGE:
		outs << "extra large";
		break;
	case LARGE:
		outs << "large";
		break;
	case MEDIUM:
		outs << "medium";
		break;
	case SMALL:
		outs << "small";
		break;
	case XTRA_SMALL:
		outs << "extra small";
		break;
	};
	outs << ", " << f.my_weight << " ounce ";
	outs << f.my_kind << endl;
	return( outs );
}

bool  operator < ( const Fruit & f1, const Fruit &f2 ) {
	return( f1.my_weight < f2.my_weight );
}

bool  operator > ( const Fruit & f1, const Fruit &f2 ) {
	return( f1.my_weight > f2.my_weight );
}

bool  operator ==( const Fruit & f1, const Fruit &f2 ) {
	return( f1.my_kind == f2.my_kind && f1.my_size == f2.my_size && f1.my_weight == f2.my_weight );
}


}