/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef SLCC_VECTOR_HPP
#define SLCC_VECTOR_HPP

#include <slcc/detail/vector2.hpp>
#include <slcc/detail/vector3.hpp>
#include <slcc/detail/vector4.hpp>

namespace gl
{

//! a two component floating-point vector
typedef gl::detail::vector<float, 2> vec2;

//! a three component floating-point vector
typedef gl::detail::vector<float, 3> vec3;

//! a four component floating-point vector
typedef gl::detail::vector<float, 4> vec4;

//! a two-component double precision floating-point vector
typedef gl::detail::vector<double, 2> dvec2;

//! a three-component double precision floating-point vector
typedef gl::detail::vector<double, 3> dvec3;

//! a four-component double precision floating-point vector
typedef gl::detail::vector<double, 4> dvec4;

//! a two component Boolean vector
typedef gl::detail::vector<char, 2> bvec2;

//! a three component Boolean vector
typedef gl::detail::vector<char, 3> bvec3;

//! a four component Boolean vector
typedef gl::detail::vector<char, 4> bvec4;

//! a two component signed integer vector
typedef gl::detail::vector<int, 2> ivec2;

//! a three component signed integer vector
typedef gl::detail::vector<int, 3> ivec3;

//! a four component signed integer vector
typedef gl::detail::vector<int, 4> ivec4;

//! a two component unsigned integer vector
typedef gl::detail::vector<unsigned int, 2> uvec2;

//! a three component unsigned integer vector
typedef gl::detail::vector<unsigned int, 3> uvec3;

//! a four component unsigned integer vector
typedef gl::detail::vector<unsigned int, 4> uvec4;

} // namespace gl

#endif /* SLCC_VECTOR_HPP */
