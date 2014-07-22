#include "stdafx.h"
#include <IO2GColumn.h>

using namespace boost::python;

class IO2GTableColumnWrap : public IO2GTableColumn, public wrapper < IO2GTableColumn >
{
	const char* getID() { return this->get_override("getID")(); }
	O2GTableColumnType getType(){ return this->get_override("getType")(); }
};

void export_IO2GTableColumn()
{
	class_<IO2GTableColumnWrap, boost::noncopyable>("IO2GTableColumn")
		.def("getID", &IO2GTableColumn::getID)
		;
}