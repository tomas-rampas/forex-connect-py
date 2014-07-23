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

void export_IO2GTablesUpdatesReader()
{
	class_<IO2GTablesUpdatesReaderWrap, boost::noncopyable>("IO2GTablesUpdatesReader", no_init)
		;
}
