#include "stdafx.h"
#include <Readers\IO2GMarketDataResponseReader.h>

using namespace boost::python;

class IO2GMarketDataResponseReaderWrap : public IO2GMarketDataResponseReader, public wrapper < IO2GMarketDataResponseReader >
{
public:
	const char* getQuoteID() { return this->get_override("getQuoteID")();}
	const char* getInstrument() { return this->get_override("getInstrument")();}
	int getSymbolID() { return this->get_override("getSymbolID")();}
	DATE getDateTime() { return this->get_override("getDateTime")();}
	double getAskLow() { return this->get_override("getAskLow")();}
	double getAskHigh() { return this->get_override("getAskHigh")();}
	double getAskOpen() { return this->get_override("getAskOpen")();}
	double getAskClose() { return this->get_override("getAskClose")();}
	double getBidLow() { return this->get_override("getBidLow")();}
	double getBidHigh() { return this->get_override("getBidHigh")();}
	double getBidOpen() { return this->get_override("getBidOpen")();}
	double getBidClose() { return this->get_override("getBidClose")();}
	double getLow() { return this->get_override("getLow")();}
	double getHigh() { return this->get_override("getHigh")();}
	int getTimingInterval() { return this->get_override("getTimingInterval")();}
	bool isCandleCompleted() { return this->get_override("isCandleCompleted")();}
	const char* getMarketDataRequestID() { return this->get_override("getMarketDataRequestID")();}
	const char* getTradingSessionID() { return this->get_override("getTradingSessionID")();}
	const char* getTradingSessionSubID() { return this->get_override("getTradingSessionSubID")();}
	int getContinuosFlag() { return this->get_override("getContinuosFlag")();}
	const char* getBidID() { return this->get_override("getBidID")();}
	const char* getBidQuoteCondition() { return this->get_override("getBidQuoteCondition")();}
	int getBidQuoteType() { return this->get_override("getBidQuoteType")();}
	DATE getBidExpireDateTime() { return this->get_override("")();}
	const char* getAskID() { return this->get_override("getAskID")();}
	const char* getAskQuoteCondition() { return this->get_override("getAskQuoteCondition")();}
	int getAskQuoteType() { return this->get_override("getAskQuoteType")();}
	DATE getAskExpireDateTime() { return this->get_override("getAskExpireDateTime")();}
};

void export_IO2GMarketDataResponseReader()
{
	class_<IO2GMarketDataResponseReaderWrap, boost::noncopyable>("IO2GMarketDataResponseReader", no_init)
		.def("getQuoteID", pure_virtual(&IO2GMarketDataResponseReader::getQuoteID))
		.def("getInstrument", pure_virtual(&IO2GMarketDataResponseReader::getInstrument))
		.def("getSymbolID", pure_virtual(&IO2GMarketDataResponseReader::getSymbolID))
		.def("getDateTime", pure_virtual(&IO2GMarketDataResponseReader::getDateTime))
		.def("getAskLow", pure_virtual(&IO2GMarketDataResponseReader::getAskLow))
		.def("getAskHigh", pure_virtual(&IO2GMarketDataResponseReader::getAskHigh))
		.def("getAskOpen", pure_virtual(&IO2GMarketDataResponseReader::getAskOpen))
		.def("getAskClose", pure_virtual(&IO2GMarketDataResponseReader::getAskClose))
		.def("getBidLow", pure_virtual(&IO2GMarketDataResponseReader::getBidLow))
		.def("getBidHigh", pure_virtual(&IO2GMarketDataResponseReader::getBidHigh))
		.def("getBidOpen", pure_virtual(&IO2GMarketDataResponseReader::getBidOpen))
		.def("getBidClose", pure_virtual(&IO2GMarketDataResponseReader::getBidClose))
		.def("getLow", pure_virtual(&IO2GMarketDataResponseReader::getLow))
		.def("getHigh", pure_virtual(&IO2GMarketDataResponseReader::getHigh))
		.def("getTimingInterval", pure_virtual(&IO2GMarketDataResponseReader::getTimingInterval))
		.def("isCandleCompleted", pure_virtual(&IO2GMarketDataResponseReader::isCandleCompleted))
		.def("getMarketDataRequestID", pure_virtual(&IO2GMarketDataResponseReader::getMarketDataRequestID))
		.def("getTradingSessionID", pure_virtual(&IO2GMarketDataResponseReader::getTradingSessionID))
		.def("getTradingSessionSubID", pure_virtual(&IO2GMarketDataResponseReader::getTradingSessionSubID))
		.def("getContinuosFlag())", pure_virtual(&IO2GMarketDataResponseReader::getContinuosFlag))
		.def("getBidID())", pure_virtual(&IO2GMarketDataResponseReader::getBidID))
		.def("getBidQuoteCondition", pure_virtual(&IO2GMarketDataResponseReader::getBidQuoteCondition))
		.def("getBidQuoteType", pure_virtual(&IO2GMarketDataResponseReader::getBidQuoteType))
		.def("getBidExpireDateTime", pure_virtual(&IO2GMarketDataResponseReader::getBidExpireDateTime))
		.def("getAskID", pure_virtual(&IO2GMarketDataResponseReader::getAskID))
		.def("getAskQuoteCondition", pure_virtual(&IO2GMarketDataResponseReader::getAskQuoteCondition))
		.def("getAskQuoteType", pure_virtual(&IO2GMarketDataResponseReader::getAskQuoteType))
		.def("getAskExpireDateTime", pure_virtual(&IO2GMarketDataResponseReader::getAskExpireDateTime))
		;
}