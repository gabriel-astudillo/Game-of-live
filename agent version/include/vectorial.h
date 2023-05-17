#ifndef _VECTORIAL_HH_
#define _VECTORIAL_HH_

#include <immintrin.h>
#include <xmmintrin.h>

__m128 loadNeighborsToVecorial(const float *p0){
		return ( _mm_load_ss(p0) );
		// b = _mm_load_ss(p1);
		// c = _mm_load_ss(p2);
		// d = _mm_load_ss(p3);
		// e = _mm_shuffle_ps(a, b, _MM_SHUFFLE(1,0,2,0));
		// e = _mm_shuffle_ps(c, d, _MM_SHUFFLE(1,0,2,0));

		// return ( _mm_shuffle_ps(e, f, _MM_SHUFFLE(2,0,2,0)));
	}

#endif