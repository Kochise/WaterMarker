//////////////////////////////////////////////////////////////////////
// CPathSplit.h - Kochise Kochise 2002-2004
//

#ifndef __CPATHSPLIT_H__
#define __CPATHSPLIT_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SigUtils.h"

class CPathSplit
{ 
  // Construction
  public: 
    CPathSplit
    (
    );

    CPathSplit
    ( const char* i_panStrPath
    );

    virtual ~CPathSplit(void);

    typedef enum ePathElement
    { ePS_DRV = 0
    , ePS_DIR
    , ePS_FN
    , ePS_EXT
    , ePS__NUM
    };

  // Operations
    // Split the path
    BOOL Split
    ( const char* i_panStrPath
    );
    
    inline char* GetPath()     { return mp_panBufferPath; }

    char* GetPath
    ( int         i_nEnd
    , const char* i_poStrQueue = NULL    // No queue
    , int         i_nStart     = ePS_DRV // From DRIVE
    );

    inline char* GetDrive()    { return GetPath(ePS_DRV, NULL, ePS_DRV); }
    inline char* GetDirectory(){ return GetPath(ePS_DIR, NULL, ePS_DIR); }
    inline char* GetFolder()   { return GetPath(ePS_DIR, NULL, ePS_DRV); }

    inline char* GetFileName() { return GetPath(ePS_FN,  NULL, ePS_FN); }
    inline char* GetExtension(){ return GetPath(ePS_EXT, NULL, ePS_EXT); }
    inline char* GetFile()     { return GetPath(ePS_EXT, NULL, ePS_FN); }

  // Attributes
  protected:
    char*   mp_panBufferPath;
    char*   mp_panBufferTempo;

    int     mp_nBufferSize;

    char*   mp_panTempo;

    int     mp_anPathFirst[ePS__NUM];
    int     mp_anPathCount[ePS__NUM];

    void    _ErasePointers();
    int     _Find(char i_nFind, bool i_bReserve = false);
    void    _Copy(const char* i_panString, int i_nNumber = 0);
}; 

#endif // __CPATHSPLIT_H__
