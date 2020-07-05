#include <iostream>
#include "Fruit.h"
#include "FruitBasket.h"

using namespace std;
//using namespace cs52;

int main() {
	using namespace cs52;
	cout << "Let's eat some fruit" << endl;
	Fruit f, g;
	Fruit tomato = Fruit( "tomato", 12, LARGE );

	cout << f;
	cout << "f + 1=" << f + 1;
	cout << tomato;
	cout << "tomato - 1=" << tomato - 1;

	if (tomato > f) {
		cout << "tomato is bigger" << endl;
	}
	if (!(tomato == f)) {
		cout << "tomato is not equal to f" << endl;
	}
	if (f == g) {
		cout << "f and g are equal" << endl;
	}

	FruitBasket fb, emptyBasket;
	cout << "basket=" << emptyBasket;
	fb.addToBasket( tomato );
	fb.addToBasket( f );
	cout << "basket=" << fb;
	
	if (fb > emptyBasket) {
		cout << "fb is bigger" << endl;
	}
	if (!(fb == emptyBasket)) {
		cout << "baskets are different" << endl;
	}
	if (fb == fb) {
		cout << "identical basket" << endl;
	}

	return( 0 );
}