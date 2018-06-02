//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#include <OpenDF.h>
#include <Windows.h>

DFFunction(DFAddress, Loader_LoadLibraryFromFile)(DFChar* File){
	return (DFAddress) LoadLibraryW(File);
}

DFFunction(DFAddress, Loader_GetFunctionEntryPoint_NoCheck)(DFAddress BaseAddress, DFChar_Legacy* Name){
	if(BaseAddress == 0 || Name == 0){ return 0; }

	DFAddress FunctionPointer = (DFAddress) GetProcAddress((HMODULE) BaseAddress, Name);
	return FunctionPointer;
}

DFFunction(DFAddress, Loader_GetFunctionEntryPoint)(DFAddress BaseAddress, DFChar_Legacy* Name){
	return Loader_GetFunctionEntryPoint_NoCheck(BaseAddress, Name);
}
