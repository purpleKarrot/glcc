/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DRAW_HPP
#define GLCC_DRAW_HPP

#include <glcc/detail/gl.hpp>
#include <boost/mpl/integral_c.hpp>
#include <vector>

namespace gl
{
namespace detail
{

template<typename T>
struct gl_type
{
};

template<>
struct gl_type<uint8_t> : boost::mpl::integral_c<GLenum, GL_UNSIGNED_BYTE>
{
};

template<>
struct gl_type<uint16_t> : boost::mpl::integral_c<GLenum, GL_UNSIGNED_SHORT>
{
};

template<>
struct gl_type<uint32_t> : boost::mpl::integral_c<GLenum, GL_UNSIGNED_INT>
{
};

} // namespace detail

enum DrawMode
{
	points = GL_POINTS,
	lines = GL_LINES,
	line_loop = GL_LINE_LOOP,
	line_strip = GL_LINE_STRIP,
	triangles = GL_TRIANGLES,
	triangle_strip = GL_TRIANGLE_STRIP,
	triangle_fan = GL_TRIANGLE_FAN
};

template<std::size_t N>
inline void draw(const GLenum(&buffers)[N])
{
	glDrawBuffers(N, buffers);
}

inline void draw(GLenum mode, int first, size_t count)
{
	glDrawArrays(mode, first, count);
}

inline void draw(GLenum mode, int first, size_t count, size_t primcount)
{
	glDrawArraysInstanced(mode, first, count, primcount);
}

template<typename C>
void draw(GLenum mode, const C& elements)
{
	glDrawElements(mode, elements.size(), //
			detail::gl_type<typename C::value_type>::type::value, &elements[0]);
}

template<typename C>
void draw(GLenum mode, const C& elements, size_t primcount)
{
	glDrawElementsInstanced(mode, elements.size(), //
			detail::gl_type<typename C::value_type>::type::value, //
			&elements[0], primcount);
}

template<typename C>
void draw(GLenum mode, GLuint start, GLuint end, const C& elements)
{
	glDrawRangeElements(mode, start, end, elements.size(), //
			detail::gl_type<typename C::value_type>::value, &elements[0]);
}

//void MultiDrawArrays(GLenum mode, GLint *first, GLsizei *count,
//		GLsizei primcount);
//
//void MultiDrawElements(GLenum mode, GLsizei *count, GLenum type,
//		GLvoid **indices, GLsizei primcount);

} // namespace gl

#endif /* GLCC_DRAW_HPP */
