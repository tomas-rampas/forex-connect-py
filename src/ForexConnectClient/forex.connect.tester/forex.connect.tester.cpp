// forex.connect.tester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

int main()
{
	PyImport_AppendInittab("example", &initexample); // Add example to built-in.
	Py_Initialize(); // Start interpreter.

	// Create the __main__ module.
	namespace python = boost::python;
	python::object main = python::import("__main__");
	python::object main_namespace = main.attr("__dict__");

	try
	{
		python::scope scope(main); // Force main scope

		//// Expose TestClass::Color as Color
		//python::enum_<TestClass::Color>("Color")
		//	.value("red", TestClass::red)
		//	.value("blue", TestClass::blue)
		//	;

		//// Print values of Color enumeration.
		//python::exec(
		//	"print Color.values",
		//	main_namespace, main_namespace);

		//// Get a handle to the Color enumeration.
		//python::object color = main_namespace["Color"];
		//python::object blue = color.attr("blue");

		//if (TestClass::blue == python::extract<TestClass::Color>(blue))
		//	std::cout << "blue enum values matched." << std::endl;

		//// Import example module into main namespace.
		//main_namespace["example"] = python::import("example");

		//// Print the values of the Motion enumeration.
		//python::exec(
		//	"print example.Motion.values",
		//	main_namespace, main_namespace);

		//// Check if the Python enums match the C++ enum values.
		//if (TestClass::bike == python::extract<TestClass::Motion>(
		//	main_namespace["example"].attr("Motion").attr("bike")))
		//	std::cout << "bike enum values matched." << std::endl;
	}
	catch (const python::error_already_set&)
	{
		PyErr_Print();
	}
}