//-------------------------------------------------------------------------
//
//  Microsoft Windows
//
//  Copyright (C) Microsoft Corporation, 2006
//
//--------------------------------------------------------------------------
// CLog::LogEvent compares the error level of the HRESULT with the error
// level of the module attempting to log the HRESULT's message (which is
// set during CLog::InitLogInstance).  If the HRESULT's error level <=
// the module's error level, then the error is logged.
//
// ADDING AND REMOVING MESSAGES
//
// Note that the MessageId is actually broken up into two parts.  The
// high 4 bits is actually an error level indicating the severity of
// the error.  The rest of the bit number indicates the actual event
// message id.  The error level can be used to filter out event
// messages that you don't want logged all the time, unless the
// administrator is actively diagnosing something.  Also note the
// message id's are limited to a 16-bit number.
//
// The messages in this file are explicitly numbered. Do not renumber
// existing messages so as to make space to add your message.
// You should always add you message in the end of the file.
// The reason is that it often desirable to be able to read an event
// log with a message file that is from a different build, so renumbering
// existing messages should be avoided.
//
// If you want to remove a message, do NOT simply delete it from the file.
// Instead change its symbolic name to BIGLOG_UNUSED_xxx (where xxx is a
// sequential number just used to uniquify the names) and its text to
//  "Unused message".
//
// If you want to set the log level of the message, you need to OR the
// message ID with the following constants, to get log level of 0, 1, 2, 3
// 0x0000 , 0x4000, 0x8000, 0xc000
//
// For example:
//     MessageId=0x8100
//     Facility=MyFacility
//     Severity=Error
//     SymbolicName=ERROR_ID_100
//     Language=English
//     This is the text for error ID 0x101, with error level 8
//     .
//     MessageId=0x4101
//     Facility=MyFacility
//     Severity=Error
//     SymbolicName=ERROR_ID_101
//     Language=English
//     This is the text for error ID 0x101, with error level 1
//     .
//     .
//     MessageId=0x10000
//     Facility=MyFacility
//     Severity=Error
//     SymbolicName=ERROR_ID_10000
//     Language=English
//     DON'T DO THIS!!!  Message ID is > 0xFFFF.  This won't EVER work
//     .
//
// IMPORTANT NOTES
//
// NOTE THAT YOU MUST NOT DELETE OR RE-USE EVENTS THAT WERE MEANINGFUL IN
// PREVIOUSLY RELEASED VERSIONS OF THE PRODUCT.  Why?  Consider an app running
// on Win2k+1 that scans the event logs of all DCs (Win2k and Win2k+1) in an
// enterprise.  The scanner should be able to retrieve the text asociated
// with the Win2k event on the Win2k+1 box (since the event log does not
// provide this service -- text must always be looked up locally).  Also
// consider that watchdog tools often cue off of certain event IDs appearing
// in the event log (e.g., to page an admin when something particularly bad
// happens), so you don't want event 893 to mean one thing on Win2k and
// something completely different on Win2k+1.
//
// By the same token, YOU MUST NOT CHANGE THE ORDER OF INSERTION STRINGS OF
// EVENTS THAT WERE MEANINGFUL IN PREVIOUSLY RELEASED VERSIONS OF THE PRODUCT.
// It's okay to add new insertion strings to existing event log messages (they
// just won't be filled in when looking at the event generated by an older
// program), just add them at the end.  (E.g., if %1 %2 and %3 are already used,
// add new insertion strings at %4, *don't* put the new one as %2 and bump
// the old %2 to %3 and the old %3 to %4.)  Whether an insertion string is
// %1 or %4 or whatever of course doesn't restrict where it can be placed in
// the message text, it only provides a mapping to the order of parameters
// given to LogEvent.
//
// To add a new message, first see if there is an existing unused message
// that you can recycle.  If so, do so.  If no more unused messages remain,
// then you must be sure to add new messages only at the very end of the
// file.
//
// Dev Note:
//     If you add new facilities here, remember to update the registry setup
//     for event logging in the manifest to correctly reflect the new category
//     count.
//
// Define the severities
//
// Define the facility names
//
//
// Service specific facilities
//
// READ THIS: be sure to update this as facilities change
//
// Category Names Used for Event Logging
//
//
// These message id's are names for categories, which are equivalent to
// to facilities - 0x100.  LogEvent extracts the facility from the HRESULT,
// and logs that as the Category.  These message IDs allow that category
// to appear as the textual facility name in the event viewer
//
//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define FACILITY_WDSTPTMGMT              0x110
#define FACILITY_MAX_WDSTPTMGMT          0x110
#define FACILITY_BASE_WDSTPTMGMT         0x100


//
// Define the severity codes
//
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: WDSTPTMGMT_CATEGORY
//
// MessageText:
//
// WdsTptMgmt
//
#define WDSTPTMGMT_CATEGORY              ((HRESULT)0x00000001L)

///////////////////////////////////////////////////////////////////
//
//                WDSTPTMGMT Facility Messages
//
///////////////////////////////////////////////////////////////////
//
// MessageId: WDSTPTMGMT_E_INVALID_PROPERTY
//
// MessageText:
//
// The property is invalid.
//
#define WDSTPTMGMT_E_INVALID_PROPERTY    ((HRESULT)0xC1100100L)

//
// MessageId: WDSTPTMGMT_E_INVALID_OPERATION
//
// MessageText:
//
// The operation is invalid.
//
#define WDSTPTMGMT_E_INVALID_OPERATION   ((HRESULT)0xC1100101L)

//
// MessageId: WDSTPTMGMT_E_INVALID_CLASS
//
// MessageText:
//
// The interface pointer passed to the method has an invalid underlying class. Only library classes are supported.
//
#define WDSTPTMGMT_E_INVALID_CLASS       ((HRESULT)0xC1100102L)

//
// MessageId: WDSTPTMGMT_E_CONTENT_PROVIDER_ALREADY_REGISTERED
//
// MessageText:
//
// A content provider with the specified name is already registered on the server.
//
#define WDSTPTMGMT_E_CONTENT_PROVIDER_ALREADY_REGISTERED ((HRESULT)0xC1100103L)

//
// MessageId: WDSTPTMGMT_E_CONTENT_PROVIDER_NOT_REGISTERED
//
// MessageText:
//
// The specified content provider is not registered on the server.
//
#define WDSTPTMGMT_E_CONTENT_PROVIDER_NOT_REGISTERED ((HRESULT)0xC1100104L)

//
// MessageId: WDSTPTMGMT_E_INVALID_CONTENT_PROVIDER_NAME
//
// MessageText:
//
// The specified content provider name is invalid. The name must be 1 to 255 characters long and cannot contain a backslash (\) character.
//
#define WDSTPTMGMT_E_INVALID_CONTENT_PROVIDER_NAME ((HRESULT)0xC1100105L)

//
// MessageId: WDSTPTMGMT_E_TRANSPORT_SERVER_ROLE_NOT_CONFIGURED
//
// MessageText:
//
// The Windows Deployment Services Transport Server role service has not been configured on the server.
//
#define WDSTPTMGMT_E_TRANSPORT_SERVER_ROLE_NOT_CONFIGURED ((HRESULT)0xC1100106L)

//
// MessageId: WDSTPTMGMT_E_NAMESPACE_ALREADY_REGISTERED
//
// MessageText:
//
// The specified namespace is already registered on the server.
//
#define WDSTPTMGMT_E_NAMESPACE_ALREADY_REGISTERED ((HRESULT)0xC1100107L)

//
// MessageId: WDSTPTMGMT_E_NAMESPACE_NOT_REGISTERED
//
// MessageText:
//
// The specified namespace is not registered on the server.
//
#define WDSTPTMGMT_E_NAMESPACE_NOT_REGISTERED ((HRESULT)0xC1100108L)

//
// MessageId: WDSTPTMGMT_E_CANNOT_REINITIALIZE_OBJECT
//
// MessageText:
//
// The object has already been initialized and cannot be reinitialized.
//
#define WDSTPTMGMT_E_CANNOT_REINITIALIZE_OBJECT ((HRESULT)0xC1100109L)

//
// MessageId: WDSTPTMGMT_E_INVALID_NAMESPACE_NAME
//
// MessageText:
//
// The specified namespace name is invalid. The name must be 1 to 255 characters long and cannot contain a backslash (\) character.
//
#define WDSTPTMGMT_E_INVALID_NAMESPACE_NAME ((HRESULT)0xC110010AL)

//
// MessageId: WDSTPTMGMT_E_INVALID_NAMESPACE_DATA
//
// MessageText:
//
// The namespace contains invalid or unknown data.
//
#define WDSTPTMGMT_E_INVALID_NAMESPACE_DATA ((HRESULT)0xC110010BL)

//
// MessageId: WDSTPTMGMT_E_NAMESPACE_READ_ONLY
//
// MessageText:
//
// The namespace data cannot be modified because it is or has been previously registered on the server.
//
#define WDSTPTMGMT_E_NAMESPACE_READ_ONLY ((HRESULT)0xC110010CL)

//
// MessageId: WDSTPTMGMT_E_INVALID_NAMESPACE_START_TIME
//
// MessageText:
//
// The scheduled start time for the namespace is invalid.
//
#define WDSTPTMGMT_E_INVALID_NAMESPACE_START_TIME ((HRESULT)0xC110010DL)

//
// MessageId: WDSTPTMGMT_E_INVALID_DIAGNOSTICS_COMPONENTS
//
// MessageText:
//
// The specified diagnostics components mask contains invalid or unknown components.
//
#define WDSTPTMGMT_E_INVALID_DIAGNOSTICS_COMPONENTS ((HRESULT)0xC110010EL)

//
// MessageId: WDSTPTMGMT_E_CANNOT_REFRESH_DIRTY_OBJECT
//
// MessageText:
//
// The object contains unsaved changes. The object data cannot be refreshed until you commit or discard the changes.
//
#define WDSTPTMGMT_E_CANNOT_REFRESH_DIRTY_OBJECT ((HRESULT)0xC110010FL)

//
// MessageId: WDSTPTMGMT_E_INVALID_SERVICE_IP_ADDRESS_RANGE
//
// MessageText:
//
// The specified IP address range is invalid. The start and end IP addresses must be valid and the start IP address must be less than or equal to the end IP address.
//
#define WDSTPTMGMT_E_INVALID_SERVICE_IP_ADDRESS_RANGE ((HRESULT)0xC1100110L)

//
// MessageId: WDSTPTMGMT_E_INVALID_SERVICE_PORT_RANGE
//
// MessageText:
//
// The specified service port range is invalid. The start port must be less than or equal to the end port, and both values must be between 1025 and 65536, inclusive.
//
#define WDSTPTMGMT_E_INVALID_SERVICE_PORT_RANGE ((HRESULT)0xC1100111L)

//
// MessageId: WDSTPTMGMT_E_INVALID_NAMESPACE_START_PARAMETERS
//
// MessageText:
//
// The start parameters for the namespace are invalid.
//
#define WDSTPTMGMT_E_INVALID_NAMESPACE_START_PARAMETERS ((HRESULT)0xC1100112L)

//
// MessageId: WDSTPTMGMT_E_TRANSPORT_SERVER_UNAVAILABLE
//
// MessageText:
//
// The Windows Deployment Services Transport Server is unavailable.
//
#define WDSTPTMGMT_E_TRANSPORT_SERVER_UNAVAILABLE ((HRESULT)0xC1100113L)

//
// MessageId: WDSTPTMGMT_E_NAMESPACE_NOT_ON_SERVER
//
// MessageText:
//
// The specified namespace has never been registered on the server.
//
#define WDSTPTMGMT_E_NAMESPACE_NOT_ON_SERVER ((HRESULT)0xC1100114L)

//
// MessageId: WDSTPTMGMT_E_NAMESPACE_REMOVED_FROM_SERVER
//
// MessageText:
//
// The specified namespace has been unregistered and removed from the server.
//
#define WDSTPTMGMT_E_NAMESPACE_REMOVED_FROM_SERVER ((HRESULT)0xC1100115L)

//
// MessageId: WDSTPTMGMT_E_INVALID_IP_ADDRESS
//
// MessageText:
//
// The specified IP address is invalid. The IP address must be a well formed value of the correct type.
//
#define WDSTPTMGMT_E_INVALID_IP_ADDRESS  ((HRESULT)0xC1100116L)

//
// MessageId: WDSTPTMGMT_E_INVALID_IPV4_MULTICAST_ADDRESS
//
// MessageText:
//
// The specified IPv4 address is not valid for multicast. IPv4 multicast addresses must be in the range 224.0.1.0 to 239.255.255.255.
//
#define WDSTPTMGMT_E_INVALID_IPV4_MULTICAST_ADDRESS ((HRESULT)0xC1100117L)

//
// MessageId: WDSTPTMGMT_E_INVALID_IPV6_MULTICAST_ADDRESS
//
// MessageText:
//
// The specified IPv6 address is not valid for multicast. IPv6 multicast addresses must start with FF (for example, FF15::FF).
//
#define WDSTPTMGMT_E_INVALID_IPV6_MULTICAST_ADDRESS ((HRESULT)0xC1100118L)

//
// MessageId: WDSTPTMGMT_E_IPV6_NOT_SUPPORTED
//
// MessageText:
//
// The Windows Deployment Services Transport Server does not support IPv6.
//
#define WDSTPTMGMT_E_IPV6_NOT_SUPPORTED  ((HRESULT)0xC1100119L)

//
// MessageId: WDSTPTMGMT_E_INVALID_IPV6_MULTICAST_ADDRESS_SOURCE
//
// MessageText:
//
// The specified IPv6 multicast address source is invalid. Transport Server only supports using IPv6 multicast addresses from a range.
//
#define WDSTPTMGMT_E_INVALID_IPV6_MULTICAST_ADDRESS_SOURCE ((HRESULT)0xC110011AL)

//
// MessageId: WDSTPTMGMT_E_INVALID_MULTISTREAM_STREAM_COUNT
//
// MessageText:
//
// The specified multistream stream count is invalid. The stream count must be set to either 2 or 3.
//
#define WDSTPTMGMT_E_INVALID_MULTISTREAM_STREAM_COUNT ((HRESULT)0xC110011BL)

//
// MessageId: WDSTPTMGMT_E_INVALID_AUTO_DISCONNECT_THRESHOLD
//
// MessageText:
//
// The specified AutoDisconnect threshold is invalid. The threshold must be set to a value between 1 KBps and 4194303 KBps, inclusive.
//
#define WDSTPTMGMT_E_INVALID_AUTO_DISCONNECT_THRESHOLD ((HRESULT)0xC110011CL)

//
// MessageId: WDSTPTMGMT_E_MULTICAST_SESSION_POLICY_NOT_SUPPORTED
//
// MessageText:
//
// You cannot configure the multicast session policy on this Transport Server. This policy is only supported on Windows Server 2008 R2 and later.
//
#define WDSTPTMGMT_E_MULTICAST_SESSION_POLICY_NOT_SUPPORTED ((HRESULT)0xC110011DL)

//
// MessageId: WDSTPTMGMT_E_INVALID_SLOW_CLIENT_HANDLING_TYPE
//
// MessageText:
//
// The specified slow-client handling type is not valid.
//
#define WDSTPTMGMT_E_INVALID_SLOW_CLIENT_HANDLING_TYPE ((HRESULT)0xC110011EL)

//
// MessageId: WDSTPTMGMT_E_NETWORK_PROFILES_NOT_SUPPORTED
//
// MessageText:
//
// This Windows Deployment Services Transport Server does not support network profiles.
//
#define WDSTPTMGMT_E_NETWORK_PROFILES_NOT_SUPPORTED ((HRESULT)0xC110011FL)


