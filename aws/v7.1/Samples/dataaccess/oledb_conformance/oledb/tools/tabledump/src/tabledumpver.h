//-----------------------------------------------------------------------------
// Microsoft OLE DB Version File
// Copyright (C) 1994-1999 By Microsoft Corporation.
//
// @doc
//
// @module version include file
//
//

// Constants -----------------------------------------------------------------
#ifndef _AXVER_H_
#define _AXVER_H_

#define VER_FILEVERSION 1,50,3518,00
#define VER_FILEVERSION_STR "1.50.3518.00\0"
#define VER_PRODUCTVERSION 1,50,3518,00
#define VER_PRODUCTVERSION_STR "1.50.3518.00\0"

#define VER_FILEFLAGSMASK		(VS_FF_DEBUG | VS_FF_PRERELEASE)
#ifdef DEBUG
#define VER_FILEFLAGS			(VS_FF_DEBUG)
#else
#define VER_FILEFLAGS			(0)
#endif

#define VER_FILEOS				VOS_NT_WINDOWS32

#define VER_COMPANYNAME_STR		"Microsoft Corporation\0"
#define VER_PRODUCTNAME_STR		"Microsoft OLE DB\0"
#define VER_LEGALCOPYRIGHT_STR	"Copyright \251 Microsoft Corporation 1994-1999\0"

// Resource DLL Version Resource ID
#define IDS_RESDLL_VER			1

#endif
//--------------------
