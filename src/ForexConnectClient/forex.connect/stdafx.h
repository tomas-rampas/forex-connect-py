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
void export_IO2GLastOrderUpdateResponseReader();
void export_IO2GMarketDataResponseReader();
void export_IO2GMarketDataSnapshotResponseReader();
void export_IO2GOrderResponseReader();
void export_IO2GSystemPropertiesReader();
void export_IO2GTablesUpdatesReader();
void export_IO2GTimeConverter();
void export_IO2GAccountRow();
void export_IO2GClosedTradeRow();
void export_IO2GMessageRow();
void export_IO2GOfferRow();
void export_IO2GOrderRow();
void export_IO2GSummaryRow();
void export_IO2GTradeRow();
void export_IO2GColumn();
void export_IO2GLoginRules();
void export_IO2GPermissionChecker();
void export_IO2GRequest();
void export_IO2GResponse();
void export_IO2GRow();
void export_IO2GSession();
//IO2GTable_Begin
void export_IO2GGenericTableResponseReader();
void export_IO2GOffersTableResponseReader();
void export_IO2GAccountsTableResponseReader();
void export_IO2GOrdersTableResponseReader();
void export_IO2GTradesTableResponseReader();
void export_IO2GClosedTradesTableResponseReader();
void export_IO2GMessagesTableResponseReader();
void export_IO2GTableIterator();
void export_IO2GTableListener();
void export_IO2GTable();
void export_IO2GTableManager();
void export_IO2GOffersTable();
void export_IO2GAccountsTable();
void export_IO2GOrdersTable();
void export_IO2GTradesTable();
void export_IO2GClosedTradesTable();
void export_IO2GMessagesTable();
void export_IO2GSummaryTable();
//IO2GTable_End
void export_IO2GTimeframe();
void export_IO2GTradingSettingsProvider();
void export_O2GDateUtils();
void export_O2GEnum();
void export_O2GRequestParamsEnum();
void export_CO2GTransport();
