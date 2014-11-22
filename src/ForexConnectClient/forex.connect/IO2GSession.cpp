#include "stdafx.h"
#include "SessionStatusListener.h"
#include <IO2GSession.h>
using namespace boost::python;

class IO2GSessionDescriptorWrap : public IO2GSessionDescriptor, public wrapper < IO2GSessionDescriptor >
{
public:
	const char* getID(){ return this->get_override("getID")(); }
	const char* getName(){ return this->get_override("getName")(); }
	const char* getDescription(){ return this->get_override("getDescription")(); }
	bool requiresPin(){ return this->get_override("requiresPin")(); }
};

class IO2GSessionDescriptorCollectionWrap : public IO2GSessionDescriptorCollection, public wrapper < IO2GSessionDescriptorCollection >
{
public:
	int size(){ return this->get_override("size")(); }
	IO2GSessionDescriptor* get(int){ return this->get_override("get")(); }
};

class IO2GSessionStatusWrap : public IO2GSessionStatus, public wrapper < IO2GSessionStatus >
{
public:
	void onSessionStatusChanged(O2GSessionStatus status){ this->get_override("onSessionStatusChanged")(); }
	void onLoginFailed(const char *error){ this->get_override("onLoginFailed")(); }
};

class IO2GTableManagerListenerWrap : public IO2GTableManagerListener, public wrapper < IO2GTableManagerListener >
{
public:
	void onStatusChanged(O2GTableManagerStatus status, IO2GTableManager *tableManager){ this->get_override("onStatusChanged")(); }
};

class IO2GSessionWrap : public IO2GSession, public wrapper < IO2GSession >
{
public:
	IO2GLoginRules* getLoginRules(){ return this->get_override("getLoginRules")();}
	void login(const char *user, const char *pwd, const char *url, const char *connection){  this->get_override("login")();}
	void logout(){ this->get_override("logout")();}
	void subscribeSessionStatus(IO2GSessionStatus* listener){ this->get_override("subscribeSessionStatus")(); }
	void unsubscribeSessionStatus(IO2GSessionStatus* listener){ this->get_override("unsubscribeSessionStatus")(); }
	IO2GSessionDescriptorCollection* getTradingSessionDescriptors(){ return this->get_override("getTradingSessionDescriptors")();}
	void setTradingSession(const char *sessionId, const char *pin){ this->get_override("setTradingSession")();}
	void subscribeResponse(IO2GResponseListener *listener){ this->get_override("subscribeResponse")();}
	void unsubscribeResponse(IO2GResponseListener *listener){ this->get_override("unsubscribeResponse")();}
	IO2GRequestFactory* getRequestFactory(){ return this->get_override("getRequestFactory")();}
	IO2GResponseReaderFactory* getResponseReaderFactory(){ return this->get_override("getResponseReaderFactory")();}
	void sendRequest(IO2GRequest *request){ this->get_override("sendRequest")();}
	IO2GTimeConverter* getTimeConverter(){ return this->get_override("getTimeConverter")();}
	void setPriceUpdateMode(O2GPriceUpdateMode mode){ this->get_override("setPriceUpdateMode")();}
	O2GPriceUpdateMode getPriceUpdateMode(){ return this->get_override("getPriceUpdateMode")();}
	DATE getServerTime(){ return this->get_override("getServerTime")();}
	int getReportURL(char* urlBuffer, int bufferSize, IO2GAccountRow* account, DATE dateFrom, DATE dateTo, 
		const char* format, const char* reportType, const char* langID, long ansiCP){ return this->get_override("getReportURL")();}
	IO2GTableManager* getTableManager() { return this->get_override("getTableManager")(); }
	IO2GTableManager* getTableManagerByAccount(const char *accountID) { return this->get_override("getTableManagerByAccount")(); }
	void useTableManager(O2GTableManagerMode mode, IO2GTableManagerListener *tablesListener) { this->get_override("useTableManager")(); }
	IO2GSessionStatus::O2GSessionStatus getSessionStatus() { return this->get_override("getSessionStatus")(); }
};

class SessionStatusListenerCallback : public SessionStatusListener
{
public:
	SessionStatusListenerCallback(PyObject *pyObject)
		: self(pyObject) {}

	SessionStatusListenerCallback(PyObject* pyObject, const SessionStatusListener& listener)
		: self(pyObject), SessionStatusListener(listener) {}

	void onSessionStatusChanged(O2GSessionStatus status)
	{
		PyGILState_STATE gstate;
		gstate = PyGILState_Ensure();
		call_method<void>(self, "onSessionStatusChanged", status);
		PyGILState_Release(gstate);
	}
	
	void onLoginFailed(const char* error)
	{
		PyGILState_STATE gstate;
		gstate = PyGILState_Ensure();
		call_method<void>(self, "onLoginFailed", error);
		PyGILState_Release(gstate);
	}

	long addRef()
	{
		PyGILState_STATE gstate;
		gstate = PyGILState_Ensure();
		long refCount = call_method<long>(self, "addRef");
		PyGILState_Release(gstate);
		return refCount;
	}

	long release()
	{
		PyGILState_STATE gstate;
		gstate = PyGILState_Ensure();
		long refCount = call_method<long>(self, "release");
		PyGILState_Release(gstate);
		return refCount;
	}

private:
	PyObject* const self;
};

void export_IO2GSession()
{
	class_<IO2GSessionDescriptorWrap, bases<IAddRef>, boost::noncopyable>("IO2GSessionDescriptor", no_init)
		.def("getID", pure_virtual(&IO2GSessionDescriptor::getID))
		.def("getName", pure_virtual(&IO2GSessionDescriptor::getName))
		.def("getDescription", pure_virtual(&IO2GSessionDescriptor::getDescription))
		.def("requiresPin", pure_virtual(&IO2GSessionDescriptor::requiresPin))
		;

	class_<IO2GSessionDescriptorCollectionWrap, bases<IAddRef>, boost::noncopyable>("IO2GSessionDescriptorCollection", no_init)
		.def("size", pure_virtual(&IO2GSessionDescriptorCollection::size))
		.def("get", pure_virtual(&IO2GSessionDescriptorCollection::get), return_value_policy<reference_existing_object>())
		;

	object obj_IO2GSessionStatus = class_<IO2GSessionStatusWrap, bases<IAddRef>, boost::noncopyable>("IO2GSessionStatus", no_init)
		.def("onSessionStatusChanged", pure_virtual(&IO2GSessionStatus::onSessionStatusChanged))
		.def("onLoginFailed", pure_virtual(&IO2GSessionStatus::onLoginFailed))
		;
	{
		scope in_IO2GSessionStatus(obj_IO2GSessionStatus);
		enum_<IO2GSessionStatus::O2GSessionStatus>("O2GSessionStatus")
			.value("Disconnected", IO2GSessionStatus::Disconnected)
			.value("Connecting", IO2GSessionStatus::Connecting)
			.value("TradingSessionRequested", IO2GSessionStatus::TradingSessionRequested)
			.value("Connected", IO2GSessionStatus::Connected)
			.value("Reconnecting", IO2GSessionStatus::Reconnecting)
			.value("Disconnecting", IO2GSessionStatus::Disconnecting)
			.value("SessionLost", IO2GSessionStatus::SessionLost)
			.value("PriceSessionReconnecting", IO2GSessionStatus::PriceSessionReconnecting)
			.value("ConnectedWithNeedToChangePassword", IO2GSessionStatus::ConnectedWithNeedToChangePassword)
			.export_values()
			;
	};

	class_<SessionStatusListener, SessionStatusListenerCallback, bases<IO2GSessionStatus>, boost::noncopyable >("SessionStatusListener", init<>())
		.def("onSessionStatusChanged", &SessionStatusListenerCallback::onSessionStatusChanged)
		.def("onLoginFailed", &SessionStatusListenerCallback::onLoginFailed)
		.def("addRef", &SessionStatusListenerCallback::addRef)
		.def("release", &SessionStatusListenerCallback::release)
		;

	class_<IO2GTableManagerListenerWrap, bases<IAddRef>, boost::noncopyable>("IO2GTableManagerListener", no_init)
		.def("onStatusChanged", pure_virtual(&IO2GTableManagerListener::onStatusChanged))
		;

	class_<IO2GSessionWrap, bases<IAddRef>, boost::noncopyable>("IO2GSession", no_init)
		.def("getLoginRules", pure_virtual(&IO2GSession::getLoginRules), return_value_policy<reference_existing_object>())
		.def("login", pure_virtual(&IO2GSession::login))
		.def("logout", pure_virtual(&IO2GSession::logout))
		.def("subscribeSessionStatus", pure_virtual(&IO2GSession::subscribeSessionStatus))
		.def("unsubscribeSessionStatus", pure_virtual(&IO2GSession::unsubscribeSessionStatus))
		.def("getTradingSessionDescriptors", pure_virtual(&IO2GSession::getTradingSessionDescriptors), return_value_policy<reference_existing_object>())
		.def("setTradingSession", pure_virtual(&IO2GSession::setTradingSession))
		.def("subscribeResponse", pure_virtual(&IO2GSession::subscribeResponse))
		.def("unsubscribeResponse", pure_virtual(&IO2GSession::unsubscribeResponse))
		.def("getRequestFactory", pure_virtual(&IO2GSession::getRequestFactory), return_value_policy<reference_existing_object>())
		.def("getResponseReaderFactory", pure_virtual(&IO2GSession::getResponseReaderFactory), return_value_policy<reference_existing_object>())
		.def("sendRequest", pure_virtual(&IO2GSession::sendRequest))
		.def("getTimeConverter", pure_virtual(&IO2GSession::getTimeConverter), return_value_policy<reference_existing_object>())
		.def("setPriceUpdateMode", pure_virtual(&IO2GSession::setPriceUpdateMode))
		.def("getPriceUpdateMode", pure_virtual(&IO2GSession::getPriceUpdateMode))
		.def("getServerTime", pure_virtual(&IO2GSession::getServerTime))
		.def("getReportURL", pure_virtual(&IO2GSession::getReportURL))
		.def("getTableManager", pure_virtual(&IO2GSession::getTableManager), return_value_policy<reference_existing_object>())
		.def("getTableManagerByAccount", pure_virtual(&IO2GSession::getTableManagerByAccount), return_value_policy<reference_existing_object>())
		.def("useTableManager", pure_virtual(&IO2GSession::useTableManager))
		.def("getSessionStatus", pure_virtual(&IO2GSession::getSessionStatus))
		;
};