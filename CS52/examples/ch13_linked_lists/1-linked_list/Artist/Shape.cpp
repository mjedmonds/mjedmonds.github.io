#include "Shape.h"

Shape::Shape( FIGURE kindOfShape, CPoint centerPoint,
			  COLOR kindOfColor, SIZE kindOfSize ) : m_Shape( kindOfShape ), 
									m_Color( kindOfColor ),
									m_Size( kindOfSize ) {
	switch( m_Size ) {
	case Shape::LARGE:
		m_BoundingBox = CRect( centerPoint.x - 50, centerPoint.y - 50, centerPoint.x + 50, centerPoint.y + 50 );
		break;
	case Shape::MEDIUM:
		m_BoundingBox = CRect( centerPoint.x - 25, centerPoint.y - 25, centerPoint.x + 25, centerPoint.y + 25 );
		break;
	case Shape::SMALL:
		m_BoundingBox = CRect( centerPoint.x - 12, centerPoint.y - 12, centerPoint.x + 12, centerPoint.y + 12 );
		break;
	}
}

void Shape::select( CDC * pDC ) {	
	draw( pDC, PS_DOT, HS_DIAGCROSS );
}

void Shape::draw( CDC * pDC, int pPenStyle, int pBrushStyle ) {
	COLORREF c;
	switch (m_Color) {
	case COLOR::BLACK:
		c = RGB( 0, 0, 0 );
		break;
	case COLOR::RED:
		c = RGB( 192, 0, 0 );
		break;
	case COLOR::BLUE:
		c = RGB( 0, 0, 192 );
		break;
	}

	CPen newPen( pPenStyle, 1, c );
	CPen * oldPen = pDC->SelectObject( &newPen );
	CBrush newBrush;
	if (pBrushStyle == PS_SOLID) {
		newBrush.CreateSolidBrush( c );
	}
	else {
		newBrush.CreateHatchBrush( pBrushStyle, c );
	}
	CBrush * oldBrush = pDC->SelectObject( &newBrush );
	switch (m_Shape) {
	case FIGURE::CIRCLE:
		pDC->Ellipse( m_BoundingBox );
		break;
	case FIGURE::SQUARE:
		pDC->Rectangle( m_BoundingBox );
		break;
	case FIGURE::ROUNDEDRECT:
		POINT pt;
		pt.x = 10;
		pt.y = 10;
		pDC->RoundRect( m_BoundingBox, pt );
		break;
	}
	pDC->SelectObject( oldPen );
	pDC->SelectObject( oldBrush );
}

BOOL Shape::PtInShape( CPoint pt ) {
	return( m_BoundingBox.PtInRect( pt ) );
}
