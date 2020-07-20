// ShapeDrawerDoc.h : interface of the CShapeDrawerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAPEDRAWERDOC_H__CE00A7DE_4420_11D6_8049_952351DC2945__INCLUDED_)
#define AFX_SHAPEDRAWERDOC_H__CE00A7DE_4420_11D6_8049_952351DC2945__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ShapeList.h"
#include "Shape.h"
class CShapeDrawerDoc : public CDocument
{
protected: // create from serialization only
	CShapeDrawerDoc();
	DECLARE_DYNCREATE(CShapeDrawerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShapeDrawerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShapeDrawerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShapeDrawerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()



private:
	ShapeList shapelist;
public:
	Shape * addShape( Shape::FIGURE f, CPoint centerPoint, Shape::COLOR c, Shape::SIZE s );
	void removeShape( Shape * s );
	void removeAll();
	Shape * getIthShape( int i );
	Shape * getShapeWithPt( CPoint pt );
	int  totalNumberOfShapes( );
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHAPEDRAWERDOC_H__CE00A7DE_4420_11D6_8049_952351DC2945__INCLUDED_)
