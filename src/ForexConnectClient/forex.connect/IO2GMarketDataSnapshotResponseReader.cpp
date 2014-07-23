#include "stdafx.h"
#include <Readers\IO2GMarketDataSnapshotResponseReader.h>

using namespace boost::python;

class IO2GMarketDataSnapshotResponseReaderWrap : public IO2GMarketDataSnapshotResponseReader, public wrapper < IO2GMarketDataSnapshotResponseReader >
{
public:
	bool isBar() { return this->get_override("isBar")(); }
	int size() { return this->get_override("size")(); }
	DATE getDate(int) { return this->get_override("getDate")(); }
	double getBid(int) { return this->get_override("getBid")(); }
	double getAsk(int) { return this->get_override("getAsk")(); }
	double getBidOpen(int) { return this->get_override("getBidOpen")(); }
	double getBidHigh(int) { return this->get_override("getBidHigh")(); }
	double getBidLow(int) { return this->get_override("getBidLow")(); }
	double getBidClose(int) { return this->get_override("getBidClose")(); }
	double getAskOpen(int) { return this->get_override("getAskOpen")(); }
	double getAskHigh(int) { return this->get_override("getAskHigh")(); }
	double getAskLow(int) { return this->get_override("getAskLow")(); }
	double getAskClose(int) { return this->get_override("getAskClose")(); }
	int getVolume(int) { return this->get_override("getVolume")(); }
	int getLastBarVolume() { return this->get_override("getLastBarVolume")(); }
	DATE getLastBarTime() { return this->get_override("getLastBarTime")(); }
};

void export_IO2GMarketDataSnapshotResponseReader()
{
	class_<IO2GMarketDataSnapshotResponseReaderWrap, boost::noncopyable>("IO2GMarketDataSnapshotResponseReader", no_init)
		.def("isBar", pure_virtual(&IO2GMarketDataSnapshotResponseReader::isBar))
		.def("size", pure_virtual(&IO2GMarketDataSnapshotResponseReader::size))
		.def("getDate", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getDate))
		.def("getBid", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getBid))
		.def("getAsk", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getAsk))
		.def("getBidOpen", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getBidOpen))
		.def("getBidHigh", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getBidHigh))
		.def("getBidLow", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getBidLow))
		.def("getBidClose", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getBidClose))
		.def("getAskOpen", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getAskOpen))
		.def("getAskHigh", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getAskHigh))
		.def("getAskLow", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getAskLow))
		.def("getAskClose", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getAskClose))
		.def("getVolume", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getVolume))
		.def("getLastBarVolume", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getLastBarVolume))
		.def("getLastBarTime", pure_virtual(&IO2GMarketDataSnapshotResponseReader::getLastBarTime))
		;
}