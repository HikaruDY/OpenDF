#include <DFTest.h>

DFUsing(Binary);

void main(){
	DFAddress R;
	TestInitialize();

	const DFInt DSTSize = 62;
	DFChar *SRC  = L"This is test string!";
	DFChar DST1[DSTSize];
	DFChar DST2[DSTSize];
	DFInt CopySize = (wcslen(SRC)+1)*2;

	DFTestInit {
		memset(DST1, 0xFF, DSTSize);
		memset(DST2, 0xFF, DSTSize);
	} DFTestExec {
		R = Binary->Clear(DST1, 3);
	} DFTestExample {
		memset(DST2, 0, 3);
	} DFTestResult {
		TestResultCompare(R, L"Clear 3 bytes", DST1, DST2, DSTSize);
	}

	DFTestInit {
		memset(DST1, 0xFF, DSTSize);
		memset(DST2, 0xFF, DSTSize);
	} DFTestExec {
		R = Binary->Clear(DST1, 32);
	} DFTestExample {
		memset(DST2, 0, 32);
	} DFTestResult {
		TestResultCompare(R, L"Clear 32 bytes", DST1, DST2, DSTSize);
	}

	DFTestInit {
		memset(DST1, 0xFF, DSTSize);
		memset(DST2, 0xFF, DSTSize);
	} DFTestExec {
		R = Binary->Clear(DST1, DSTSize);
	} DFTestExample {
		memset(DST2, 0, DSTSize);
	} DFTestResult {
		TestResultCompare(R, L"Clear All", DST1, DST2, DSTSize);
	}

	DFTestInit {
		memset(DST1, 0, DSTSize);
		memset(DST2, 0, DSTSize);
	} DFTestExec {
		R = Binary->Set(DST1, 0xDF, DSTSize);
	} DFTestExample {
		memset(DST2, 0xDF, DSTSize);
	} DFTestResult {
		TestResultCompare(R, L"Set", DST1, DST2, DSTSize);
	}

	DFTestInit {
		memset(DST1, 0xFF, DSTSize);
		memset(DST2, 0xFF, DSTSize);
	} DFTestExec {
		R = Binary->Copy1x(DST1, DSTSize, SRC, CopySize);
	} DFTestExample {
		memmove(DST2, SRC, CopySize);
	} DFTestResult {
		TestResultCompare(R, L"Copy1x", DST1, DST2, DSTSize);
	}

	DFTestInit {
		memset(DST1, 0xFF, DSTSize);
		memset(DST2, 0xFF, DSTSize);
	} DFTestExec {
		R = Binary->Copy1x(DST1, 16, SRC, CopySize);
	} DFTestExample {
		memmove(DST2, SRC, 16);
	} DFTestResult {
		TestResultCompare(R, L"Copy1x Overflow", DST1, DST2, DSTSize);
	}

	DFTestInit {
		memset(DST1, 0xFF, DSTSize);
		memset(DST2, 0xFF, DSTSize);
	} DFTestExec {
		R = Binary->Copy4x(DST1, DSTSize, SRC, CopySize);
	} DFTestExample {
		memmove(DST2, SRC, CopySize);
	} DFTestResult {
		TestResultCompare(R, L"Copy4x", DST1, DST2, (CopySize >> 2) << 2); //Copy4x only supports multiples of 4bytes
	}

	DFTestInit {
		memset(DST1, 0xFF, DSTSize);
		memset(DST2, 0xFF, DSTSize);
	} DFTestExec {
		R = Binary->Copy4x(DST1, 16, SRC, CopySize);
	} DFTestExample {
		memmove(DST2, SRC, 16);
	} DFTestResult {
		TestResultCompare(R, L"Copy4x Overflow", DST1, DST2, DSTSize);
	}


	DFTestInit {
		memset(DST1, 0xFF, DSTSize);
		memset(DST2, 0xFF, DSTSize);
	} DFTestExec {
		R = Binary->Copy(DST1, DSTSize, SRC, CopySize);
	} DFTestExample {
		memmove(DST2, SRC, CopySize);
	} DFTestResult {
		TestResultCompare(R, L"Copy", DST1, DST2, DSTSize);
	}

	DFTestInit {
		memset(DST1, 0xFF, DSTSize);
		memset(DST2, 0xFF, DSTSize);
	} DFTestExec {
		R = Binary->Copy(DST1, 16, SRC, CopySize);
	} DFTestExample {
		memmove(DST2, SRC, 16);
	} DFTestResult {
		TestResultCompare(R, L"Copy Overflow", DST1, DST2, DSTSize);
	}


	TestExit();
}

