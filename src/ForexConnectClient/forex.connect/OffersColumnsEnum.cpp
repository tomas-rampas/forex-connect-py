#include "stdafx.h"
#include <enums\OffersColumnsEnum.h>

void export_OffersColumnsEnum()
{
	using namespace boost::python;

	object obj_OfferColumnsEnum
		= class_<OfferColumnsEnum>("OfferColumnsEnum", "Offer columns enumeration", init<>());
	{
		scope obj_OfferColumnsEnum;
		enum_<OfferColumnsEnum::Columns>("OfferColumnsEnum")
			.value("OfferID", OfferColumnsEnum::OfferID)
			.value("Instrument", OfferColumnsEnum::Instrument)
			.value("QuoteID", OfferColumnsEnum::QuoteID)
			.value("Bid", OfferColumnsEnum::Bid)
			.value("Ask", OfferColumnsEnum::Ask)
			.value("Low", OfferColumnsEnum::Low)
			.value("High", OfferColumnsEnum::High)
			.value("Volume", OfferColumnsEnum::Volume)
			.value("Time", OfferColumnsEnum::Time)
			.value("BidTradable", OfferColumnsEnum::BidTradable)
			.value("AskTradable", OfferColumnsEnum::AskTradable)
			.value("SellInterest", OfferColumnsEnum::SellInterest)
			.value("BuyInterest", OfferColumnsEnum::BuyInterest)
			.value("ContractCurrency", OfferColumnsEnum::ContractCurrency)
			.value("Digits", OfferColumnsEnum::Digits)
			.value("PointSize", OfferColumnsEnum::PointSize)
			.value("SubscriptionStatus", OfferColumnsEnum::SubscriptionStatus)
			.value("InstrumentType", OfferColumnsEnum::InstrumentType)
			.value("ContractMultiplier", OfferColumnsEnum::ContractMultiplier)
			.value("TradingStatus", OfferColumnsEnum::TradingStatus)
			.value("ValueDate", OfferColumnsEnum::ValueDate)
			.export_values()
			;
	}

	object obj_OfferTableColumnsEnum
		= class_<OfferTableColumnsEnum>("OfferTableColumnsEnum", "Offer table columns enumeration", init<>());
	{
		scope obj_OfferTableColumnsEnum;
		enum_<OfferTableColumnsEnum::Columns>("OfferTableColumnsEnum")
			.value("OfferID", OfferTableColumnsEnum::OfferID)
			.value("Instrument", OfferTableColumnsEnum::Instrument)
			.value("QuoteID", OfferTableColumnsEnum::QuoteID)
			.value("Bid", OfferTableColumnsEnum::Bid)
			.value("Ask", OfferTableColumnsEnum::Ask)
			.value("Low", OfferTableColumnsEnum::Low)
			.value("High", OfferTableColumnsEnum::High)
			.value("Volume", OfferTableColumnsEnum::Volume)
			.value("Time", OfferTableColumnsEnum::Time)
			.value("BidTradable", OfferTableColumnsEnum::BidTradable)
			.value("AskTradable", OfferTableColumnsEnum::AskTradable)
			.value("SellInterest", OfferTableColumnsEnum::SellInterest)
			.value("BuyInterest", OfferTableColumnsEnum::BuyInterest)
			.value("ContractCurrency", OfferTableColumnsEnum::ContractCurrency)
			.value("Digits", OfferTableColumnsEnum::Digits)
			.value("PointSize", OfferTableColumnsEnum::PointSize)
			.value("SubscriptionStatus", OfferTableColumnsEnum::SubscriptionStatus)
			.value("InstrumentType", OfferTableColumnsEnum::InstrumentType)
			.value("ContractMultiplier", OfferTableColumnsEnum::ContractMultiplier)
			.value("TradingStatus", OfferTableColumnsEnum::TradingStatus)
			.value("ValueDate", OfferTableColumnsEnum::ValueDate)
			.value("PipCost", OfferTableColumnsEnum::PipCost)
			.export_values()
			;
	}
}