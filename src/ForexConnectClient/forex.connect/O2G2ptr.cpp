#include "stdafx.h"
#include <O2G2ptr.h>
#include <IO2GSession.h>

using namespace boost::python;

class IO2GSessionPtr: public O2G2Ptr<IO2GSession>
{
};

void export_O2G2PteredClasses()
{
	class_<IO2GSessionPtr>("IO2GSessionPtr", init<>())
		.def("Release", &IO2GSessionPtr::Release)
		.def("Detach", (IO2GSession*(IO2GSessionPtr::*)())(&IO2GSessionPtr::Detach), return_value_policy<reference_existing_object>())
		;
};
