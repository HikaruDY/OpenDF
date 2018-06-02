//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#include <OpenDF.h>

ODF_AUTOGEN_ODFCreate(Loader, Object){
	Object->LoadLibraryFromFile = Loader_LoadLibraryFromFile;
	Object->GetFunctionEntryPoint = Loader_GetFunctionEntryPoint;
	return DFR_Success;
}

