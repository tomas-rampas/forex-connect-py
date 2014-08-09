#include "stdafx.h"
#include <O2GDateUtils.h>
using namespace boost::python;

void export_O2GDateUtils()
{
	//enum_<O2GDateUtils::SYSTEMTIME_DEFINED>("SYSTEMTIME_DEFINED")
	//	;
	class_<CO2GDateUtils>("CO2GDateUtils", init<>())
		.def("CTimeToOleTime", &CO2GDateUtils::CTimeToOleTime)
		.staticmethod("CTimeToOleTime")
		.def("CTimeToWindowsTime", &CO2GDateUtils::CTimeToWindowsTime)
		.staticmethod("CTimeToWindowsTime")
		.def("OleTimeToWindowsTime", &CO2GDateUtils::OleTimeToWindowsTime)
		.staticmethod("OleTimeToWindowsTime")
		.def("OleTimeToCTime", &CO2GDateUtils::OleTimeToCTime)
		.staticmethod("OleTimeToCTime")
		.def("WindowsTimeToOleTime", &CO2GDateUtils::WindowsTimeToOleTime)
		.staticmethod("WindowsTimeToOleTime")
		.def("WindowsTimeToCTime", &CO2GDateUtils::WindowsTimeToCTime)
		.staticmethod("WindowsTimeToCTime")
		;
};