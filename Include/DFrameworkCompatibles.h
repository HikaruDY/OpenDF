//OpenDF :: An open source implementation of DFramework.]
//	(C)2018 OpenDF Project
//
//	Read LICENSE file for licenses and copyrights information before using this file.
//

//DFrameworkCompatibles.h
//OpenDF does not use these macros and definitions. But required for building some client applications.

#define DFUsing(t) DFP##t t = (DFP##t) DFUsingHelper((DFAddress*)&##t, DFCreate(DF_IID_##t, ((DFAddress*) &##t)));
extern "C" static DFAddress (__stdcall DFUsingHelper)(DFAddress* Type, DFResult DFC){return *Type;}


