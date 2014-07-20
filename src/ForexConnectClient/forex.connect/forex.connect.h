// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the FOREXCONNECT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// FOREXCONNECT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef FOREXCONNECT_EXPORTS
#define FOREXCONNECT_API __declspec(dllexport)
#else
#define FOREXCONNECT_API __declspec(dllimport)
#endif

// This class is exported from the forex.connect.dll
class FOREXCONNECT_API Cforexconnect {
public:
	Cforexconnect(void);
	// TODO: add your methods here.
};

extern FOREXCONNECT_API int nforexconnect;

FOREXCONNECT_API int fnforexconnect(void);
