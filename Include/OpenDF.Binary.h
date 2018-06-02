//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#ifndef ODF_API_OpenDF_Binary_H 
#define ODF_API_OpenDF_Binary_H 
typedef struct ___DFBinary{
	DFPFunction(DFAddress, Clear)(DFAddress Dst, DFUInt DstSize);
	DFPFunction(DFAddress, Set)(DFAddress Dst, DFByte Value, DFUInt DstSize);
	DFPFunction(DFAddress, Copy4x)(DFAddress Dst, DFUInt DstSize, DFAddress Src, DFUInt CopySize);
	DFPFunction(DFAddress, Copy1x)(DFAddress Dst, DFUInt DstSize, DFAddress Src, DFUInt CopySize);
	DFPFunction(DFAddress, Copy)(DFAddress Dst, DFUInt DstSize, DFAddress Src, DFUInt CopySize);
} DFBinary, *DFPBinary;
#endif //ODF_API_OpenDF_Binary_H 
