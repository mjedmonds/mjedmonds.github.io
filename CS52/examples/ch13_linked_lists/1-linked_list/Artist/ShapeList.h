#ifndef SHAPELIST_H
#define SHAPELIST_H
#include "StdAfx.h"
#include "Shape.h"
#include "NoSuchShape.h"
#include <list>

class ShapeList {
public:
	ShapeList();

	int size() const;
	void draw( CDC * pDC,  int item = -1 ) const;
	void insert( Shape * pShapeToInsert );
	void remove( Shape * pShapeToRemove );
	void removeAll();
	Shape * getIthShape( int i ) const throw (NoSuchShape);
	Shape * getShapeWithPt( CPoint p ) const throw (NoSuchShape);

private:
	std::list<Shape *> shapes;

};


#endif