//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#include <OpenDF.h>
#include <string.h>

DFFunction(DFAddress, Binary_Clear)(DFAddress Dst, DFUInt DstSize){
	memset(Dst, 0, DstSize);
	return Dst;
}

DFFunction(DFAddress, Binary_Set)(DFAddress Dst, DFByte Value, DFUInt DstSize){
	memset(Dst, Value, DstSize);
	return Dst;
}

#include <stdio.h>
DFFunction(DFAddress, Binary_Copy)(DFAddress Dst, DFUInt DstSize, DFAddress Src, DFUInt CopySize){
	if(DstSize < CopySize){
		CopySize = DstSize;
	}
	memmove_s(Dst, DstSize, Src, CopySize);
	return Dst;
}

