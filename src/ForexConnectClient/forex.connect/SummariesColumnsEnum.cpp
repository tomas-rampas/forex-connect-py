#include "stdafx.h"
#include <enums\SummariesColumnsEnum.h>

void export_SummariesColumnsEnum()
{
	using namespace boost::python;

	object obj_SummariesTableColumnsEnum
		= class_<SummariesTableColumnsEnum>("SummariesTableColumnsEnum", "Summaries table columns enumeration", init<>());
	{
		scope in_SummariesTableColumnsEnum(obj_SummariesTableColumnsEnum);
		enum_<SummariesTableColumnsEnum::Columns>("Columns")
			.value("OfferID", SummariesTableColumnsEnum::OfferID)
			.value("DefaultSortOrder", SummariesTableColumnsEnum::DefaultSortOrder)
			.value("Instrument", SummariesTableColumnsEnum::Instrument)
			.value("SellNetPL", SummariesTableColumnsEnum::SellNetPL)
			.value("SellAmount", SummariesTableColumnsEnum::SellAmount)
			.value("SellAvgOpen", SummariesTableColumnsEnum::SellAvgOpen)
			.value("BuyClose", SummariesTableColumnsEnum::BuyClose)
			.value("SellClose", SummariesTableColumnsEnum::SellClose)
			.value("BuyAvgOpen", SummariesTableColumnsEnum::BuyAvgOpen)
			.value("BuyAmount", SummariesTableColumnsEnum::BuyAmount)
			.value("BuyNetPL", SummariesTableColumnsEnum::BuyNetPL)
			.value("Amount", SummariesTableColumnsEnum::Amount)
			.value("GrossPL", SummariesTableColumnsEnum::GrossPL)
			.value("NetPL", SummariesTableColumnsEnum::NetPL)
			.export_values()
			;
	}
}