// WaterMarkerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WaterMarker.h"
#include "WaterMarkerDlg.h"

#include "SkinProgress.h"
#include "amsWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWaterMarkerDlg dialog

CWaterMarkerDlg::CWaterMarkerDlg(CWnd* pParent /*=NULL*/)
  : CDialog(CWaterMarkerDlg::IDD, pParent)
{
  //{{AFX_DATA_INIT(CWaterMarkerDlg)
  m_nOffsetBas = 0;
  m_nOffsetDroite = 0;
  m_nOffsetGauche = 0;
  m_nOffsetHaut = 0;
  m_nQualDst = 0;
  m_oStrPathSrc = _T("");
  m_oStrPathDst = _T("");
  m_oStrFileStamp = _T("");
  m_nAlpha = 0;
  m_bAlpha = FALSE;
  m_nRedimApres = 0;
  m_nRedimAvant = 0;
  m_bTile = FALSE;
  //}}AFX_DATA_INIT
  // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
  m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWaterMarkerDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CWaterMarkerDlg)
  DDX_Control(pDX, IDC_SLIDER_REDIM_AVANT, m_oSliderRedimAvant);
  DDX_Control(pDX, IDC_SLIDER_REDIM_APRES, m_oSliderRedimApres);
  DDX_Control(pDX, IDC_EDIT_PATH_SRC, m_oEditPathSrc);
  DDX_Control(pDX, IDC_EDIT_PATH_DST, m_oEditPathDst);
  DDX_Control(pDX, IDC_EDIT_FILE_STAMP, m_oEditFileStamp);
  DDX_Control(pDX, IDC_GROUP_RUN, m_oGroupRun);
  DDX_Control(pDX, IDC_GROUP_CONFIG, m_oGroupConfig);
  DDX_Control(pDX, IDC_SLIDER_ALPHA, m_oSliderAlpha);
  DDX_Control(pDX, IDC_STATIC_RECT_STAMP, m_oRectStamp);
  DDX_Control(pDX, IDC_STATIC_RECT_FINAL, m_oRectFinal);
  DDX_Control(pDX, IDC_BUTTON_RUN, m_oButtonRun);
  DDX_Control(pDX, IDC_EDIT_QUAL_DST, m_oWndQualDst);
  DDX_Control(pDX, IDC_STATIC_TEXT, m_oWndStatus);
  DDX_Control(pDX, IDC_STATIC_PROGRESS, m_oWndProgress);
  DDX_Control(pDX, IDC_STATIC_BMP_STAMP, m_oBmpStamp);
  DDX_Control(pDX, IDC_STATIC_BMP_FINAL, m_oBmpFinal);
  DDX_Control(pDX, IDC_SLIDER_QUAL_DST, m_oSliderQualDst);
  DDX_Control(pDX, IDC_COMBO_TYPE_SRC, m_oComboTypeSrc);
  DDX_Control(pDX, IDC_COMBO_TYPE_DST, m_oComboTypeDst);
  DDX_Text(pDX, IDC_EDIT_BAS, m_nOffsetBas);
  DDX_Text(pDX, IDC_EDIT_DROITE, m_nOffsetDroite);
  DDX_Text(pDX, IDC_EDIT_GAUCHE, m_nOffsetGauche);
  DDX_Text(pDX, IDC_EDIT_HAUT, m_nOffsetHaut);
  DDX_Text(pDX, IDC_EDIT_QUAL_DST, m_nQualDst);
  DDX_Text(pDX, IDC_EDIT_PATH_SRC, m_oStrPathSrc);
  DDX_Text(pDX, IDC_EDIT_PATH_DST, m_oStrPathDst);
  DDX_Text(pDX, IDC_EDIT_FILE_STAMP, m_oStrFileStamp);
  DDX_Text(pDX, IDC_EDIT_ALPHA, m_nAlpha);
  DDV_MinMaxInt(pDX, m_nAlpha, 0, 255);
  DDX_Check(pDX, IDC_CHECK_ALPHA, m_bAlpha);
  DDX_Text(pDX, IDC_EDIT_REDIM_APRES, m_nRedimApres);
  DDX_Text(pDX, IDC_EDIT_REDIM_AVANT, m_nRedimAvant);
  DDX_Check(pDX, IDC_CHECK_TILE, m_bTile);
  //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWaterMarkerDlg, CDialog)
  //{{AFX_MSG_MAP(CWaterMarkerDlg)
  ON_WM_PAINT()
  ON_WM_QUERYDRAGICON()
  ON_EN_CHANGE(IDC_EDIT_PATH_SRC, OnChangeEditPathSrc)
  ON_BN_CLICKED(IDC_BUTTON_PATH_SRC, OnButtonPathSrc)
  ON_CBN_SELCHANGE(IDC_COMBO_TYPE_SRC, OnSelchangeComboTypeSrc)
  ON_EN_CHANGE(IDC_EDIT_FILE_STAMP, OnChangeEditFileStamp)
  ON_BN_CLICKED(IDC_BUTTON_FILE_STAMP, OnButtonFileStamp)
  ON_EN_CHANGE(IDC_EDIT_PATH_DST, OnChangeEditPathDst)
  ON_BN_CLICKED(IDC_BUTTON_PATH_DST, OnButtonPathDst)
  ON_CBN_SELCHANGE(IDC_COMBO_TYPE_DST, OnSelchangeComboTypeDst)
  ON_EN_CHANGE(IDC_EDIT_QUAL_DST, OnChangeEditQualDst)
  ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_QUAL_DST, OnReleasedcaptureSliderQualDst)
  ON_EN_CHANGE(IDC_EDIT_HAUT, OnChangeEditHaut)
  ON_EN_CHANGE(IDC_EDIT_BAS, OnChangeEditBas)
  ON_EN_CHANGE(IDC_EDIT_GAUCHE, OnChangeEditGauche)
  ON_EN_CHANGE(IDC_EDIT_DROITE, OnChangeEditDroite)
  ON_BN_CLICKED(IDC_BUTTON_CSG, OnButtonCsg)
  ON_BN_CLICKED(IDC_BUTTON_H, OnButtonH)
  ON_BN_CLICKED(IDC_BUTTON_CSD, OnButtonCsd)
  ON_BN_CLICKED(IDC_BUTTON_G, OnButtonG)
  ON_BN_CLICKED(IDC_BUTTON_C, OnButtonC)
  ON_BN_CLICKED(IDC_BUTTON_D, OnButtonD)
  ON_BN_CLICKED(IDC_BUTTON_CIG, OnButtonCig)
  ON_BN_CLICKED(IDC_BUTTON_B, OnButtonB)
  ON_BN_CLICKED(IDC_BUTTON_CID, OnButtonCid)
  ON_WM_DESTROY()
  ON_BN_CLICKED(IDC_BUTTON_RUN, OnButtonRun)
  ON_EN_CHANGE(IDC_EDIT_ALPHA, OnChangeEditAlpha)
  ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_ALPHA, OnReleasedcaptureSliderAlpha)
  ON_BN_CLICKED(IDC_CHECK_ALPHA, OnCheckAlpha)
  ON_EN_CHANGE(IDC_EDIT_REDIM_AVANT, OnChangeEditRedimAvant)
  ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_REDIM_AVANT, OnReleasedcaptureSliderRedimAvant)
  ON_EN_CHANGE(IDC_EDIT_REDIM_APRES, OnChangeEditRedimApres)
  ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_REDIM_APRES, OnReleasedcaptureSliderRedimApres)
  ON_BN_CLICKED(IDC_CHECK_TILE, OnCheckTile)
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

// ========================

struct DocType
{
  public:
    int nID;
    BOOL bRead;
    BOOL bWrite;
    const char* description;
    const char* ext;
};

DocType doctypes[CMAX_IMAGE_FORMATS] =
{
  { -1, TRUE, TRUE, "Fichiers supportés", "*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.ico;*.tif;*.tiff;*.tga;*.pcx;*.wbmp;*.wmf;*.emf;*.j2k;*.jp2;*.jbg;*.j2c;*.jpc;*.pgx;*.pnm;*.pgm;*.ppm;*.ras" },
#if CXIMAGE_SUPPORT_BMP
  { CXIMAGE_FORMAT_BMP, TRUE, TRUE, "Fichiers BMP", "*.bmp" },
#endif
#if CXIMAGE_SUPPORT_GIF
  { CXIMAGE_FORMAT_GIF, TRUE, TRUE, "Fichiers GIF", "*.gif" },
#endif
#if CXIMAGE_SUPPORT_JPG
  { CXIMAGE_FORMAT_JPG, TRUE, TRUE, "Fichiers JPG", "*.jpg;*.jpeg" },
#endif
#if CXIMAGE_SUPPORT_PNG
  { CXIMAGE_FORMAT_PNG, TRUE, TRUE, "Fichiers PNG", "*.png" },
#endif
#if CXIMAGE_SUPPORT_MNG
  { CXIMAGE_FORMAT_MNG, TRUE, TRUE, "Fichiers MNG", "*.mng;*.jng;*.png" },
#endif
#if CXIMAGE_SUPPORT_ICO
  { CXIMAGE_FORMAT_ICO, TRUE, TRUE, "Fichiers ICO CUR", "*.ico;*.cur" },
#endif
#if CXIMAGE_SUPPORT_TIF
  { CXIMAGE_FORMAT_TIF, TRUE, TRUE, "Fichiers TIF", "*.tif;*.tiff" },
#endif
#if CXIMAGE_SUPPORT_TGA
  { CXIMAGE_FORMAT_TGA, TRUE, TRUE, "Fichiers TGA", "*.tga" },
#endif
#if CXIMAGE_SUPPORT_PCX
  { CXIMAGE_FORMAT_PCX, TRUE, TRUE, "Fichiers PCX", "*.pcx" },
#endif
#if CXIMAGE_SUPPORT_WBMP
  { CXIMAGE_FORMAT_WBMP, TRUE, TRUE, "Fichiers WBMP", "*.wbmp" },
#endif
#if CXIMAGE_SUPPORT_WMF
  { CXIMAGE_FORMAT_WMF, TRUE, FALSE, "Fichiers WMF EMF", "*.wmf;*.emf" },
#endif
#if CXIMAGE_SUPPORT_J2K
  { CXIMAGE_FORMAT_J2K, TRUE, TRUE, "Fichiers J2K", "*.j2k;*.jp2" },
#endif
#if CXIMAGE_SUPPORT_JBG
  { CXIMAGE_FORMAT_JBG, TRUE, TRUE, "Fichiers JBG", "*.jbg" },
#endif
#if CXIMAGE_SUPPORT_JP2
  { CXIMAGE_FORMAT_JP2, TRUE, TRUE, "Fichiers JP2", "*.j2k;*.jp2" },
#endif
#if CXIMAGE_SUPPORT_JPC
  { CXIMAGE_FORMAT_JPC, TRUE, TRUE, "Fichiers JPC", "*.j2c;*.jpc" },
#endif
#if CXIMAGE_SUPPORT_PGX
  { CXIMAGE_FORMAT_PGX, TRUE, TRUE, "Fichiers PGX", "*.pgx" },
#endif
#if CXIMAGE_SUPPORT_RAS
  { CXIMAGE_FORMAT_RAS, TRUE, TRUE, "Fichiers RAS", "*.ras" },
#endif
#if CXIMAGE_SUPPORT_PNM
  { CXIMAGE_FORMAT_PNM, TRUE, TRUE, "Fichiers PNM", "*.pnm;*.pgm;*.ppm" }
#endif
};

/////////////////////////////////////////////////////////////////////////////
// CWaterMarkerDlg message handlers

BOOL CWaterMarkerDlg::OnInitDialog()
{
  int   l_nLoop;
  int   l_nType;
  CRect l_oRectTemp;

  CDialog::OnInitDialog();

  m_oGroupConfig.EnableWindow(TRUE);

  CAMSWnd::Restore(this, _T("WaterMarkerDlg"), CAMSWnd::Position);

  SetIcon(m_hIcon, TRUE);      // Set big icon
  SetIcon(m_hIcon, FALSE);    // Set small icon
  
  m_oStrAppPath = AfxGetApp()->m_pszHelpFilePath;
  m_oStrAppPath = m_oStrAppPath.Left(m_oStrAppPath.ReverseFind('\\')+1);

  //

  m_oStrPathSrc   = AfxGetApp()->GetProfileString(_T("File"), _T("PathSrc"), m_oStrAppPath);
  m_oStrPathDst   = AfxGetApp()->GetProfileString(_T("File"), _T("PathDst"), m_oStrAppPath);
  m_oStrFileStamp = AfxGetApp()->GetProfileString(_T("File"), _T("FileStamp"), m_oStrAppPath+"Logo.png");

  m_nOffsetBas    = AfxGetApp()->GetProfileInt(_T("Offset"), _T("Bas"),    0);
  m_nOffsetDroite = AfxGetApp()->GetProfileInt(_T("Offset"), _T("Droite"), 0);
  m_nOffsetGauche = AfxGetApp()->GetProfileInt(_T("Offset"), _T("Gauche"), 0);
  m_nOffsetHaut   = AfxGetApp()->GetProfileInt(_T("Offset"), _T("Haut"),   0);

  m_nOffsetX      = AfxGetApp()->GetProfileInt(_T("Offset"), _T("X"), 0);
  m_nOffsetY      = AfxGetApp()->GetProfileInt(_T("Offset"), _T("Y"), 0);

  //

  m_nQualDst      = AfxGetApp()->GetProfileInt(_T("Work"), _T("QualDst"), 80);

  if(m_nQualDst <   0) m_nQualDst = 0;
  if(m_nQualDst > 100) m_nQualDst = 100;

  m_oSliderQualDst.SetRange(0, 100);
  m_oSliderQualDst.SetTicFreq(20);
  m_oSliderQualDst.SetPageSize(20);
  m_oSliderQualDst.SetPos(m_nQualDst);

  //

  m_nAlpha        = AfxGetApp()->GetProfileInt(_T("Work"), _T("Alpha"), 128);
  m_bAlpha        = AfxGetApp()->GetProfileInt(_T("Work"), _T("Trans"), FALSE);

  if(m_nAlpha <   0) m_nAlpha = 0;
  if(m_nAlpha > 255) m_nAlpha = 255;

  m_oSliderAlpha.SetRange(0, 255);
  m_oSliderAlpha.SetTicFreq(32);
  m_oSliderAlpha.SetPageSize(32);
  m_oSliderAlpha.SetPos(m_nAlpha);

  //

  m_nRedimAvant   = AfxGetApp()->GetProfileInt(_T("Work"), _T("RedimAvant"), 100);

  if(m_nRedimAvant <  10) m_nRedimAvant = 10;
  if(m_nRedimAvant > 200) m_nRedimAvant = 200;

  m_oSliderRedimAvant.SetRange(10, 200);
  m_oSliderRedimAvant.SetTicFreq(20);
  m_oSliderRedimAvant.SetPageSize(20);
  m_oSliderRedimAvant.SetPos(m_nRedimAvant);


  //

  m_bTile         = AfxGetApp()->GetProfileInt(_T("Work"), _T("Tile"), FALSE) & 1;

  //

  m_nRedimApres   = AfxGetApp()->GetProfileInt(_T("Work"), _T("RedimApres"), 100);

  if(m_nRedimApres <  10) m_nRedimApres = 10;
  if(m_nRedimApres > 200) m_nRedimApres = 200;

  m_oSliderRedimApres.SetRange(10, 200);
  m_oSliderRedimApres.SetTicFreq(20);
  m_oSliderRedimApres.SetPageSize(20);
  m_oSliderRedimApres.SetPos(m_nRedimApres);

  // SOURCE

  for
  ( l_nLoop  = 1
  ; l_nLoop <  CMAX_IMAGE_FORMATS
  ; l_nLoop += 1
  )
  {
    if(doctypes[l_nLoop].bRead == TRUE)
    {
      m_oComboTypeSrc.SetItemData
      ( m_oComboTypeSrc.AddString(doctypes[l_nLoop].description)
      , doctypes[l_nLoop].nID
      );
    }
  }

  l_nType = AfxGetApp()->GetProfileInt(_T("Work"), _T("TypeSrc"), CXIMAGE_FORMAT_JPG);

  for
  ( l_nLoop  = 0
  ; l_nLoop <  m_oComboTypeSrc.GetCount()
  ; l_nLoop += 1
  )
  {
    if(m_oComboTypeSrc.GetItemData(l_nLoop) == l_nType)
    {
      m_oComboTypeSrc.SetCurSel(l_nLoop);
      break;
    }
  }

  // DESTINATION

  for
  ( l_nLoop  = 1
  ; l_nLoop <  CMAX_IMAGE_FORMATS
  ; l_nLoop += 1
  )
  {
    if(doctypes[l_nLoop].bWrite == TRUE)
    {
      m_oComboTypeDst.SetItemData
      ( m_oComboTypeDst.AddString(doctypes[l_nLoop].description)
      , doctypes[l_nLoop].nID
      );
    }
  }

  l_nType = AfxGetApp()->GetProfileInt(_T("Work"), _T("TypeDst"), CXIMAGE_FORMAT_JPG);

  for
  ( l_nLoop  = 0
  ; l_nLoop <  m_oComboTypeDst.GetCount()
  ; l_nLoop += 1
  )
  {
    if(m_oComboTypeDst.GetItemData(l_nLoop) == l_nType)
    {
      m_oComboTypeDst.SetCurSel(l_nLoop);
      break;
    }
  }

  //

  m_oRectStamp.GetClientRect(&l_oRectTemp);
  m_oBmpStamp.SetWindowPos
  ( NULL
  , l_oRectTemp.left
  , l_oRectTemp.top
  , l_oRectTemp.Width()
  , l_oRectTemp.Height()
  , SWP_NOMOVE | SWP_NOZORDER | SWP_SHOWWINDOW
  );

  //

  m_oRectFinal.GetClientRect(&l_oRectTemp);
  m_oBmpFinal.SetWindowPos
  ( NULL
  , l_oRectTemp.left
  , l_oRectTemp.top
  , l_oRectTemp.Width()
  , l_oRectTemp.Height()
  , SWP_NOMOVE | SWP_NOZORDER | SWP_SHOWWINDOW
  );

  //

  m_hBmpStamp = NULL; // AVANT VerifRun !!!
  m_hBmpFinal = NULL; // AVANT VerifRun !!!

  OnSelchangeComboTypeDst(); // Qualité
  VerifRun(); // Le reste

  //
  
  return TRUE;  // return TRUE  unless you set the focus to a control
}


void CWaterMarkerDlg::OnDestroy() 
{
  m_bStop = TRUE; // Arret du traitement en cours !!!

  if(m_hBmpStamp)
  {
    DeleteObject(m_hBmpStamp);
  }
  else{}

  if(m_hBmpFinal)
  {
    DeleteObject(m_hBmpFinal);
  }
  else{}

  //

  CAMSWnd::Save(this, _T("WaterMarkerDlg"));

  CDialog::OnDestroy();

  m_oPathSplitter.Split(m_oStrPathSrc);
  AfxGetApp()->WriteProfileString(_T("File"), _T("PathSrc"), m_oPathSplitter.GetFolder());

  m_oPathSplitter.Split(m_oStrPathDst);
  AfxGetApp()->WriteProfileString(_T("File"), _T("PathDst"), m_oPathSplitter.GetFolder());

  AfxGetApp()->WriteProfileString(_T("File"), _T("FileStamp"), m_oStrFileStamp);

  AfxGetApp()->WriteProfileInt(_T("Offset"), _T("Bas"),        m_nOffsetBas);
  AfxGetApp()->WriteProfileInt(_T("Offset"), _T("Droite"),     m_nOffsetDroite);
  AfxGetApp()->WriteProfileInt(_T("Offset"), _T("Gauche"),     m_nOffsetGauche);
  AfxGetApp()->WriteProfileInt(_T("Offset"), _T("Haut"),       m_nOffsetHaut);

  AfxGetApp()->WriteProfileInt(_T("Offset"), _T("X"),          m_nOffsetX);
  AfxGetApp()->WriteProfileInt(_T("Offset"), _T("Y"),          m_nOffsetY);

  AfxGetApp()->WriteProfileInt(_T("Work"),   _T("QualDst"),    m_nQualDst);
  AfxGetApp()->WriteProfileInt(_T("Work"),   _T("Alpha"),      m_nAlpha);
  AfxGetApp()->WriteProfileInt(_T("Work"),   _T("Trans"),      m_bAlpha);

  AfxGetApp()->WriteProfileInt(_T("Work"),   _T("RedimAvant"), m_nRedimAvant);

  AfxGetApp()->WriteProfileInt(_T("Work"),   _T("Tile"),       m_bTile & 1);

  AfxGetApp()->WriteProfileInt(_T("Work"),   _T("RedimApres"), m_nRedimApres);

  AfxGetApp()->WriteProfileInt(_T("Work"),   _T("TypeSrc"),    m_oComboTypeSrc.GetItemData(m_oComboTypeSrc.GetCurSel()));
  AfxGetApp()->WriteProfileInt(_T("Work"),   _T("TypeDst"),    m_oComboTypeDst.GetItemData(m_oComboTypeDst.GetCurSel()));
}

void CWaterMarkerDlg::OnPaint() 
{
  if (IsIconic())
  {
    CPaintDC dc(this); // device context for painting

    SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

    // Center icon in client rectangle
    int cxIcon = GetSystemMetrics(SM_CXICON);
    int cyIcon = GetSystemMetrics(SM_CYICON);
    CRect rect;
    GetClientRect(&rect);
    int x = (rect.Width() - cxIcon + 1) / 2;
    int y = (rect.Height() - cyIcon + 1) / 2;

    // Draw the icon
    dc.DrawIcon(x, y, m_hIcon);
  }
  else
  {
    CDialog::OnPaint();
  }
}

HCURSOR CWaterMarkerDlg::OnQueryDragIcon()
{
  return (HCURSOR) m_hIcon;
}

/////////////////////////////////////////////////////////////////////////////

void CWaterMarkerDlg::OnChangeEditPathSrc() 
{
  UpdateData(TRUE);

//  m_oPathSplitter.Split(m_oStrPathSrc);
//  m_oStrPathSrc = m_oPathSplitter.GetFolder();

  VerifRun();
}

void CWaterMarkerDlg::OnButtonPathSrc() 
{
  UpdateData(TRUE);

  m_oPathSplitter.Split(m_oStrPathSrc);

  CFileDialog l_oDlgFileSelect
  ( TRUE
  , NULL
  , (CString) m_oPathSplitter.GetFolder()+"Répertoire source"
  , 0
  );

  if(l_oDlgFileSelect.DoModal() == IDOK)
  { // Si c'est OK
    m_oPathSplitter.Split(l_oDlgFileSelect.GetPathName());

    m_oStrPathSrc = m_oPathSplitter.GetFolder();

    VerifRun();
  }
  else{}
}

void CWaterMarkerDlg::OnSelchangeComboTypeSrc() 
{
  VerifRun(); // Vérifie s'il y a des fichier du type source à traiter
}

void CWaterMarkerDlg::OnChangeEditFileStamp() 
{
  UpdateData(TRUE);

  VerifRun();
}

void CWaterMarkerDlg::OnButtonFileStamp() 
{
  int     l_nLoop;
  CString l_oStrFilter;

  UpdateData(TRUE);

  for
  ( l_nLoop  = 1
  ; l_nLoop <  CMAX_IMAGE_FORMATS
  ; l_nLoop += 1
  )
  {
    if(doctypes[l_nLoop].bRead == TRUE)
    {
      l_oStrFilter
      += (CString) doctypes[l_nLoop].description
//      +  " ("+doctypes[l_nLoop].ext+")"
      +  "|"+doctypes[l_nLoop].ext+"|"
      ;
    }
  }

  l_oStrFilter += (CString) "|";

  CFileDialog l_oDlgFileSelect
  ( TRUE
  , NULL
  , m_oStrFileStamp
  , 0
  , l_oStrFilter
  );

  if(l_oDlgFileSelect.DoModal() == IDOK)
  { // Si c'est OK
    m_oStrFileStamp = l_oDlgFileSelect.GetPathName();

    VerifRun();
  }
  else{}
}

void CWaterMarkerDlg::OnChangeEditPathDst() 
{
  UpdateData(TRUE);

//  m_oPathSplitter.Split(m_oStrPathDst);
//  m_oStrPathDst = m_oPathSplitter.GetFolder();

  VerifRun();
}

void CWaterMarkerDlg::OnButtonPathDst() 
{
  UpdateData(TRUE);

  m_oPathSplitter.Split(m_oStrPathDst);

  CFileDialog l_oDlgFileSelect
  ( TRUE
  , NULL
  , (CString) m_oPathSplitter.GetFolder()+"Répertoire destination"
  , 0
  );

  if(l_oDlgFileSelect.DoModal() == IDOK)
  { // Si c'est OK
    m_oPathSplitter.Split(l_oDlgFileSelect.GetPathName());

    m_oStrPathDst = m_oPathSplitter.GetFolder();

    VerifRun();
  }
  else{}
}

void CWaterMarkerDlg::OnSelchangeComboTypeDst() 
{
  int l_nType = m_oComboTypeDst.GetItemData(m_oComboTypeDst.GetCurSel());

  if
  (
       (l_nType == CXIMAGE_FORMAT_JPG)
#if CXIMAGE_SUPPORT_J2K
    || (l_nType == CXIMAGE_FORMAT_J2K)
#endif
#if CXIMAGE_SUPPORT_JBG
    || (l_nType == CXIMAGE_FORMAT_JBG)
#endif
#if CXIMAGE_SUPPORT_JP2
    || (l_nType == CXIMAGE_FORMAT_JP2)
#endif
#if CXIMAGE_SUPPORT_JPC
    || (l_nType == CXIMAGE_FORMAT_JPC)
#endif
  )
  {
    m_oSliderQualDst.EnableWindow(TRUE);
    m_oWndQualDst.EnableWindow(TRUE);
  }
  else
  {
    m_oSliderQualDst.EnableWindow(FALSE);
    m_oWndQualDst.EnableWindow(FALSE);
  }
}

void CWaterMarkerDlg::OnChangeEditQualDst() 
{
  UpdateData(TRUE);

  if(m_nQualDst <   0) m_nQualDst = 0;
  if(m_nQualDst > 100) m_nQualDst = 100;

  m_oSliderQualDst.SetPos(m_nQualDst);
}

void CWaterMarkerDlg::OnReleasedcaptureSliderQualDst(NMHDR* pNMHDR, LRESULT* pResult) 
{
  m_nQualDst = m_oSliderQualDst.GetPos();

  UpdateData(FALSE);

  *pResult = 0;
}


void CWaterMarkerDlg::OnCheckAlpha() 
{
  UpdateData(TRUE);

  VerifRun();
}

void CWaterMarkerDlg::OnChangeEditAlpha() 
{
  UpdateData(TRUE);

  if(m_nAlpha <   0) m_nAlpha = 0;
  if(m_nAlpha > 255) m_nAlpha = 255;

  m_oSliderAlpha.SetPos(m_nAlpha);
}

void CWaterMarkerDlg::OnReleasedcaptureSliderAlpha(NMHDR* pNMHDR, LRESULT* pResult) 
{
  m_nAlpha = m_oSliderAlpha.GetPos();

  UpdateData(FALSE);

  VerifRun();

  *pResult = 0;
}

void CWaterMarkerDlg::OnChangeEditRedimAvant() 
{
  UpdateData(TRUE);

  if(m_nRedimAvant <  10) m_nRedimAvant = 10;
  if(m_nRedimAvant > 200) m_nRedimAvant = 200;

  m_oSliderRedimAvant.SetPos(m_nRedimAvant);

  VerifRun();
}

void CWaterMarkerDlg::OnReleasedcaptureSliderRedimAvant(NMHDR* pNMHDR, LRESULT* pResult) 
{
  m_nRedimAvant = m_oSliderRedimAvant.GetPos();

  UpdateData(FALSE);

  VerifRun();

  *pResult = 0;
}

void CWaterMarkerDlg::OnCheckTile() 
{
  UpdateData(TRUE);

  m_bTile &= 1;

  VerifRun();
}

void CWaterMarkerDlg::OnChangeEditRedimApres() 
{
  UpdateData(TRUE);

  if(m_nRedimApres <  10) m_nRedimApres = 10;
  if(m_nRedimApres > 200) m_nRedimApres = 200;

  m_oSliderRedimApres.SetPos(m_nRedimApres);

//  VerifRun();
}

void CWaterMarkerDlg::OnReleasedcaptureSliderRedimApres(NMHDR* pNMHDR, LRESULT* pResult) 
{
  m_nRedimApres = m_oSliderRedimApres.GetPos();

  UpdateData(FALSE);

//  VerifRun();

  *pResult = 0;
}

/////////////////////////////////////////////////////////////////////////////

void CWaterMarkerDlg::OnChangeEditHaut() 
{
  UpdateData(TRUE);

  VerifRun();
}

void CWaterMarkerDlg::OnChangeEditBas() 
{
  UpdateData(TRUE);

  VerifRun();
}

void CWaterMarkerDlg::OnChangeEditGauche() 
{
  UpdateData(TRUE);

  VerifRun();
}

void CWaterMarkerDlg::OnChangeEditDroite() 
{
  UpdateData(TRUE);

  VerifRun();
}

/////////////////////////////////////////////////////////////////////////////

void CWaterMarkerDlg::OnButtonCsg() 
{
  m_nOffsetX = -1;
  m_nOffsetY = -1;

  VerifRun();
}

void CWaterMarkerDlg::OnButtonH() 
{
  m_nOffsetX = 0;
  m_nOffsetY = -1;

  VerifRun();
}

void CWaterMarkerDlg::OnButtonCsd() 
{
  m_nOffsetX = 1;
  m_nOffsetY = -1;

  VerifRun();
}

void CWaterMarkerDlg::OnButtonG() 
{
  m_nOffsetX = -1;
  m_nOffsetY = 0;

  VerifRun();
}

void CWaterMarkerDlg::OnButtonC() 
{
  m_nOffsetX = 0;
  m_nOffsetY = 0;

  VerifRun();
}

void CWaterMarkerDlg::OnButtonD() 
{
  m_nOffsetX = 1;
  m_nOffsetY = 0;

  VerifRun();
}

void CWaterMarkerDlg::OnButtonCig() 
{
  m_nOffsetX = -1;
  m_nOffsetY = 1;

  VerifRun();
}

void CWaterMarkerDlg::OnButtonB() 
{
  m_nOffsetX = 0;
  m_nOffsetY = 1;

  VerifRun();
}

void CWaterMarkerDlg::OnButtonCid() 
{
  m_nOffsetX = 1;
  m_nOffsetY = 1;

  VerifRun();
}

/////////////////////////////////////////////////////////////////////////////

void CWaterMarkerDlg::OnButtonRun() 
{
  CWaitCursor  l_oWaitCursor;
  CStringArray l_aoStrFichSrc;
  int          l_nTempo[3];
  int          l_nTypeDst   = m_oComboTypeSrc.GetItemData(m_oComboTypeSrc.GetCurSel());
  CString      l_oStrDstExt = GetExtFromType(l_nTypeDst);

  int          l_nXTileMin;
  int          l_nYTileMin;
  int          l_nXTileMed;
  int          l_nYTileMed;
  int          l_nXTileMax;
  int          l_nYTileMax;

  //

  m_oGroupRun.EnableWindow(FALSE);
  m_oGroupConfig.EnableWindow(FALSE);

  // Extension des fichiers destination

  l_nTempo[0] = l_oStrDstExt.Find(';');
  if(l_nTempo[0] > -1)
  { // On ne garde pas les autres extension, on ne prend que la première
    l_oStrDstExt = l_oStrDstExt.Left(l_nTempo[0]);
  }
  else{}

  l_oStrDstExt.Remove('*'); // Pas besoin de ça

  // Liste des fichiers source

  l_nTempo[1] = ListeFichiers
  ( l_aoStrFichSrc
  , m_oStrPathSrc
  , ""
  , GetExtFromType(m_oComboTypeSrc.GetItemData(m_oComboTypeSrc.GetCurSel()))
  , TRUE
  );

  CSkinProgress l_oProgressWatermark
  ( &m_oWndProgress
  , l_nTempo[1]
  , NULL
#ifdef dCSP_SLIDERBAR_METHOD
  , FALSE
#endif // dCSP_SLIDERBAR_METHOD
  , &m_oWndStatus
  , ""
  , cSPT_TIMED
  );

  // Boucle de travail

  for
  ( l_nTempo[0]  = 0
  ; l_nTempo[0] <  l_nTempo[1]
  ; l_nTempo[0] += 1
  )
  {
    m_oPathSplitter.Split(l_aoStrFichSrc.GetAt(l_nTempo[0]));

    l_oProgressWatermark.SetText
    ( (CString) "Watermark de "+m_oPathSplitter.GetFile()
    );

    // On charge l'image à traiter
    m_oImgFileSrc.Load(l_aoStrFichSrc.GetAt(l_nTempo[0]));

    // On la redimensionne au besoin
    if(m_nRedimAvant != 100)
    {
      m_oImgFileSrc.Resample
      ( m_oImgFileSrc.GetWidth()  * ((double) m_nRedimAvant / 100.0)
      , m_oImgFileSrc.GetHeight() * ((double) m_nRedimAvant / 100.0)
      );
    }
    else{}

    //

    if(m_bTile == TRUE)
    {
      l_nXTileMin
      = (m_nOffsetX < 0) ? 0 - (m_oImgFileSrc.GetWidth() / m_oImgFileStamp.GetWidth()) * m_oImgFileStamp.GetWidth() // DROITE -> GAUCHE
      : (m_nOffsetX > 0) ? (m_nOffsetDroite > 0) ? 0 - m_oImgFileStamp.GetWidth() : 0 // DROITE
      :                    0 - (m_oImgFileSrc.GetWidth() / m_oImgFileStamp.GetWidth()) * m_oImgFileStamp.GetWidth()
      ;
  
      l_nXTileMax
      = (m_nOffsetX < 0) ? (m_nOffsetGauche > 0) ? m_oImgFileStamp.GetWidth() : 0 // GAUCHE
      : (m_nOffsetX > 0) ? (m_oImgFileSrc.GetWidth() / m_oImgFileStamp.GetWidth()) * m_oImgFileStamp.GetWidth() // DROITE->GAUCHE
      :                    (m_oImgFileSrc.GetWidth() / m_oImgFileStamp.GetWidth()) * m_oImgFileStamp.GetWidth()
      ;

      l_nYTileMin
      = (m_nOffsetY < 0) ? (m_nOffsetHaut > 0) ? 0 - m_oImgFileStamp.GetHeight() : 0 // HAUT
      : (m_nOffsetY > 0) ? 0 - (m_oImgFileSrc.GetHeight() / m_oImgFileStamp.GetHeight()) * m_oImgFileStamp.GetHeight() // HAUT->BAS
      :                    0 - (m_oImgFileSrc.GetHeight() / m_oImgFileStamp.GetHeight()) * m_oImgFileStamp.GetHeight()
      ;
  
      l_nYTileMax
      = (m_nOffsetY < 0) ? (m_oImgFileSrc.GetHeight() / m_oImgFileStamp.GetHeight()) * m_oImgFileStamp.GetHeight() // HAUT->BAS
      : (m_nOffsetY > 0) ? (m_nOffsetBas > 0) ? m_oImgFileStamp.GetHeight() : 0 // BAS
      :                    (m_oImgFileSrc.GetHeight() / m_oImgFileStamp.GetHeight()) * m_oImgFileStamp.GetHeight()
      ;
    }
    else
    {
      l_nXTileMin = 0;
      l_nYTileMin = 0;
      l_nXTileMax = 1;
      l_nYTileMax = 1;
    }

    for
    ( l_nYTileMed  = l_nYTileMin
    ; l_nYTileMed <  l_nYTileMax
    ; l_nYTileMed += m_oImgFileStamp.GetHeight()
    )
    {
      for
      ( l_nXTileMed  = l_nXTileMin
      ; l_nXTileMed <  l_nXTileMax
      ; l_nXTileMed += m_oImgFileStamp.GetWidth()
      )
      { // On colle le tampon dessus
        m_oImgFileSrc.Mix
        ( m_oImgFileStamp
        , CxImage::ImageOpType::OpScreen
        , (m_oImgFileStamp.GetWidth()  / 2)
        - ((m_oImgFileSrc.GetWidth()  + (m_oImgFileSrc.GetWidth()  * m_nOffsetX)) / 2)
        + (m_nOffsetX * ((m_nOffsetX < 0) ? m_nOffsetGauche : (m_nOffsetX > 0) ? m_nOffsetDroite : 0))
        + (m_nOffsetX * (m_oImgFileStamp.GetWidth()  / 2))
        + l_nXTileMed
        , (m_oImgFileStamp.GetHeight() / 2)
        - ((m_oImgFileSrc.GetHeight() - (m_oImgFileSrc.GetHeight() * m_nOffsetY)) / 2)
        - (m_nOffsetY * ((m_nOffsetY < 0) ? m_nOffsetHaut   : (m_nOffsetY > 0) ? m_nOffsetBas    : 0))
        - (m_nOffsetY * (m_oImgFileStamp.GetHeight() / 2))
        + l_nXTileMed
        , (m_bAlpha == TRUE)
        );

      }
    }

    // On redimensionne le résultat
    if(m_nRedimApres != 100)
    {
      m_oImgFileSrc.Resample
      ( m_oImgFileSrc.GetWidth()  * ((double) m_nRedimApres / 100.0)
      , m_oImgFileSrc.GetHeight() * ((double) m_nRedimApres / 100.0)
      );
    }
    else{}

    if
    (
         (l_nTypeDst == CXIMAGE_FORMAT_JPG)
#if CXIMAGE_SUPPORT_J2K
      || (l_nTypeDst == CXIMAGE_FORMAT_J2K)
#endif
#if CXIMAGE_SUPPORT_JBG
      || (l_nTypeDst == CXIMAGE_FORMAT_JBG)
#endif
#if CXIMAGE_SUPPORT_JP2
      || (l_nTypeDst == CXIMAGE_FORMAT_JP2)
#endif
#if CXIMAGE_SUPPORT_JPC
      || (l_nTypeDst == CXIMAGE_FORMAT_JPC)
#endif
    )
    {
      m_oImgFileSrc.SetJpegQuality(m_nQualDst);
    }
    else{}

    m_oImgFileSrc.Save
    ( m_oStrPathDst + m_oPathSplitter.GetFileName() + l_oStrDstExt
    , l_nTypeDst
    );

    l_oProgressWatermark.StepIt();

    PeekAndPump();

    if(m_bStop == TRUE)
    {
      break;
    }
    else{}
  }

  //

  m_oGroupConfig.EnableWindow(TRUE);
  m_oGroupRun.EnableWindow(TRUE);

  VerifRun();
}

/////////////////////////////////////////////////////////////////////////////

void CWaterMarkerDlg::VerifRun(void)
{
  CWaitCursor  l_oWaitCursor;
  CStringArray l_aoStrFichSrc;
  CRect        l_oRectTemp;
  int          l_nFichSrc;
  double       l_nRatio;

  int          l_nXTileMin;
  int          l_nYTileMin;
  int          l_nXTileMed;
  int          l_nYTileMed;
  int          l_nXTileMax;
  int          l_nYTileMax;

  BOOL         l_bPathSrcExist   = m_oDiskObject.DirectoryExists(m_oStrPathSrc);
  BOOL         l_bPathDstExist   = m_oDiskObject.DirectoryExists(m_oStrPathDst);
  BOOL         l_bFileStampExist = m_oDiskObject.FileExists(m_oStrFileStamp);

  l_nFichSrc = ListeFichiers
  ( l_aoStrFichSrc
  , m_oStrPathSrc
  , ""
  , GetExtFromType(m_oComboTypeSrc.GetItemData(m_oComboTypeSrc.GetCurSel()))
  , TRUE
  );

  if(l_bPathSrcExist == TRUE)
  { // On complete le répertoire source
    m_oStrPathSrc = m_oStrPathSrc + "\\";
    while(m_oStrPathSrc.Replace("\\\\", "\\"));
  }
  else{}

  if(l_bPathDstExist == TRUE)
  { // On complete le répertoire destination
    m_oStrPathDst = m_oStrPathDst + "\\";
    while(m_oStrPathDst.Replace("\\\\", "\\"));
  }
  else{}

  // Modification de l'interface

  ((CButton*) GetDlgItem(IDC_BUTTON_CSG))->SetCheck((m_nOffsetX  < 0) && (m_nOffsetY  < 0));
  ((CButton*) GetDlgItem(IDC_BUTTON_H  ))->SetCheck((m_nOffsetX == 0) && (m_nOffsetY  < 0));
  ((CButton*) GetDlgItem(IDC_BUTTON_CSD))->SetCheck((m_nOffsetX  > 0) && (m_nOffsetY  < 0));
  ((CButton*) GetDlgItem(IDC_BUTTON_G  ))->SetCheck((m_nOffsetX  < 0) && (m_nOffsetY == 0));
  ((CButton*) GetDlgItem(IDC_BUTTON_C  ))->SetCheck((m_nOffsetX == 0) && (m_nOffsetY == 0));
  ((CButton*) GetDlgItem(IDC_BUTTON_D  ))->SetCheck((m_nOffsetX  > 0) && (m_nOffsetY == 0));
  ((CButton*) GetDlgItem(IDC_BUTTON_CIG))->SetCheck((m_nOffsetX  < 0) && (m_nOffsetY  > 0));
  ((CButton*) GetDlgItem(IDC_BUTTON_B  ))->SetCheck((m_nOffsetX == 0) && (m_nOffsetY  > 0));
  ((CButton*) GetDlgItem(IDC_BUTTON_CID))->SetCheck((m_nOffsetX  > 0) && (m_nOffsetY  > 0));

  ((CWnd*) GetDlgItem(IDC_EDIT_HAUT  ))->EnableWindow(m_nOffsetY < 0);
  ((CWnd*) GetDlgItem(IDC_EDIT_BAS   ))->EnableWindow(m_nOffsetY > 0);
  ((CWnd*) GetDlgItem(IDC_EDIT_GAUCHE))->EnableWindow(m_nOffsetX < 0);
  ((CWnd*) GetDlgItem(IDC_EDIT_DROITE))->EnableWindow(m_nOffsetX > 0);

  m_oEditPathSrc.SetBkColor
  ( ((l_bPathSrcExist == TRUE) && (l_nFichSrc > 0))
  ? RGB(255, 255, 255)
  : RGB(255, 191, 191)
  );
  
  m_oEditPathDst.SetBkColor
  ( (l_bPathDstExist == TRUE) && (m_oStrPathDst.CollateNoCase(m_oStrPathSrc) != 0)
  ? RGB(255, 255, 255)
  : RGB(255, 191, 191)
  );
  
  m_oEditFileStamp.SetBkColor
  ( (l_bFileStampExist == TRUE)
  ? RGB(255, 255, 255)
  : RGB(255, 191, 191)
  );

  if
  (
       (l_bPathSrcExist   == TRUE)
    && (l_bPathDstExist   == TRUE)
    && (l_bFileStampExist == TRUE)
    && (l_nFichSrc > 0)
    && (m_oStrPathDst.CollateNoCase(m_oStrPathSrc) != 0)
    && (m_oImgFileStamp.Load(m_oStrFileStamp))
    && (m_oImgFileSrc.Load(l_aoStrFichSrc.GetAt(0)))
  )
  {
    if(m_bAlpha == TRUE)
    {
      m_oImgFileStamp.AlphaCreate();
      m_oImgFileStamp.AlphaSet(m_nAlpha);
    }
    else
    {
//      m_oImgFileStamp.AlphaDelete();
    }

    ((CWnd*) GetDlgItem(IDC_EDIT_ALPHA))->EnableWindow(m_bAlpha);
    ((CWnd*) GetDlgItem(IDC_SLIDER_ALPHA))->EnableWindow(m_bAlpha);

    CxImage l_oImgTempStamp;

    l_oImgTempStamp.Copy(m_oImgFileStamp);
    m_oRectStamp.GetClientRect(&l_oRectTemp);

    // Calcul du facteur de redimensionnement
    l_nRatio
    = ((l_oImgTempStamp.GetWidth() <= l_oRectTemp.Width()) && (l_oImgTempStamp.GetHeight() <= l_oRectTemp.Height()))
    ? 1.0 // Si l'image est plus petite que le cadre, on ne l'aggrandie pas
    : (((double) l_oRectTemp.Width()  / l_oImgTempStamp.GetWidth()) < ((double) l_oRectTemp.Height() / l_oImgTempStamp.GetHeight()))
    ? ((double) l_oRectTemp.Width()  / l_oImgTempStamp.GetWidth())
    : ((double) l_oRectTemp.Height() / l_oImgTempStamp.GetHeight())
    ;

    l_oImgTempStamp.Resample
    ( l_oImgTempStamp.GetWidth()  * l_nRatio
    , l_oImgTempStamp.GetHeight() * l_nRatio
    );

    if(m_hBmpStamp)
    {
      DeleteObject(m_hBmpStamp);
    }
    else{}

    m_hBmpStamp = l_oImgTempStamp.MakeBitmap(m_oBmpStamp.GetDC()->m_hDC);
    m_oBmpStamp.SetBitmap(m_hBmpStamp);

/*
    m_oBmpStamp.SetWindowPos
    ( this
    , l_oRectTemp.left
    , l_oRectTemp.top
    , l_oRectTemp.Width()
    , l_oRectTemp.Height()
    , SWP_NOMOVE | SWP_NOZORDER | SWP_SHOWWINDOW
    );
*/
    //

    CxImage l_oImgTempFinal;

    l_oImgTempFinal.Copy(m_oImgFileSrc);

    // On la redimensionne au besoin
    if(m_nRedimAvant != 100)
    {
      l_oImgTempFinal.Resample
      ( l_oImgTempFinal.GetWidth()  * ((double) m_nRedimAvant / 100.0)
      , l_oImgTempFinal.GetHeight() * ((double) m_nRedimAvant / 100.0)
      );
    }
    else{}

    if(m_bTile == TRUE)
    {
      l_nXTileMin
      = (m_nOffsetX < 0) ? 0 - (l_oImgTempFinal.GetWidth() / m_oImgFileStamp.GetWidth()) * m_oImgFileStamp.GetWidth() // DROITE -> GAUCHE
      : (m_nOffsetX > 0) ? (m_nOffsetDroite > 0) ? 0 - m_oImgFileStamp.GetWidth() : 0 // DROITE
      :                    0 - (l_oImgTempFinal.GetWidth() / m_oImgFileStamp.GetWidth()) * m_oImgFileStamp.GetWidth()
      ;
  
      l_nXTileMax
      = (m_nOffsetX < 0) ? (m_nOffsetGauche > 0) ? m_oImgFileStamp.GetWidth() : 0 // GAUCHE
      : (m_nOffsetX > 0) ? (l_oImgTempFinal.GetWidth() / m_oImgFileStamp.GetWidth()) * m_oImgFileStamp.GetWidth() // DROITE->GAUCHE
      :                    (l_oImgTempFinal.GetWidth() / m_oImgFileStamp.GetWidth()) * m_oImgFileStamp.GetWidth()
      ;

      l_nYTileMin
      = (m_nOffsetY < 0) ? (m_nOffsetHaut > 0) ? 0 - m_oImgFileStamp.GetHeight() : 0 // HAUT
      : (m_nOffsetY > 0) ? 0 - (l_oImgTempFinal.GetHeight() / m_oImgFileStamp.GetHeight()) * m_oImgFileStamp.GetHeight() // HAUT->BAS
      :                    0 - (l_oImgTempFinal.GetHeight() / m_oImgFileStamp.GetHeight()) * m_oImgFileStamp.GetHeight()
      ;
  
      l_nYTileMax
      = (m_nOffsetY < 0) ? (l_oImgTempFinal.GetHeight() / m_oImgFileStamp.GetHeight()) * m_oImgFileStamp.GetHeight() // HAUT->BAS
      : (m_nOffsetY > 0) ? (m_nOffsetBas > 0) ? m_oImgFileStamp.GetHeight() : 0 // BAS
      :                    (l_oImgTempFinal.GetHeight() / m_oImgFileStamp.GetHeight()) * m_oImgFileStamp.GetHeight()
      ;
    }
    else
    {
      l_nXTileMin = 0;
      l_nYTileMin = 0;
      l_nXTileMax = 1;
      l_nYTileMax = 1;
    }

    for
    ( l_nYTileMed  = l_nYTileMin
    ; l_nYTileMed <= l_nYTileMax
    ; l_nYTileMed += m_oImgFileStamp.GetHeight()
    )
    {
      for
      ( l_nXTileMed  = l_nXTileMin
      ; l_nXTileMed <= l_nXTileMax
      ; l_nXTileMed += m_oImgFileStamp.GetWidth()
      )
      { // On colle le tampon dessus
        l_oImgTempFinal.Mix
        ( m_oImgFileStamp
        , CxImage::ImageOpType::OpScreen
        , (m_oImgFileStamp.GetWidth()  / 2)
        - ((l_oImgTempFinal.GetWidth()  + (l_oImgTempFinal.GetWidth()  * m_nOffsetX)) / 2)
        + (m_nOffsetX * ((m_nOffsetX < 0) ? m_nOffsetGauche : (m_nOffsetX > 0) ? m_nOffsetDroite : 0))
        + (m_nOffsetX * (m_oImgFileStamp.GetWidth()  / 2))
        + l_nXTileMed
        , (m_oImgFileStamp.GetHeight() / 2)
        - ((l_oImgTempFinal.GetHeight() - (l_oImgTempFinal.GetHeight() * m_nOffsetY)) / 2)
        - (m_nOffsetY * ((m_nOffsetY < 0) ? m_nOffsetHaut   : (m_nOffsetY > 0) ? m_nOffsetBas    : 0))
        - (m_nOffsetY * (m_oImgFileStamp.GetHeight() / 2))
        + l_nYTileMed
        , (m_bAlpha == TRUE)
        );
      }
    }

    m_oRectFinal.GetClientRect(&l_oRectTemp);

    l_nRatio
    = ((l_oImgTempFinal.GetWidth() <= l_oRectTemp.Width()) && (l_oImgTempFinal.GetHeight() <= l_oRectTemp.Height()))
    ? 1.0 // Si l'image est plus petite que le cadre, on ne l'agrandie pas
    : (((double) l_oRectTemp.Width()  / l_oImgTempFinal.GetWidth()) < ((double) l_oRectTemp.Height() / l_oImgTempFinal.GetHeight()))
    ? ((double) l_oRectTemp.Width()  / l_oImgTempFinal.GetWidth())
    : ((double) l_oRectTemp.Height() / l_oImgTempFinal.GetHeight())
    ;

    l_oImgTempFinal.Resample
    ( l_oImgTempFinal.GetWidth()  * l_nRatio
    , l_oImgTempFinal.GetHeight() * l_nRatio
    );

    if(m_hBmpFinal)
    {
      DeleteObject(m_hBmpFinal);
    }
    else{}

    m_hBmpFinal = l_oImgTempFinal.MakeBitmap(m_oBmpFinal.GetDC()->m_hDC);
    m_oBmpFinal.SetBitmap(m_hBmpFinal);

/*
    m_oBmpFinal.SetWindowPos
    ( this
    , l_oRectTemp.left
    , l_oRectTemp.top
    , l_oRectTemp.Width()
    , l_oRectTemp.Height()
    , SWP_NOMOVE | SWP_NOZORDER | SWP_SHOWWINDOW
    );
*/

    m_oGroupRun.EnableWindow(TRUE);
  }
  else
  {
    m_oGroupRun.EnableWindow(FALSE);
  }

  m_bStop = FALSE;

  UpdateData(FALSE);
}

int CWaterMarkerDlg::ListeFichiers
( CStringArray& o_raoListeFichiers
, CString       i_oStrRepertoire
, CString       i_oStrHeader
, CString       i_oStrExtensions
, BOOL          i_bConcatenate // = TRUE
)
{
  CString         l_oStrTempo[2];
  int             l_nTempo;
  int             l_nFichiers = 0;

  HANDLE          l_hFile;
  WIN32_FIND_DATA l_hFileFind;

  //

  l_oStrTempo[0] = i_oStrExtensions;
  do
  {
    l_nTempo = l_oStrTempo[0].Find(';');
    if(l_nTempo < 0)
    {
      l_nTempo = l_oStrTempo[0].GetLength();
    }else{}

    l_oStrTempo[1] = l_oStrTempo[0].Left(l_nTempo);
    if(l_oStrTempo[1].IsEmpty() == TRUE)
    {
      l_oStrTempo[1] = "*";
    }
    else
    {
      l_oStrTempo[1].Remove('*');
      l_oStrTempo[1].Remove('.');
      l_oStrTempo[1].TrimLeft();
      l_oStrTempo[1].TrimRight();
    }

    l_oStrTempo[0] = l_oStrTempo[0].Mid(l_nTempo);
    while(l_oStrTempo[0].Left(1) == ";")
    {
      l_oStrTempo[0] = l_oStrTempo[0].Mid(1);
    }

    l_oStrTempo[1] = i_oStrRepertoire+"\\"+i_oStrHeader+"*."+l_oStrTempo[1];
    while(l_oStrTempo[1].Replace("\\\\", "\\")); // Erase double slash

    l_hFile = FindFirstFile(l_oStrTempo[1], &l_hFileFind);
    do
    {
      if
      (
           (l_hFile != INVALID_HANDLE_VALUE)
        && ((l_hFileFind.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) 
      )
      {
        if(i_bConcatenate == TRUE)
        {
          l_oStrTempo[1] = i_oStrRepertoire+"\\"+l_hFileFind.cFileName;
          while(l_oStrTempo[1].Replace("\\\\", "\\")); // Erase double slash
          o_raoListeFichiers.Add(l_oStrTempo[1]);
        }
        else
        {
          o_raoListeFichiers.Add(l_hFileFind.cFileName);
        }

        l_nFichiers += 1;
      }else{}
    }
    while(FindNextFile(l_hFile, &l_hFileFind));

    FindClose(l_hFile);
  }
  while(l_oStrTempo[0].IsEmpty() == FALSE);

  return l_nFichiers;
}

CString CWaterMarkerDlg::GetExtFromType(int i_nDocType)
{
  int l_nLoop;

  for
  ( l_nLoop  = 0
  ; l_nLoop <  CMAX_IMAGE_FORMATS
  ; l_nLoop += 1
  )
  {
    if(doctypes[l_nLoop].nID == i_nDocType)
    {
      return doctypes[l_nLoop].ext;
    }
    else{}
  }

  return CString("");
}
