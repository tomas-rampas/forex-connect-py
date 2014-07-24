#include "stdafx.h"
#include <IAddRef.h>

using namespace boost::python;

class IAddRefWrap : public IAddRef, public wrapper < IAddRef >
{
public:
	long addRef() { return this->get_override("addRef")(); }
	long release() { return this->get_override("release")(); }
};

void export_IAddRefClass()
{
	class_<IAddRefWrap, boost::noncopyable>("IAddRef", no_init)
		.def("addRef", pure_virtual(&IAddRef::addRef))
		.def("release", pure_virtual(&IAddRef::release))
		;
	typedef double DATE;
}