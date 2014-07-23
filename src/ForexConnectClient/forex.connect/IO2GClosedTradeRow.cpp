#include "stdafx.h"
#include <Rows\IO2GClosedTradeRow.h>

using namespace boost::python;

class IO2GClosedTradeRowWrap : public IO2GClosedTradeRow, public wrapper < IO2GClosedTradeRow >
{
public:
	const char* getTradeID(){ return this->get_override("getTradeID()")();}
	const char* getAccountID(){ return this->get_override("getAccountID")();}
	const char* getAccountName(){ return this->get_override("getAccountName")();}
	const char* getAccountKind(){ return this->get_override("getAccountKind")();}
	const char* getOfferID(){ return this->get_override("getOfferID")();}
	int getAmount(){ return this->get_override("getAmount()")();}
	const char* getBuySell(){ return this->get_override("getBuySell")();}
	double getGrossPL(){ return this->get_override("getGrossPL")();}
	double getCommission(){ return this->get_override("getCommission")();}
	double getRolloverInterest(){ return this->get_override("getRolloverInterest")();}
	double getOpenRate(){ return this->get_override("getOpenRate")();}
	const char* getOpenQuoteID(){ return this->get_override("getOpenQuoteID")();}
	DATE getOpenTime(){ return this->get_override("getOpenTime")();}
	const char* getOpenOrderID(){ return this->get_override("getOpenOrderID")();}
	const char* getOpenOrderReqID(){ return this->get_override("getOpenOrderReqID")();}
	const char* getOpenOrderRequestTXT(){ return this->get_override("getOpenOrderRequestTXT")();}
	const char* getOpenOrderParties(){ return this->get_override("getOpenOrderParties")();}
	double getCloseRate(){ return this->get_override("getCloseRate")();}
	const char* getCloseQuoteID(){ return this->get_override("getCloseQuoteID")();}
	DATE getCloseTime(){ return this->get_override("getCloseTime")();}
	const char* getCloseOrderID(){ return this->get_override("getCloseOrderID")();}
	const char* getCloseOrderReqID(){ return this->get_override("getCloseOrderReqID")();}
	const char* getCloseOrderRequestTXT(){ return this->get_override("getCloseOrderRequestTXT")();}
	const char* getCloseOrderParties(){ return this->get_override("getCloseOrderParties")();}
	const char* getTradeIDOrigin(){ return this->get_override("getTradeIDOrigin")();}
	const char* getTradeIDRemain(){ return this->get_override("getTradeIDRemain")();}
	const char* getValueDate(){ return this->get_override("getValueDate")();}
};

class IO2GClosedTradeTableRowWrap : public IO2GClosedTradeTableRow, public wrapper < IO2GClosedTradeTableRow >
{
	double getPL() {return this->get_override("getPL")();}
};

void export_IO2GClosedTradeRow()
{
	class_<IO2GClosedTradeRowWrap, bases<IO2GRow>, boost::noncopyable>("IO2GClosedTradeRow", no_init)
		.def("getTradeID", pure_virtual(&IO2GClosedTradeRow::getTradeID))
		.def("getAccountID", pure_virtual(&IO2GClosedTradeRow::getAccountID))
		.def("getAccountName", pure_virtual(&IO2GClosedTradeRow::getAccountName))
		.def("getAccountKind", pure_virtual(&IO2GClosedTradeRow::getAccountKind))
		.def("getOfferID", pure_virtual(&IO2GClosedTradeRow::getOfferID))
		.def("getAmount", pure_virtual(&IO2GClosedTradeRow::getAmount))
		.def("getBuySell", pure_virtual(&IO2GClosedTradeRow::getBuySell))
		.def("getGrossPL", pure_virtual(&IO2GClosedTradeRow::getGrossPL))
		.def("getCommission", pure_virtual(&IO2GClosedTradeRow::getCommission))
		.def("getRolloverInterest", pure_virtual(&IO2GClosedTradeRow::getRolloverInterest))
		.def("getOpenRate", pure_virtual(&IO2GClosedTradeRow::getOpenRate))
		.def("getOpenQuoteID", pure_virtual(&IO2GClosedTradeRow::getOpenQuoteID))
		.def("getOpenTime", pure_virtual(&IO2GClosedTradeRow::getOpenTime))
		.def("getOpenOrderID", pure_virtual(&IO2GClosedTradeRow::getOpenOrderID))
		.def("getOpenOrderReqID", pure_virtual(&IO2GClosedTradeRow::getOpenOrderReqID))
		.def("getOpenOrderRequestTXT", pure_virtual(&IO2GClosedTradeRow::getOpenOrderRequestTXT))
		.def("getOpenOrderParties", pure_virtual(&IO2GClosedTradeRow::getOpenOrderParties))
		.def("getCloseRate", pure_virtual(&IO2GClosedTradeRow::getCloseRate))
		.def("getCloseQuoteID", pure_virtual(&IO2GClosedTradeRow::getCloseQuoteID))
		.def("getCloseTime", pure_virtual(&IO2GClosedTradeRow::getCloseTime))
		.def("getCloseOrderID", pure_virtual(&IO2GClosedTradeRow::getCloseOrderID))
		.def("getCloseOrderReqID", pure_virtual(&IO2GClosedTradeRow::getCloseOrderReqID))
		.def("getCloseOrderRequestTXT", pure_virtual(&IO2GClosedTradeRow::getCloseOrderRequestTXT))
		.def("getCloseOrderParties", pure_virtual(&IO2GClosedTradeRow::getCloseOrderParties))
		.def("getTradeIDOrigin", pure_virtual(&IO2GClosedTradeRow::getTradeIDOrigin))
		.def("getTradeIDRemain", pure_virtual(&IO2GClosedTradeRow::getTradeIDRemain))
		.def("getValueDate", pure_virtual(&IO2GClosedTradeRow::getValueDate))
		;

	class_<IO2GClosedTradeTableRowWrap, bases<IO2GClosedTradeRow>, boost::noncopyable>("IO2GClosedTradeTableRow", no_init)
		.def("getPL", pure_virtual(&IO2GClosedTradeTableRow::getPL))
		; 
};