#include "stdafx.h"
#include <O2G2ptr.h>
#include <IO2GSession.h>

using namespace boost::python;

class IO2GSessionPtr : public O2G2Ptr < IO2GSession >
{
};

void export_O2G2PteredClasses()
{
	class_<IO2GSessionPtr>("IO2GSessionPtr", init<>())
		.def(init<IO2GSessionPtr>())
		.def("release", &IO2GSessionPtr::Release)
		.def("detach", (IO2GSession*(IO2GSessionPtr::*)())(&IO2GSessionPtr::Detach), return_value_policy<reference_existing_object>())
		.def("assign", &IO2GSessionPtr::operator=, return_value_policy<reference_existing_object>())
		.def("__eq__", &IO2GSessionPtr::operator==)
		.def("__lt__", &IO2GSessionPtr::operator<)
		.def("__not__", &IO2GSessionPtr::operator!)
		;
};
