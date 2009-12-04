/*
 * link12.cpp
 *
 *  Created on: Nov 30, 2009
 *      Author: Daniel Pfeifer
 */

#include <boost/config.hpp>
#ifdef BOOST_WINDOWS

#include <glcc/detail/gl.hpp>
#include <GL/glx.h>
#include <cassert>

#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>

#if defined(__APPLE__) || defined(__APPLE_CC__)
#include <Carbon/Carbon.h>
#endif

//name = reinterpret_cast<type> (wglGetProcAddress(#name));
#define GLCC_PROC(type, name, arg)                            \
	name = (type) glXGetProcAddress((const GLubyte*)#name);   \
	assert(name && "unable to get proc address");             \

//#define GLCC_PROC(TYPE, NAME)                                            \
//	functionName = CFStringCreateWithCString(kCFAllocatorDefault,          \
//			#NAME, kCFStringEncodingASCII);                                \
//	NAME = (TYPE) CFBundleGetFunctionPointerForName(bundle, functionName); \
//	CFRelease(functionName);

static void link()
{
	//	CFURLRef bundleURL = CFURLCreateWithFileSystemPath(kCFAllocatorDefault,
	//			CFSTR("/System/Library/Frameworks/OpenGL.framework"),
	//			kCFURLPOSIXPathStyle, true);
	//
	//	CFBundleRef bundle = CFBundleCreate(kCFAllocatorDefault, bundleURL);
	//	assert(bundle != NULL);
	//
	//	CFStringRef functionName;

#include <glcc/proc/gl12.hpp>
	//#include <glcc/proc/gl13.hpp>
	//#include <glcc/proc/gl14.hpp>
	//#include <glcc/proc/gl15.hpp>
	//#include <glcc/proc/gl20.hpp>
	//#include <glcc/proc/gl21.hpp>
	//#include <glcc/proc/gl30.hpp>
	//#include <glcc/proc/gl31.hpp>
	//#include <glcc/proc/gl32.hpp>

	//	CFRelease(bundle);
	//	CFRelease(bundleURL);
}

#undef GLCC_PROC

#define P1(r, data, i, elem)        \
	BOOST_PP_COMMA_IF(I)            \
	BOOST_PP_TUPLE_ELEM(2, 0, elem) \
	BOOST_PP_TUPLE_ELEM(2, 1, elem) \

#define P2(r, data, i, elem)        \
	BOOST_PP_COMMA_IF(I)            \
	BOOST_PP_TUPLE_ELEM(2, 1, elem) \

#define GLCC_PROC(ptr, name, arg)                              \
	static void lazy_##name(BOOST_PP_SEQ_FOR_EACH_I(P1,, arg)) \
	{                                                          \
		link();                                                \
		name(BOOST_PP_SEQ_FOR_EACH_I(P2,, arg));               \
	}                                                          \
	ptr name = lazy_##name;                                    \

#include <glcc/proc/gl12.hpp>
//#include <glcc/proc/gl13.hpp>
//#include <glcc/proc/gl14.hpp>
//#include <glcc/proc/gl15.hpp>
//#include <glcc/proc/gl20.hpp>
//#include <glcc/proc/gl21.hpp>
//#include <glcc/proc/gl30.hpp>
//#include <glcc/proc/gl31.hpp>
//#include <glcc/proc/gl32.hpp>

#undef GLCC_PROC
#undef P2
#undef P1

#endif
