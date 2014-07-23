#include "stdafx.h"
#include <Rows\IO2GSummaryRow.h>

using namespace boost::python;

//IO2GSummaryRow
class IO2GSummaryRowWrap : public IO2GSummaryRow, public wrapper < IO2GSummaryRow >
{
public:
};

//IO2GSummaryTableRow
class IO2GSummaryTableRowWrap : public IO2GSummaryTableRow, public wrapper < IO2GSummaryTableRow >
{
public:
	const char* getOfferID(){ return this->get_override("getOfferID")();}
	int getDefaultSortOrder(){ return this->get_override("getDefaultSortOrder")();}
	const char* getInstrument(){ return this->get_override("getInstrument")();}
	double getSellNetPL(){ return this->get_override("getSellNetPL")();}
	double getSellAmount(){ return this->get_override("getSellAmount")();}
	double getSellAvgOpen(){ return this->get_override("getSellAvgOpen")();}
	double getBuyClose(){ return this->get_override("getBuyClose")();}
	double getSellClose(){ return this->get_override("getSellClose")();}
	double getBuyAvgOpen(){ return this->get_override("getBuyAvgOpen")();}
	double getBuyAmount(){ return this->get_override("getBuyAmount")();}
	double getBuyNetPL(){ return this->get_override("getBuyNetPL")();}
	double getAmount(){ return this->get_override("getAmount")();}
	double getGrossPL(){ return this->get_override("getGrossPL")();}
	double getNetPL(){ return this->get_override("getNetPL")();}
};

void export_IO2GSummaryRow()
{
	class_<IO2GSummaryRowWrap, bases<IO2GRow>, boost::noncopyable>("IO2GSummaryRow", no_init)
		;

	class_<IO2GSummaryTableRowWrap, bases<IO2GSummaryRow>, boost::noncopyable>("IO2GSummaryTableRow", no_init)
		.def("getOfferID", pure_virtual(&IO2GSummaryTableRow::getOfferID))
		.def("getDefaultSortOrder", pure_virtual(&IO2GSummaryTableRow::getDefaultSortOrder))
		.def("getInstrument", pure_virtual(&IO2GSummaryTableRow::getInstrument))
		.def("getSellNetPL", pure_virtual(&IO2GSummaryTableRow::getSellNetPL))
		.def("getSellAmount", pure_virtual(&IO2GSummaryTableRow::getSellAmount))
		.def("getSellAvgOpen", pure_virtual(&IO2GSummaryTableRow::getSellAvgOpen))
		.def("getBuyClose", pure_virtual(&IO2GSummaryTableRow::getBuyClose))
		.def("getSellClose", pure_virtual(&IO2GSummaryTableRow::getSellClose))
		.def("getBuyAvgOpen", pure_virtual(&IO2GSummaryTableRow::getBuyAvgOpen))
		.def("getBuyAmount", pure_virtual(&IO2GSummaryTableRow::getBuyAmount))
		.def("getBuyNetPL", pure_virtual(&IO2GSummaryTableRow::getBuyNetPL))
		.def("getAmount", pure_virtual(&IO2GSummaryTableRow::getAmount))
		.def("getGrossPL", pure_virtual(&IO2GSummaryTableRow::getGrossPL))
		.def("getNetPL", pure_virtual(&IO2GSummaryTableRow::getNetPL))
		;
};