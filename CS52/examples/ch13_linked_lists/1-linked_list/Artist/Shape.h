#ifndef SHAPE_H
#define SHAPE_H
#include "StdAfx.h"

class Shape {
public:
	enum FIGURE { CIRCLE, SQUARE, ROUNDEDRECT };
	enum COLOR { BLACK, BLUE, RED };
	enum SIZE { SMALL, MEDIUM, LARGE };

	Shape( FIGURE kindOfShape = Shape::CIRCLE, CPoint centerPoint = CPoint( 50, 50 ), COLOR kindOfColor = Shape::BLACK, SIZE kindOfSize = Shape::SMALL );

	void draw( CDC * pDC, int pPenStyle = PS_SOLID, int pBrushStyle = PS_SOLID );
	void select( CDC * pDC );
	BOOL PtInShape( CPoint pt );

private:
	SIZE m_Size;
	COLOR m_Color;
	FIGURE m_Shape;
	CRect m_BoundingBox;
};


#endif