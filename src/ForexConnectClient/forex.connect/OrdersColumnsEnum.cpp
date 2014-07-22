#include "stdafx.h"
#include <Enums\OrdersColumnsEnum.h>

void export_OrdersColumnsEnum()
{
	using namespace boost::python;
	object obj_OrderColumnsEnum
		= class_<OrderColumnsEnum>("OrderColumnsEnum", "Order columns enumeration", init<>());
	{
		scope in_AccountColumnsEnum(obj_OrderColumnsEnum);
		enum_<OrderColumnsEnum::Columns>("Columns")
			.value("OrderID", OrderColumnsEnum::OrderID)
			.value("RequestID", OrderColumnsEnum::RequestID)
			.value("Rate", OrderColumnsEnum::Rate)
			.value("ExecutionRate", OrderColumnsEnum::ExecutionRate)
			.value("RateMin", OrderColumnsEnum::RateMin)
			.value("RateMax", OrderColumnsEnum::RateMax)
			.value("TradeID", OrderColumnsEnum::TradeID)
			.value("AccountID", OrderColumnsEnum::AccountID)
			.value("AccountName", OrderColumnsEnum::AccountName)
			.value("OfferID", OrderColumnsEnum::OfferID)
			.value("NetQuantity", OrderColumnsEnum::NetQuantity)
			.value("BuySell", OrderColumnsEnum::BuySell)
			.value("Stage", OrderColumnsEnum::Stage)
			.value("Type", OrderColumnsEnum::Type)
			.value("Status", OrderColumnsEnum::Status)
			.value("StatusTime", OrderColumnsEnum::StatusTime)
			.value("Amount", OrderColumnsEnum::Amount)
			.value("Lifetime", OrderColumnsEnum::Lifetime)
			.value("AtMarket", OrderColumnsEnum::AtMarket)
			.value("TrailStep", OrderColumnsEnum::TrailStep)
			.value("TrailRate", OrderColumnsEnum::TrailRate)
			.value("TimeInForce", OrderColumnsEnum::TimeInForce)
			.value("AccountKind", OrderColumnsEnum::AccountKind)
			.value("RequestTXT", OrderColumnsEnum::RequestTXT)
			.value("ContingentOrderID", OrderColumnsEnum::ContingentOrderID)
			.value("ContingencyType", OrderColumnsEnum::ContingencyType)
			.value("PrimaryID", OrderColumnsEnum::PrimaryID)
			.value("OriginAmount", OrderColumnsEnum::OriginAmount)
			.value("FilledAmount", OrderColumnsEnum::FilledAmount)
			.value("WorkingIndicator", OrderColumnsEnum::WorkingIndicator)
			.value("PegType", OrderColumnsEnum::PegType)
			.value("PegOffset", OrderColumnsEnum::PegOffset)
			.value("ExpireDate", OrderColumnsEnum::ExpireDate)
			.value("ValueDate", OrderColumnsEnum::ValueDate)
			.value("Parties", OrderColumnsEnum::Parties)
			.export_values()
			;
	}

	object obj_OrderTableColumnsEnum
		= class_<OrderTableColumnsEnum>("OrderTableColumnsEnum", "Order table columns enumeration", init<>());
	{
		scope in_OrderTableColumnsEnum(obj_OrderTableColumnsEnum);
		enum_<OrderTableColumnsEnum::Columns>("Columns")
			.value("OrderID", OrderTableColumnsEnum::OrderID)
			.value("RequestID", OrderTableColumnsEnum::RequestID)
			.value("Rate", OrderTableColumnsEnum::Rate)
			.value("ExecutionRate", OrderTableColumnsEnum::ExecutionRate)
			.value("RateMin", OrderTableColumnsEnum::RateMin)
			.value("RateMax", OrderTableColumnsEnum::RateMax)
			.value("TradeID", OrderTableColumnsEnum::TradeID)
			.value("AccountID", OrderTableColumnsEnum::AccountID)
			.value("AccountName", OrderTableColumnsEnum::AccountName)
			.value("OfferID", OrderTableColumnsEnum::OfferID)
			.value("NetQuantity", OrderTableColumnsEnum::NetQuantity)
			.value("BuySell", OrderTableColumnsEnum::BuySell)
			.value("Stage", OrderTableColumnsEnum::Stage)
			.value("Type", OrderTableColumnsEnum::Type)
			.value("Status", OrderTableColumnsEnum::Status)
			.value("StatusTime", OrderTableColumnsEnum::StatusTime)
			.value("Amount", OrderTableColumnsEnum::Amount)
			.value("Lifetime", OrderTableColumnsEnum::Lifetime)
			.value("AtMarket", OrderTableColumnsEnum::AtMarket)
			.value("TrailStep", OrderTableColumnsEnum::TrailStep)
			.value("TrailRate", OrderTableColumnsEnum::TrailRate)
			.value("TimeInForce", OrderTableColumnsEnum::TimeInForce)
			.value("AccountKind", OrderTableColumnsEnum::AccountKind)
			.value("RequestTXT", OrderTableColumnsEnum::RequestTXT)
			.value("ContingentOrderID", OrderTableColumnsEnum::ContingentOrderID)
			.value("ContingencyType", OrderTableColumnsEnum::ContingencyType)
			.value("PrimaryID", OrderTableColumnsEnum::PrimaryID)
			.value("OriginAmount", OrderTableColumnsEnum::OriginAmount)
			.value("FilledAmount", OrderTableColumnsEnum::FilledAmount)
			.value("WorkingIndicator", OrderTableColumnsEnum::WorkingIndicator)
			.value("PegType", OrderTableColumnsEnum::PegType)
			.value("PegOffset", OrderTableColumnsEnum::PegOffset)
			.value("ExpireDate", OrderTableColumnsEnum::ExpireDate)
			.value("ValueDate", OrderTableColumnsEnum::ValueDate)
			.value("Parties", OrderTableColumnsEnum::Parties)
			.value("Stop", OrderTableColumnsEnum::Stop)
			.value("Limit", OrderTableColumnsEnum::Limit)
			.value("StopTrailStep", OrderTableColumnsEnum::StopTrailStep)
			.value("StopTrailRate", OrderTableColumnsEnum::StopTrailRate)
			.export_values()
			;
	}
}