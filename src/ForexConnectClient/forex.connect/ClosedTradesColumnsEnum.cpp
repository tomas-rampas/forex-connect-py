#include "stdafx.h"
#include <Enums\ClosedTradesColumnsEnum.h>

void export_ClosedTradesColumnsEnum()
{
	using namespace boost::python;

	object obj_ClosedTradeColumnsEnum
		= class_<ClosedTradeColumnsEnum>("ClosedTradeColumnsEnum", "Closed trade columns enumeration", init<>());
	{
		scope in_ClosedTradeColumnsEnum(obj_ClosedTradeColumnsEnum);
		enum_<ClosedTradeColumnsEnum::Columns>("Columns")
			.value("TradeID", ClosedTradeColumnsEnum::TradeID)
			.value("AccountID", ClosedTradeColumnsEnum::AccountID)
			.value("AccountName", ClosedTradeColumnsEnum::AccountName)
			.value("AccountKind", ClosedTradeColumnsEnum::AccountKind)
			.value("OfferID", ClosedTradeColumnsEnum::OfferID)
			.value("Amount", ClosedTradeColumnsEnum::Amount)
			.value("BuySell", ClosedTradeColumnsEnum::BuySell)
			.value("GrossPL", ClosedTradeColumnsEnum::GrossPL)
			.value("Commission", ClosedTradeColumnsEnum::Commission)
			.value("RolloverInterest", ClosedTradeColumnsEnum::RolloverInterest)
			.value("OpenRate", ClosedTradeColumnsEnum::OpenRate)
			.value("OpenQuoteID", ClosedTradeColumnsEnum::OpenQuoteID)
			.value("OpenTime", ClosedTradeColumnsEnum::OpenTime)
			.value("OpenOrderID", ClosedTradeColumnsEnum::OpenOrderID)
			.value("OpenOrderReqID", ClosedTradeColumnsEnum::OpenOrderReqID)
			.value("OpenOrderRequestTXT", ClosedTradeColumnsEnum::OpenOrderRequestTXT)
			.value("OpenOrderParties", ClosedTradeColumnsEnum::OpenOrderParties)
			.value("CloseRate", ClosedTradeColumnsEnum::CloseRate)
			.value("CloseQuoteID", ClosedTradeColumnsEnum::CloseQuoteID)
			.value("CloseTime", ClosedTradeColumnsEnum::CloseTime)
			.value("CloseOrderID", ClosedTradeColumnsEnum::CloseOrderID)
			.value("CloseOrderReqID", ClosedTradeColumnsEnum::CloseOrderReqID)
			.value("CloseOrderRequestTXT", ClosedTradeColumnsEnum::CloseOrderRequestTXT)
			.value("CloseOrderParties", ClosedTradeColumnsEnum::CloseOrderParties)
			.value("TradeIDOrigin", ClosedTradeColumnsEnum::TradeIDOrigin)
			.value("TradeIDRemain", ClosedTradeColumnsEnum::TradeIDRemain)
			.value("ValueDate", ClosedTradeColumnsEnum::ValueDate)
			.export_values()
			;
	}

	object obj_ClosedTradeTableColumnsEnum
		= class_<ClosedTradeTableColumnsEnum>("ClosedTradeTableColumnsEnum", "Closed trade table columns enumeration", init<>());
	{
		scope in_ClosedTradeTableColumnsEnum(obj_ClosedTradeTableColumnsEnum);
		enum_<ClosedTradeTableColumnsEnum::Columns>("Columns")
			.value("TradeID", ClosedTradeTableColumnsEnum::TradeID)
			.value("AccountID", ClosedTradeTableColumnsEnum::AccountID)
			.value("AccountName", ClosedTradeTableColumnsEnum::AccountName)
			.value("AccountKind", ClosedTradeTableColumnsEnum::AccountKind)
			.value("OfferID", ClosedTradeTableColumnsEnum::OfferID)
			.value("Amount", ClosedTradeTableColumnsEnum::Amount)
			.value("BuySell", ClosedTradeTableColumnsEnum::BuySell)
			.value("GrossPL", ClosedTradeTableColumnsEnum::GrossPL)
			.value("Commission", ClosedTradeTableColumnsEnum::Commission)
			.value("RolloverInterest", ClosedTradeTableColumnsEnum::RolloverInterest)
			.value("OpenRate", ClosedTradeTableColumnsEnum::OpenRate)
			.value("OpenQuoteID", ClosedTradeTableColumnsEnum::OpenQuoteID)
			.value("OpenTime", ClosedTradeTableColumnsEnum::OpenTime)
			.value("OpenOrderID", ClosedTradeTableColumnsEnum::OpenOrderID)
			.value("OpenOrderReqID", ClosedTradeTableColumnsEnum::OpenOrderReqID)
			.value("OpenOrderRequestTXT", ClosedTradeTableColumnsEnum::OpenOrderRequestTXT)
			.value("OpenOrderParties", ClosedTradeTableColumnsEnum::OpenOrderParties)
			.value("CloseRate", ClosedTradeTableColumnsEnum::CloseRate)
			.value("CloseQuoteID", ClosedTradeTableColumnsEnum::CloseQuoteID)
			.value("CloseTime", ClosedTradeTableColumnsEnum::CloseTime)
			.value("CloseOrderID", ClosedTradeTableColumnsEnum::CloseOrderID)
			.value("CloseOrderReqID", ClosedTradeTableColumnsEnum::CloseOrderReqID)
			.value("CloseOrderRequestTXT", ClosedTradeTableColumnsEnum::CloseOrderRequestTXT)
			.value("CloseOrderParties", ClosedTradeTableColumnsEnum::CloseOrderParties)
			.value("TradeIDOrigin", ClosedTradeTableColumnsEnum::TradeIDOrigin)
			.value("TradeIDRemain", ClosedTradeTableColumnsEnum::TradeIDRemain)
			.value("ValueDate", ClosedTradeTableColumnsEnum::ValueDate)
			.value("PL", ClosedTradeTableColumnsEnum::PL)
			.export_values()
			;
	}
}
