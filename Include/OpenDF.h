//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#ifndef ODF_OPENDF_H
#define ODF_OPENDF_H

#define DFFunction(rt, fn) extern "C" rt (__stdcall fn)
#define DFPFunction(rt, fn) rt (__stdcall *fn)

#define DF_TOSTRING_(s) L#s
#define DF_TOSTRING(s) DF_TOSTRING_(s)

#define ODF_AUTOGEN_ODFCreate(n, i) static DF##n DefaultObject; \
	DFFunction(DFResult, ODFCreate_##n##_ObjectWriter)(DFP##n Object); /* Declaration of Object Writer */ \
	DFFunction(DFResult, ODFCreate_##n)(DF_IID IID, DFP##n *PassedObject){ /* Implements of ODFCreate_*** */ \
		DFP##n ObjectToWrite = 0; \
		if(PassedObject == 0){ return DFR_E_InvalidOperation; } /* if PassedObject is null, can't return generated object */ \
		if(*PassedObject == 0){ \
			ObjectToWrite = &DefaultObject; /* Use DefaultObject as write address. */ \
			*PassedObject = &DefaultObject; /* Change passed address to DefaultObject. */ \
		} else { \
			ObjectToWrite = *PassedObject; /* Use passed address as write address. */ \
		} \
		return ODFCreate_##n##_ObjectWriter(ObjectToWrite); /* Call Object Writer */ \
	} \
	DFFunction(DFResult, ODFCreate_##n##_ObjectWriter)(DFP##n i) //Object Writer


#include "OpenDF_Build.h"
#include "OpenDF_Types.h"
#include "OpenDF_IID.h"
#include "OpenDF_DFResult.h"
#include "OpenDF_Include.h"
#include "DFrameworkCompatibles.h"
#include "OpenDF_ClientLibrary.h"


#endif //ODF_OPENDF_H
