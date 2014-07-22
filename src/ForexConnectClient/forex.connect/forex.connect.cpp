// forex.connect.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "forex.connect.h"

void export_AccountsColumnsEnum();

BOOST_PYTHON_MODULE(forexconnect)
{
	void export_AccountsColumnsEnum();
	void export_TradesColumnsEnum();
}



//// This is an example of an exported variable
//FOREXCONNECT_API int nforexconnect=0;
//
//// This is an example of an exported function.
//FOREXCONNECT_API int fnforexconnect(void)
//{
//	return 42;
//}
//
//// This is the constructor of a class that has been exported.
//// see forex.connect.h for the class definition
//Cforexconnect::Cforexconnect()
//{
//	return;
//}
