/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_PROC
# error GLCC_PROC must be defined before including this file!
#endif

// Version 1.5
GLCC_PROC(PFNGLGENQUERIESPROC, glGenQueries)
GLCC_PROC(PFNGLDELETEQUERIESPROC, glDeleteQueries)
GLCC_PROC(PFNGLISQUERYPROC, glIsQuery)
GLCC_PROC(PFNGLBEGINQUERYPROC, glBeginQuery)
GLCC_PROC(PFNGLENDQUERYPROC, glEndQuery)
GLCC_PROC(PFNGLGETQUERYIVPROC, glGetQueryiv)
GLCC_PROC(PFNGLGETQUERYOBJECTIVPROC, glGetQueryObjectiv)
GLCC_PROC(PFNGLGETQUERYOBJECTUIVPROC, glGetQueryObjectuiv)
GLCC_PROC(PFNGLBINDBUFFERPROC, glBindBuffer)
GLCC_PROC(PFNGLDELETEBUFFERSPROC, glDeleteBuffers)
GLCC_PROC(PFNGLGENBUFFERSPROC, glGenBuffers)
GLCC_PROC(PFNGLISBUFFERPROC, glIsBuffer)
GLCC_PROC(PFNGLBUFFERDATAPROC, glBufferData)
GLCC_PROC(PFNGLBUFFERSUBDATAPROC, glBufferSubData)
GLCC_PROC(PFNGLGETBUFFERSUBDATAPROC, glGetBufferSubData)
GLCC_PROC(PFNGLMAPBUFFERPROC, glMapBuffer)
GLCC_PROC(PFNGLUNMAPBUFFERPROC, glUnmapBuffer)
GLCC_PROC(PFNGLGETBUFFERPARAMETERIVPROC, glGetBufferParameteriv)
GLCC_PROC(PFNGLGETBUFFERPOINTERVPROC, glGetBufferPointerv)
