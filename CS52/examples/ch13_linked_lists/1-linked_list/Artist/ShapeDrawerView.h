// ShapeDrawerView.h : interface of the CShapeDrawerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAPEDRAWERVIEW_H__CE00A7E0_4420_11D6_8049_952351DC2945__INCLUDED_)
#define AFX_SHAPEDRAWERVIEW_H__CE00A7E0_4420_11D6_8049_952351DC2945__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShapeDrawerView : public CView
{
private:
	Shape::FIGURE m_CurrentFigure;
	Shape::COLOR m_CurrentColor;
	Shape::SIZE m_CurrentSize;
	Shape * m_SelectedShape;
	
	void setSize( Shape::SIZE s );
	void setColor( Shape::COLOR c );
	void setFigure( Shape::FIGURE f );
	void deselectCurrentShape();

protected: // create from serialization only
	CShapeDrawerView();
	DECLARE_DYNCREATE(CShapeDrawerView)

// Attributes
public:
	CShapeDrawerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShapeDrawerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShapeDrawerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShapeDrawerView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnColorBlack();
	afx_msg void OnUpdateColorBlack(CCmdUI* pCmdUI);
	afx_msg void OnColorBlue();
	afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	afx_msg void OnColorRed();
	afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);
	afx_msg void OnUpdateShapeCircle(CCmdUI* pCmdUI);
	afx_msg void OnShapeCircle();
	afx_msg void OnShapeRoundrect();
	afx_msg void OnUpdateShapeRoundrect(CCmdUI* pCmdUI);
	afx_msg void OnShapeSquare();
	afx_msg void OnUpdateShapeSquare(CCmdUI* pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEditClearall();
	afx_msg void OnUpdateEditClearall(CCmdUI* pCmdUI);
	afx_msg void OnEditDelete();
	afx_msg void OnUpdateEditDelete(CCmdUI* pCmdUI);
	afx_msg void OnSizeLarge();
	afx_msg void OnUpdateSizeLarge(CCmdUI* pCmdUI);
	afx_msg void OnSizeMedium();
	afx_msg void OnUpdateSizeMedium(CCmdUI* pCmdUI);
	afx_msg void OnSizeSmall();
	afx_msg void OnUpdateSizeSmall(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShapeDrawerView.cpp
inline CShapeDrawerDoc* CShapeDrawerView::GetDocument()
   { return (CShapeDrawerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHAPEDRAWERVIEW_H__CE00A7E0_4420_11D6_8049_952351DC2945__INCLUDED_)
