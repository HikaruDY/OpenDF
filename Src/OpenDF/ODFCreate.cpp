//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#include <OpenDF.h>

#define ODFSupport(p, n) DFFunction(DFResult, ODFCreate_##n)(DF_IID IID, DFP##n* Object);
#include "SupportedDFInterfaces.inc"
#undef ODFSupport

DFFunction(DFResult, ODFCreate)(DF_IID IID, DFAddress* Object){
	switch(IID){
		#define ODFSupport(p, n) case (DF_IID_##n): return ODFCreate_##n(IID, (DFP##n*) Object); break;
		#include "SupportedDFInterfaces.inc"
		#undef ODFSupport
	}
	return DFR_E_NoInterface;
}
