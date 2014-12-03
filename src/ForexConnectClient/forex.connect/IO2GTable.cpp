#include "stdafx.h"
#include <IO2GTable.h>
#include "TableListener.h"
using namespace boost::python;

class IO2GGenericTableResponseReaderWrap : public IO2GGenericTableResponseReader, public wrapper < IO2GGenericTableResponseReader >
{
	int size(){ return this->get_override("size")(); }
	IO2GTableColumnCollection* columns(){ return this->get_override("columns")(); }
	const void* getCell(int row, int column){ return this->get_override("getCell")(); }
	bool isCellValid(int row, int column){ return this->get_override("isCellValid")(); }
	O2GTable getType(){ return this->get_override("getType")(); }
	IO2GRow* getGenericRow(int rowIndex){ return this->get_override("getGenericRow")(); }
};

void export_IO2GGenericTableResponseReader()
{
	class_<IO2GGenericTableResponseReaderWrap, bases<IAddRef>, boost::noncopyable>("IO2GGenericTableResponseReader", no_init)
		.def("size", pure_virtual(&IO2GGenericTableResponseReader::size))
		.def("columns", pure_virtual(&IO2GGenericTableResponseReader::columns), return_value_policy<reference_existing_object>())
		.def("getCell", pure_virtual((PyObject*(IO2GGenericTableResponseReader::*)(int, int))(&IO2GGenericTableResponseReader::getCell)))
		.def("isCellValid", pure_virtual(&IO2GGenericTableResponseReader::isCellValid))
		.def("getType", pure_virtual(&IO2GGenericTableResponseReader::getType))
		.def("getGenericRow", pure_virtual(&IO2GGenericTableResponseReader::getGenericRow), return_value_policy<reference_existing_object>())
		;
};

class IO2GOffersTableResponseReaderWrap : public IO2GOffersTableResponseReader, public wrapper < IO2GOffersTableResponseReader >
{
public:
	IO2GOfferRow* getRow(int index){ return this->get_override("getRow")(); }
};

void export_IO2GOffersTableResponseReader()
{
	class_<IO2GOffersTableResponseReaderWrap, bases<IO2GGenericTableResponseReader>, boost::noncopyable>("IO2GOffersTableResponseReader", no_init)
		.def("getRow", pure_virtual(&IO2GOffersTableResponseReader::getRow), return_value_policy<reference_existing_object>())
		;
};

class IO2GAccountsTableResponseReaderWrap : public IO2GAccountsTableResponseReader, public wrapper < IO2GAccountsTableResponseReader >
{
public:
	IO2GAccountRow* getRow(int index){ return this->get_override("getRow")(); }
};

void export_IO2GAccountsTableResponseReader()
{
	class_<IO2GAccountsTableResponseReaderWrap, bases<IO2GGenericTableResponseReader>, boost::noncopyable>("IO2GAccountsTableResponseReader", no_init)
		.def("getRow", pure_virtual(&IO2GAccountsTableResponseReader::getRow), return_value_policy<reference_existing_object>())
		;
};

class IO2GOrdersTableResponseReaderWrap : public IO2GOrdersTableResponseReader, public wrapper < IO2GOrdersTableResponseReader >
{
public:
	IO2GOrderRow* getRow(int index){ return this->get_override("getRow")(); }
};

void export_IO2GOrdersTableResponseReader()
{
	class_<IO2GOrdersTableResponseReaderWrap, bases<IO2GGenericTableResponseReader>, boost::noncopyable>("IO2GOrdersTableResponseReader", no_init)
		.def("getRow", pure_virtual(&IO2GOrdersTableResponseReader::getRow), return_value_policy<reference_existing_object>())
		;
};

class IO2GTradesTableResponseReaderWrap : public IO2GTradesTableResponseReader, public wrapper < IO2GTradesTableResponseReader >
{
public:
	IO2GTradeRow* getRow(int index){ return this->get_override("getRow")(); }
};

void export_IO2GTradesTableResponseReader()
{
	class_<IO2GTradesTableResponseReaderWrap, bases<IO2GGenericTableResponseReader>, boost::noncopyable>("IO2GTradesTableResponseReader", no_init)
		.def("getRow", pure_virtual(&IO2GTradesTableResponseReader::getRow), return_value_policy<reference_existing_object>())
		;
};

//IO2GClosedTradesTableResponseReader
class IO2GClosedTradesTableResponseReaderWrap : public IO2GClosedTradesTableResponseReader, public wrapper < IO2GClosedTradesTableResponseReader >
{
public:
	IO2GClosedTradeRow* getRow(int index){ return this->get_override("getRow")(); }
};

void export_IO2GClosedTradesTableResponseReader()
{
	class_<IO2GClosedTradesTableResponseReaderWrap, bases<IO2GGenericTableResponseReader>, boost::noncopyable>("IO2GClosedTradesTableResponseReader", no_init)
		.def("getRow", pure_virtual(&IO2GClosedTradesTableResponseReader::getRow), return_value_policy<reference_existing_object>())
		;
};

//IO2GMessagesTableResponseReader
class IO2GMessagesTableResponseReaderWrap : public IO2GMessagesTableResponseReader, public wrapper < IO2GMessagesTableResponseReader >
{
public:
	IO2GMessageRow* getRow(int index){ return this->get_override("getRow")(); }
};

void export_IO2GMessagesTableResponseReader()
{
	class_<IO2GMessagesTableResponseReaderWrap, bases<IO2GGenericTableResponseReader>, boost::noncopyable>("IO2GMessagesTableResponseReader", no_init)
		.def("getRow", pure_virtual(&IO2GMessagesTableResponseReader::getRow), return_value_policy<reference_existing_object>())
		;
};

//IO2GTableIterator
void export_IO2GTableIterator(){
	class_<IO2GTableIterator>("IO2GTableIterator", init<>())
		.def("reset", &IO2GTableIterator::reset)
	;
};

//IO2GTableListener
class IO2GTableListenerWrap : public IO2GTableListener, public wrapper < IO2GTableListener >
{
public:
	void onAdded(const char *rowID, IO2GRow *rowData){ this->get_override("onAdded")();}
	void onChanged(const char *rowID, IO2GRow *rowData){ this->get_override("onChanged")();}
	void onDeleted(const char *rowID, IO2GRow *rowData){ this->get_override("onDeleted")();}
	void onStatusChanged(O2GTableStatus status) { this->get_override("onStatusChanged")();}
};

//IO2GEachRowListener
class IO2GEachRowListenerWrap : public IO2GEachRowListener, public wrapper<IO2GEachRowListener>
{
public:
	void onEachRow(const char *rowID, IO2GRow *rowData){ this->get_override("onEachRow")();}
};

void export_IO2GTableListener()
{
	class_<IO2GTableListenerWrap, bases<IAddRef>, boost::noncopyable>("IO2GTableListener", no_init)
		.def("onAdded", pure_virtual(&IO2GTableListener::onAdded))
		.def("onChanged", pure_virtual(&IO2GTableListener::onChanged))
		.def("onDeleted", pure_virtual(&IO2GTableListener::onDeleted))
		.def("onStatusChanged", pure_virtual(&IO2GTableListener::onStatusChanged))
		;

	class_<TableListener, TableListenerImpl, bases<IO2GTableListener>, boost::noncopyable>("TableListener", init<>())
		//.def(init<TableListener>())
		.def("onAdded", &TableListenerImpl::onAdded)
		.def("onChanged", &TableListenerImpl::onChanged)
		.def("onDeleted", &TableListenerImpl::onDeleted)
		.def("onStatusChanged", &TableListenerImpl::onStatusChanged)
		.def("addRef", &TableListenerImpl::addRef)
		.def("release", &TableListenerImpl::release)
		;

	class_<IO2GEachRowListenerWrap, bases<IAddRef>, boost::noncopyable>("IO2GEachRowListener", no_init)
		.def("onEachRow", pure_virtual(&IO2GEachRowListener::onEachRow))
		;
};

//IO2GTable
class IO2GTableWrap : public IO2GTable, public wrapper<IO2GTable>
{
public:
	void subscribeUpdate(O2GTableUpdateType updateType, IO2GTableListener *listener){ this->get_override("subscribeUpdate")();}
	void unsubscribeUpdate(O2GTableUpdateType updateType, IO2GTableListener *listener){ this->get_override("unsubscribeUpdate")();}
	void subscribeStatus(IO2GTableListener *listener){ this->get_override("subscribeStatus")();}
	void unsubscribeStatus(IO2GTableListener *listener){ this->get_override("unsubscribeStatus")();}
	O2GTableStatus getStatus(){ return this->get_override("getStatus")();}
	void forEachRow(IO2GEachRowListener *listener){ this->get_override("forEachRow")();}
	bool isCellChanged(int row, int column){ return this->get_override("isCellChanged")();}
	bool getNextGenericRow(IO2GTableIterator &iterator, IO2GRow *&row){ return this->get_override("getNextGenericRow")();}
	bool getNextGenericRowByColumnValue(const char *columnID, const void *columnValueAsVariant, IO2GTableIterator &iterator, IO2GRow *&row)
	{ return this->get_override("getNextGenericRowByColumnValue")();}
	bool getNextGenericRowByMultiColumnValues(const int columnCount, const char *columnNames[], const void *columnValues[], IO2GTableIterator &iterator, IO2GRow *&row)
	{ return this->get_override("getNextGenericRowByMultiColumnValues")();}
	bool getNextGenericRowByColumnValues(const char *columnName, const int valueCount, const void *columnValues[], IO2GTableIterator &iterator, IO2GRow *&row)
	{ return this->get_override("getNextGenericRowByColumnValues")();}
};

void export_IO2GTable()
{
	class_<IO2GTableWrap, bases<IO2GGenericTableResponseReader>, boost::noncopyable>("IO2GTable", no_init)
		.def("subscribeUpdate", pure_virtual(&IO2GTable::subscribeUpdate))
		.def("unsubscribeUpdate", pure_virtual(&IO2GTable::unsubscribeUpdate))
		.def("subscribeStatus", pure_virtual(&IO2GTable::subscribeStatus))
		.def("unsubscribeStatus", pure_virtual(&IO2GTable::unsubscribeStatus))
		.def("getStatus", pure_virtual(&IO2GTable::getStatus))
		.def("forEachRow", pure_virtual(&IO2GTable::forEachRow))
		.def("isCellChanged", pure_virtual(&IO2GTable::isCellChanged))
		.def("getNextGenericRow", pure_virtual(&IO2GTable::getNextGenericRow))
		.def("getNextGenericRowByColumnValue", pure_virtual(&IO2GTable::getNextGenericRowByColumnValue))
		.def("getNextGenericRowByMultiColumnValues", pure_virtual(&IO2GTable::getNextGenericRowByMultiColumnValues))
		.def("getNextGenericRowByColumnValues", pure_virtual(&IO2GTable::getNextGenericRowByColumnValues))
		;
};

//IO2GTableManager
class IO2GTableManagerWrap : public IO2GTableManager, public wrapper<IO2GTableManager>
{
public:
	IO2GTable* getTable(O2GTable tableType){ return this->get_override("getTable")();}
	O2GTableManagerStatus getStatus(){ return this->get_override("getStatus")();}
	void lockUpdates(){ this->get_override("lockUpdates")();}
	void unlockUpdates(){ this->get_override("unlockUpdates")();}
};

void export_IO2GTableManager()
{
	class_<IO2GTableManagerWrap, bases<IAddRef>, boost::noncopyable>("IO2GTableManager", no_init)
		.def("getTable", pure_virtual(&IO2GTableManager::getTable), return_value_policy<reference_existing_object>())
		.def("getStatus", pure_virtual(&IO2GTableManager::getStatus))
		.def("lockUpdates", pure_virtual(&IO2GTableManager::lockUpdates))
		.def("unlockUpdates", pure_virtual(&IO2GTableManager::unlockUpdates))
		;
};

//IO2GOffersTable
class IO2GOffersTableWrap : public IO2GOffersTable, public wrapper<IO2GOffersTable>
{
public:
	IO2GOfferTableRow* getRow(int index){ return this->get_override("getRow")();}
	bool getNextRow(IO2GTableIterator &iterator, IO2GOfferTableRow *&row){ return this->get_override("getNextRow")();}
	bool getNextRowByColumnValue(const char *columnID, const void *columnValueAsVariant, IO2GTableIterator &iterator, IO2GOfferTableRow *&row)
	{ return this->get_override("getNextRowByColumnValue")();}
	bool findRow(const char *id, IO2GOfferTableRow *&row){ return this->get_override("findRow")();}
	bool getNextRowByMultiColumnValues(const int columnCount, const char *columnNames[], const void *columnValues[], IO2GTableIterator &iterator, IO2GOfferTableRow *&row)
	{ return this->get_override("getNextRowByMultiColumnValues")();}
	bool getNextRowByColumnValues(const char *columnName, const int valueCount, const void *columnValues[], IO2GTableIterator &iterator, IO2GOfferTableRow *&row)
	{ return this->get_override("getNextRowByColumnValues")();} 
	void subscribeUpdate(O2GTableUpdateType updateType, IO2GTableListener *listener)
	{ 		
		this->get_override("subscribeUpdate")(); 
	}
};

class IO2GOffersTableCallable : public IO2GOffersTableWrap
{
public:
	IO2GOffersTableCallable(PyObject* obj, IO2GOffersTableWrap& table) :self(obj), IO2GOffersTableWrap(table){}

	static IO2GOfferTableRow* getNextRow(IO2GOffersTable& self_, IO2GTableIterator &iterator)
	{
		IO2GOfferTableRow *offerRow = NULL;
		bool ret = self_.getNextRow(iterator, offerRow);
		return offerRow;
	}

	static IO2GOfferTableRow* findRow(IO2GOffersTable& self_, const char* id)
	{
		IO2GOfferTableRow *offerRow = NULL;
		bool ret = self_.findRow(id, offerRow);
		return offerRow;
	}

private:
	PyObject* const self;
};

void export_IO2GOffersTable()
{
	class_<IO2GOffersTableWrap, IO2GOffersTableCallable, bases<IO2GTable>, boost::noncopyable>("IO2GOffersTable", no_init)
		.def("getRow", pure_virtual(&IO2GOffersTable::getRow), return_value_policy<reference_existing_object>())
		.def("getNextRow", &IO2GOffersTableCallable::getNextRow, return_value_policy<reference_existing_object>())
		.def("getNextRowByColumnValue", pure_virtual(&IO2GOffersTable::getNextRowByColumnValue))
		.def("findRow", &IO2GOffersTableCallable::findRow, return_value_policy<reference_existing_object>())
		.def("getNextRowByMultiColumnValues", pure_virtual(&IO2GOffersTable::getNextRowByMultiColumnValues))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GOffersTable::getNextRowByColumnValue))
		.def("subscribeUpdate", pure_virtual(&IO2GOffersTable::subscribeUpdate))
		;

};

//IO2GAccountsTable
class IO2GAccountsTableWrap : public IO2GAccountsTable, public wrapper<IO2GAccountsTable>
{
public:
	IO2GAccountTableRow* getRow(int index){ return this->get_override("getRow")();}
	bool getNextRow(IO2GTableIterator &iterator, IO2GAccountTableRow *&row){ return this->get_override("getNextRow")();}
	bool getNextRowByColumnValue(const char *columnID, const void *columnValueAsVariant, IO2GTableIterator &iterator, IO2GAccountTableRow *&row)
	{ return this->get_override("getNextRowByColumnValue")();}
	bool findRow(const char *id, IO2GAccountTableRow *&row){ return this->get_override("findRow")();}
	bool getNextRowByMultiColumnValues(const int columnCount, const char *columnNames[], const void *columnValues[], IO2GTableIterator &iterator, IO2GAccountTableRow *&row)
	{ return this->get_override("getNextRowByMultiColumnValues")();}
	bool getNextRowByColumnValues(const char *columnName, const int valueCount, const void *columnValues[], IO2GTableIterator &iterator, IO2GAccountTableRow *&row)
	{ return this->get_override("getNextRowByColumnValues")();}
};

void export_IO2GAccountsTable()
{
	class_<IO2GAccountsTableWrap, bases<IO2GTable>, boost::noncopyable>("IO2GAccountsTable", no_init)
		.def("getRow", pure_virtual(&IO2GAccountsTable::getRow), return_value_policy<reference_existing_object>())
		.def("getNextRow", pure_virtual(&IO2GAccountsTable::getNextRow))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GAccountsTable::getNextRowByColumnValue))
		.def("findRow", pure_virtual(&IO2GAccountsTable::findRow))
		.def("getNextRowByMultiColumnValues", pure_virtual(&IO2GAccountsTable::getNextRowByMultiColumnValues))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GAccountsTable::getNextRowByColumnValue))
		;
};

//IO2GOrdersTable
class IO2GOrdersTableWrap : public IO2GOrdersTable, public wrapper<IO2GOrdersTable>
{
public:
	virtual IO2GOrderTableRow* getRow(int index) = 0;
	virtual bool getNextRow(IO2GTableIterator &iterator, IO2GOrderTableRow *&row) = 0;
	virtual bool getNextRowByColumnValue(const char *columnID, const void *columnValueAsVariant, IO2GTableIterator &iterator, IO2GOrderTableRow *&row) = 0;
	virtual bool findRow(const char *id, IO2GOrderTableRow *&row) = 0;
	virtual bool getNextRowByMultiColumnValues(const int columnCount, const char *columnNames[], const void *columnValues[], IO2GTableIterator &iterator, IO2GOrderTableRow *&row) = 0;
	virtual bool getNextRowByColumnValues(const char *columnName, const int valueCount, const void *columnValues[], IO2GTableIterator &iterator, IO2GOrderTableRow *&row) = 0;
};

void export_IO2GOrdersTable()
{
	class_<IO2GOrdersTableWrap, bases<IO2GTable>, boost::noncopyable>("IO2GOrdersTable", no_init)
		.def("getRow", pure_virtual(&IO2GOrdersTable::getRow), return_value_policy<reference_existing_object>())
		.def("getNextRow", pure_virtual(&IO2GOrdersTable::getNextRow))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GOrdersTable::getNextRowByColumnValue))
		.def("findRow", pure_virtual(&IO2GOrdersTable::findRow))
		.def("getNextRowByMultiColumnValues", pure_virtual(&IO2GOrdersTable::getNextRowByMultiColumnValues))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GOrdersTable::getNextRowByColumnValue))
		;
};

//IO2GTradesTable
class IO2GTradesTableWrap : public IO2GTradesTable, public wrapper<IO2GTradesTable>
{
public:
	IO2GTradeTableRow* getRow(int index){ return this->get_override("getRow")();}
	bool getNextRow(IO2GTableIterator &iterator, IO2GTradeTableRow *&row){ return this->get_override("getNextRow")();}
	bool getNextRowByColumnValue(const char *columnID, const void *columnValueAsVariant, IO2GTableIterator &iterator, IO2GTradeTableRow *&row)
	{ return this->get_override("getNextRowByColumnValue")();}
	bool findRow(const char *id, IO2GTradeTableRow *&row){ return this->get_override("findRow")();}
	bool getNextRowByMultiColumnValues(const int columnCount, const char *columnNames[], const void *columnValues[], IO2GTableIterator &iterator, IO2GTradeTableRow *&row)
	{ return this->get_override("getNextRowByMultiColumnValues")();}
	bool getNextRowByColumnValues(const char *columnName, const int valueCount, const void *columnValues[], IO2GTableIterator &iterator, IO2GTradeTableRow *&row)
	{ return this->get_override("getNextRowByColumnValues")();}
};

void export_IO2GTradesTable()
{
	class_<IO2GTradesTableWrap, bases<IO2GTable>, boost::noncopyable>("IO2GTradesTable", no_init)
		.def("getRow", pure_virtual(&IO2GTradesTable::getRow), return_value_policy<reference_existing_object>())
		.def("getNextRow", pure_virtual(&IO2GTradesTable::getNextRow))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GTradesTable::getNextRowByColumnValue))
		.def("findRow", pure_virtual(&IO2GTradesTable::findRow))
		.def("getNextRowByMultiColumnValues", pure_virtual(&IO2GTradesTable::getNextRowByMultiColumnValues))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GTradesTable::getNextRowByColumnValue))
		;
};


//IO2GClosedTradesTable
class IO2GClosedTradesTableWrap : public IO2GClosedTradesTable, public wrapper<IO2GClosedTradesTable>
{
public:
	IO2GClosedTradeTableRow* getRow(int index){ return this->get_override("getRow")();}
	bool getNextRow(IO2GTableIterator &iterator, IO2GClosedTradeTableRow *&row){ return this->get_override("getNextRow")();}
	bool getNextRowByColumnValue(const char *columnID, const void *columnValueAsVariant, IO2GTableIterator &iterator, IO2GClosedTradeTableRow *&row)
	{ return this->get_override("getNextRowByColumnValue")();}
	bool findRow(const char *id, IO2GClosedTradeTableRow *&row){ return this->get_override("findRow")();}
	bool getNextRowByMultiColumnValues(const int columnCount, const char *columnNames[], const void *columnValues[], IO2GTableIterator &iterator, IO2GClosedTradeTableRow *&row)
	{ return this->get_override("getNextRowByMultiColumnValues")();}
	bool getNextRowByColumnValues(const char *columnName, const int valueCount, const void *columnValues[], IO2GTableIterator &iterator, IO2GClosedTradeTableRow *&row)
	{ return this->get_override("getNextRowByColumnValues")();}
};

void export_IO2GClosedTradesTable()
{
	class_<IO2GClosedTradesTableWrap, bases<IO2GTable>, boost::noncopyable>("IO2GClosedTradesTable", no_init)
		.def("getRow", pure_virtual(&IO2GClosedTradesTable::getRow), return_value_policy<reference_existing_object>())
		.def("getNextRow", pure_virtual(&IO2GClosedTradesTable::getNextRow))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GClosedTradesTable::getNextRowByColumnValue))
		.def("findRow", pure_virtual(&IO2GClosedTradesTable::findRow))
		.def("getNextRowByMultiColumnValues", pure_virtual(&IO2GClosedTradesTable::getNextRowByMultiColumnValues))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GClosedTradesTable::getNextRowByColumnValue))
		;
};

//IO2GMessagesTable
class IO2GMessagesTableWrap : public IO2GMessagesTable, public wrapper<IO2GMessagesTable>
{
public:
	IO2GMessageTableRow* getRow(int index){ return this->get_override("getRow")();}
	bool getNextRow(IO2GTableIterator &iterator, IO2GMessageTableRow *&row){ return this->get_override("getNextRow")();}
	bool getNextRowByColumnValue(const char *columnID, const void *columnValueAsVariant, IO2GTableIterator &iterator, IO2GMessageTableRow *&row)
	{ return this->get_override("getNextRowByColumnValue")();}
	bool findRow(const char *id, IO2GMessageTableRow *&row){ return this->get_override("findRow")();}
	bool getNextRowByMultiColumnValues(const int columnCount, const char *columnNames[], const void *columnValues[], IO2GTableIterator &iterator, IO2GMessageTableRow *&row)
	{ return this->get_override("getNextRowByMultiColumnValues")();}
	bool getNextRowByColumnValues(const char *columnName, const int valueCount, const void *columnValues[], IO2GTableIterator &iterator, IO2GMessageTableRow *&row)
	{ return this->get_override("getNextRowByColumnValues")();}
};

void export_IO2GMessagesTable()
{
	class_<IO2GMessagesTableWrap, bases<IO2GTable>, boost::noncopyable>("IO2GMessagesTable", no_init)
		.def("getRow", pure_virtual(&IO2GMessagesTable::getRow), return_value_policy<reference_existing_object>())
		.def("getNextRow", pure_virtual(&IO2GMessagesTable::getNextRow))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GMessagesTable::getNextRowByColumnValue))
		.def("findRow", pure_virtual(&IO2GMessagesTable::findRow))
		.def("getNextRowByMultiColumnValues", pure_virtual(&IO2GMessagesTable::getNextRowByMultiColumnValues))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GMessagesTable::getNextRowByColumnValue))
		;
};

//IO2GSummaryTable
class IO2GSummaryTableWrap : public IO2GSummaryTable, public wrapper<IO2GSummaryTable>
{
public:
	IO2GSummaryTableRow* getRow(int index){ return this->get_override("getRow")();}
	bool getNextRow(IO2GTableIterator &iterator, IO2GSummaryTableRow *&row){ return this->get_override("getNextRow")();}
	bool getNextRowByColumnValue(const char *columnID, const void *columnValueAsVariant, IO2GTableIterator &iterator, IO2GSummaryTableRow *&row)
	{ return this->get_override("getNextRowByColumnValue")();}
	bool findRow(const char *id, IO2GSummaryTableRow *&row){ return this->get_override("findRow")();}
	bool getNextRowByMultiColumnValues(const int columnCount, const char *columnNames[], const void *columnValues[], IO2GTableIterator &iterator, IO2GSummaryTableRow *&row)
	{ return this->get_override("getNextRowByMultiColumnValues")();}
	bool getNextRowByColumnValues(const char *columnName, const int valueCount, const void *columnValues[], IO2GTableIterator &iterator, IO2GSummaryTableRow *&row)
	{ return this->get_override("getNextRowByColumnValues")();}
};

void export_IO2GSummaryTable()
{
	class_<IO2GSummaryTableWrap, bases<IO2GTable>, boost::noncopyable>("IO2GSummaryTable", no_init)
		.def("getRow", pure_virtual(&IO2GSummaryTable::getRow), return_value_policy<reference_existing_object>())
		.def("getNextRow", pure_virtual(&IO2GSummaryTable::getNextRow))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GSummaryTable::getNextRowByColumnValue))
		.def("findRow", pure_virtual(&IO2GSummaryTable::findRow))
		.def("getNextRowByMultiColumnValues", pure_virtual(&IO2GSummaryTable::getNextRowByMultiColumnValues))
		.def("getNextRowByColumnValue", pure_virtual(&IO2GSummaryTable::getNextRowByColumnValue))
		;
};
