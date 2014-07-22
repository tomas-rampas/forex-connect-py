#include "stdafx.h"
#include <Enums\TradesColumnsEnum.h>


void export_TradesColumnsEnum()
{
	using namespace boost::python;

	object obj_TradeColumnsEnum =
		class_<TradeColumnsEnum> ("TradeColumnsEnum", "Trade columns enumeration", init<>());

	{
		scope in_TradeColumnsEnum(obj_TradeColumnsEnum);
		enum_<TradeColumnsEnum::Columns>
			("Columns")
			.value("TradeID", TradeColumnsEnum::TradeID)
			.value("AccountID", TradeColumnsEnum::AccountID)
			.value("AccountName", TradeColumnsEnum::AccountName)
			.value("AccountKind", TradeColumnsEnum::AccountKind)
			.value("OfferID", TradeColumnsEnum::OfferID)
			.value("Amount", TradeColumnsEnum::Amount)
			.value("BuySell", TradeColumnsEnum::BuySell)
			.value("OpenRate", TradeColumnsEnum::OpenRate)
			.value("OpenTime", TradeColumnsEnum::OpenTime)
			.value("OpenQuoteID", TradeColumnsEnum::OpenQuoteID)
			.value("OpenOrderID", TradeColumnsEnum::OpenOrderID)
			.value("OpenOrderReqID", TradeColumnsEnum::OpenOrderReqID)
			.value("OpenOrderRequestTXT", TradeColumnsEnum::OpenOrderRequestTXT)
			.value("Commission", TradeColumnsEnum::Commission)
			.value("RolloverInterest", TradeColumnsEnum::RolloverInterest)
			.value("TradeIDOrigin", TradeColumnsEnum::TradeIDOrigin)
			.value("UsedMargin", TradeColumnsEnum::UsedMargin)
			.value("ValueDate", TradeColumnsEnum::ValueDate)
			.value("Parties", TradeColumnsEnum::Parties)
			.export_values()
			;
	}

	object obj_TradeTableColumnsEnum =
		class_<TradeTableColumnsEnum>("TradeTableColumnsEnum", "TradeTableColumnsEnum", init<>());

	{
		scope in_TradeTableColumnsEnum(obj_TradeTableColumnsEnum);
		enum_<TradeTableColumnsEnum::Columns>
			("Columns")
			.value("TradeID", TradeTableColumnsEnum::TradeID)
			.value("AccountID", TradeTableColumnsEnum::AccountID)
			.value("AccountName", TradeTableColumnsEnum::AccountName)
			.value("AccountKind", TradeTableColumnsEnum::AccountKind)
			.value("OfferID", TradeTableColumnsEnum::OfferID)
			.value("Amount", TradeTableColumnsEnum::Amount)
			.value("BuySell", TradeTableColumnsEnum::BuySell)
			.value("OpenRate", TradeTableColumnsEnum::OpenRate)
			.value("OpenTime", TradeTableColumnsEnum::OpenTime)
			.value("OpenQuoteID", TradeTableColumnsEnum::OpenQuoteID)
			.value("OpenOrderID", TradeTableColumnsEnum::OpenOrderID)
			.value("OpenOrderReqID", TradeTableColumnsEnum::OpenOrderReqID)
			.value("OpenOrderRequestTXT", TradeTableColumnsEnum::OpenOrderRequestTXT)
			.value("Commission", TradeTableColumnsEnum::Commission)
			.value("RolloverInterest", TradeTableColumnsEnum::RolloverInterest)
			.value("TradeIDOrigin", TradeTableColumnsEnum::TradeIDOrigin)
			.value("UsedMargin", TradeTableColumnsEnum::UsedMargin)
			.value("ValueDate", TradeTableColumnsEnum::ValueDate)
			.value("Parties", TradeTableColumnsEnum::Parties)
			.value("PL", TradeTableColumnsEnum::PL)
			.value("GrossPL", TradeTableColumnsEnum::GrossPL)
			.value("Close", TradeTableColumnsEnum::Close)
			.value("Stop", TradeTableColumnsEnum::Stop)
			.value("Limit", TradeTableColumnsEnum::Limit)
			.export_values()
			;
	}
};