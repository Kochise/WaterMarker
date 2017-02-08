// WaterMarker.h : main header file for the WATERMARKER application
//

#if !defined(AFX_WATERMARKER_H__64C3B745_04B9_4FB0_BDC7_5849B19209FF__INCLUDED_)
#define AFX_WATERMARKER_H__64C3B745_04B9_4FB0_BDC7_5849B19209FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWaterMarkerApp:
// See WaterMarker.cpp for the implementation of this class
//

class CWaterMarkerApp : public CWinApp
{
public:
	CWaterMarkerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWaterMarkerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWaterMarkerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WATERMARKER_H__64C3B745_04B9_4FB0_BDC7_5849B19209FF__INCLUDED_)
