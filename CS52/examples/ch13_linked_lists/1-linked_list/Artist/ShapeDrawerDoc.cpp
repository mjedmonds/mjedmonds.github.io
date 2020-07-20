// ShapeDrawerDoc.cpp : implementation of the CShapeDrawerDoc class
//

#include "stdafx.h"
#include "ShapeDrawer.h"

#include "ShapeDrawerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShapeDrawerDoc

IMPLEMENT_DYNCREATE(CShapeDrawerDoc, CDocument)

BEGIN_MESSAGE_MAP(CShapeDrawerDoc, CDocument)
	//{{AFX_MSG_MAP(CShapeDrawerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShapeDrawerDoc construction/destruction

CShapeDrawerDoc::CShapeDrawerDoc()
{
	// TODO: add one-time construction code here

}

CShapeDrawerDoc::~CShapeDrawerDoc()
{
}

BOOL CShapeDrawerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShapeDrawerDoc serialization

void CShapeDrawerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CShapeDrawerDoc diagnostics

#ifdef _DEBUG
void CShapeDrawerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShapeDrawerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShapeDrawerDoc commands

Shape * CShapeDrawerDoc::addShape( Shape::FIGURE f, CPoint centerPoint,
								   Shape::COLOR c, Shape::SIZE s ) {
	Shape * pShape = new Shape( f, centerPoint, c, s );
	shapelist.insert( pShape );
	return( pShape );
}

void CShapeDrawerDoc::removeShape( Shape * s ) {
	shapelist.remove( s );
	UpdateAllViews( NULL );
}

Shape * CShapeDrawerDoc::getIthShape( int i ) {
	return( shapelist.getIthShape( i ) );
}

int  CShapeDrawerDoc::totalNumberOfShapes( ) {
	return( shapelist.size( ) );
}

Shape * CShapeDrawerDoc::getShapeWithPt( CPoint pt ) {
	return( shapelist.getShapeWithPt( pt ) );
}

void CShapeDrawerDoc::removeAll( ) {
	shapelist.removeAll();
	UpdateAllViews( NULL );
}