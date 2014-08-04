#include "stdafx.h"
#include <O2GTransport.h>
using namespace boost::python;

//class CO2GTransport
//{
//public:
//	static IO2GSession* createSession();
//	static void setProxy(const char* proxyHost, int port, const char* user, const char* password);
//	static void setCAInfo(const char* caFilePath);
//	static void setNumberOfReconnections(const int number);
//	static void setApplicationID(const char* applicationID);
//	static void getApplicationID(char* applicationID, size_t &len);
//	static void setClosedHistorySize(const int size);
//	static int getClosedHistorySize();
//};

void export_CO2GTransport()
{
	class_<CO2GTransport>("CO2GTransport", init<>())
		.def("createSession", &CO2GTransport::createSession, return_value_policy<reference_existing_object>())
		.def("setProxy", &CO2GTransport::setProxy)
		.def("setCAInfo", &CO2GTransport::setCAInfo)
		.def("setNumberOfReconnections", &CO2GTransport::setNumberOfReconnections)
		.def("setApplicationID", &CO2GTransport::setApplicationID)
		.def("getApplicationID", &CO2GTransport::getApplicationID)
		.def("setClosedHistorySize", &CO2GTransport::setClosedHistorySize)
		.def("getClosedHistorySize", &CO2GTransport::getClosedHistorySize)
		.staticmethod("createSession")
		.staticmethod("setProxy")
		.staticmethod("setCAInfo")
		.staticmethod("setNumberOfReconnections")
		.staticmethod("setApplicationID")
		.staticmethod("getApplicationID")
		.staticmethod("setClosedHistorySize")
		.staticmethod("getClosedHistorySize")
		;
};
