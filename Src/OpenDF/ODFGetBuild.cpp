//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#include <OpenDF.h>

DFFunction(const DFChar*, ODFGetBuild)(){
	return DF_TOSTRING_(DF_BUILD);
}

