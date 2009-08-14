/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

/*
 * 8.5 Matrix Functions
 */

#ifndef GLCC_MATH_MATRIX_HPP
#define GLCC_MATH_MATRIX_HPP

#include <glcc/matrix.hpp>

namespace gl
{
namespace math
{

/// Multiply matrix x by matrix y component-wise, i.e.,
/// result[i][j] is the scalar product of x[i][j] and y[i][j].
/// Note: to get linear algebraic matrix multiplication, use
/// the multiply operator (*).
template<std::size_t M, std::size_t N>
inline gl::detail::matrix<GLfloat, M, N> //
matrixCompMult(const gl::detail::matrix<GLfloat, M, N>& x,
        const gl::detail::matrix<GLfloat, M, N>& y)
{
	gl::detail::matrix<GLfloat, M, N> mat(x);
	gl::detail::loop_op<M * N>::eval(gl::detail::multiplies_assign(), //
	        mat.begin(), y.begin());
	return mat;
}

/// Treats the first parameter c as a column vector (matrix
/// with one column) and the second parameter r as a row
/// vector (matrix with one row) and does a linear algebraic
/// matrix multiply c * r, yielding a matrix whose number of
/// rows is the number of components in c and whose
/// number of columns is the number of components in r.
template<std::size_t M, std::size_t N>
inline gl::detail::matrix<GLfloat, M, N> outerProduct(
        const typename gl::detail::vector<GLfloat, N>::type& c,
        const typename gl::detail::vector<GLfloat, M>::type& r)
{
	gl::detail::matrix<GLfloat, M, N> mat;
	//	detail::loop_op<M * N>::eval(detail::multiplies_assign(), //
	//			mat.begin(), y.begin());
	return mat;
}

/// Returns a matrix that is the transpose of m. The input
/// matrix m is not modified.
template<std::size_t M, std::size_t N>
inline gl::detail::matrix<GLfloat, M, N> //
transpose(const gl::detail::matrix<GLfloat, N, M>& m)
{
	gl::detail::matrix<GLfloat, M, N> mat;
	//	detail::loop_op<M * N>::eval(detail::multiplies_assign(), //
	//			mat.begin(), y.begin());
	return mat;
}

/// Returns the determinant of m.
GLfloat determinant(const gl::mat2& m);
GLfloat determinant(const mat3& m);
GLfloat determinant(const mat4& m);

/// Returns a matrix that is the inverse of m. The input
/// matrix m is not modified. The values in the returned
/// matrix are undefined if m is singular or poorly-
/// conditioned (nearly singular).
mat2 inverse(const mat2& m);
mat3 inverse(const mat3& m);
mat4 inverse(const mat4& m);

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_MATRIX_HPP */
