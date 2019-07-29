// this muted code is from c standard library (torvalds/linux/lib/bsearch.c)
// for an exact lookup (binary search) in a sorted (ascending array)
// 
/* void *bsearch(const void *key, const void *base, size_t num, size_t size,
	      int (*cmp)(const void *key, const void *elt))
{
	const char *pivot;
	int result;

	while (num > 0) {
		pivot = base + (num >> 1) * size;
		result = cmp(key, pivot);

		if (result == 0)
			return (void *)pivot;

		if (result > 0) {
			base = pivot + size;
			num--;
		}
		num >>= 1;
	}

	return NULL;
} */

#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include "mex.h"

#define COMPARE(x,y) ((x)<(y)?-1:((x)==(y)?0:1))
#define SWAP(x,y) do \
   { unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
     memcpy(swap_temp,&y,sizeof(x)); \
     memcpy(&y,&x,       sizeof(x)); \
     memcpy(&x,swap_temp,sizeof(x)); \
    } while(0)

int cmp_int8(const void * a, const void * b) {
   return (int)COMPARE( *(int8_t*)a, *(int8_t*)b );
}
int cmp_uint8(const void * a, const void * b) {
   return (int)COMPARE( *(uint8_t*)a, *(uint8_t*)b );
}
int cmp_int16(const void * a, const void * b) {
   return (int)COMPARE( *(int16_t*)a, *(int16_t*)b );
}
int cmp_uint16(const void * a, const void * b) {
   return (int)COMPARE( *(uint16_t*)a, *(uint16_t*)b );
}
int cmp_int32(const void * a, const void * b) {
   return (int)COMPARE( *(int32_t*)a, *(int32_t*)b );
}
int cmp_uint32(const void * a, const void * b) {
   return (int)COMPARE( *(uint32_t*)a, *(uint32_t*)b );
}
int cmp_int64(const void * a, const void * b) {
   return (int)COMPARE( *(int64_t*)a, *(int64_t*)b );
}
int cmp_uint64(const void * a, const void * b) {
   return (int)COMPARE( *(uint64_t*)a, *(uint64_t*)b );
}
int cmp_float(const void * a, const void * b) {
   return (int)COMPARE( *(float*)a, *(float*)b );
}
int cmp_double(const void * a, const void * b) {
   return (int)COMPARE( *(double*)a, *(double*)b );
}

void *bsearch_ge(const void *key, const void *base, size_t num, size_t size,
	      int (*cmp)(const void *key, const void *elt))
{
	const char *pivot = NULL;
	int result;

	// check to make sure key is greater than base[0]
	// return first array element otherwise
	if ( cmp(key, base) <= 0 ) {
		return (void *)base;
	}
	
	// check to make sure key is less than or equal to base[num - 1]
	// return NULL if key is larger than the last array element
	if ( cmp(key, (char *)base + (num - 1) * size) > 0) {
		return NULL;
	}
	
	while (num > 0) {
		pivot = (char *)base + (num >> 1) * size;
		result = cmp(key, pivot);

		// return early if an exact match is found
		if (result == 0) {
			return (void *)pivot;
		}

		if (result > 0) {
			base = pivot + size;
			num--;
		}
		num >>= 1;
	}
    if (result > 0) {
	    pivot += size;
    }
	
	// keep in mind this will return an out of index pointer if there are 
	// no array elements greater than or equal to key
	// this is a condition we can avoid by checking ahead of time that
	// key is greater than base[0] and less than or equal to base[num-1]
    return (void *)pivot;

}

void *bsearch_gt(const void *key, const void *base, size_t num, size_t size,
	      int (*cmp)(const void *key, const void *elt))
{
	const char *pivot = NULL;
	int result;

	// check if key is greater than or equal to base[0]
	// return first array element otherwise
	if ( cmp(key, (void *)base) < 0 ) {
		return (void *)base;
	}
	
	// check to make sure key is less than or equal to base[num - 1]
	// return NULL if key is larger than (or equal to) the last array element
	if ( cmp(key, (char *)base + (num - 1) * size) >= 0) {
		return NULL;
	}
	
	while (num > 0) {
		pivot = (char *)base + (num >> 1) * size;
		result = cmp(key, pivot);

		if (result >= 0) {
			base = pivot + size;
			num--;
		}
		num >>= 1;
	}
    if (result >= 0) {
	    pivot += size;
    }

    return (void *)pivot;

}

void *bsearch_lt(const void *key, const void *base, size_t num, size_t size,
	      int (*cmp)(const void *key, const void *elt))
{
	const char *pivot = NULL;
	int result;
	
	// check to make sure key is less than or equal to base[0]
	// return NULL if key is less than (or equal to) the first array element
	if ( cmp(key, base) <= 0 ) {
		return NULL;
	}

	// start at the end and move backwards
	base = (const void *)((char *)base + (num - 1) * size);
	
	// check to make sure key is less than or equal to base[num - 1]
	// return last array element otherwise
	if ( cmp(key, (char *)base) > 0) {
		return (void *)base;
	}
		
	while (num > 0) {
		pivot = (char *)base - (num >> 1) * size;
		result = cmp(key, pivot);

		if (result <= 0) {
			base = pivot - size;
			num--;
		}
		num >>= 1;
	}
    if (result <= 0) {
	    pivot -= size;
    }
	
    return (void *)pivot;

}

void *bsearch_le(const void *key, const void *base, size_t num, size_t size,
	      int (*cmp)(const void *key, const void *elt))
{
	const char *pivot = NULL;
	int result;
	
	// check to make sure key is less than or equal to base[0]
	// return NULL if key is less than the first array element
	if ( cmp(key, base) < 0 ) {
		return NULL;
	}
	
	// start at the end and move backwards
	base = (const void *)((char *)base + (num - 1) * size);
	
	// check to make sure key is less than to base[num - 1]
	// return last array element otherwise
	if ( cmp(key, (char *)base) >= 0) {
		return (void *)base;
	}
	
	while (num > 0) {
		pivot = (char *)base - (num >> 1) * size;
		result = cmp(key, pivot);
		
		// return early if an exact match is found
		if (result == 0) {
			return (void *)pivot;
		}

		if (result < 0) {
			base = pivot - size;
			num--;
		}
		num >>= 1;
	}
    if (result < 0) {
	    pivot -= size;
    }
	
    return (void *)pivot;

}