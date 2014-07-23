#include "stdafx.h"
#include <Readers\IO2GTimeConverter.h>

using namespace boost::python;

class IO2GTimeConverterWrap : public IO2GTimeConverter, public wrapper < IO2GTimeConverter >
{
	DATE convert(DATE dtSource, TimeZone fromZone, TimeZone toZone) { return this->get_override("convert")(); }
};

void export_IO2GTimeConverter(){
	
	object obj_IO2GTimeConverter = class_<IO2GTimeConverterWrap, boost::noncopyable>("IO2GTimeConverter", no_init)
		.def("convert", pure_virtual(&IO2GTimeConverter::convert))
		;
	{
		scope in_IO2GTimeConverter(obj_IO2GTimeConverter);
		enum_<IO2GTimeConverter::TimeZone>("TimeZone")
			.value("UTC", IO2GTimeConverter::UTC)
			.value("Local", IO2GTimeConverter::Local)
			.value("EST", IO2GTimeConverter::EST)
			.value("Server", IO2GTimeConverter::Server)
			.export_values()
			;
	}
}