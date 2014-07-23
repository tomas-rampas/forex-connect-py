#include "stdafx.h"
#include <Rows\IO2GMessageRow.h>
using namespace boost::python;

class IO2GMessageRowWrap : public IO2GMessageRow, public wrapper < IO2GMessageRow >
{
public:
	const char* getMsgID(){ return this->get_override("getMsgID")();}
	DATE getTime(){ return this->get_override("getTime")();}
	const char* getFrom(){ return this->get_override("getFrom")();}
	const char* getType(){ return this->get_override("getType")();}
	const char* getFeature(){ return this->get_override("getFeature")();}
	const char* getText(){ return this->get_override("getText")();}
	const char* getSubject(){ return this->get_override("getSubject")();}
	bool getHTMLFragmentFlag(){ return this->get_override("getHTMLFragmentFlag")();}
};

void export_IO2GMessageRow()
{
	class_<IO2GMessageRowWrap, bases<IO2GRow>, boost::noncopyable>("IO2GMessageRow", no_init)
		.def("getMsgID", pure_virtual(&IO2GMessageRow::getMsgID))
		.def("getTime", pure_virtual(&IO2GMessageRow::getTime))
		.def("getFrom", pure_virtual(&IO2GMessageRow::getFrom))
		.def("getType", pure_virtual(&IO2GMessageRow::getType))
		.def("getFeature", pure_virtual(&IO2GMessageRow::getFeature))
		.def("getText", pure_virtual(&IO2GMessageRow::getText))
		.def("getSubject", pure_virtual(&IO2GMessageRow::getSubject))
		.def("getHTMLFragmentFlag", pure_virtual(&IO2GMessageRow::getHTMLFragmentFlag))
		;

	class_<IO2GMessageTableRow, bases<IO2GMessageRow>, boost::noncopyable>("IO2GMessageTableRow", no_init)
		;
};