/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATRIX_HPP
#define GLCC_MATRIX_HPP

#include <glcc/detail/matrix.hpp>

namespace gl
{

//! a 2x2 floating-point matrix
typedef gl::detail::matrix<2, 2> mat2;

//! a 3x3 floating-point matrix
typedef gl::detail::matrix<3, 3> mat3;

//! a 4x4 floating-point matrix
typedef gl::detail::matrix<4, 4> mat4;

//! same as a mat2
typedef mat2 mat2x2;

//! a floating-point matrix with 2 columns and 3 rows
typedef gl::detail::matrix<2, 3> mat2x3;

//! a floating-point matrix with 2 columns and 4 rows
typedef gl::detail::matrix<2, 4> mat2x4;

//! a floating-point matrix with 3 columns and 2 rows
typedef gl::detail::matrix<3, 2> mat3x2;

//! same as a mat3
typedef mat3 mat3x3;

//! a floating-point matrix with 3 columns and 4 rows
typedef gl::detail::matrix<3, 4> mat3x4;

//! a floating-point matrix with 4 columns and 2 rows
typedef gl::detail::matrix<4, 2> mat4x2;

//! a floating-point matrix with 4 columns and 3 rows
typedef gl::detail::matrix<4, 3> mat4x3;

//! same as a mat4
typedef mat4 mat4x4;

} //namespace gl

#endif /* GLCC_MATRIX_HPP */
