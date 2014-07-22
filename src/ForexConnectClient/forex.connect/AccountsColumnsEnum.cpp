#include "stdafx.h"
#include <Enums\AccountsColumnsEnum.h>

using namespace boost::python;

void export_AccountsColumnsEnum(){
	object obj_AccountColumnsEnum
		= class_<AccountColumnsEnum>("AccountColumnsEnum", "Account columns enumeration", init<>());
	{
		scope in_AccountColumnsEnum(obj_AccountColumnsEnum);
		enum_<AccountColumnsEnum::Columns>("Columns")
			.value("AccountID", AccountColumnsEnum::AccountID)
			.value("AccountName", AccountColumnsEnum::AccountName)
			.value("AccountKind", AccountColumnsEnum::AccountKind)
			.value("Balance", AccountColumnsEnum::Balance)
			.value("NonTradeEquity", AccountColumnsEnum::NonTradeEquity)
			.value("M2MEquity", AccountColumnsEnum::M2MEquity)
			.value("UsedMargin", AccountColumnsEnum::UsedMargin)
			.value("UsedMargin3", AccountColumnsEnum::UsedMargin3)
			.value("MarginCallFlag", AccountColumnsEnum::MarginCallFlag)
			.value("LastMarginCallDate", AccountColumnsEnum::LastMarginCallDate)
			.value("MaintenanceType", AccountColumnsEnum::MaintenanceType)
			.value("AmountLimit", AccountColumnsEnum::AmountLimit)
			.value("BaseUnitSize", AccountColumnsEnum::BaseUnitSize)
			.value("MaintenanceFlag", AccountColumnsEnum::MaintenanceFlag)
			.value("ManagerAccountID", AccountColumnsEnum::ManagerAccountID)
			.value("LeverageProfileID", AccountColumnsEnum::LeverageProfileID)
			.export_values()
			;
	};

	object obj_AccountTableColumnsEnum
		= class_<AccountTableColumnsEnum>("AccountTableColumnsEnum", "Account table columns enumeratrion", init<>());
	{
		scope in_AccountTableColumnsEnum(obj_AccountTableColumnsEnum);
		enum_<AccountTableColumnsEnum::Columns>("Columns")
			.value("AccountID", AccountTableColumnsEnum::AccountID)
			.value("AccountName", AccountTableColumnsEnum::AccountName)
			.value("AccountKind", AccountTableColumnsEnum::AccountKind)
			.value("Balance", AccountTableColumnsEnum::Balance)
			.value("NonTradeEquity", AccountTableColumnsEnum::NonTradeEquity)
			.value("M2MEquity", AccountTableColumnsEnum::M2MEquity)
			.value("UsedMargin", AccountTableColumnsEnum::UsedMargin)
			.value("UsedMargin3", AccountTableColumnsEnum::UsedMargin3)
			.value("MarginCallFlag", AccountTableColumnsEnum::MarginCallFlag)
			.value("LastMarginCallDate", AccountTableColumnsEnum::LastMarginCallDate)
			.value("MaintenanceType", AccountTableColumnsEnum::MaintenanceType)
			.value("AmountLimit", AccountTableColumnsEnum::AmountLimit)
			.value("BaseUnitSize", AccountTableColumnsEnum::BaseUnitSize)
			.value("MaintenanceFlag", AccountTableColumnsEnum::MaintenanceFlag)
			.value("ManagerAccountID", AccountTableColumnsEnum::ManagerAccountID)
			.value("LeverageProfileID", AccountTableColumnsEnum::LeverageProfileID)
			.value("Equity", AccountTableColumnsEnum::Equity)
			.value("DayPL", AccountTableColumnsEnum::DayPL)
			.value("UsableMargin", AccountTableColumnsEnum::UsableMargin)
			.value("GrossPL", AccountTableColumnsEnum::GrossPL)
			.export_values()
			;
	}
}