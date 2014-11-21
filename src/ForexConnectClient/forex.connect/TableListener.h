#pragma once

using namespace boost::python; 

class TableListener : public IO2GTableListener
{
public:
	virtual void onAdded(const char *rowID, IO2GRow *rowData) = 0;
	virtual void onChanged(const char *rowID, IO2GRow *rowData) = 0;
	virtual void onDeleted(const char *rowID, IO2GRow *rowData) = 0;
	virtual void onStatusChanged(O2GTableStatus status) = 0;
};

class TableListenerImpl : public TableListener 
{
public:
	TableListenerImpl(PyObject* pyObject) : self(pyObject){}
	TableListenerImpl(PyObject* pyObject, const TableListener& listener) : self(pyObject), TableListener(listener){}

	void onAdded(const char *rowID, IO2GRow *rowData) 
	{
		PyGILState_STATE gstate;
		gstate = PyGILState_Ensure();
		call_method<void>(self, "onAdded", rowID, rowData);
		PyGILState_Release(gstate);
	};

	void onChanged(const char *rowID, IO2GRow *rowData)
	{
		PyGILState_STATE gstate;
		gstate = PyGILState_Ensure();
		call_method<void>(self, "onChanged", rowID, rowData);
		PyGILState_Release(gstate);
	};
	void onDeleted(const char *rowID, IO2GRow *rowData)
	{
		PyGILState_STATE gstate;
		gstate = PyGILState_Ensure();
		call_method<void>(self, "onDeleted", rowID, rowData);
		PyGILState_Release(gstate);
	};
	void onStatusChanged(O2GTableStatus status)
	{
		PyGILState_STATE gstate;
		gstate = PyGILState_Ensure();
		call_method<void>(self, "onStatusChanged", status);
		PyGILState_Release(gstate);
	};
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