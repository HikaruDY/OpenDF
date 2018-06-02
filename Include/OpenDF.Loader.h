//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#ifndef ODF_API_OpenDF_Loader_H 
#define ODF_API_OpenDF_Loader_H 
typedef struct ___DFLoader{
	DFPFunction(DFAddress, LoadLibraryFromFile)(DFChar* File);
	DFPFunction(DFAddress, GetFunctionEntryPoint)(DFAddress BaseAddress, DFChar_Legacy* Name);
} DFLoader, *DFPLoader;
#endif //ODF_API_OpenDF_Loader_H 
