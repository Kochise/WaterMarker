//////////////////////////////////////////////////////////////////////
// CPathSplit.cpp - Kochise 2002-2004
//

#include "stdafx.h"
#include "CPathSplit.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinProgress

// g_Global      : g_ = Global
// i_Input       : i_ = Input
// no z...
// m_Member      : m_ = Member
// o_Output      : o_ = Output
// l_Local       : l_ = Local
// ...           : use your imagination

// aArray        : a  = Array    (array)
// bBool         : b  = Boolean  (boolean, TRUE/FALSE)
// cConstant     : c  = Constant (constant, whatever...)
// dDefine       : d  = Define   (simple define or defined value)
// eEnum         : e  = Enum     (enum list element)
// iIterator     : i  = Iterator (STL iterator)
// nNumber       : n  = Number   (char, long, int, whatever...)
// oObject       : o  = Object   (C++ class)
// pPointer      : p  = Pointer  (typicaly a 32 bits ulong address)
// sStruct       : s  = Struct   (structure)
// tTemplate     : t  = Template (template)
// uUnion        : u  = Union    (join two or more values of the same size under a common name)
// vVector       : v  = Vector   (STL vector, mostly like an array)

// poRemoteClass : po = Pointer on Object
// cdConstantDef : cd = Constant Define, typicaly a constant defined value
// usUnionStruct : us = Union of Structures
// ...           : use your imagination

// o_psBitmap    : CBitmap::GetBitmap((BITMAP*) o_psBitmap); // s = BITMAP, p = *, o_ means it's an output

// <Value>
// [Function]

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          :                                                            */
/* Role          :                                                            */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : Sets the default values to                                 */
/* Behavior      :                                                            */
/*----------------------------------------------------------------------------*/
/* PROC                                                                       */
/*                                                                            */
/* A.....                                                                     */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
CPathSplit::CPathSplit
(
)
{
  mp_panBufferPath  = NULL;
  mp_panBufferTempo = NULL;
  mp_nBufferSize    = 0;

  // Init

  _ErasePointers();

  // Process
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          :                                                            */
/* Role          :                                                            */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : Sets the default values to                                 */
/* Behavior      :                                                            */
/*----------------------------------------------------------------------------*/
/* PROC                                                                       */
/*                                                                            */
/* A.....                                                                     */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
CPathSplit::CPathSplit
( const char* i_panStrPath
)
{
  mp_panBufferPath  = NULL;
  mp_panBufferTempo = NULL;
  mp_nBufferSize    = 0;

  // Init

  _ErasePointers();

  // Process

  Split(i_panStrPath);
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          :                                                            */
/* Role          :                                                            */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : Sets the default values to                                 */
/* Behavior      :                                                            */
/*----------------------------------------------------------------------------*/
/* PROC                                                                       */
/*                                                                            */
/* A.....                                                                     */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
CPathSplit::~CPathSplit
( void
)
{
  if(mp_panBufferPath != NULL)
  {
    delete [] mp_panBufferPath;
  }
  else{}

  if(mp_panBufferTempo != NULL)
  {
    delete [] mp_panBufferTempo;
  }
  else{}
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          :                                                            */
/* Role          :                                                            */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : Sets the default values to                                 */
/* Behavior      :                                                            */
/*----------------------------------------------------------------------------*/
/* PROC                                                                       */
/*                                                                            */
/* A.....                                                                     */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
BOOL CPathSplit::Split
( const char* i_panStrPath
)
{
  int l_nPathLenght = strlen(i_panStrPath);

  // Init

  _ErasePointers(); // Erase pointers

  if
  (
       (l_nPathLenght > mp_nBufferSize)
    || (mp_panBufferPath  == NULL)
    || (mp_panBufferTempo == NULL)
  )
  {
    if(mp_panBufferPath != NULL)
    {
      delete [] mp_panBufferPath;
    }
    else{}

    if(mp_panBufferTempo != NULL)
    {
      delete [] mp_panBufferTempo;
    }
    else{}

    mp_nBufferSize = (l_nPathLenght + 1023) & (-1024); // Par paquet de 1024
    mp_panBufferPath  = new char[mp_nBufferSize];
    mp_panBufferTempo = new char[mp_nBufferSize];
  }
  else{}

  strcpy
  ( mp_panBufferPath
  , i_panStrPath
  );

  TrimLeftRight(mp_panBufferPath);

  // Process

  l_nPathLenght = strlen(mp_panBufferPath);
  mp_panTempo   = mp_panBufferPath; // Start look-up

  if(l_nPathLenght > 0)
  { // If the path is not empty
    mp_anPathFirst[ePS_DIR] = _Find('\\', false);

    if(mp_anPathFirst[ePS_DIR] != (-1))
    { // If first directory found
      mp_anPathCount[ePS_DRV] = mp_anPathFirst[ePS_DIR] - mp_anPathFirst[ePS_DRV];

      if
      (
           (mp_panBufferPath[mp_anPathFirst[ePS_DIR] + 0] == '\\')
        && (mp_panBufferPath[mp_anPathFirst[ePS_DIR] + 1] == '\\')
      )
      { // If Network
        mp_anPathFirst[ePS_DIR] += 1;
      }
      else{}

      mp_anPathFirst[ePS_FN] = _Find('\\', true);

      if(mp_anPathFirst[ePS_FN] != (-1))
      { // If last directory found (typicaly the file name, but may be empty also)
        mp_anPathFirst[ePS_FN] += 1; // Include the trailing '\' in the directory
        mp_anPathCount[ePS_DIR] = mp_anPathFirst[ePS_FN] - mp_anPathFirst[ePS_DIR];

        mp_anPathFirst[ePS_EXT] = _Find('.', true);

        if
        (
             (mp_anPathFirst[ePS_EXT] != (-1))
          && (mp_anPathFirst[ePS_EXT]  > mp_anPathFirst[ePS_FN])
        )
        { // If a extension was found AFTER the last directory
          mp_anPathCount[ePS_FN]  = mp_anPathFirst[ePS_EXT] - mp_anPathFirst[ePS_FN];
          mp_anPathCount[ePS_EXT] = l_nPathLenght - mp_anPathFirst[ePS_EXT];
        }
        else
        {
          mp_anPathCount[ePS_FN]  = l_nPathLenght - mp_anPathFirst[ePS_FN];
          mp_anPathFirst[ePS_EXT] = 0;
          // mp_anPathCount[ePS_EXT] = 0; // Already to 0 from _ErasePointers()
        }
      }
      else{}
    }
    else
    {
      mp_anPathCount[ePS_DRV] = l_nPathLenght;
    }

    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          :                                                            */
/* Role          :                                                            */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : Sets the default values to                                 */
/* Behavior      :                                                            */
/*----------------------------------------------------------------------------*/
/* PROC                                                                       */
/*                                                                            */
/* A.....                                                                     */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
char* CPathSplit::GetPath
(       int   i_nEnd
, const char* i_poStrQueue
,       int   i_nStart
)
{
  if(i_nEnd < ePS_DRV)
  { // In case...
    i_nEnd = ePS_DRV;
  }
  else{}

  if(i_nStart < ePS_DRV)
  { // ...of bad values
    i_nStart = ePS_DRV;
  }
  else{}

  if(i_nEnd >= ePS__NUM)
  { // Clip to the maximum number of path elements currently supported
    i_nEnd = ePS__NUM - 1;
  }
  else{}

  if(i_nStart > i_nEnd)
  { // Clip the start
    i_nStart = i_nEnd;
  }
  else{}

  mp_panTempo = mp_panBufferTempo;

  //

  _Copy
  ( &mp_panBufferPath[mp_anPathFirst[i_nStart]] // From...
  , (mp_anPathFirst[i_nEnd] - mp_anPathFirst[i_nStart]) // Size of the Start TO end
  +  mp_anPathCount[i_nEnd] // Includes size of end
  );

  if(i_poStrQueue != NULL)
  { // Add a queue of needed
    _Copy
    ( i_poStrQueue // From...
    , 0 // Copy up to NULL char
    );
  }
  else{}

  // End null char
  *mp_panTempo = '\0';

  return mp_panBufferTempo;
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          :                                                            */
/* Role          :                                                            */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : Sets the default values to                                 */
/* Behavior      :                                                            */
/*----------------------------------------------------------------------------*/
/* PROC                                                                       */
/*                                                                            */
/* A.....                                                                     */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
void CPathSplit::_ErasePointers
(
)
{
  int l_nLoop;

  // Init

  for
  ( l_nLoop = 0
  ; l_nLoop < ePS__NUM
  ; l_nLoop += 1
  )
  { // Erase pointers
    mp_anPathFirst[l_nLoop] = 0;
    mp_anPathCount[l_nLoop] = 0;
  }

  // Process
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          :                                                            */
/* Role          :                                                            */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : Sets the default values to                                 */
/* Behavior      :                                                            */
/*----------------------------------------------------------------------------*/
/* PROC                                                                       */
/*                                                                            */
/* A.....                                                                     */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
int CPathSplit::_Find
( char i_nFind
, bool i_bReserve // = false
)
{
  if(i_bReserve == false)
  { // Forward
    while
    (
         (*mp_panTempo != 0)
      && (*mp_panTempo != i_nFind)
    )
    { // NOT (end OR char)
      mp_panTempo += 1;
    }

    if(*mp_panTempo == i_nFind)
    {
      return mp_panTempo - mp_panBufferPath;
    }
    else
    {
      return -1;
    }
  }
  else
  { // Backward
    while(*mp_panTempo != 0)
    { // NOT end
      mp_panTempo += 1;
    }

    while
    (
         (mp_panTempo  != mp_panBufferPath)
      && (*mp_panTempo != i_nFind)
    )
    { // NOT (start OR char)
      mp_panTempo -= 1;
    }

    if(*mp_panTempo == i_nFind)
    {
      return mp_panTempo - mp_panBufferPath;
    }
    else
    {
      return -1;
    }
  }
}

/*--- START FUNCTION HEADER --------------------------------------------------*/
/* Name          :                                                            */
/* Role          :                                                            */
/* Type          : public                                                     */
/* Interface     : RETURN (direct value)                                      */
/*                   None                                                     */
/*                 OUTPUT (pointer to value)                                  */
/*                   None                                                     */
/*                 INPUT  (pointer to value, direct/default value)            */
/*                   None                                                     */
/* Pre-condition : None                                                       */
/* Constraints   : Sets the default values to                                 */
/* Behavior      :                                                            */
/*----------------------------------------------------------------------------*/
/* PROC                                                                       */
/*                                                                            */
/* A.....                                                                     */
/*----------------------------------------------------------------------------*/
/*--- END FUNCTION HEADER ----------------------------------------------------*/
void CPathSplit::_Copy
( const char* i_panString
, int         i_nNumber // = 0
)
{
  if(i_nNumber > 0)
  {
    while
    (
         (i_nNumber > 0)
      && (*i_panString != 0)
    )
    {
      *mp_panTempo++ = *i_panString++;
      i_nNumber -= 1;
    }
  }
  else
  {
    while(*i_panString != 0)
    {
      *mp_panTempo++ = *i_panString++;
    }
  }
}
