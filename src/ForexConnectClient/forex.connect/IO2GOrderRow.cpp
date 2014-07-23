#include "stdafx.h"
#include <Rows\IO2GOrderRow.h>
using namespace boost::python;

class IO2GOrderRowWrap : public IO2GOrderRow, public wrapper < IO2GOrderRow >
{
public:
	const char* getOrderID(){ return this->get_override("getOrderID")();}
	const char* getRequestID(){ return this->get_override("getRequestID")();}
	double getRate(){ return this->get_override("getRate")();}
	double getExecutionRate(){ return this->get_override("getExecutionRate")();}
	double getRateMin(){ return this->get_override("getRateMin")();}
	double getRateMax(){ return this->get_override("getRateMax")();}
	const char* getTradeID(){ return this->get_override("getTradeID")();}
	const char* getAccountID(){ return this->get_override("getAccountID")();}
	const char* getAccountName(){ return this->get_override("getAccountName")();}
	const char* getOfferID(){ return this->get_override("getOfferID")();}
	bool getNetQuantity(){ return this->get_override("getNetQuantity")();}
	const char* getBuySell(){ return this->get_override("getBuySell")();}
	const char* getStage(){ return this->get_override("getStage")();}
	const char* getType(){ return this->get_override("getType")();}
	const char* getStatus(){ return this->get_override("getStatus")();}
	DATE getStatusTime(){ return this->get_override("getStatusTime")();}
	int getAmount(){ return this->get_override("getAmount")();}
	double getLifetime(){ return this->get_override("getLifetime")();}
	double getAtMarket(){ return this->get_override("getAtMarket")();}
	int getTrailStep(){ return this->get_override("getTrailStep")();}
	double getTrailRate(){ return this->get_override("getTrailRate")();}
	const char* getTimeInForce(){ return this->get_override("getTimeInForce")();}
	const char* getAccountKind(){ return this->get_override("getAccountKind")();}
	const char* getRequestTXT(){ return this->get_override("getRequestTXT")();}
	const char* getContingentOrderID(){ return this->get_override("getContingentOrderID")();}
	int getContingencyType(){ return this->get_override("getContingencyType")();}
	const char* getPrimaryID(){ return this->get_override("getPrimaryID")();}
	int getOriginAmount(){ return this->get_override("getOriginAmount")();}
	int getFilledAmount(){ return this->get_override("getFilledAmount")();}
	bool getWorkingIndicator(){ return this->get_override("getWorkingIndicator")();}
	const char* getPegType(){ return this->get_override("getPegType")();}
	double getPegOffset(){ return this->get_override("getPegOffset")();}
	DATE getExpireDate(){ return this->get_override("getExpireDate")();}
	const char* getValueDate(){ return this->get_override("getValueDate")();}
	const char* getParties(){ return this->get_override("getParties")();}
};

class IO2GOrderTableRowWrap : public IO2GOrderTableRow, public wrapper < IO2GOrderTableRow > 
{
public:
	double getStop(){ return this->get_override("getStop")();}
	double getLimit(){ return this->get_override("getLimit")();}
	int getStopTrailStep(){ return this->get_override("getStopTrailStep")();}
	double getStopTrailRate(){ return this->get_override("getStopTrailRate")();}
};

void export_IO2GOrderRow()
{
	class_<IO2GOrderRowWrap, bases<IO2GRow>, boost::noncopyable>("IO2GOrderRow", no_init)
		.def("getOrderID", pure_virtual(&IO2GOrderRow::getOrderID))
		.def("getRequestID", pure_virtual(&IO2GOrderRow::getRequestID))
		.def("getRate", pure_virtual(&IO2GOrderRow::getRate))
		.def("getExecutionRate", pure_virtual(&IO2GOrderRow::getExecutionRate))
		.def("getRateMin", pure_virtual(&IO2GOrderRow::getRateMin))
		.def("getRateMax", pure_virtual(&IO2GOrderRow::getRateMax))
		.def("getTradeID", pure_virtual(&IO2GOrderRow::getTradeID))
		.def("getAccountID", pure_virtual(&IO2GOrderRow::getAccountID))
		.def("getAccountName", pure_virtual(&IO2GOrderRow::getAccountName))
		.def("getOfferID", pure_virtual(&IO2GOrderRow::getOfferID))
		.def("getNetQuantity", pure_virtual(&IO2GOrderRow::getNetQuantity))
		.def("getBuySell", pure_virtual(&IO2GOrderRow::getBuySell))
		.def("getStage", pure_virtual(&IO2GOrderRow::getStage))
		.def("getType", pure_virtual(&IO2GOrderRow::getType))
		.def("getStatus", pure_virtual(&IO2GOrderRow::getStatus))
		.def("getStatusTime", pure_virtual(&IO2GOrderRow::getStatusTime))
		.def("getAmount", pure_virtual(&IO2GOrderRow::getAmount))
		.def("getLifetime", pure_virtual(&IO2GOrderRow::getLifetime))
		.def("getAtMarket", pure_virtual(&IO2GOrderRow::getAtMarket))
		.def("getTrailStep", pure_virtual(&IO2GOrderRow::getTrailStep))
		.def("getTrailRate", pure_virtual(&IO2GOrderRow::getTrailRate))
		.def("getTimeInForce", pure_virtual(&IO2GOrderRow::getTimeInForce))
		.def("getAccountKind", pure_virtual(&IO2GOrderRow::getAccountKind))
		.def("getRequestTXT", pure_virtual(&IO2GOrderRow::getRequestTXT))
		.def("getContingentOrderID", pure_virtual(&IO2GOrderRow::getContingentOrderID))
		.def("getContingencyType", pure_virtual(&IO2GOrderRow::getContingencyType))
		.def("getPrimaryID", pure_virtual(&IO2GOrderRow::getPrimaryID))
		.def("getOriginAmount", pure_virtual(&IO2GOrderRow::getOriginAmount))
		.def("getFilledAmount", pure_virtual(&IO2GOrderRow::getFilledAmount))
		.def("getWorkingIndicator", pure_virtual(&IO2GOrderRow::getWorkingIndicator))
		.def("getPegType", pure_virtual(&IO2GOrderRow::getPegType))
		.def("getPegOffset", pure_virtual(&IO2GOrderRow::getPegOffset))
		.def("getExpireDate", pure_virtual(&IO2GOrderRow::getExpireDate))
		.def("getValueDate", pure_virtual(&IO2GOrderRow::getValueDate))
		.def("getParties", pure_virtual(&IO2GOrderRow::getParties))
		;

	class_<IO2GOrderTableRowWrap, bases<IO2GOrderRow>, boost::noncopyable>("IO2GOrderTableRow", no_init)
		.def("getStop", pure_virtual(&IO2GOrderTableRow::getStop))
		.def("getLimit", pure_virtual(&IO2GOrderTableRow::getLimit))
		.def("getStopTrailStep", pure_virtual(&IO2GOrderTableRow::getStopTrailStep))
		.def("getStopTrailRate", pure_virtual(&IO2GOrderTableRow::getStopTrailRate))
		;
}; 