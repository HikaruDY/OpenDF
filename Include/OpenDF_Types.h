//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

#ifndef ODF_OPENDF_TYPES_H
#define ODF_OPENDF_TYPES_H

//8bit: 1 byte
typedef char DFInt8;
typedef unsigned char DFUInt8;
typedef DFUInt8 DFByte;

//16bit: 2 bytes
typedef short int DFInt16;
typedef unsigned short int DFUInt16;

//32bit: 4 bytes 
typedef long int DFInt32;
typedef unsigned long int DFUInt32;
typedef DFInt32 DFInt;
typedef DFUInt32 DFUInt;

//64bit: 8bytes
typedef long long int DFInt64;
typedef unsigned long long int DFUInt64;

//Unicode Strings
typedef wchar_t DFChar;

//ASCII Strings
typedef char DFChar_Legacy;

//Address Pointer
typedef void* DFAddress;

//Void
typedef void DFVoid;

//DFBool
typedef enum __DFBool {
	DFFalse = 0,
	DFTrue = 1,
} DFBool;

#endif //ODF_OPENDF_TYPES_H
