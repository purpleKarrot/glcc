/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_VECTOR_HPP
#define GLCC_VECTOR_HPP

#include <boost/la/vec.hpp>
#include <glcc/detail/gl.hpp>

namespace gl
{

//! a two component floating-point vector
typedef boost::la::vec<GLfloat, 2> vec2;

//! a three component floating-point vector
typedef boost::la::vec<GLfloat, 3> vec3;

//! a four component floating-point vector
typedef boost::la::vec<GLfloat, 4> vec4;

//! a two-component double precision floating-point vector
typedef boost::la::vec<GLdouble, 2> dvec2;

//! a three-component double precision floating-point vector
typedef boost::la::vec<GLdouble, 3> dvec3;

//! a four-component double precision floating-point vector
typedef boost::la::vec<GLdouble, 4> dvec4;

//! a two component Boolean vector
typedef boost::la::vec<GLboolean, 2> bvec2;

//! a three component Boolean vector
typedef boost::la::vec<GLboolean, 3> bvec3;

//! a four component Boolean vector
typedef boost::la::vec<GLboolean, 4> bvec4;

//! a two component signed integer vector
typedef boost::la::vec<GLint, 2> ivec2;

//! a three component signed integer vector
typedef boost::la::vec<GLint, 3> ivec3;

//! a four component signed integer vector
typedef boost::la::vec<GLint, 4> ivec4;

//! a two component unsigned integer vector
typedef boost::la::vec<GLuint, 2> uvec2;

//! a three component unsigned integer vector
typedef boost::la::vec<GLuint, 3> uvec3;

//! a four component unsigned integer vector
typedef boost::la::vec<GLuint, 4> uvec4;

} // namespace gl

#endif /* GLCC_VECTOR_HPP */
