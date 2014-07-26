#include "stdafx.h"
#include <IO2GRow.h>
using namespace boost::python;

class IO2GRowWrap : public IO2GRow, public wrapper < IO2GRow >
{
public:
	const void* getCell(int column){ return this->get_override("getCell")(column);}
	bool isCellChanged(int column){ return this->get_override("isCellChanged")();}
	IO2GTableColumnCollection* columns(){ return this->get_override("columns")();}
	O2GTable getTableType(){ return this->get_override("getTableType")();}

};

void export_IO2GRow()
{
	class_<IO2GRowWrap, bases<IAddRef>, boost::noncopyable>("IO2GRow", no_init)
		.def("getCell", pure_virtual((PyObject *(IO2GRow::*)(int))(&IO2GRow::getCell)))
		.def("isCellChanged", pure_virtual(&IO2GRow::isCellChanged))
		.def("columns", pure_virtual(&IO2GRow::columns), return_value_policy<reference_existing_object>())
		.def("getTableType", pure_virtual(&IO2GRow::getTableType))
		;
};