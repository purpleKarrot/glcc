/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_VEC_HPP
#define GLCC_VEC_HPP

#include <GL/gl.h>

namespace gl
{
namespace detail
{

template<typename T, int Dim>
struct vec
{
	T a[Dim];

	template<class R>
	operator R() const
	{
		R r;
		assign(r, *this);
		return r;
	}
};

} // namespace detail

//! a two component floating-point vector
typedef gl::detail::vec<GLfloat, 2> vec2;

//! a three component floating-point vector
typedef gl::detail::vec<GLfloat, 3> vec3;

//! a four component floating-point vector
typedef gl::detail::vec<GLfloat, 4> vec4;

//! a two-component double precision floating-point vector
typedef gl::detail::vec<GLdouble, 2> dvec2;

//! a three-component double precision floating-point vector
typedef gl::detail::vec<GLdouble, 3> dvec3;

//! a four-component double precision floating-point vector
typedef gl::detail::vec<GLdouble, 4> dvec4;

//! a two component Boolean vector
typedef gl::detail::vec<GLboolean, 2> bvec2;

//! a three component Boolean vector
typedef gl::detail::vec<GLboolean, 3> bvec3;

//! a four component Boolean vector
typedef gl::detail::vec<GLboolean, 4> bvec4;

//! a two component signed integer vector
typedef gl::detail::vec<GLint, 2> ivec2;

//! a three component signed integer vector
typedef gl::detail::vec<GLint, 3> ivec3;

//! a four component signed integer vector
typedef gl::detail::vec<GLint, 4> ivec4;

//! a two component unsigned integer vector
typedef gl::detail::vec<GLuint, 2> uvec2;

//! a three component unsigned integer vector
typedef gl::detail::vec<GLuint, 3> uvec3;

//! a four component unsigned integer vector
typedef gl::detail::vec<GLuint, 4> uvec4;

} // namespace gl

#endif /* GLCC_VEC_HPP */
