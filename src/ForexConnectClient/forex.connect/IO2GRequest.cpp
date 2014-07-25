#include "stdafx.h"
#include <IO2GRequest.h>

using namespace boost::python;

class IO2GRequestWrap : public IO2GRequest, public wrapper < IO2GRequest >
{
public:
	const char* getRequestID(){ return this->get_override("getRequestID")(); }
	int getChildrenCount(){ return this->get_override("getChildrenCount")(); }
	IO2GRequest* getChildRequest(int){ return this->get_override("getChildRequest")(); }
};

class IO2GValueMapWrap : public IO2GValueMap, public wrapper < IO2GValueMap >
{
public:
	void setString(O2GRequestParamsEnum, const char*){ this->get_override("setString")(); }
	void setDouble(O2GRequestParamsEnum, double){ this->get_override("setDouble")(); }
	void setInt(O2GRequestParamsEnum, int){ this->get_override("setInt")(); }
	void setBoolean(O2GRequestParamsEnum, bool){ this->get_override("setBoolean")(); }
	IO2GValueMap* clone(){ return this->get_override("clone")(); }
	void clear(){ this->get_override("clear")(); }
	int getChildrenCount(){ return this->get_override("getChildrenCount")(); }
	IO2GValueMap* getChild(int){ return this->get_override("getChild")(); }
	void appendChild(IO2GValueMap*){ this->get_override("appendChild")(); }

};

class IO2GRequestFactoryWrap : public IO2GRequestFactory, public wrapper < IO2GRequestFactory >
{
public:
	IO2GTimeframeCollection* getTimeFrameCollection(){ return this->get_override("getTimeFrameCollection")(); }
	IO2GRequest* createMarketDataSnapshotRequestInstrument(const char *instrument, IO2GTimeframe *timeframe, int maxBars = 300)
	{
		return this->get_override("createMarketDataSnapshotRequestInstrument")();
	}
	void fillMarketDataSnapshotRequestTime(IO2GRequest *request, DATE timeFrom = 0, DATE timeTo = 0, bool isIncludeWeekends = false)
	{
		this->get_override("fillMarketDataSnapshotRequestTime")();
	}
	IO2GRequest* createRefreshTableRequest(O2GTable){ return this->get_override("createRefreshTableRequest")(); }
	IO2GRequest* createRefreshTableRequestByAccount(O2GTable, const char*){ return this->get_override("createRefreshTableRequestByAccount")(); }
	IO2GRequest* createOrderRequest(IO2GValueMap *){ return this->get_override("createOrderRequest")(); }
	IO2GValueMap* createValueMap(){ return this->get_override("createValueMap")(); }
	const char* getLastError(){ return this->get_override("getLastError")(); }
};

void export_IO2GRequest()
{
	class_<IO2GRequestWrap, bases<IAddRef>, boost::noncopyable>("IO2GRequest", no_init)
		.def("getRequestID", pure_virtual(&IO2GRequest::getRequestID))
		.def("getChildrenCount", pure_virtual(&IO2GRequest::getChildrenCount))
		.def("getChildRequest", pure_virtual(&IO2GRequest::getChildRequest), return_value_policy<reference_existing_object>())
		;

	class_<IO2GValueMapWrap, bases<IAddRef>, boost::noncopyable>("IO2GValueMap", no_init)
		.def("setString", pure_virtual(&IO2GValueMap::setString))
		.def("setDouble", pure_virtual(&IO2GValueMap::setDouble))
		.def("setInt", pure_virtual(&IO2GValueMap::setInt))
		.def("setBoolean", pure_virtual(&IO2GValueMap::setBoolean))
		.def("clone", pure_virtual(&IO2GValueMap::clone), return_value_policy<reference_existing_object>())
		.def("clear", pure_virtual(&IO2GValueMap::clear))
		.def("getChildrenCount", pure_virtual(&IO2GValueMap::getChildrenCount))
		.def("getChild", pure_virtual(&IO2GValueMap::getChild), return_value_policy<reference_existing_object>())
		.def("appendChild", pure_virtual(&IO2GValueMap::appendChild))
		;

	class_<IO2GRequestFactoryWrap, bases<IAddRef>, boost::noncopyable>("IO2GRequestFactory", no_init)
		.def("getTimeFrameCollection", pure_virtual(&IO2GRequestFactory::getTimeFrameCollection), return_value_policy<reference_existing_object>())
		.def("createMarketDataSnapshotRequestInstrument", pure_virtual(&IO2GRequestFactory::createMarketDataSnapshotRequestInstrument),
			(arg("instrument"), arg("timeFrame"), arg("maxBar") = 300), return_value_policy<reference_existing_object>())
		.def("fillMarketDataSnapshotRequestTime", pure_virtual(&IO2GRequestFactory::fillMarketDataSnapshotRequestTime),
			(arg("request"), arg("timeFrom") = 0, arg("timeTo") = 0, arg("isIncludeWeekends") = false))
		.def("createRefreshTableRequest", pure_virtual(&IO2GRequestFactory::createRefreshTableRequest), return_value_policy<reference_existing_object>())
		.def("createRefreshTableRequestByAccount", pure_virtual(&IO2GRequestFactory::createRefreshTableRequestByAccount), return_value_policy<reference_existing_object>())
		.def("createOrderRequest", pure_virtual(&IO2GRequestFactory::createOrderRequest), return_value_policy<reference_existing_object>())
		.def("createValueMap", pure_virtual(&IO2GRequestFactory::createValueMap), return_value_policy<reference_existing_object>())
		.def("getLastError", pure_virtual(&IO2GRequestFactory::getLastError))

		;
};