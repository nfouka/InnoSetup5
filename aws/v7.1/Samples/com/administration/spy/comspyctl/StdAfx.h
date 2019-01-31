// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#if !defined(AFX_STDAFX_H__A9B39075_AAD0_11D0_B183_00AA00BA3258__INCLUDED_)
#define AFX_STDAFX_H__A9B39075_AAD0_11D0_B183_00AA00BA3258__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define STRICT


#if !defined(_WIN32_WINNT)
#define _WIN32_WINNT 0x0500
#endif // !defined(_WIN32_WINNT)

#define _ATL_APARTMENT_THREADED


#include <atlbase.h>
#include "commctrl.h"
#include <comsvcs.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
#include <atlctl.h>
#pragma warning( disable : 4786) // disable the warning "identifier was truncated to '255' characters in the debug information" generated by STL
#include <list>
#include <map> 
#include <string>
#include <ocidl.h>	// Added by ClassView
using namespace std;


class CAppInfo;
interface ICOMSysLCE;

typedef map <wstring, CAppInfo *> MapStringToAppInfo;
typedef map <int, ICOMSysLCE*> SUBSCRIBERMAP;


#define _ATL_DEBUG_QI
#define _ATL_DEBUG_REFCOUNT


//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A9B39075_AAD0_11D0_B183_00AA00BA3258__INCLUDED)
