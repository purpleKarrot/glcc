/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_WGL_HPP
#define GLCC_DETAIL_WGL_HPP

#ifdef WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <GL/gl.h>
#include <glcc/detail/ext/wglext.h>

#define GLCC_PROC(TYPE, NAME) extern TYPE NAME;
#include <glcc/proc/wglarb.hpp>
#include <glcc/proc/wglext.hpp>
#undef GLCC_PROC

#endif /* WIN32 */

#endif /* GLCC_DETAIL_WGL_HPP */
