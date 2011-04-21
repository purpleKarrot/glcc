/**************************************************************
 * Copyright (c) 2008-2011 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MAT_HPP
#define GLCC_MAT_HPP

#include <GL/gl.h>

namespace gl
{
namespace detail
{

template<typename T, int Cols, int Rows>
struct mat
{
	T a[Cols][Rows];

	template<typename R>
	operator R() const
	{
		R r;
		assign(r, *this);
		return r;
	}
};

} // namespace detail

typedef gl::detail::mat<GLfloat, 2, 2> mat2;
typedef gl::detail::mat<GLfloat, 2, 3> mat2x3;
typedef gl::detail::mat<GLfloat, 2, 4> mat2x4;

typedef gl::detail::mat<GLfloat, 3, 2> mat3x2;
typedef gl::detail::mat<GLfloat, 3, 3> mat3;
typedef gl::detail::mat<GLfloat, 3, 4> mat3x4;

typedef gl::detail::mat<GLfloat, 4, 2> mat4x2;
typedef gl::detail::mat<GLfloat, 4, 3> mat4x3;
typedef gl::detail::mat<GLfloat, 4, 4> mat4;

typedef gl::detail::mat<GLdouble, 2, 2> dmat2;
typedef gl::detail::mat<GLdouble, 2, 3> dmat2x3;
typedef gl::detail::mat<GLdouble, 2, 4> dmat2x4;

typedef gl::detail::mat<GLdouble, 3, 2> dmat3x2;
typedef gl::detail::mat<GLdouble, 3, 3> dmat3;
typedef gl::detail::mat<GLdouble, 3, 4> dmat3x4;

typedef gl::detail::mat<GLdouble, 4, 2> dmat4x2;
typedef gl::detail::mat<GLdouble, 4, 3> dmat4x3;
typedef gl::detail::mat<GLdouble, 4, 4> dmat4;

} // namespace gl

#endif /* GLCC_MAT_HPP */
