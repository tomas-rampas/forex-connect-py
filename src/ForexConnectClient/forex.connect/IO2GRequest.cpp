#include "stdafx.h"
#include <IO2GRequest.h>

using namespace boost::python;

class IO2GRequestWrap : public IO2GRequest, public wrapper<IO2GRequest>
{
public :
	const char* getRequestID(){ return this->get_override("getRequestID")();}
	int getChildrenCount(){ return this->get_override("getChildrenCount")();}
	IO2GRequest* getChildRequest(int){ return this->get_override("getChildRequest")();}
};

class IO2GValueMapWrap : public IO2GValueMap, public wrapper < IO2GValueMap >
{

};

class IO2GRequestFactoryWrap : public IO2GRequestFactory, public wrapper < IO2GRequestFactory > 
{

};

void export_IO2GRequest()
{
	class_<IO2GRequestWrap, bases<IAddRef>, boost::noncopyable>("IO2GRequest", no_init)
		.def("getRequestID", pure_virtual(&IO2GRequest::getRequestID))
		.def("getChildrenCount", pure_virtual(&IO2GRequest::getChildrenCount))
		.def("getChildRequest", pure_virtual(&IO2GRequest::getChildRequest), return_value_policy<reference_existing_object>())
		;

	class_<IO2GValueMapWrap, bases<IAddRef>, boost::noncopyable>("IO2GValueMap", no_init)
		;

	class_<IO2GRequestFactoryWrap, bases<IAddRef>, boost::noncopyable>("IO2GRequestFactory", no_init)
		;
};