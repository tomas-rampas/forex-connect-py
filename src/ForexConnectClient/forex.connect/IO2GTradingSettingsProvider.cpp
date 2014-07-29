#include "stdafx.h"
#include <IO2GTradingSettingsProvider.h>
using namespace boost::python;

//IO2GTradingSettingsProvider
class IO2GTradingSettingsProviderWrap : public IO2GTradingSettingsProvider, public wrapper<IO2GTradingSettingsProvider>
{
public:
	int getCondDistStopForTrade(const char* instrument){ return this->get_override("getCondDistStopForTrade")();}
	int getCondDistLimitForTrade(const char* instrument){ return this->get_override("getCondDistLimitForTrade")();}
	int getCondDistEntryStop(const char* instrument){ return this->get_override("getCondDistEntryStop")();}
	int getCondDistEntryLimit(const char* instrument){ return this->get_override("getCondDistEntryLimit")();}
	int getMinQuantity(const char* instrument, IO2GAccountRow* account){ return this->get_override("getMinQuantity")();}
	int getMaxQuantity(const char* instrument, IO2GAccountRow* account){ return this->get_override("getMaxQuantity")();}
	int getBaseUnitSize(const char* instrument, IO2GAccountRow* account){ return this->get_override("getBaseUnitSize")();}
	O2GMarketStatus getMarketStatus(const char* instrument){ return this->get_override("getMarketStatus")();}
	int getMinTrailingStep(){ return this->get_override("getMinTrailingStep")();}
	int getMaxTrailingStep(){ return this->get_override("getMaxTrailingStep")();}
	double getMMR(const char* instrument, IO2GAccountRow* account){ return this->get_override("getMMR")();}
	bool getMargins(const char* instrument, IO2GAccountRow* account, double& mmr, double& emr, double& lmr)
	{ return this->get_override("getMargins")();}
};

void export_IO2GTradingSettingsProvider()
{
	class_<IO2GTradingSettingsProviderWrap, bases<IAddRef>, boost::noncopyable>("IO2GTradingSettingsProvider", no_init)
		.def("getCondDistStopForTrade", pure_virtual(&IO2GTradingSettingsProvider::getCondDistStopForTrade))
		.def("getCondDistLimitForTrade", pure_virtual(&IO2GTradingSettingsProvider::getCondDistLimitForTrade))
		.def("getCondDistEntryStop", pure_virtual(&IO2GTradingSettingsProvider::getCondDistEntryStop))
		.def("getCondDistEntryLimit", pure_virtual(&IO2GTradingSettingsProvider::getCondDistEntryLimit))
		.def("getMinQuantity", pure_virtual(&IO2GTradingSettingsProvider::getMinQuantity))
		.def("getMaxQuantity", pure_virtual(&IO2GTradingSettingsProvider::getMaxQuantity))
		.def("getBaseUnitSize", pure_virtual(&IO2GTradingSettingsProvider::getBaseUnitSize))
		.def("getMarketStatus", pure_virtual(&IO2GTradingSettingsProvider::getMarketStatus))
		.def("getMinTrailingStep", pure_virtual(&IO2GTradingSettingsProvider::getMinTrailingStep))
		.def("getMaxTrailingStep", pure_virtual(&IO2GTradingSettingsProvider::getMaxTrailingStep))
		.def("getMMR", pure_virtual(&IO2GTradingSettingsProvider::getMMR))
		.def("getMargins", pure_virtual(&IO2GTradingSettingsProvider::getMargins))
		;
};