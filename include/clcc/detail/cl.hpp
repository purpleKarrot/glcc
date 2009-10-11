/**************************************************************
 * Copyright (c) 2009 Daniel Pfeifer                          *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef CLCC_DETAIL_CL_HPP
#define CLCC_DETAIL_CL_HPP

#ifdef _WIN32
#include <windows.h>
#include <CL/cl.h>
#endif // _WIN32

#if defined(__APPLE__) || defined(__MACOSX)
#include <OpenCL/cl.h>
#include <OpenGL/opengl.h>
#include <OpenCL/cl_gl.h>
#else
#include <CL/cl.h>
#include <GL/gl.h>
#include <CL/cl_gl.h>
#endif // !__APPLE__

#endif /* CLCC_DETAIL_GL_HPP */
