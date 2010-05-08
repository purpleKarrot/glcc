/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DEPTH_HPP
#define GLCC_DEPTH_HPP

#include <GL3/gl3w.h>
#include <glcc/detail/get.hpp>
#include <glcc/detail/macros.hpp>

namespace gl
{
namespace depth
{

//! Control whether the depth test is enabled
GLCC_ENABLE(GL_DEPTH_TEST)

inline void function(GLenum func)
{
	glDepthFunc(func);
}

inline void mask(bool flag)
{
	glDepthMask(flag);
}

inline bool mask()
{
	return detail::get<bool>(GL_DEPTH_WRITEMASK);
}

inline void range(GLclampd near_val, GLclampd far_val)
{
	glDepthRange(near_val, far_val);
}

inline void clear(GLclampd depth)
{
	glClearDepth(depth);
}

} // namespace depth
} // namespace gl

#endif /* GLCC_DEPTH_HPP */
