/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_STENCIL_HPP
#define GLCC_STENCIL_HPP

#include <GL/gl.h>
#include <glcc/detail/macros.hpp>

namespace gl
{
namespace stencil
{

GLCC_ENABLE(GL_STENCIL_TEST)

inline void function(GLenum func, int ref, unsigned int mask)
{
	glStencilFunc(func, ref, mask);
}

inline void function(GLenum face, GLenum func, int ref, unsigned int mask)
{
	glStencilFuncSeparate(face, func, ref, mask);
}

inline void op(GLenum sfail, GLenum dpfail, GLenum dppass)
{
	glStencilOp(sfail, dpfail, dppass);
}

inline void op(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
	glStencilOpSeparate(face, sfail, dpfail, dppass);
}

inline void clear(int s)
{
	glClearStencil(s);
}

inline void mask(unsigned int m)
{
	glStencilMask(m);
}

inline void mask(GLenum face, unsigned int mask)
{
	glStencilMaskSeparate(face, mask);
}

} // namespace stencil
} // namespace gl

#endif /* GLCC_STENCIL_HPP */
