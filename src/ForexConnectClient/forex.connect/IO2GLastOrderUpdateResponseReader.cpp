#include "stdafx.h"
#include <Readers/IO2GLastOrderUpdateResponseReader.h>

using namespace boost::python;

class IO2GLastOrderUpdateResponseReaderWrap : public IO2GLastOrderUpdateResponseReader, public wrapper < IO2GLastOrderUpdateResponseReader >
{
public:
	O2GTableUpdateType getUpdateType() { return this->get_override("getUpdateType")(); }
	IO2GOrderRow* getOrder() { return this->get_override("getOrder")(); }
};

void export_IO2GLastOrderUpdateResponseReader()
{
	class_<IO2GLastOrderUpdateResponseReaderWrap, bases<IAddRef>, boost::noncopyable>("IO2GLastOrderUpdateResponseReader", no_init)
		.def("getUpdateType", pure_virtual(&IO2GLastOrderUpdateResponseReader::getUpdateType))
		.def("getOrder", pure_virtual(&IO2GLastOrderUpdateResponseReader::getOrder), return_value_policy<reference_existing_object>())
		;
}