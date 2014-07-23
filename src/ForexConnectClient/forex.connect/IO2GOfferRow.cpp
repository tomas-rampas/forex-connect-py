#include "stdafx.h"
#include <rows\IO2GOfferRow.h>

using namespace boost::python;

class IO2GOfferRowWrap : public IO2GOfferRow, public wrapper < IO2GOfferRow >
{
public:
	const char* getOfferID(){ return this->get_override("getOfferID")(); }
	const char* getInstrument(){ return this->get_override("getInstrument")(); }
	const char* getQuoteID(){ return this->get_override("getQuoteID")(); }
	double getBid(){ return this->get_override("getBid")(); }
	double getAsk(){ return this->get_override("getAsk")(); }
	double getLow(){ return this->get_override("getLow")(); }
	double getHigh(){ return this->get_override("getHigh")(); }
	int getVolume(){ return this->get_override("getVolume")(); }
	DATE getTime(){ return this->get_override("getTime")(); }
	const char* getBidTradable(){ return this->get_override("getBidTradable")(); }
	const char* getAskTradable(){ return this->get_override("getAskTradable")(); }
	double getSellInterest(){ return this->get_override("getSellInterest")(); }
	double getBuyInterest(){ return this->get_override("getBuyInterest")(); }
	const char* getContractCurrency(){ return this->get_override("getContractCurrency")(); }
	int getDigits(){ return this->get_override("getDigits")(); }
	double getPointSize(){ return this->get_override("getPointSize")(); }
	const char* getSubscriptionStatus(){ return this->get_override("getSubscriptionStatus")(); }
	int getInstrumentType(){ return this->get_override("getInstrumentType")(); }
	double getContractMultiplier(){ return this->get_override("getContractMultiplier")(); }
	const char* getTradingStatus(){ return this->get_override("getTradingStatus")(); }
	const char* getValueDate(){ return this->get_override("getValueDate")(); }
	bool isOfferIDValid(){ return this->get_override("isOfferIDValid")(); }
	bool isInstrumentValid(){ return this->get_override("isInstrumentValid")(); }
	bool isQuoteIDValid(){ return this->get_override("isQuoteIDValid")(); }
	bool isBidValid(){ return this->get_override("isBidValid")(); }
	bool isAskValid(){ return this->get_override("isAskValid")(); }
	bool isLowValid(){ return this->get_override("isLowValid")(); }
	bool isHighValid(){ return this->get_override("isHighValid")(); }
	bool isVolumeValid(){ return this->get_override("isVolumeValid")(); }
	bool isTimeValid(){ return this->get_override("isTimeValid")(); }
	bool isBidTradableValid(){ return this->get_override("isBidTradableValid")(); }
	bool isAskTradableValid(){ return this->get_override("isAskTradableValid")(); }
	bool isSellInterestValid(){ return this->get_override("isSellInterestValid")(); }
	bool isBuyInterestValid(){ return this->get_override("isBuyInterestValid")(); }
	bool isContractCurrencyValid(){ return this->get_override("isContractCurrencyValid")(); }
	bool isDigitsValid(){ return this->get_override("isDigitsValid")(); }
	bool isPointSizeValid(){ return this->get_override("isPointSizeValid")(); }
	bool isSubscriptionStatusValid(){ return this->get_override("isSubscriptionStatusValid")(); }
	bool isInstrumentTypeValid(){ return this->get_override("isInstrumentTypeValid")(); }
	bool isContractMultiplierValid(){ return this->get_override("isContractMultiplierValid")(); }
	bool isTradingStatusValid(){ return this->get_override("isTradingStatusValid")(); }
	bool isValueDateValid(){ return this->get_override("isValueDateValid")(); }
};

class IO2GOfferTableRowWrap : public IO2GOfferTableRow, public wrapper < IO2GOfferTableRow >
{
public:
	double getPipCost() { return this->get_override("getPipCost")(); }
};

void export_IO2GOfferRow()
{
	class_<IO2GOfferRowWrap, bases<IO2GRow>, boost::noncopyable>("IO2GOfferRow", no_init)
		.def("getOfferID", pure_virtual(&IO2GOfferRow::getOfferID))
		.def("getInstrument", pure_virtual(&IO2GOfferRow::getInstrument))
		.def("getQuoteID", pure_virtual(&IO2GOfferRow::getQuoteID))
		.def("getBid", pure_virtual(&IO2GOfferRow::getBid))
		.def("getAsk", pure_virtual(&IO2GOfferRow::getAsk))
		.def("getLow", pure_virtual(&IO2GOfferRow::getLow))
		.def("getHigh", pure_virtual(&IO2GOfferRow::getHigh))
		.def("getVolume", pure_virtual(&IO2GOfferRow::getVolume))
		.def("getTime", pure_virtual(&IO2GOfferRow::getTime))
		.def("getBidTradable", pure_virtual(&IO2GOfferRow::getBidTradable))
		.def("getAskTradable", pure_virtual(&IO2GOfferRow::getAskTradable))
		.def("getSellInterest", pure_virtual(&IO2GOfferRow::getSellInterest))
		.def("getBuyInterest", pure_virtual(&IO2GOfferRow::getBuyInterest))
		.def("getContractCurrency", pure_virtual(&IO2GOfferRow::getContractCurrency))
		.def("getDigits", pure_virtual(&IO2GOfferRow::getDigits))
		.def("getPointSize", pure_virtual(&IO2GOfferRow::getPointSize))
		.def("getSubscriptionStatus", pure_virtual(&IO2GOfferRow::getSubscriptionStatus))
		.def("getInstrumentType", pure_virtual(&IO2GOfferRow::getInstrumentType))
		.def("getContractMultiplier", pure_virtual(&IO2GOfferRow::getContractMultiplier))
		.def("getTradingStatus", pure_virtual(&IO2GOfferRow::getTradingStatus))
		.def("getValueDate", pure_virtual(&IO2GOfferRow::getValueDate))
		.def("isOfferIDValid", pure_virtual(&IO2GOfferRow::isOfferIDValid))
		.def("isInstrumentValid", pure_virtual(&IO2GOfferRow::isInstrumentValid))
		.def("isQuoteIDValid", pure_virtual(&IO2GOfferRow::isQuoteIDValid))
		.def("isBidValid", pure_virtual(&IO2GOfferRow::isBidValid))
		.def("isAskValid", pure_virtual(&IO2GOfferRow::isAskValid))
		.def("isLowValid", pure_virtual(&IO2GOfferRow::isLowValid))
		.def("isHighValid", pure_virtual(&IO2GOfferRow::isHighValid))
		.def("isVolumeValid", pure_virtual(&IO2GOfferRow::isVolumeValid))
		.def("isTimeValid", pure_virtual(&IO2GOfferRow::isTimeValid))
		.def("isBidTradableValid", pure_virtual(&IO2GOfferRow::isBidTradableValid))
		.def("isAskTradableValid", pure_virtual(&IO2GOfferRow::isAskTradableValid))
		.def("isSellInterestValid", pure_virtual(&IO2GOfferRow::isSellInterestValid))
		.def("isBuyInterestValid", pure_virtual(&IO2GOfferRow::isBuyInterestValid))
		.def("isContractCurrencyValid", pure_virtual(&IO2GOfferRow::isContractCurrencyValid))
		.def("isDigitsValid", pure_virtual(&IO2GOfferRow::isDigitsValid))
		.def("isPointSizeValid", pure_virtual(&IO2GOfferRow::isPointSizeValid))
		.def("isSubscriptionStatusValid", pure_virtual(&IO2GOfferRow::isSubscriptionStatusValid))
		.def("isInstrumentTypeValid", pure_virtual(&IO2GOfferRow::isInstrumentTypeValid))
		.def("isContractMultiplierValid", pure_virtual(&IO2GOfferRow::isContractMultiplierValid))
		.def("isTradingStatusValid", pure_virtual(&IO2GOfferRow::isTradingStatusValid))
		.def("isValueDateValid", pure_virtual(&IO2GOfferRow::isValueDateValid))
		;

	class_<IO2GOfferTableRowWrap, bases<IO2GOfferRow>, boost::noncopyable>("IO2GOfferTableRow", no_init)
		.def("getPipCost", pure_virtual(&IO2GOfferTableRow::getPipCost))
		;
};