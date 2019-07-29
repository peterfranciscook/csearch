#include "mex.h"
#include "csearch.h"
#include "string.h"

enum relop{lt, le, gt, ge};

int validateInput(int nrhs, const mxArray* prhs[], size_t* num, int* op)
{
	char s[3];
	// Validate # of Inputs
	if (nrhs < 3) {
		printf("Error using csearch\nNot enough input arguments.\n");
		return 0;
	}
	else if (nrhs > 3) {
		printf("Error using csearch\nToo many input arguments.\n");
		return 0;
	}
	// Validate 1st Input
	if (!mxIsNumeric(prhs[0])) {
		printf("First Input Must be a Numeric Array\n");
		return 0;
	}
	else if (mxIsComplex(prhs[0])) {
		printf("Complex Data Not Supported\n");
		return 0;
	}
	else {
		*num = mxGetNumberOfElements(prhs[0]);
		if (*num < 2) {
			printf("Input Array Must Have More Than 1 Element");
			return 0;
		}
	}
	// Validate 3rd Input
	if (!mxIsNumeric(prhs[2])) {
		printf("Third Input Must be Numeric\n");
		return 0;
	}
	// Validate 2nd Input
	if (!mxIsChar(prhs[1])) {
		printf("Second Input Must be an Operator String (lt, le, gt, ge)\n");
		return 0;
	}
	else {
		mxGetString(prhs[1], s, 3);
		if (strcmp(s, "lt") == 0) {
			*op = lt;
			return 1;
		}
		else if (strcmp(s, "le") == 0) {
			*op = le;
			return 1;
		}
		else if (strcmp(s, "gt") == 0) {
			*op = gt;
			return 1;
		}
		else if (strcmp(s, "ge") == 0) {
			*op = ge;
			return 1;
		}
		else {
			printf("Second Input Must be A Relational Operator (lt, le, gt, ge)\n");
			return 0;
		}
	}
}

void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
	// validate inputs to mexFunction
	int op;
	size_t num;
	int isOK = validateInput(nrhs, prhs, &num, &op);
	if (!isOK) {
		mexErrMsgTxt("Input Validation Failed");
	}

	int64_t argmin;

	// x_min : lower limit
	// x_max : upper limit
	// matlab equivalent function calls:
	// argmin = find(x>x_min, 1, 'first');
	// argmax = find(x<x_max, 1, 'last');

	// create output array of indices
	plhs[0] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
	int64_t* idx_out = (int64_t*)mxGetData(plhs[0]);

	unsigned char* p;
	unsigned char* x = (unsigned char*)mxGetData(prhs[0]);
	unsigned char* y = (unsigned char*)mxGetData(prhs[2]);
	size_t sz = 1;
	int (*cmp)(const void* key, const void* elt);

	if (mxIsDouble(prhs[0])) {
		cmp = cmp_double;
		sz = sizeof(double);
	}
	else if (mxIsSingle(prhs[0])) {
		cmp = cmp_float;
		sz = sizeof(float);
	}
	else if (mxIsInt8(prhs[0])) {
		cmp = cmp_int8;
		sz = sizeof(int8_t);
	}
	else if (mxIsUint8(prhs[0])) {
		cmp = cmp_uint8;
		sz = sizeof(uint8_t);
	}
	else if (mxIsInt16(prhs[0])) {
		cmp = cmp_int16;
		sz = sizeof(int16_t);
	}	
	else if (mxIsUint16(prhs[0])) {
		cmp = cmp_uint16;
		sz = sizeof(uint16_t);
	}	
	else if (mxIsInt32(prhs[0])) {
		cmp = cmp_int32;
		sz = sizeof(int32_t);
	}	
	else if (mxIsUint32(prhs[0])) {
		cmp = cmp_uint32;
		sz = sizeof(uint32_t);
	}	
	else if (mxIsInt64(prhs[0])) {
		cmp = cmp_int64;
		sz = sizeof(int64_t);
	}	
	else if (mxIsUint64(prhs[0])) {
		cmp = cmp_uint64;
		sz = sizeof(uint64_t);
	}
	else {
		mexErrMsgTxt("Incompatible Type. Input Array Must Be Integer, Float, or Double\n");
	}

	switch (op) {
	case 0:
		p = (unsigned char*)bsearch_lt(y, x, num, sz, cmp);
		break;
	case 1:
		p = (unsigned char*)bsearch_le(y, x, num, sz, cmp);
		break;
	case 2:
		p = (unsigned char*)bsearch_gt(y, x, num, sz, cmp);
		break;
	case 3:
		p = (unsigned char*)bsearch_ge(y, x, num, sz, cmp);
		break;
	default:
		p = NULL;
	}
	
	if (p != NULL) {
		//argmin = p - x;
		argmin = (p - x) / sz;
	}
	else {
		argmin = -1;
	}

	// fill and send idx_out back to matlab
	// shift the indices from zero-based to one-based
	idx_out[0] = argmin + 1;
	//idx_out[1] = argmax + 1;
}
