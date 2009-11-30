//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_5FD6A664ACC811DEAAFF8A8055D89593
#define UUID_5FD6A664ACC811DEAAFF8A8055D89593

#include <math.h>

namespace
boost
	{
	namespace
	la
		{
		template <class T> T acos( T );
		template <class T> T asin( T );
		template <class T> T atan( T );
		template <class T> T atan2( T, T );
		template <class T> T cos( T );
		template <class T> T sin( T );
		template <class T> T tan( T );
		template <class T> T cosh( T );
		template <class T> T sinh( T );
		template <class T> T tanh( T );
		template <class T> T exp( T );
		template <class T> T log( T );
		template <class T> T log10( T );
		template <class T> T mod( T , T );
		template <class T> T pow( T, T );
		template <class T> T sqrt( T );
		template <class T> T ceil( T );
		template <class T> T abs( T );
		template <class T> T floor( T );
		template <class T> T mod( T, T );
		template <class T> T ldexp( T, int );
		template <class T> T sign( T );

		template <> inline float acos<float>( float x ) { return ::acosf(x); }
		template <> inline float asin<float>( float x ) { return ::asinf(x); }
		template <> inline float atan<float>( float x ) { return ::atanf(x); }
		template <> inline float atan2<float>( float x, float y ) { return ::atan2f(x,y); }
		template <> inline float cos<float>( float x ) { return ::cosf(x); }
		template <> inline float sin<float>( float x ) { return ::sinf(x); }
		template <> inline float tan<float>( float x ) { return ::tanf(x); }
		template <> inline float cosh<float>( float x ) { return ::coshf(x); }
		template <> inline float sinh<float>( float x ) { return ::sinhf(x); }
		template <> inline float tanh<float>( float x ) { return ::tanhf(x); }
		template <> inline float exp<float>( float x ) { return ::expf(x); }
		template <> inline float log<float>( float x ) { return ::logf(x); }
		template <> inline float log10<float>( float x ) { return ::log10f(x); }
		template <> inline float mod<float>( float x, float y ) { return ::fmodf(x,y); }
		template <> inline float pow<float>( float x, float y ) { return ::powf(x,y); }
		template <> inline float sqrt<float>( float x ) { return ::sqrtf(x); }
		template <> inline float ceil<float>( float x ) { return ::ceilf(x); }
		template <> inline float abs<float>( float x ) { return ::fabsf(x); }
		template <> inline float floor<float>( float x ) { return ::floorf(x); }
		template <> inline float ldexp<float>( float x, int y ) { return ::ldexpf(x,y); }
		template <> inline float sign<float>( float x ) { return x<0 ? -1.f : +1.f; }
					
		template <> inline double acos<double>( double x ) { return ::acos(x); }
		template <> inline double asin<double>( double x ) { return ::asin(x); }
		template <> inline double atan<double>( double x ) { return ::atan(x); }
		template <> inline double atan2<double>( double x, double y ) { return ::atan2(x,y); }
		template <> inline double cos<double>( double x ) { return ::cos(x); }
		template <> inline double sin<double>( double x ) { return ::sin(x); }
		template <> inline double tan<double>( double x ) { return ::tan(x); }
		template <> inline double cosh<double>( double x ) { return ::cosh(x); }
		template <> inline double sinh<double>( double x ) { return ::sinh(x); }
		template <> inline double tanh<double>( double x ) { return ::tanh(x); }
		template <> inline double exp<double>( double x ) { return ::exp(x); }
		template <> inline double log<double>( double x ) { return ::log(x); }
		template <> inline double log10<double>( double x ) { return ::log10(x); }
		template <> inline double mod<double>( double x, double y ) { return ::fmod(x,y); }
		template <> inline double pow<double>( double x, double y ) { return ::pow(x,y); }
		template <> inline double sqrt<double>( double x ) { return ::sqrt(x); }
		template <> inline double ceil<double>( double x ) { return ::ceil(x); }
		template <> inline double abs<double>( double x ) { return ::fabs(x); }
		template <> inline double floor<double>( double x ) { return ::floor(x); }
		template <> inline double ldexp<double>( double x, int y ) { return ::ldexp(x,y); }
		template <> inline double sign<double>( double x ) { return x<0 ? -1.0 : +1.0; }
		}
	}

#endif
