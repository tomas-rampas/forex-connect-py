#include "stdafx.h"
#include <IO2GTimeFrame.h>
using namespace boost::python;

//IO2GTimeframe
class IO2GTimeframeWrap : public IO2GTimeframe, public wrapper<IO2GTimeframe>
{
public:
	const char* getID(){ return this->get_override("getID")();}
	O2GTimeframeUnit getUnit(){ return this->get_override("getUnit")();}
	int getQueryDepth(){ return this->get_override("getQueryDepth")();}
	int getSize(){ return this->get_override("getSize")();}
};

//IO2GTimeframeCollection 
class IO2GTimeframeCollectionWrap : public IO2GTimeframeCollection, public wrapper<IO2GTimeframeCollection>
{
public:
	int size(){ return this->get_override("size")();}
	IO2GTimeframe* get(int index){ return this->get_override("get")();}
	IO2GTimeframe* get(const char *id){ return this->get_override("get")();}
};

void export_IO2GTimeframe()
{
	enum_<O2GTimeframeUnit>("O2GTimeframeUnit")
		.value("Tick", O2GTimeframeUnit::Tick)
		.value("Min", O2GTimeframeUnit::Min)
		.value("Hour", O2GTimeframeUnit::Hour)
		.value("Day", O2GTimeframeUnit::Day)
		.value("Week", O2GTimeframeUnit::Week)
		.value("Month", O2GTimeframeUnit::Month)
		.value("Year", O2GTimeframeUnit::Year)
		.export_values()
		;

	class_<IO2GTimeframeWrap, bases<IAddRef>, boost::noncopyable>("IO2GTimeframe", no_init)
		.def("getID", pure_virtual(&IO2GTimeframe::getID))
		.def("getUnit", pure_virtual(&IO2GTimeframe::getUnit))
		.def("getQueryDepth", pure_virtual(&IO2GTimeframe::getQueryDepth))
		.def("getSize", pure_virtual(&IO2GTimeframe::getSize))
		;

	class_<IO2GTimeframeCollectionWrap, bases<IAddRef>, boost::noncopyable>("IO2GTimeframeCollection", no_init)
		.def("size", pure_virtual(&IO2GTimeframeCollection::size))
		.def("get", pure_virtual((IO2GTimeframe*(IO2GTimeframeCollection::*)(int))(&IO2GTimeframeCollection::get)), return_value_policy<reference_existing_object>())
		.def("get", pure_virtual((IO2GTimeframe*(IO2GTimeframeCollection::*)(const char *))(&IO2GTimeframeCollection::get)), return_value_policy<reference_existing_object>())
		;
};

