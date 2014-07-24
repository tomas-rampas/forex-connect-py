#include "stdafx.h"
#include <IO2GPermissionChecker.h>
using namespace boost::python;

class IO2GPermissionCheckerWrap : public IO2GPermissionChecker, public wrapper<IO2GPermissionChecker>
{
public:
	O2GPermissionStatus canCreateMarketOpenOrder(const char*) { return this->get_override("canCreateMarketOpenOrder")(); }
	O2GPermissionStatus canChangeMarketOpenOrder(const char*) { return this->get_override("canChangeMarketOpenOrder")(); }
	O2GPermissionStatus canDeleteMarketOpenOrder(const char*) { return this->get_override("canDeleteMarketOpenOrder")(); }
	O2GPermissionStatus canCreateMarketCloseOrder(const char*) { return this->get_override("canCreateMarketCloseOrder")(); }
	O2GPermissionStatus canChangeMarketCloseOrder(const char*) { return this->get_override("canChangeMarketCloseOrder")(); }
	O2GPermissionStatus canDeleteMarketCloseOrder(const char*) { return this->get_override("canDeleteMarketCloseOrder")(); }
	O2GPermissionStatus canCreateEntryOrder(const char*) { return this->get_override("canCreateEntryOrder")(); }
	O2GPermissionStatus canChangeEntryOrder(const char*) { return this->get_override("canChangeEntryOrder")(); }
	O2GPermissionStatus canDeleteEntryOrder(const char*) { return this->get_override("canDeleteEntryOrder")(); }
	O2GPermissionStatus canCreateStopLimitOrder(const char*) { return this->get_override("canCreateStopLimitOrder")(); }
	O2GPermissionStatus canChangeStopLimitOrder(const char*) { return this->get_override("canChangeStopLimitOrder")(); }
	O2GPermissionStatus canDeleteStopLimitOrder(const char*) { return this->get_override("canDeleteStopLimitOrder")(); }
	O2GPermissionStatus canRequestQuote(const char*) { return this->get_override("canRequestQuote")(); }
	O2GPermissionStatus canAcceptQuote(const char*) { return this->get_override("canAcceptQuote")(); }
	O2GPermissionStatus canDeleteQuote(const char*) { return this->get_override("canDeleteQuote")(); }
	O2GPermissionStatus canCreateOCO(const char*) { return this->get_override("canCreateOCO")(); }
	O2GPermissionStatus canCreateOTO(const char*) { return this->get_override("canCreateOTO")(); }
	O2GPermissionStatus canJoinToNewContingencyGroup(const char*) { return this->get_override("canJoinToNewContingencyGroup")(); }
	O2GPermissionStatus canJoinToExistingContingencyGroup(const char*) { return this->get_override("canJoinToExistingContingencyGroup")(); }
	O2GPermissionStatus canRemoveFromContingencyGroup(const char*) { return this->get_override("canRemoveFromContingencyGroup")(); }
	O2GPermissionStatus canChangeOfferSubscription(const char*) { return this->get_override("canChangeOfferSubscription")(); }
	O2GPermissionStatus canCreateNetCloseOrder(const char*) { return this->get_override("canCreateNetCloseOrder")(); }
	O2GPermissionStatus canChangeNetCloseOrder(const char*) { return this->get_override("canChangeNetCloseOrder")(); }
	O2GPermissionStatus canDeleteNetCloseOrder(const char*) { return this->get_override("canDeleteNetCloseOrder")(); }
	O2GPermissionStatus canCreateNetStopLimitOrder(const char*) { return this->get_override("canCreateNetStopLimitOrder")(); }
	O2GPermissionStatus canChangeNetStopLimitOrder(const char*) { return this->get_override("canChangeNetStopLimitOrder")(); }
	O2GPermissionStatus canDeleteNetStopLimitOrder(const char*) { return this->get_override("canDeleteNetStopLimitOrder")(); }
	O2GPermissionStatus canUseDynamicTrailingForStop() { return this->get_override("canUseDynamicTrailingForStop")(); }
	O2GPermissionStatus canUseDynamicTrailingForLimit() { return this->get_override("canUseDynamicTrailingForLimit")(); }
	O2GPermissionStatus canUseDynamicTrailingForEntryStop() { return this->get_override("canUseDynamicTrailingForEntryStop")(); }
	O2GPermissionStatus canUseDynamicTrailingForEntryLimit() { return this->get_override("canUseDynamicTrailingForEntryLimit")(); }
	O2GPermissionStatus canUseFluctuateTrailingForStop() { return this->get_override("canUseFluctuateTrailingForStop")(); }
	O2GPermissionStatus canUseFluctuateTrailingForLimit() { return this->get_override("canUseFluctuateTrailingForLimit")(); }
	O2GPermissionStatus canUseFluctuateTrailingForEntryStop() { return this->get_override("canUseFluctuateTrailingForEntryStop")(); }
	O2GPermissionStatus canUseFluctuateTrailingForEntryLimit() { return this->get_override("canUseFluctuateTrailingForEntryLimit")(); }
};

void export_IO2GPermissionChecker()
{
	class_<IO2GPermissionCheckerWrap, bases<IAddRef>, boost::noncopyable>("IO2GPermissionChecker", no_init)
		.def("canCreateMarketOpenOrder", pure_virtual(&IO2GPermissionChecker::canCreateMarketOpenOrder))
		.def("canChangeMarketOpenOrder", pure_virtual(&IO2GPermissionChecker::canChangeMarketOpenOrder))
		.def("canDeleteMarketOpenOrder", pure_virtual(&IO2GPermissionChecker::canDeleteMarketOpenOrder))
		.def("canCreateMarketCloseOrder", pure_virtual(&IO2GPermissionChecker::canCreateMarketCloseOrder))
		.def("canChangeMarketCloseOrder", pure_virtual(&IO2GPermissionChecker::canChangeMarketCloseOrder))
		.def("canDeleteMarketCloseOrder", pure_virtual(&IO2GPermissionChecker::canDeleteMarketCloseOrder))
		.def("canCreateEntryOrder", pure_virtual(&IO2GPermissionChecker::canCreateEntryOrder))
		.def("canChangeEntryOrder", pure_virtual(&IO2GPermissionChecker::canChangeEntryOrder))
		.def("canDeleteEntryOrder", pure_virtual(&IO2GPermissionChecker::canDeleteEntryOrder))
		.def("canCreateStopLimitOrder", pure_virtual(&IO2GPermissionChecker::canCreateStopLimitOrder))
		.def("canChangeStopLimitOrder", pure_virtual(&IO2GPermissionChecker::canChangeStopLimitOrder))
		.def("canDeleteStopLimitOrder", pure_virtual(&IO2GPermissionChecker::canDeleteStopLimitOrder))
		.def("canRequestQuote", pure_virtual(&IO2GPermissionChecker::canRequestQuote))
		.def("canAcceptQuote", pure_virtual(&IO2GPermissionChecker::canAcceptQuote))
		.def("canDeleteQuote", pure_virtual(&IO2GPermissionChecker::canDeleteQuote))
		.def("canCreateOCO", pure_virtual(&IO2GPermissionChecker::canCreateOCO))
		.def("canCreateOTO", pure_virtual(&IO2GPermissionChecker::canCreateOTO))
		.def("canJoinToNewContingencyGroup", pure_virtual(&IO2GPermissionChecker::canJoinToNewContingencyGroup))
		.def("canJoinToExistingContingencyGroup", pure_virtual(&IO2GPermissionChecker::canJoinToExistingContingencyGroup))
		.def("canRemoveFromContingencyGroup", pure_virtual(&IO2GPermissionChecker::canRemoveFromContingencyGroup))
		.def("canChangeOfferSubscription", pure_virtual(&IO2GPermissionChecker::canChangeOfferSubscription))
		.def("canCreateNetCloseOrder", pure_virtual(&IO2GPermissionChecker::canCreateNetCloseOrder))
		.def("canChangeNetCloseOrder", pure_virtual(&IO2GPermissionChecker::canChangeNetCloseOrder))
		.def("canDeleteNetCloseOrder", pure_virtual(&IO2GPermissionChecker::canDeleteNetCloseOrder))
		.def("canCreateNetStopLimitOrder", pure_virtual(&IO2GPermissionChecker::canCreateNetStopLimitOrder))
		.def("canChangeNetStopLimitOrder", pure_virtual(&IO2GPermissionChecker::canChangeNetStopLimitOrder))
		.def("canDeleteNetStopLimitOrder", pure_virtual(&IO2GPermissionChecker::canDeleteNetStopLimitOrder))
		.def("canUseDynamicTrailingForStop", pure_virtual(&IO2GPermissionChecker::canUseDynamicTrailingForStop))
		.def("canUseDynamicTrailingForLimit", pure_virtual(&IO2GPermissionChecker::canUseDynamicTrailingForLimit))
		.def("canUseDynamicTrailingForEntryStop", pure_virtual(&IO2GPermissionChecker::canUseDynamicTrailingForEntryStop))
		.def("canUseDynamicTrailingForEntryLimit", pure_virtual(&IO2GPermissionChecker::canUseDynamicTrailingForEntryLimit))
		.def("canUseFluctuateTrailingForStop", pure_virtual(&IO2GPermissionChecker::canUseFluctuateTrailingForStop))
		.def("canUseFluctuateTrailingForLimit", pure_virtual(&IO2GPermissionChecker::canUseFluctuateTrailingForLimit))
		.def("canUseFluctuateTrailingForEntryStop", pure_virtual(&IO2GPermissionChecker::canUseFluctuateTrailingForEntryStop))
		.def("canUseFluctuateTrailingForEntryLimit", pure_virtual(&IO2GPermissionChecker::canUseFluctuateTrailingForEntryLimit))
		;
};