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

#include <glcc/detail/matrix.hpp>

namespace gl
{
namespace math
{

/// Multiply matrix x by matrix y component-wise, i.e.,
/// result[i][j] is the scalar product of x[i][j] and y[i][j].
/// Note: to get linear algebraic matrix multiplication, use
/// the multiply operator (*).
template<typename T, std::size_t M, std::size_t N>
inline gl::detail::matrix<T, M, N> matrixCompMult(const gl::detail::matrix<T,
        M, N>& x, const gl::detail::matrix<T, M, N>& y)
{
	gl::detail::matrix<T, M, N> mat(x);
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
template<typename T, std::size_t M, std::size_t N>
inline gl::detail::matrix<T, M, N> outerProduct(
        const typename gl::detail::vector<T, N>::type& c,
        const typename gl::detail::vector<T, M>::type& r)
{
	gl::detail::matrix<T, M, N> mat;
	//	detail::loop_op<M * N>::eval(detail::multiplies_assign(), //
	//			mat.begin(), y.begin());
	return mat;
}

/// Returns a matrix that is the transpose of m. The input
/// matrix m is not modified.
template<typename T, std::size_t M, std::size_t N>
inline gl::detail::matrix<T, M, N> transpose(const gl::detail::matrix<T, N, M>& m)
{
	gl::detail::matrix<T, M, N> mat;
	//	detail::loop_op<M * N>::eval(detail::multiplies_assign(), //
	//			mat.begin(), y.begin());
	return mat;
}

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_MATRIX_HPP */
