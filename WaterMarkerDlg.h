// WaterMarkerDlg.h : header file
//

#if !defined(AFX_WATERMARKERDLG_H__415B120C_ABF3_4FF7_9E36_E8A6EDFB8BAF__INCLUDED_)
#define AFX_WATERMARKERDLG_H__415B120C_ABF3_4FF7_9E36_E8A6EDFB8BAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include ".\CxImage\CxImage\ximage.h"
#include "CPathSplit.h"
#include "DiskObject.h"
#include "EditLabel.h"
#include "GroupControl.h"

/////////////////////////////////////////////////////////////////////////////
// CWaterMarkerDlg dialog

class CWaterMarkerDlg : public CDialog
{
// Construction
public:
	CWaterMarkerDlg(CWnd* pParent = NULL);	// standard constructor

  CString     m_oStrAppPath;
  CDiskObject m_oDiskObject;
  CPathSplit  m_oPathSplitter;

  int         m_nOffsetX;
  int         m_nOffsetY;

  CxImage     m_oImgFileStamp;
  CxImage     m_oImgFileSrc;

// Dialog Data
	//{{AFX_DATA(CWaterMarkerDlg)
	enum { IDD = IDD_WATERMARKER_DIALOG };
	CSliderCtrl	m_oSliderRedimAvant;
	CSliderCtrl	m_oSliderRedimApres;
	CEditLabel	m_oEditPathSrc;
	CEditLabel	m_oEditPathDst;
	CEditLabel	m_oEditFileStamp;
	CGroupControl	m_oGroupRun;
	CGroupControl	m_oGroupConfig;
	CSliderCtrl	m_oSliderAlpha;
	CStatic	m_oRectStamp;
	CStatic	m_oRectFinal;
	CButton	m_oButtonRun;
	CEdit	m_oWndQualDst;
	CStatic	m_oWndStatus;
	CStatic	m_oWndProgress;
	CStatic	m_oBmpStamp;
	CStatic	m_oBmpFinal;
	CSliderCtrl	m_oSliderQualDst;
	CComboBox	m_oComboTypeSrc;
	CComboBox	m_oComboTypeDst;
	int		m_nOffsetBas;
	int		m_nOffsetDroite;
	int		m_nOffsetGauche;
	int		m_nOffsetHaut;
	int		m_nQualDst;
	CString	m_oStrPathSrc;
	CString	m_oStrPathDst;
	CString	m_oStrFileStamp;
	int		m_nAlpha;
	BOOL	m_bAlpha;
	int		m_nRedimApres;
	int		m_nRedimAvant;
	BOOL	m_bTile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWaterMarkerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	HBITMAP m_hBmpStamp;
	HBITMAP m_hBmpFinal;

  BOOL    m_bStop;

  void    VerifRun(void);
  int     ListeFichiers(CStringArray& o_raoListeFichiers, CString i_oStrRepertoire, CString i_oStrHeader, CString i_oStrExtensions, BOOL i_bConcatenate = TRUE);
	CString GetExtFromType(int i_nDocType);

	// Generated message map functions
	//{{AFX_MSG(CWaterMarkerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeEditPathSrc();
	afx_msg void OnButtonPathSrc();
	afx_msg void OnSelchangeComboTypeSrc();
	afx_msg void OnChangeEditFileStamp();
	afx_msg void OnButtonFileStamp();
	afx_msg void OnChangeEditPathDst();
	afx_msg void OnButtonPathDst();
	afx_msg void OnSelchangeComboTypeDst();
	afx_msg void OnChangeEditQualDst();
	afx_msg void OnReleasedcaptureSliderQualDst(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEditHaut();
	afx_msg void OnChangeEditBas();
	afx_msg void OnChangeEditGauche();
	afx_msg void OnChangeEditDroite();
	afx_msg void OnButtonCsg();
	afx_msg void OnButtonH();
	afx_msg void OnButtonCsd();
	afx_msg void OnButtonG();
	afx_msg void OnButtonC();
	afx_msg void OnButtonD();
	afx_msg void OnButtonCig();
	afx_msg void OnButtonB();
	afx_msg void OnButtonCid();
	afx_msg void OnDestroy();
	afx_msg void OnButtonRun();
	afx_msg void OnChangeEditAlpha();
	afx_msg void OnReleasedcaptureSliderAlpha(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCheckAlpha();
	afx_msg void OnChangeEditRedimAvant();
	afx_msg void OnReleasedcaptureSliderRedimAvant(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEditRedimApres();
	afx_msg void OnReleasedcaptureSliderRedimApres(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCheckTile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WATERMARKERDLG_H__415B120C_ABF3_4FF7_9E36_E8A6EDFB8BAF__INCLUDED_)
