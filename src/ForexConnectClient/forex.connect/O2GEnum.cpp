#include "stdafx.h"
#include <O2GEnum.h>

void export_O2GEnum()
{
	using namespace boost::python;

	enum_<O2GTable>("O2GTable")
		.value("TableUnknown", O2GTable::TableUnknown)
		.value("Offers", O2GTable::Offers)
		.value("Accounts", O2GTable::Accounts)
		.value("Orders", O2GTable::Orders)
		.value("Trades", O2GTable::Trades)
		.value("ClosedTrades", O2GTable::ClosedTrades)
		.value("Messages", O2GTable::Messages)
		.value("Summary", O2GTable::Summary)
		.export_values()
		;

	enum_<O2GResponseType>("O2GResponseType")
		.value("ResponseUnknown", O2GResponseType::ResponseUnknown)
		.value("TablesUpdates", O2GResponseType::TablesUpdates)
		.value("MarketDataSnapshot", O2GResponseType::MarketDataSnapshot)
		.value("GetAccounts", O2GResponseType::GetAccounts)
		.value("GetOffers", O2GResponseType::GetOffers)
		.value("GetOrders", O2GResponseType::GetOrders)
		.value("GetTrades", O2GResponseType::GetTrades)
		.value("GetClosedTrades", O2GResponseType::GetClosedTrades)
		.value("GetMessages", O2GResponseType::GetMessages)
		.value("CreateOrderResponse", O2GResponseType::CreateOrderResponse)
		.value("GetSystemProperties", O2GResponseType::GetSystemProperties)
		.value("CommandResponse", O2GResponseType::CommandResponse)
		.value("MarginRequirementsResponse", O2GResponseType::MarginRequirementsResponse)
		.value("GetLastOrderUpdate", O2GResponseType::GetLastOrderUpdate)
		.value("MarketData", O2GResponseType::MarketData)
		.export_values()
		;

	enum_<O2GTableUpdateType>("O2GTableUpdateType")
		.value("UpdateUnknown", O2GTableUpdateType::UpdateUnknown)
		.value("Insert", O2GTableUpdateType::Insert)
		.value("Update", O2GTableUpdateType::Update)
		.value("Delete", O2GTableUpdateType::Delete)
		.export_values()
		;

	enum_<O2GPermissionStatus>("O2GPermissionStatus")
		.value("PermissionDisabled", O2GPermissionStatus::PermissionDisabled)
		.value("PermissionEnabled", O2GPermissionStatus::PermissionEnabled)
		.value("PermissionHidden ", O2GPermissionStatus::PermissionHidden)
		.export_values()
		;

	enum_<O2GMarketStatus>("O2GMarketStatus")
		.value("MarketStatusOpen", O2GMarketStatus::MarketStatusOpen)
		.value("MarketStatusClosed", O2GMarketStatus::MarketStatusClosed)
		.value("MarketStatusUndefined", O2GMarketStatus::MarketStatusUndefined)
		.export_values()
		;

	enum_<O2GPriceUpdateMode>("O2GPriceUpdateMode")
		.value("Default", O2GPriceUpdateMode::Default)
		.value("NoPrice", O2GPriceUpdateMode::NoPrice)
		.export_values()
		;

	enum_<O2GTableManagerMode>("O2GTableManagerMode")
		.value("No", O2GTableManagerMode::No)
		.value("Yes", O2GTableManagerMode::Yes)
		.export_values()
		;

	enum_<O2GTableStatus>("O2GTableStatus")
		.value("Initial", O2GTableStatus::Initial)
		.value("Refreshing", O2GTableStatus::Refreshing)
		.value("Refreshed", O2GTableStatus::Refreshed)
		.value("Failed", O2GTableStatus::Failed)
		.export_values()
		;

	enum_<O2GReportUrlError>("O2GReportUrlError")
		.value("ReportUrlNotSupported", O2GReportUrlError::ReportUrlNotSupported)
		.value("ReportUrlTooSmallBuffer", O2GReportUrlError::ReportUrlTooSmallBuffer)
		.value("ReportUrlNotLogged", O2GReportUrlError::ReportUrlNotLogged)
		.export_values()
		;

	enum_<O2GTableManagerStatus>("O2GTableManagerStatus")
		.value("TablesLoading", O2GTableManagerStatus::TablesLoading)
		.value("TablesLoaded", O2GTableManagerStatus::TablesLoaded)
		.value("TablesLoadFailed", O2GTableManagerStatus::TablesLoadFailed)
		.export_values()
		;
}