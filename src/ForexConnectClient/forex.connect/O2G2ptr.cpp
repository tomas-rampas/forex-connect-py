#include "stdafx.h"
#include <O2G2ptr.h>
#include <IO2GSession.h>

using namespace boost::python;

template<typename T> class O2G2PtrWrap : public O2G2Ptr<T>, public wrapper<O2G2Ptr<T>>{};

class IO2GSessionPtr : public O2G2Ptr < IO2GSession > {};

class IO2GLoginRulesPtr : public O2G2Ptr < IO2GLoginRules > {};

class IO2GSessionDescriptorCollectionPtr : public O2G2Ptr < IO2GSessionDescriptorCollection > {};

class IO2GAccountRowPtr : public O2G2Ptr < IO2GAccountRow > {};

class IO2GTableManagerPtr : public O2G2Ptr < IO2GTableManager > {};

class IO2GOffersTablePtr : public O2G2Ptr < IO2GOffersTable > {};

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
	class_<IO2GSessionDescriptorCollectionPtr, bases<O2G2Ptr<IO2GSessionDescriptorCollection>>>("IO2GSessionDescriptorCollectionPtr", init<>())
		.def(init<IO2GSessionDescriptorCollectionPtr>())
		.def("release", &IO2GSessionDescriptorCollectionPtr::Release)
		.def("detach", (IO2GSessionDescriptorCollection*(IO2GSessionDescriptorCollectionPtr::*)())(&IO2GSessionDescriptorCollectionPtr::Detach), return_value_policy<reference_existing_object>())
		.def("assign", &IO2GSessionDescriptorCollectionPtr::operator=, return_value_policy<reference_existing_object>())
		.def("__eq__", &IO2GSessionDescriptorCollectionPtr::operator==)
		.def("__lt__", &IO2GSessionDescriptorCollectionPtr::operator<)
		.def("__not__", &IO2GSessionDescriptorCollectionPtr::operator!)
		;

	class_<IO2GTableManagerPtr, bases<O2G2Ptr<IO2GTableManager>>>("IO2GTableManagerPtr", init<>())
		.def(init<IO2GTableManagerPtr>())
		.def("release", &IO2GTableManagerPtr::Release)
		.def("detach", (IO2GTableManager*(IO2GTableManagerPtr::*)())(&IO2GTableManagerPtr::Detach), return_value_policy<reference_existing_object>())
		.def("assign", &IO2GTableManagerPtr::operator=, return_value_policy<reference_existing_object>())
		.def("__eq__", &IO2GTableManagerPtr::operator==)
		.def("__lt__", &IO2GTableManagerPtr::operator<)
		.def("__not__", &IO2GTableManagerPtr::operator!)
		;

	class_<IO2GOffersTablePtr, bases<O2G2Ptr<IO2GOffersTable>>>("IO2GOffersTablePtr", init<>())
		.def(init<IO2GOffersTablePtr>())
		.def("release", &IO2GOffersTablePtr::Release)
		.def("detach", (IO2GOffersTable*(IO2GOffersTablePtr::*)())(&IO2GOffersTablePtr::Detach), return_value_policy<reference_existing_object>())
		.def("assign", &IO2GOffersTablePtr::operator=, return_value_policy<reference_existing_object>())
		.def("__eq__", &IO2GOffersTablePtr::operator==)
		.def("__lt__", &IO2GOffersTablePtr::operator<)
		.def("__not__", &IO2GOffersTablePtr::operator!)
		;

};
