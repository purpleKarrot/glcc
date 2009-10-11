/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/detail/gl.hpp>
#include <glcc/detail/wgl.hpp>

#ifdef WIN32

#define GLCC_PROC(type, name) type name = NULL;
#include <glcc/proc/gl12.hpp>
#include <glcc/proc/gl13.hpp>
#include <glcc/proc/gl14.hpp>
#include <glcc/proc/gl15.hpp>
#include <glcc/proc/gl20.hpp>
#include <glcc/proc/gl21.hpp>
#include <glcc/proc/gl30.hpp>
#include <glcc/proc/gl31.hpp>
#include <glcc/proc/glarb.hpp>
#undef GLCC_PROC

#endif

#if defined(__APPLE__) || defined(__APPLE_CC__)
#include <Carbon/Carbon.h>
#endif

void wgl_foo()
{
#ifdef WIN32

#define GLCC_PROC(type, name) \
	name = reinterpret_cast<type> (wglGetProcAddress(#name));

#include <glcc/proc/gl12.hpp>
#include <glcc/proc/gl13.hpp>
#include <glcc/proc/gl14.hpp>
#include <glcc/proc/gl15.hpp>
#include <glcc/proc/gl20.hpp>
#include <glcc/proc/gl21.hpp>
#include <glcc/proc/gl30.hpp>
#include <glcc/proc/gl31.hpp>
#include <glcc/proc/glarb.hpp>

#undef GLCC_PROC

#endif
}

//void glx_foo()
//{
//#define GLCC_PROC(TYPE, NAME) \
//	NAME = (TYPE) glXGetProcAddress((const GLubyte*)#NAME);
//
//#include <glcc/detail/proc.hpp>
//
//#undef GLCC_PROC
//}

//void apple_foo()
//{
//	CFURLRef bundleURL = CFURLCreateWithFileSystemPath(kCFAllocatorDefault,
//			CFSTR("/System/Library/Frameworks/OpenGL.framework"),
//			kCFURLPOSIXPathStyle, true);
//
//	CFBundleRef bundle = CFBundleCreate(kCFAllocatorDefault, bundleURL);
//	assert(bundle != NULL);
//
//	CFStringRef functionName;
//
//#define GLCC_PROC(TYPE, NAME)                                              \
//	functionName = CFStringCreateWithCString(kCFAllocatorDefault,          \
//			#NAME, kCFStringEncodingASCII);                                \
//	NAME = (TYPE) CFBundleGetFunctionPointerForName(bundle, functionName); \
//	CFRelease(functionName);                                               \
//
//#include <glcc/detail/proc.hpp>
//
//#undef GLCC_PROC
//
//	CFRelease(bundle);
//	CFRelease(bundleURL);
//}
