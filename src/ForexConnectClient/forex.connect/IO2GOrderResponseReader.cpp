#include "stdafx.h"
#include <Readers\IO2GOrderResponseReader.h>

using namespace boost::python;

class IO2GOrderResponseReaderWrap : public IO2GOrderResponseReader, public wrapper < IO2GOrderResponseReader >
{
public:
	const char* getOrderID(){ return this->get_override("getOrderID")(); }
	bool isUnderDealerIntervention() { return this->get_override("isUnderDealerIntervention")(); }
};

void export_IO2GOrderResponseReader()
{
	class_<IO2GOrderResponseReaderWrap, bases<IAddRef>, boost::noncopyable>("IO2GOrderResponseReader", no_init)
		.def("getOrderID", pure_virtual(&IO2GOrderResponseReader::getOrderID))
		.def("isUnderDealerIntervention", pure_virtual(&IO2GOrderResponseReader::isUnderDealerIntervention))
		;
};
