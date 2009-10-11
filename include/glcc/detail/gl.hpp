/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_GL_HPP
#define GLCC_DETAIL_GL_HPP

#define GL_VERSION_1_2_DEPRECATED 1
#define GL_VERSION_1_3_DEPRECATED 1
#define GL_VERSION_1_4_DEPRECATED 1
#define GL_VERSION_1_5_DEPRECATED 1
#define GL_VERSION_2_0_DEPRECATED 1
#define GL_VERSION_2_1_DEPRECATED 1
#define GL_VERSION_3_0_DEPRECATED 1
#define GL_ARB_imaging_DEPRECATED 1
#define GL_ARB_framebuffer_object_DEPRECATED 1

#ifdef WIN32

//#define WIN32_LEAN_AND_MEAN
//#include <windows.h>
#define __glext_h_
#include <GL/gl.h>
#undef  __glext_h_

#include <glcc/detail/ext/glext.h>

#define GLCC_PROC(type, name) extern type name;
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

#ifdef _MSC_VER
#pragma comment(lib, "OpenGL32.lib")
#endif

#elif defined(__APPLE__)

#include <OpenGL/gl.h>
#include <glcc/detail/ext/glext.h>

#else

#define GL_GLEXT_LEGACY 1
#include <GL/gl.h>

//#define GLX_GLXEXT_LEGACY 1
//#include <GL/glx.h>

#define GL_GLEXT_PROTOTYPES 1
#include <glcc/detail/ext/glext.h>

//#define GLX_GLXEXT_PROTOTYPES 1
//#include <glcc/detail/ext/glxext.h>

#endif

#endif /* GLCC_DETAIL_GL_HPP */
