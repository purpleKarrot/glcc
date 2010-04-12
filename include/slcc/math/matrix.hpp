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

#include <slcc/matrix.hpp>
#include <boost/la/all.hpp>
//#include <boost/la/matrix_determinant.hpp>
//#include <boost/la/matrix_inverse.hpp>
//#include <boost/la/row_matrix.hpp>
//#include <boost/la/col_matrix.hpp>
//#include <boost/la/matrix_assign.hpp>

namespace gl
{
namespace math
{

/// Multiply matrix x by matrix y component-wise, i.e.,
/// result[i][j] is the scalar product of x[i][j] and y[i][j].
/// Note: to get linear algebraic matrix multiplication, use
/// the multiply operator (*).
template<std::size_t M, std::size_t N>
inline gl::detail::matrix<M, N> //
matrixCompMult(gl::detail::matrix<M, N> const& x,
		gl::detail::matrix<M, N> const& y)
{
	gl::detail::matrix<M, N> m;
	for (int i = 0; i < M * N; ++i)
		m.data[i] = x.data[i] * y.data[i];
	return m;
}

/// Treats the first parameter c as a column vector (matrix
/// with one column) and the second parameter r as a row
/// vector (matrix with one row) and does a linear algebraic
/// matrix multiply c * r, yielding a matrix whose number of
/// rows is the number of components in c and whose
/// number of columns is the number of components in r.
template<std::size_t M, std::size_t N>
inline gl::detail::matrix<M, N> //
outerProduct(gl::detail::vector<float, N> const& c,
		gl::detail::vector<float, M> const& r)
{
	using namespace boost::la;
	return (c | col_matrix) * (r | row_matrix);
}

/// Returns a matrix that is the transpose of m. The input
/// matrix m is not modified.
template<int M, int N>
inline gl::detail::matrix<M, N> transpose(gl::detail::matrix<N, M> const& m)
{
	return m | boost::la::transpose;
}

/// Returns the determinant of m.
template<int D>
inline GLfloat determinant(gl::detail::matrix<D, D> const& m)
{
	return boost::la::determinant(m);
}

/// Returns a matrix that is the inverse of m. The input
/// matrix m is not modified. The values in the returned
/// matrix are undefined if m is singular or poorly-
/// conditioned (nearly singular).
template<int D>
inline gl::detail::matrix<D, D> inverse(gl::detail::matrix<D, D> const& m)
{
	return boost::la::inverse(m);
}

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_MATRIX_HPP */
