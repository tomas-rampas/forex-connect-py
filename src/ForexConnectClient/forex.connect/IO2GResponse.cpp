#include "stdafx.h"

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python/args.hpp>
#include <boost/python/tuple.hpp>
#include <boost/python/class.hpp>
#include <boost/python/overloads.hpp>
#include <boost/python/return_internal_reference.hpp>

#include "IO2GResponse.h"

using namespace boost::python;

class IO2GResponseWrap : public IO2GResponse, public wrapper < IO2GResponse >
{
public:
	O2GResponseType getType() {return this->get_override("getType")();}
	const char * getRequestID() { return this->get_override("getRequestID")(); }
};

class IO2GResponseListenerWrap : public IO2GResponseListener, public wrapper < IO2GResponseListener >
{
public:
	void onRequestCompleted(const char * requestId, IO2GResponse* response = 0) { this->get_override("onRequestCompleted")(); }
	void onRequestFailed(const char *, const char *) { this->get_override("onRequestFailed")(); }
	void onTablesUpdates(IO2GResponse *) { this->get_override("onTablesUpdates")(); }	
};


class IO2GResponseReaderFactoryWrap : public IO2GResponseReaderFactory, public wrapper < IO2GResponseReaderFactory >
{
public:
	IO2GTablesUpdatesReader *createTablesUpdatesReader(IO2GResponse *response) = 0;
	IO2GMarketDataSnapshotResponseReader *createMarketDataSnapshotReader(IO2GResponse *response) = 0;
	IO2GMarketDataResponseReader *createMarketDataReader(IO2GResponse *response) = 0;
	IO2GOffersTableResponseReader *createOffersTableReader(IO2GResponse *response) = 0;
	IO2GAccountsTableResponseReader *createAccountsTableReader(IO2GResponse *response) = 0;
	IO2GOrdersTableResponseReader *createOrdersTableReader(IO2GResponse *response) = 0;
	IO2GTradesTableResponseReader *createTradesTableReader(IO2GResponse *response) = 0;
	IO2GClosedTradesTableResponseReader *createClosedTradesTableReader(IO2GResponse *response) = 0;
	IO2GMessagesTableResponseReader *createMessagesTableReader(IO2GResponse *response) = 0;
	IO2GOrderResponseReader *createOrderResponseReader(IO2GResponse *response) = 0;
	IO2GLastOrderUpdateResponseReader *createLastOrderUpdateResponseReader(IO2GResponse *response) = 0;
	IO2GSystemPropertiesReader *createSystemPropertiesReader(IO2GResponse *response) = 0;
	bool processMarginRequirementsResponse(IO2GResponse *response) = 0;	
};

//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(onRequestCompleted_overload, onRequestCompleted, 1, 2)

void export_IO2GResponse()
{	
	
	//void(IO2GResponseListener::*orq)(const char *, IO2GResponse *) = &IO2GResponseListener::onRequestCompleted;

	class_<IO2GResponseWrap, bases<IAddRef>, boost::noncopyable>("IO2GResponse", no_init)
		.def("getType", pure_virtual(&IO2GResponse::getType))
		.def("getRequestID", pure_virtual(&IO2GResponse::getRequestID))
		;
	class_<IO2GResponseListenerWrap, bases<IAddRef>, boost::noncopyable>("IO2GResponseListener", no_init)
		.def("onRequestCompleted", pure_virtual(&IO2GResponseListener::onRequestCompleted), (arg("requestId"), arg("response") = 0))
		//onRequestCompleted_overload(args("requestId", "response"), "doc str"))
		.def("onRequestFailed", pure_virtual(&IO2GResponseListener::onRequestFailed))
		.def("onTablesUpdates", pure_virtual(&IO2GResponseListener::onTablesUpdates))
		;
	class_<IO2GResponseReaderFactoryWrap, bases<IAddRef>, boost::noncopyable > ("IO2GResponseReaderFactory", no_init)
		.def("createTablesUpdatesReader", pure_virtual(&IO2GResponseReaderFactory::createTablesUpdatesReader), return_value_policy<reference_existing_object>())
		.def("createMarketDataSnapshotReader", pure_virtual(&IO2GResponseReaderFactory::createMarketDataSnapshotReader), return_value_policy<reference_existing_object>())
		.def("createMarketDataReader", pure_virtual(&IO2GResponseReaderFactory::createMarketDataReader), return_value_policy<reference_existing_object>())
		.def("createOffersTableReader", pure_virtual(&IO2GResponseReaderFactory::createOffersTableReader), return_value_policy<reference_existing_object>())
		.def("createAccountsTableReader", pure_virtual(&IO2GResponseReaderFactory::createAccountsTableReader), return_value_policy<reference_existing_object>())
		.def("createOrdersTableReader", pure_virtual(&IO2GResponseReaderFactory::createOrdersTableReader), return_value_policy<reference_existing_object>())
		.def("createTradesTableReader", pure_virtual(&IO2GResponseReaderFactory::createTradesTableReader), return_value_policy<reference_existing_object>())
		.def("createClosedTradesTableReader", pure_virtual(&IO2GResponseReaderFactory::createClosedTradesTableReader), return_value_policy<reference_existing_object>())
		.def("createMessagesTableReader", pure_virtual(&IO2GResponseReaderFactory::createMessagesTableReader), return_value_policy<reference_existing_object>())
		.def("createOrderResponseReader", pure_virtual(&IO2GResponseReaderFactory::createOrderResponseReader), return_value_policy<reference_existing_object>())
		.def("createLastOrderUpdateResponseReader", pure_virtual(&IO2GResponseReaderFactory::createLastOrderUpdateResponseReader), return_value_policy<reference_existing_object>())
		.def("createSystemPropertiesReader", pure_virtual(&IO2GResponseReaderFactory::createSystemPropertiesReader), return_value_policy<reference_existing_object>())
		.def("processMarginRequirementsResponse", pure_virtual(&IO2GResponseReaderFactory::processMarginRequirementsResponse))
		;
};