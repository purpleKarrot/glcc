/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef SLCC_MATRIX_HPP
#define SLCC_MATRIX_HPP

#include "detail/matrix.hpp"

namespace sl
{

//! a 2x2 floating-point matrix
typedef sl::detail::matrix<float, 2, 2> mat2;

//! a 3x3 floating-point matrix
typedef sl::detail::matrix<float, 3, 3> mat3;

//! a 4x4 floating-point matrix
typedef sl::detail::matrix<float, 4, 4> mat4;

//! same as a mat2
typedef mat2 mat2x2;

//! a floating-point matrix with 2 columns and 3 rows
typedef sl::detail::matrix<float, 2, 3> mat2x3;

//! a floating-point matrix with 2 columns and 4 rows
typedef sl::detail::matrix<float, 2, 4> mat2x4;

//! a floating-point matrix with 3 columns and 2 rows
typedef sl::detail::matrix<float, 3, 2> mat3x2;

//! same as a mat3
typedef mat3 mat3x3;

//! a floating-point matrix with 3 columns and 4 rows
typedef sl::detail::matrix<float, 3, 4> mat3x4;

//! a floating-point matrix with 4 columns and 2 rows
typedef sl::detail::matrix<float, 4, 2> mat4x2;

//! a floating-point matrix with 4 columns and 3 rows
typedef sl::detail::matrix<float, 4, 3> mat4x3;

//! same as a mat4
typedef mat4 mat4x4;

//! a 2×2 double-precision floating-point matrix
typedef sl::detail::matrix<double, 2, 2> dmat2;

//! a 3×3 double-precision floating-point matrix
typedef sl::detail::matrix<double, 3, 3> dmat3;

//! a 4×4 double-precision floating-point matrix
typedef sl::detail::matrix<double, 4, 4> dmat4;

//! same as a dmat2
typedef dmat2 dmat2x2;

//! a double-precision floating-point matrix with 2 columns and 3 rows
typedef sl::detail::matrix<double, 2, 3> dmat2x3;

//! a double-precision floating-point matrix with 2 columns and 4 rows
typedef sl::detail::matrix<double, 2, 4> dmat2x4;

//! a double-precision floating-point matrix with 3 columns and 2 rows
typedef sl::detail::matrix<double, 3, 2> dmat3x2;

//! same as a dmat3
typedef dmat3 dmat3x3;

//! a double-precision floating-point matrix with 3 columns and 4 rows
typedef sl::detail::matrix<double, 3, 4> dmat3x4;

//! a double-precision floating-point matrix with 4 columns and 2 rows
typedef sl::detail::matrix<double, 4, 2> dmat4x2;

//! a double-precision floating-point matrix with 4 columns and 3 rows
typedef sl::detail::matrix<double, 4, 3> dmat4x3;

//! same as a dmat4
typedef dmat4 dmat4x4;

} //namespace sl

#endif /* SLCC_MATRIX_HPP */
