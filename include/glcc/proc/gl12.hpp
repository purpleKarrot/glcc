/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_PROC
# error GLCC_PROC must be defined before including this file!
#endif

GLCC_PROC(PFNGLBLENDCOLORPROC, glBlendColor,
		((GLclampf, red))
		((GLclampf, green))
		((GLclampf, blue))
		((GLclampf, alpha))
)

GLCC_PROC(PFNGLBLENDEQUATIONPROC, glBlendEquation,
		((GLenum, mode))
)

GLCC_PROC(PFNGLDRAWRANGEELEMENTSPROC, glDrawRangeElements,
		((GLenum, mode))
		((GLuint, start))
		((GLuint, end))
		((GLsizei, count))
		((GLenum, type))
		((const GLvoid*, indices))
)

GLCC_PROC(PFNGLTEXIMAGE3DPROC, glTexImage3D,
		((GLenum, target))
		((GLint, level))
		((GLint, internalformat))
		((GLsizei, width))
		((GLsizei, height))
		((GLsizei, depth))
		((GLint, border))
		((GLenum, format))
		((GLenum, type))
		((const GLvoid*, pixels))
)

GLCC_PROC(PFNGLTEXSUBIMAGE3DPROC, glTexSubImage3D,
		((GLenum, target))
		((GLint, level))
		((GLint, xoffset))
		((GLint, yoffset))
		((GLint, zoffset))
		((GLsizei, width))
		((GLsizei, height))
		((GLsizei, depth))
		((GLenum, format))
		((GLenum, type))
		((const GLvoid*, pixels))
)

GLCC_PROC(PFNGLCOPYTEXSUBIMAGE3DPROC, glCopyTexSubImage3D,
		((GLenum, target))
		((GLint, level))
		((GLint, xoffset))
		((GLint, yoffset))
		((GLint, zoffset))
		((GLint, x))
		((GLint, y))
		((GLsizei, width))
		((GLsizei, height))
)
