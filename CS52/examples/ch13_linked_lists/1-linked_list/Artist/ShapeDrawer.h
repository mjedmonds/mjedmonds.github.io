// ShapeDrawer.h : main header file for the SHAPEDRAWER application
//

#if !defined(AFX_SHAPEDRAWER_H__CE00A7D8_4420_11D6_8049_952351DC2945__INCLUDED_)
#define AFX_SHAPEDRAWER_H__CE00A7D8_4420_11D6_8049_952351DC2945__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShapeDrawerApp:
// See ShapeDrawer.cpp for the implementation of this class
//

class CShapeDrawerApp : public CWinApp
{
public:
	CShapeDrawerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShapeDrawerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShapeDrawerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHAPEDRAWER_H__CE00A7D8_4420_11D6_8049_952351DC2945__INCLUDED_)
