#include "stdafx.h"
#include <O2G2ptr.h>
#include <IO2GSession.h>

using namespace boost::python;

class IO2GSessionPtr : public O2G2Ptr < IO2GSession >
{
};

class IO2GLoginRulesPtr : public O2G2Ptr < IO2GLoginRules >
{
};

class IO2GAccountRowPtr : public O2G2Ptr<IO2GAccountRow> {};

void export_O2G2PteredClasses()
{
	class_<IO2GSessionPtr, bases<O2G2Ptr<IO2GSession>>>("IO2GSessionPtr", init<>())
		.def(init<IO2GSessionPtr>())
		.def("release", &IO2GSessionPtr::Release)
		.def("detach", (IO2GSession*(IO2GSessionPtr::*)())(&IO2GSessionPtr::Detach), return_value_policy<reference_existing_object>())
		.def("assign", &IO2GSessionPtr::operator=, return_value_policy<reference_existing_object>())
		.def("__eq__", &IO2GSessionPtr::operator==)
		.def("__lt__", &IO2GSessionPtr::operator<)
		.def("__not__", &IO2GSessionPtr::operator!)
		;
	class_<IO2GAccountRowPtr, bases<O2G2Ptr<IO2GAccountRow>>>("IO2GAccountRowPtr", init<>())
		.def(init<IO2GAccountRowPtr>())
		.def("release", &IO2GAccountRowPtr::Release)
		.def("detach", (IO2GAccountRow*(IO2GAccountRowPtr::*)())(&IO2GAccountRowPtr::Detach), return_value_policy<reference_existing_object>())
		.def("assign", &IO2GAccountRowPtr::operator=, return_value_policy<reference_existing_object>())
		.def("__eq__", &IO2GAccountRowPtr::operator==)
		.def("__lt__", &IO2GAccountRowPtr::operator<)
		.def("__not__", &IO2GAccountRowPtr::operator!)
		;
};
