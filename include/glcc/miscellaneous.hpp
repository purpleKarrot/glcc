/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MISCELLANEOUS_HPP
#define GLCC_MISCELLANEOUS_HPP

#include <GL3/gl3w.h>
#include <glcc/detail/get.hpp>
#include <glcc/vec.hpp>

namespace gl
{

// framebuffer
inline void clear_color(const vec4& value)
{
	//glClearColor(value.r, value.g, value.b, value.a);
	glClearColor(value.a[0], value.a[1], value.a[2], value.a[3]);
}

inline vec4 clear_color()
{
	return detail::get<vec4>(GL_COLOR_CLEAR_VALUE);
}

// framebuffer
inline void clear(GLbitfield mask)
{
	glClear(mask);
}

// framebuffer
inline void color_mask(const bvec4& value)
{
	//glColorMask(value.r, value.g, value.b, value.a);
	glColorMask(value.a[0], value.a[1], value.a[2], value.a[3]);
}

inline bvec4 color_mask()
{
	return detail::get<bvec4>(GL_COLOR_WRITEMASK);
}

// Pixel operations
inline void logic_op(GLenum opcode)
{
	glLogicOp(opcode);
}

// Drawing control
inline void cull_face(GLenum mode)
{
	glCullFace(mode);
}

// Drawing control
inline void front_face(GLenum mode)
{
	glFrontFace(mode);
}

// Drawing control
inline void point_size(float size)
{
	glPointSize(size);
}

// Drawing control
inline void line_width(float width)
{
	glLineWidth(width);
}

// Drawing control
inline void scissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
	glScissor(x, y, width, height);
}

// Framebuffer
inline void draw_buffer(GLenum mode)
{
	glDrawBuffer(mode);
}

/// Force all previous GL commands to complete. Finish does not return until all
/// effects from previously issued commands on GL client and server state and the
/// framebuffer are fully realized.
inline void finish()
{
	glFinish();
}

/// Indicate that all commands that have previously been sent to the GL must
/// complete in finite time.
inline void flush()
{
	glFlush();
}

inline void viewport(int x, int y, int w, int h)
{
	glViewport(x, y, w, h);
}

/*
 * As of version 3.0 polygons are always drawn in the same mode,
 * no matter which face is being rasterized.
 * GL_FRONT_AND_BACK is the only valid parameter
 */
inline void polygon_mode(GLenum mode)
{
	glPolygonMode(GL_FRONT_AND_BACK, mode);
}

} // namespace gl

#endif /* GLCC_MISCELLANEOUS_HPP */
