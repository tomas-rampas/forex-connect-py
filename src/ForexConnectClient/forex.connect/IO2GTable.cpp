#include "stdafx.h"
#include <IO2GTable.h>
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