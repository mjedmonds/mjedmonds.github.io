#include "ShapeList.h"
using namespace std;

ShapeList::ShapeList() {

}

int ShapeList::size() const {
	return( shapes.size() );
}

void ShapeList::removeAll() {
	shapes.clear();
}

// item 0 is the first element on the list
void ShapeList::draw( CDC * pDC,  int item ) const {
	bool doall = false;
	list<Shape *>::const_iterator iter = shapes.begin();
	if (item == -1)   doall = true;
	
	while (iter != shapes.end()) {
		if (doall || item == 0) {
			Shape * s = *iter;
			s->draw( pDC );
		}
		item--;
		iter++;
	}
}

// item 0 is the first item on the list 
Shape * ShapeList::getIthShape( int i ) const throw( NoSuchShape ) {
	Shape * result = NULL;
	if (i >= 0) {
		list<Shape *>::const_iterator iter = shapes.begin();
		while (iter != shapes.end()) {
			if (i == 0) {
				result = *iter;
			}
			i--;
			iter++;
		}
	}
	if (result == NULL) throw( NoSuchShape() );
	return( result );
}


Shape * ShapeList::getShapeWithPt( CPoint p ) const throw( NoSuchShape ) {
	Shape * result = NULL;
	list<Shape *>::const_iterator iter = shapes.begin();
	while (iter != shapes.end()) {
		Shape * s = *iter;
		if (s->PtInShape( p )) {
			result = s;
			break;
		}
		iter++;
	}
	if (result == NULL) throw( NoSuchShape() );
	return( result );
}

void ShapeList::insert( Shape * pShapeToInsert ) {
	shapes.push_back( pShapeToInsert );
}

void ShapeList::remove( Shape * pShapeToRemove ) {
	shapes.remove( pShapeToRemove );
}
