#include "stdafx.h"
#include <Readers\IO2GSystemProperties.h>

using namespace boost::python;

class IO2GSystemPropertiesReaderWrap : public IO2GSystemPropertiesReader, public wrapper < IO2GSystemPropertiesReader >
{
public:
	const char* findProperty(const char*) { return this->get_override("findProperty")(); }
	const char* getProperty(int index, const char*&){ return this->get_override("getProperty")(); }
	int size(){ return this->get_override("size")(); }
};

void export_IO2GSystemPropertiesReader()
{
	class_<IO2GSystemPropertiesReaderWrap, boost::noncopyable>("IO2GSystemPropertiesReader", no_init)
		.def("findProperty", pure_virtual(&IO2GSystemPropertiesReader::findProperty))
		.def("getProperty", pure_virtual(&IO2GSystemPropertiesReader::getProperty))
		.def("size", pure_virtual(&IO2GSystemPropertiesReader::size))
		;
}
