//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#ifndef ODF_OPENDF_DFRESULT_H 
#define ODF_OPENDF_DFRESULT_H 
typedef enum __DFResult {
	DFR_Success 			= 0x00000000, 
	DFR_OK 				= 0x00000000, 
	DFR_Error 			= 0x80000000, 
	DFR_E_InvalidOperation 		= 0x80000001, 
	DFR_E_FileNotFound 		= 0x80000002, 
	DFR_E_InvalidKey 		= 0x80000003, 
	DFR_E_IOFailure 		= 0x80000004, 
	DFR_E_NoPermission 		= 0x80000005, 
	DFR_E_NotSupported 		= 0x80000006, 
	DFR_E_NoStorage 		= 0x80000007, 
	DFR_E_NoMemory 			= 0x80000008, 
	DFR_E_NoInterface 		= 0x8FFFFFFF, 
} DFResult;
#endif //ODF_OPENDF_DFRESULT_H 
