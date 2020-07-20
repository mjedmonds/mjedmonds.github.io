// ShapeDrawerView.cpp : implementation of the CShapeDrawerView class
//

#include "stdafx.h"
#include "ShapeDrawer.h"

#include "ShapeDrawerDoc.h"
#include "ShapeDrawerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShapeDrawerView

IMPLEMENT_DYNCREATE(CShapeDrawerView, CView)

BEGIN_MESSAGE_MAP(CShapeDrawerView, CView)
	//{{AFX_MSG_MAP(CShapeDrawerView)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_COLOR_BLACK, OnColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, OnUpdateColorBlack)
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, OnUpdateColorBlue)
	ON_COMMAND(ID_COLOR_RED, OnColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_CIRCLE, OnUpdateShapeCircle)
	ON_COMMAND(ID_SHAPE_CIRCLE, OnShapeCircle)
	ON_COMMAND(ID_SHAPE_ROUNDRECT, OnShapeRoundrect)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_ROUNDRECT, OnUpdateShapeRoundrect)
	ON_COMMAND(ID_SHAPE_SQUARE, OnShapeSquare)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_SQUARE, OnUpdateShapeSquare)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_EDIT_CLEARALL, OnEditClearall)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEARALL, OnUpdateEditClearall)
	ON_COMMAND(ID_EDIT_DELETE, OnEditDelete)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETE, OnUpdateEditDelete)
	ON_COMMAND(ID_SIZE_LARGE, OnSizeLarge)
	ON_UPDATE_COMMAND_UI(ID_SIZE_LARGE, OnUpdateSizeLarge)
	ON_COMMAND(ID_SIZE_MEDIUM, OnSizeMedium)
	ON_UPDATE_COMMAND_UI(ID_SIZE_MEDIUM, OnUpdateSizeMedium)
	ON_COMMAND(ID_SIZE_SMALL, OnSizeSmall)
	ON_UPDATE_COMMAND_UI(ID_SIZE_SMALL, OnUpdateSizeSmall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShapeDrawerView construction/destruction

CShapeDrawerView::CShapeDrawerView()
{
	// TODO: add construction code here
	// default menu choices
	m_CurrentColor = Shape::BLACK;
	m_CurrentFigure = Shape::CIRCLE;
	m_CurrentSize = Shape::SMALL;
	m_SelectedShape = NULL;
}

CShapeDrawerView::~CShapeDrawerView()
{
}

BOOL CShapeDrawerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShapeDrawerView drawing

void CShapeDrawerView::OnDraw(CDC* pDC)
{
	CShapeDrawerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	TRACE( "running onDraw\n" );
	try {
		for (int i = 0; i <= pDoc->totalNumberOfShapes() - 1; i++) {
			Shape * s = pDoc->getIthShape( i );
			s->draw( pDC );
		}
	} catch( NoSuchShape nss ) {
		// for now
		TRACE( "no such shape exception caught!\n" );
	}
}

/////////////////////////////////////////////////////////////////////////////
// CShapeDrawerView diagnostics

#ifdef _DEBUG
void CShapeDrawerView::AssertValid() const
{
	CView::AssertValid();
}

void CShapeDrawerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShapeDrawerDoc* CShapeDrawerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShapeDrawerDoc)));
	return (CShapeDrawerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShapeDrawerView message handlers

void CShapeDrawerView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CShapeDrawerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	TRACE( "running LButtonDown\n" );

	Shape * pShape = pDoc->addShape( m_CurrentFigure, point, m_CurrentColor, m_CurrentSize );
	CDC * pDC = GetDC();
	deselectCurrentShape();
	pShape->draw( pDC );
	ReleaseDC( pDC );

	CView::OnLButtonDown(nFlags, point);
}

void CShapeDrawerView::setColor( Shape::COLOR c ) {
	m_CurrentColor = c;
}

void CShapeDrawerView::setFigure( Shape::FIGURE f ) {
	m_CurrentFigure = f;
}

void CShapeDrawerView::OnColorBlack() 
{
	// TODO: Add your command handler code here
	setColor( Shape::BLACK );
}

void CShapeDrawerView::OnUpdateColorBlack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck( m_CurrentColor == Shape::BLACK ); 
}

void CShapeDrawerView::OnColorBlue() 
{
	// TODO: Add your command handler code here
	setColor( Shape::BLUE );	
}

void CShapeDrawerView::OnUpdateColorBlue(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck( m_CurrentColor == Shape::BLUE ); 	
}

void CShapeDrawerView::OnColorRed() 
{
	// TODO: Add your command handler code here
	setColor( Shape::RED );	
}

void CShapeDrawerView::OnUpdateColorRed(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck( m_CurrentColor == Shape::RED ); 	
}

void CShapeDrawerView::OnUpdateShapeCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck( m_CurrentFigure == Shape::CIRCLE );	
}

void CShapeDrawerView::OnShapeCircle() 
{
	// TODO: Add your command handler code here
	setFigure( Shape::CIRCLE );	
}

void CShapeDrawerView::OnShapeRoundrect() 
{
	// TODO: Add your command handler code here
	setFigure( Shape::ROUNDEDRECT );		
}

void CShapeDrawerView::OnUpdateShapeRoundrect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck( m_CurrentFigure == Shape::ROUNDEDRECT );	
}

void CShapeDrawerView::OnShapeSquare() 
{
	// TODO: Add your command handler code here
	setFigure( Shape::SQUARE );		
}

void CShapeDrawerView::OnUpdateShapeSquare(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck( m_CurrentFigure == Shape::SQUARE );
}

void CShapeDrawerView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CShapeDrawerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	TRACE( "running RButtonDown\n" );
	
	try {
		deselectCurrentShape();
		Shape * pShape = pDoc->getShapeWithPt( point );
		CDC * pDC = GetDC();
		pShape->select( pDC );
		m_SelectedShape = pShape;
		ReleaseDC( pDC );
	} catch( NoSuchShape nss ) {
		TRACE( "no such shape exception caught\n" );
	}
	
	CView::OnRButtonDown(nFlags, point);
}

void CShapeDrawerView::deselectCurrentShape() {
	if (m_SelectedShape != NULL) {
		CDC * pDC = GetDC();
		m_SelectedShape->draw( pDC );
		ReleaseDC( pDC );
		m_SelectedShape = NULL;
	}
}

void CShapeDrawerView::OnEditClearall() 
{
	// TODO: Add your command handler code here
	CShapeDrawerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->removeAll();	
}

void CShapeDrawerView::OnUpdateEditClearall(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CShapeDrawerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pCmdUI->Enable( pDoc->totalNumberOfShapes() > 0 );
}

void CShapeDrawerView::OnEditDelete() 
{
	// TODO: Add your command handler code here
	CShapeDrawerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->removeShape( m_SelectedShape );
	delete( m_SelectedShape );
	m_SelectedShape = NULL;
}

void CShapeDrawerView::OnUpdateEditDelete(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( m_SelectedShape != NULL );
}

void CShapeDrawerView::setSize( Shape::SIZE s ) {
	m_CurrentSize = s;
}

void CShapeDrawerView::OnSizeLarge() 
{
	// TODO: Add your command handler code here
	setSize( Shape::LARGE );	
}

void CShapeDrawerView::OnUpdateSizeLarge(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck( m_CurrentSize == Shape::LARGE );	
}

void CShapeDrawerView::OnSizeMedium() 
{
	// TODO: Add your command handler code here
	setSize( Shape::MEDIUM );		
}

void CShapeDrawerView::OnUpdateSizeMedium(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck( m_CurrentSize == Shape::MEDIUM );		
}

void CShapeDrawerView::OnSizeSmall() 
{
	// TODO: Add your command handler code here
	setSize( Shape::SMALL );		
}

void CShapeDrawerView::OnUpdateSizeSmall(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck( m_CurrentSize == Shape::SMALL );		
}
