/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_PROC
# error GLCC_PROC must be defined before including this file!
#endif

// WGL_ARB_buffer_region
GLCC_PROC(PFNWGLCREATEBUFFERREGIONARBPROC, wglCreateBufferRegionARB)
GLCC_PROC(PFNWGLDELETEBUFFERREGIONARBPROC, wglDeleteBufferRegionARB)
GLCC_PROC(PFNWGLSAVEBUFFERREGIONARBPROC, wglSaveBufferRegionARB)
GLCC_PROC(PFNWGLRESTOREBUFFERREGIONARBPROC, wglRestoreBufferRegionARB)

// WGL_ARB_extensions_string
GLCC_PROC(PFNWGLGETEXTENSIONSSTRINGARBPROC, wglGetExtensionsStringARB)

// WGL_ARB_pixel_format
GLCC_PROC(PFNWGLGETPIXELFORMATATTRIBIVARBPROC, wglGetPixelFormatAttribivARB)
GLCC_PROC(PFNWGLGETPIXELFORMATATTRIBFVARBPROC, wglGetPixelFormatAttribfvARB)
GLCC_PROC(PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB)

// WGL_ARB_make_current_read
GLCC_PROC(PFNWGLMAKECONTEXTCURRENTARBPROC, wglMakeContextCurrentARB)
GLCC_PROC(PFNWGLGETCURRENTREADDCARBPROC, wglGetCurrentReadDCARB)

// WGL_ARB_pbuffer
GLCC_PROC(PFNWGLCREATEPBUFFERARBPROC, wglCreatePbufferARB)
GLCC_PROC(PFNWGLGETPBUFFERDCARBPROC, wglGetPbufferDCARB)
GLCC_PROC(PFNWGLRELEASEPBUFFERDCARBPROC, wglReleasePbufferDCARB)
GLCC_PROC(PFNWGLDESTROYPBUFFERARBPROC, wglDestroyPbufferARB)
GLCC_PROC(PFNWGLQUERYPBUFFERARBPROC, wglQueryPbufferARB)

// WGL_ARB_render_texture
GLCC_PROC(PFNWGLBINDTEXIMAGEARBPROC, wglBindTexImageARB)
GLCC_PROC(PFNWGLRELEASETEXIMAGEARBPROC, wglReleaseTexImageARB)
GLCC_PROC(PFNWGLSETPBUFFERATTRIBARBPROC, wglSetPbufferAttribARB)

// WGL_ARB_create_context
GLCC_PROC(PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB)
