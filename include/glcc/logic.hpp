/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_LOGIC_HPP
#define GLCC_LOGIC_HPP

#include <GL/gl.h>
#include <glcc/detail/get.hpp>
#include <glcc/detail/macros.hpp>

namespace gl
{
namespace logic
{

GLCC_ENABLE(GL_COLOR_LOGIC_OP)

//! specify a logical pixel operation for color index rendering
inline void op(GLenum code)
{
	glLogicOp(code);
}

inline GLenum op()
{
	return detail::get<GLenum>(GL_LOGIC_OP_MODE);
}

} // namespace logic
} // namespace gl

#endif /* GLCC_LOGIC_HPP */
