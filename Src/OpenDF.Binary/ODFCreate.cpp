//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#include <OpenDF.h>

static DFBinary DefaultObject;
DFFunction(DFResult, ODFCreate_Binary)(DF_IID IID, DFPBinary *Interface){
	DFPBinary Object = &DefaultObject;
	if(Interface != 0){
		*Interface = Object;
	}

	Object->Clear = Binary_Clear;
	Object->Set = Binary_Set;
	Object->Copy4x = Binary_Copy;
	Object->Copy1x = Binary_Copy;
	Object->Copy = Binary_Copy;

	return DFR_Success;
}
