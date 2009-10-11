/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_PROC
# error GLCC_PROC must be defined before including this file!
#endif

// WGL_EXT_display_color_table
GLCC_PROC(PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC, wglCreateDisplayColorTableEXT)
GLCC_PROC(PFNWGLLOADDISPLAYCOLORTABLEEXTPROC, wglLoadDisplayColorTableEXT)
GLCC_PROC(PFNWGLBINDDISPLAYCOLORTABLEEXTPROC, wglBindDisplayColorTableEXT)
GLCC_PROC(PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC, wglDestroyDisplayColorTableEXT)

// WGL_EXT_extensions_string
GLCC_PROC(PFNWGLGETEXTENSIONSSTRINGEXTPROC, wglGetExtensionsStringEXT)

// WGL_EXT_make_current_read
GLCC_PROC(PFNWGLMAKECONTEXTCURRENTEXTPROC, wglMakeContextCurrentEXT)
GLCC_PROC(PFNWGLGETCURRENTREADDCEXTPROC, wglGetCurrentReadDCEXT)

// WGL_EXT_pbuffer
GLCC_PROC(PFNWGLCREATEPBUFFEREXTPROC, wglCreatePbufferEXT)
GLCC_PROC(PFNWGLGETPBUFFERDCEXTPROC, wglGetPbufferDCEXT)
GLCC_PROC(PFNWGLRELEASEPBUFFERDCEXTPROC, wglReleasePbufferDCEXT)
GLCC_PROC(PFNWGLDESTROYPBUFFEREXTPROC, wglDestroyPbufferEXT)
GLCC_PROC(PFNWGLQUERYPBUFFEREXTPROC, wglQueryPbufferEXT)

// WGL_EXT_pixel_format
GLCC_PROC(PFNWGLGETPIXELFORMATATTRIBIVEXTPROC, wglGetPixelFormatAttribivEXT)
GLCC_PROC(PFNWGLGETPIXELFORMATATTRIBFVEXTPROC, wglGetPixelFormatAttribfvEXT)
GLCC_PROC(PFNWGLCHOOSEPIXELFORMATEXTPROC, wglChoosePixelFormatEXT)

// WGL_EXT_swap_control
GLCC_PROC(PFNWGLSWAPINTERVALEXTPROC, wglSwapIntervalEXT)
GLCC_PROC(PFNWGLGETSWAPINTERVALEXTPROC, wglGetSwapIntervalEXT)
