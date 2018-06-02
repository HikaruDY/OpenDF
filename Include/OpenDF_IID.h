//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#ifndef ODF_OPENDF_IID_H 
#define ODF_OPENDF_IID_H 


//DO NOT SET THIS TO '0x0DF00000'. WHEN YOU USE THE OpenDF AND DFramework AT THE SAME TIME, UNEXPECTED BEHAVIOR OCCURS.
#define DF_IID_BEGIN 0x0DF00000 //0DF = ODF



typedef enum __DF_IID {
	DF_IID_START = DF_IID_BEGIN,

	#define ODFSupport(p, n) DF_IID_##n,
	#include "SupportedDFInterfaces.inc"
	#undef ODFSupport

	DF_IID_END
} DF_IID;


#if (DF_IID_BEGIN > 0x0DF00000)
	#error DF_ID_BEGIN must be set to 0x0DF00000 or less. When you use the OpenDF and DFramework at the same time, unexpected behavior occurs.
#endif //if

#endif //ODF_OPENDF_IID_H 
