#define ODF_INCLUDE_H(s) <OpenDF.##s##.h>
#define ODFSupport(p, n) p##include ODF_INCLUDE_H(n)

#include <SupportedDFInterfaces.inc>

#undef ODFSupport
