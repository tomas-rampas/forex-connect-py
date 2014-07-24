#include "stdafx.h"
#include <IO2GLoginRules.h>

using namespace boost::python;

class IO2GLoginRulesWrap : public IO2GLoginRules, public wrapper < IO2GLoginRules >
{
public:
	bool isTableLoadedByDefault(O2GTable){ return this->get_override("isTableLoadedByDefault")();}
	IO2GResponse* getTableRefreshResponse(O2GTable){ return this->get_override("getTableRefreshResponse")();}
	IO2GResponse* getSystemPropertiesResponse(){ return this->get_override("getSystemPropertiesResponse")();}
	IO2GPermissionChecker* getPermissionChecker(){ return this->get_override("getPermissionChecker")();}
	IO2GTradingSettingsProvider* getTradingSettingsProvider(){ return this->get_override("getTradingSettingsProvider")();}
};

void export_IO2GLoginRules()
{
	class_<IO2GLoginRulesWrap, bases<IAddRef>, boost::noncopyable>("IO2GLoginRules", no_init)
		.def("isTableLoadedByDefault", pure_virtual(&IO2GLoginRules::isTableLoadedByDefault))
		.def("getTableRefreshResponse", pure_virtual(&IO2GLoginRules::getTableRefreshResponse), return_value_policy<reference_existing_object>())
		.def("getSystemPropertiesResponse", pure_virtual(&IO2GLoginRules::getSystemPropertiesResponse), return_value_policy<reference_existing_object>())
		.def("getPermissionChecker", pure_virtual(&IO2GLoginRules::getPermissionChecker), return_value_policy<reference_existing_object>())
		.def("getTradingSettingsProvider", pure_virtual(&IO2GLoginRules::getTradingSettingsProvider), return_value_policy<reference_existing_object>())
		;
};
