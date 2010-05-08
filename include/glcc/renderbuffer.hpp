/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_RENDERBUFFER_HPP
#define GLCC_RENDERBUFFER_HPP

#include <GL3/gl3w.h>
#include <glcc/detail/macros.hpp>

namespace gl
{
namespace detail
{

class renderbuffer_base
{
public:
	void bind()
	{
		glBindRenderbuffer(GL_RENDERBUFFER, name);
	}

	void storage(GLenum internalformat, GLsizei width, GLsizei height)
	{
		glRenderbufferStorage(GL_RENDERBUFFER, internalformat, width, height);
	}

	void storage(GLsizei samples, GLenum internalformat, GLsizei width,
			GLsizei height)
	{
		glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples,
				internalformat, width, height);
	}

GLCC_BASE(renderbuffer_base, Renderbuffer, Renderbuffers)
};

} // namespace detail

GLCC_OBJECT(renderbuffer)

} // namespace gl

#endif /* GLCC_RENDERBUFFER_HPP */
