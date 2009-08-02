/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_VECTOR_HPP
#define GLCC_VECTOR_HPP

#include <glcc/detail/gl.hpp>
#include <glcc/detail/vector2.hpp>
#include <glcc/detail/vector3.hpp>
#include <glcc/detail/vector4.hpp>

namespace gl
{

//! a two component floating-point vector
typedef gl::detail::vector2<GLfloat> vec2;

//! a three component floating-point vector
typedef gl::detail::vector3<GLfloat> vec3;

//! a four component floating-point vector
typedef gl::detail::vector4<GLfloat> vec4;

//! a two component Boolean vector
typedef gl::detail::vector2<GLboolean> bvec2;

//! a three component Boolean vector
typedef gl::detail::vector3<GLboolean> bvec3;

//! a four component Boolean vector
typedef gl::detail::vector4<GLboolean> bvec4;

//! a two component signed integer vector
typedef gl::detail::vector2<GLint> ivec2;

//! a three component signed integer vector
typedef gl::detail::vector3<GLint> ivec3;

//! a four component signed integer vector
typedef gl::detail::vector4<GLint> ivec4;

//! a two component unsigned integer vector
typedef gl::detail::vector2<GLuint> uvec2;

//! a three component unsigned integer vector
typedef gl::detail::vector3<GLuint> uvec3;

//! a four component unsigned integer vector
typedef gl::detail::vector4<GLuint> uvec4;

} // namespace gl

#endif /* GLCC_VECTOR_HPP */
