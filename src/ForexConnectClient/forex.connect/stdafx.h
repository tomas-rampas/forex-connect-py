// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#define BOOST_ALL_DYN_LINK
#define BOOST_LIB_DIAGNOSTIC
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

#include <ForexConnect.h>

// Declaration
void export_AccountsColumnsEnum();
void export_TradesColumnsEnum();
void export_ClosedTradesColumnsEnum();
void export_MessagesColumnsEnum();
void export_OffersColumnsEnum();
void export_OrdersColumnsEnum();
void export_SummariesColumnsEnum();
void export_IAddRefClass();
void export_IO2GTableColumn();