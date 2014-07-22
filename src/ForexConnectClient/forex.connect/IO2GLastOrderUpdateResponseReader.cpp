#include "stdafx.h"
#include <Readers/IO2GLastOrderUpdateResponseReader.h>

using namespace boost::python;

class IO2GLastOrderUpdateResponseReaderWrap : public IO2GLastOrderUpdateResponseReader, public wrapper < IO2GLastOrderUpdateResponseReader >
{
	O2GTableUpdateType getUpdateType() = 0;
	IO2GOrderRow *getOrder() = 0;

};