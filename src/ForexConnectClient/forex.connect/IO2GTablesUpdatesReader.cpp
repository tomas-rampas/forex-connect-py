#include "stdafx.h"
#include <Readers\IO2GTablesUpdatesReader.h>

using namespace boost::python;

class IO2GTablesUpdatesReaderWrap : public IO2GTablesUpdatesReader, public wrapper < IO2GTablesUpdatesReader >
{
public:
	DATE getServerTime(){ return this->get_override("getServerTime")(); }
	int size(){ return this->get_override("size")(); }
	O2GTableUpdateType getUpdateType(int){ return this->get_override("getUpdateType")(); }
	O2GTable getUpdateTable(int){ return this->get_override("getUpdateTable")(); }
	IO2GOfferRow* getOfferRow(int){ return this->get_override("getOfferRow")(); }
	IO2GAccountRow* getAccountRow(int){ return this->get_override("getAccountRow")(); }
	IO2GOrderRow* getOrderRow(int){ return this->get_override("getOrderRow")(); }
	IO2GTradeRow* getTradeRow(int){ return this->get_override("getTradeRow")(); }
	IO2GClosedTradeRow* getClosedTradeRow(int){ return this->get_override("getClosedTradeRow")(); }
	IO2GMessageRow* getMessageRow(int){ return this->get_override("getMessageRow")(); }
};

//TODO missing Rows definitons
void export_IO2GTablesUpdatesReader()
{
	class_<IO2GTablesUpdatesReaderWrap, boost::noncopyable>("IO2GTablesUpdatesReader", no_init)
		.def("getServerTime", pure_virtual(&IO2GTablesUpdatesReader::getServerTime))
		.def("size", pure_virtual(&IO2GTablesUpdatesReader::size))
		.def("getUpdateType", pure_virtual(&IO2GTablesUpdatesReader::getUpdateType))
		.def("getUpdateTable", pure_virtual(&IO2GTablesUpdatesReader::getUpdateTable))
		.def("getOfferRow", pure_virtual(&IO2GTablesUpdatesReader::getOfferRow), return_value_policy<reference_existing_object>())
		.def("getAccountRow", pure_virtual(&IO2GTablesUpdatesReader::getAccountRow), return_value_policy<reference_existing_object>())
		.def("getOrderRow", pure_virtual(&IO2GTablesUpdatesReader::getOrderRow), return_value_policy<reference_existing_object>())
		.def("getTradeRow", pure_virtual(&IO2GTablesUpdatesReader::getTradeRow), return_value_policy<reference_existing_object>())
		.def("getClosedTradeRow", pure_virtual(&IO2GTablesUpdatesReader::getClosedTradeRow), return_value_policy<reference_existing_object>())
		.def("getMessageRow", pure_virtual(&IO2GTablesUpdatesReader::getMessageRow), return_value_policy<reference_existing_object>())
		;
}
