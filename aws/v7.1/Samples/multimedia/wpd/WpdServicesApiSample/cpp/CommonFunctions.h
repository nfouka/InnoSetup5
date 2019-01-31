// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

// Implemented in ContentProperties.cpp
void DisplayStringProperty(
    IPortableDeviceValues*  pProperties,
    REFPROPERTYKEY          key,
    PCWSTR                  pszKey);

// Implemented in ContentProperties.cpp
void DisplayGuidProperty(
    IPortableDeviceValues*  pProperties,
    REFPROPERTYKEY          key,
    PCWSTR                  pszKey);

// Implemented in Service Capabilities.cpp
void DisplayFormat(
    IPortableDeviceServiceCapabilities* pCapabilities,
    REFGUID                             Format);
    
// Implemented in ServiceCapabilities.cpp
void DisplayParameterForm(
    DWORD                   dwForm);

// Implemented in ServiceCapabilities.cpp
void DisplayVarType(
    VARTYPE                 vartype);


// Helper class to convert a GUID to a string
class CGuidToString
{
private:        
    WCHAR _szGUID[64];

public:
    CGuidToString(REFGUID guid)
    {
        if (!::StringFromGUID2(guid,  _szGUID, 64))
        {
            _szGUID[0] = L'\0';
        }
    }

    operator PWSTR()
    {
        return _szGUID;
    }
};