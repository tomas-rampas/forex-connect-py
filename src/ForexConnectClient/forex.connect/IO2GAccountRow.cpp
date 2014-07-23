#include "stdafx.h"
#include <Rows\IO2GAccountRow.h>

using namespace boost::python;

class IO2GAccountRowWrap : public IO2GAccountRow, public wrapper < IO2GAccountRow >
{
public:
	const char* getAccountID(){ return this->get_override("getAccountID")();}
	const char* getAccountName(){ return this->get_override("getAccountName")();}
	const char* getAccountKind(){ return this->get_override("getAccountKind")();}
	double getBalance(){ return this->get_override("getBalance")();}
	double getNonTradeEquity(){ return this->get_override("getNonTradeEquity")();}
	double getM2MEquity(){ return this->get_override("getM2MEquity")();}
	double getUsedMargin(){ return this->get_override("getUsedMargin")();}
	double getUsedMargin3(){ return this->get_override("getUsedMargin3")();}
	const char* getMarginCallFlag(){ return this->get_override("getMarginCallFlag")();}
	DATE getLastMarginCallDate(){ return this->get_override("getLastMarginCallDate")();}
	const char* getMaintenanceType(){ return this->get_override("getMaintenanceType")();}
	int getAmountLimit(){ return this->get_override("getAmountLimit")();}
	int getBaseUnitSize(){ return this->get_override("getBaseUnitSize")();}
	bool getMaintenanceFlag(){ return this->get_override("getMaintenanceFlag")();}
	const char* getManagerAccountID(){ return this->get_override("getManagerAccountID")();}
	const char* getLeverageProfileID(){ return this->get_override("getLeverageProfileID")();}
};

class IO2GAccountTableRowWrap : public IO2GAccountTableRow, public wrapper < IO2GAccountTableRow >
{
public:
	double getEquity(){ return this->get_override("getEquity")();}
	double getDayPL(){ return this->get_override("getDayPL")();}
	double getUsableMargin(){ return this->get_override("getUsableMargin")();}
	double getGrossPL(){ return this->get_override("getGrossPL")();}
};

void export_IO2GAccountRow()
{
	class_<IO2GAccountRowWrap, bases<IO2GRow>, boost::noncopyable>("IO2GAccountRow", no_init)
		.def("getAccountID", pure_virtual(&IO2GAccountRow::getAccountID))
		.def("getAccountName", pure_virtual(&IO2GAccountRow::getAccountName))
		.def("getAccountKind", pure_virtual(&IO2GAccountRow::getAccountKind))
		.def("getBalance", pure_virtual(&IO2GAccountRow::getBalance))
		.def("getNonTradeEquity", pure_virtual(&IO2GAccountRow::getNonTradeEquity))
		.def("getM2MEquity", pure_virtual(&IO2GAccountRow::getM2MEquity))
		.def("getUsedMargin", pure_virtual(&IO2GAccountRow::getUsedMargin))
		.def("getUsedMargin3", pure_virtual(&IO2GAccountRow::getUsedMargin3))
		.def("getMarginCallFlag", pure_virtual(&IO2GAccountRow::getMarginCallFlag))
		.def("getLastMarginCallDate", pure_virtual(&IO2GAccountRow::getLastMarginCallDate))
		.def("getMaintenanceType", pure_virtual(&IO2GAccountRow::getMaintenanceType))
		.def("getAmountLimit", pure_virtual(&IO2GAccountRow::getAmountLimit))
		.def("getBaseUnitSize", pure_virtual(&IO2GAccountRow::getBaseUnitSize))
		.def("getMaintenanceFlag", pure_virtual(&IO2GAccountRow::getMaintenanceFlag))
		.def("getManagerAccountID", pure_virtual(&IO2GAccountRow::getManagerAccountID))
		.def("getLeverageProfileID", pure_virtual(&IO2GAccountRow::getLeverageProfileID))
		;

	class_<IO2GAccountTableRowWrap, bases<IO2GAccountRow>, boost::noncopyable>("IO2GAccountTableRow", no_init)
		.def("getEquity", pure_virtual(&IO2GAccountTableRow::getEquity))
		.def("getDayPL", pure_virtual(&IO2GAccountTableRow::getDayPL))
		.def("getUsableMargin", pure_virtual(&IO2GAccountTableRow::getUsableMargin))
		.def("getGrossPL", pure_virtual(&IO2GAccountTableRow::getGrossPL))
		;
}