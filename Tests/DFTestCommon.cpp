//DFramework Test Framework
//	(C)Project Entertainments
//	http://dark-x.net/
//This file and each _Test_.cpp are also licensed to OpenDF.

#include <DFTest.h>

static HANDLE STDOUT = GetStdHandle(STD_OUTPUT_HANDLE);
static CONSOLE_SCREEN_BUFFER_INFO StartupCSBI;
static BOOL B = GetConsoleScreenBufferInfo(STDOUT, &StartupCSBI);
static BOOL DFTotalResult = DFTrue;

DFFunction(void, TestInitialize)(){
	DFTotalResult = DFTrue;
}

DFFunction(void, TestExit)(){
	if(DFTotalResult){
		SetConsoleTextAttribute(STDOUT, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		wprintf(L"\nAll tests are successful!\n");
		SetConsoleTextAttribute(STDOUT, StartupCSBI.wAttributes);
		ExitProcess(0);
	} else {
		SetConsoleTextAttribute(STDOUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
		wprintf(L"\nSome or all tests are failed.\n");
		SetConsoleTextAttribute(STDOUT, StartupCSBI.wAttributes);
		ExitProcess(-1);
	}
}

DFFunction(void, TestDump)(DFAddress Data, DFUInt Size){
	DFByte *D = (DFByte*) Data;
	wprintf(L"\t");
	for(DFInt i=0; i<Size; i++){
		wprintf(L"%02X ", (*D++));
		if( (i % 16) == 15 ){wprintf(L"\n\t");}
	}
	wprintf(L"\n");
}

DFFunction(void, TestFailed)(){
		SetConsoleTextAttribute(STDOUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
		wprintf(L"Failed");
		SetConsoleTextAttribute(STDOUT, StartupCSBI.wAttributes);
		wprintf(L"\n");
		DFTotalResult = DFFalse;
}

DFFunction(void, TestSuccess)(){
		SetConsoleTextAttribute(STDOUT, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		wprintf(L"Success");
		SetConsoleTextAttribute(STDOUT, StartupCSBI.wAttributes);
		wprintf(L"\n");
}

DFFunction(void, TestWarning)(){
		SetConsoleTextAttribute(STDOUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		wprintf(L"Warning");
		SetConsoleTextAttribute(STDOUT, StartupCSBI.wAttributes);
		wprintf(L"\n");
}

DFFunction(DFBool, TestResultCompare)(DFAddress ReturnValue, DFChar* Name, DFAddress Result, DFAddress Example, DFInt ExampleSize){
	DFBool R = DFFalse;
	wprintf(L"[Return: %08X] ", ReturnValue);
	wprintf(L"%s : ", Name);
	if(!memcmp(Result, Example, ExampleSize)){
		R = DFTrue;
		TestSuccess();
	} else {
		R = DFFalse;
		TestFailed();
		wprintf(L"	Result:\n");
		TestDump(Result, ExampleSize);
		wprintf(L"	Expects:\n");
		TestDump(Example, ExampleSize);
	}
	return R;
}

