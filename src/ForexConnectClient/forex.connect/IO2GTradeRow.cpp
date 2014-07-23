#include "stdafx.h"
#include <Rows\IO2GTradeRow.h>
using namespace boost::python;

class IO2GTradeRowWrap : public IO2GTradeRow, public wrapper < IO2GTradeRow >
{
public:
	const char* getTradeID(){ return this->get_override("getTradeID")();}
	const char* getAccountID(){ return this->get_override("getAccountID")();}
	const char* getAccountName(){ return this->get_override("getAccountName")();}
	const char* getAccountKind(){ return this->get_override("getAccountKind")();}
	const char* getOfferID(){ return this->get_override("getOfferID")();}
	int getAmount(){ return this->get_override("getAmount")();}
	const char* getBuySell(){ return this->get_override("getBuySell")();}
	double getOpenRate(){ return this->get_override("getOpenRate")();}
	DATE getOpenTime(){ return this->get_override("getOpenTime")();}
	const char* getOpenQuoteID(){ return this->get_override("getOpenQuoteID")();}
	const char* getOpenOrderID(){ return this->get_override("getOpenOrderID")();}
	const char* getOpenOrderReqID(){ return this->get_override("getOpenOrderReqID")();}
	const char* getOpenOrderRequestTXT(){ return this->get_override("getOpenOrderRequestTXT")();}
	double getCommission(){ return this->get_override("getCommission")();}
	double getRolloverInterest(){ return this->get_override("getRolloverInterest")();}
	const char* getTradeIDOrigin(){ return this->get_override("getTradeIDOrigin")();}
	double getUsedMargin(){ return this->get_override("getUsedMargin")();}
	const char* getValueDate(){ return this->get_override("getValueDate")();}
	const char* getParties(){ return this->get_override("getParties")();}
};

class IO2GTradeTableRowWrap : public IO2GTradeTableRow, public wrapper < IO2GTradeTableRow >
{
public:
	double getPL(){ return this->get_override("getPL")();}
	double getGrossPL(){ return this->get_override("getGrossPL")();}
	double getClose(){ return this->get_override("getClose")();}
	double getStop(){ return this->get_override("getStop")();}
	double getLimit(){ return this->get_override("getLimit")();}
};

void export_IO2GTradeRow()
{
	class_<IO2GTradeRowWrap, bases<IO2GRow>, boost::noncopyable>("IO2GTradeRow", no_init)
		.def("getTradeID", pure_virtual(&IO2GTradeRow::getTradeID))
		.def("getAccountID", pure_virtual(&IO2GTradeRow::getAccountID))
		.def("getAccountName", pure_virtual(&IO2GTradeRow::getAccountName))
		.def("getAccountKind", pure_virtual(&IO2GTradeRow::getAccountKind))
		.def("getOfferID", pure_virtual(&IO2GTradeRow::getOfferID))
		.def("getAmount", pure_virtual(&IO2GTradeRow::getAmount))
		.def("getBuySell", pure_virtual(&IO2GTradeRow::getBuySell))
		.def("getOpenRate", pure_virtual(&IO2GTradeRow::getOpenRate))
		.def("getOpenTime", pure_virtual(&IO2GTradeRow::getOpenTime))
		.def("getOpenQuoteID", pure_virtual(&IO2GTradeRow::getOpenQuoteID))
		.def("getOpenOrderID", pure_virtual(&IO2GTradeRow::getOpenOrderID))
		.def("getOpenOrderReqID", pure_virtual(&IO2GTradeRow::getOpenOrderReqID))
		.def("getOpenOrderRequestTXT", pure_virtual(&IO2GTradeRow::getOpenOrderRequestTXT))
		.def("getCommission", pure_virtual(&IO2GTradeRow::getCommission))
		.def("getRolloverInterest", pure_virtual(&IO2GTradeRow::getRolloverInterest))
		.def("getTradeIDOrigin", pure_virtual(&IO2GTradeRow::getTradeIDOrigin))
		.def("getUsedMargin", pure_virtual(&IO2GTradeRow::getUsedMargin))
		.def("getValueDate", pure_virtual(&IO2GTradeRow::getValueDate))
		.def("getParties", pure_virtual(&IO2GTradeRow::getParties))
		;

	class_<IO2GTradeTableRowWrap, bases<IO2GTradeRow>, boost::noncopyable>("IO2GTradeTableRow", no_init)
		.def("getPL", pure_virtual(&IO2GTradeTableRow::getPL))
		.def("getGrossPL", pure_virtual(&IO2GTradeTableRow::getGrossPL))
		.def("getClose", pure_virtual(&IO2GTradeTableRow::getClose))
		.def("getStop", pure_virtual(&IO2GTradeTableRow::getStop))
		.def("getLimit", pure_virtual(&IO2GTradeTableRow::getLimit))
		;
};