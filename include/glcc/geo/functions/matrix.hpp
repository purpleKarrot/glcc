/*
 * 8.5 Matrix Functions
 */

#ifndef BOOST_GLSL_MATRIX_HPP
#define BOOST_GLSL_MATRIX_HPP

#include <boost/glcc/sl/types.hpp>

namespace gl
{
namespace sl
{

/// Multiply matrix x by matrix y component-wise, i.e.,
/// result[i][j] is the scalar product of x[i][j] and y[i][j].
/// Note: to get linear algebraic matrix multiplication, use
/// the multiply operator (*).
template<typename T, std::size_t M, std::size_t N>
inline detail::matrix<T, M, N> matrixCompMult(const detail::matrix<T, M, N>& x,
		const detail::matrix<T, M, N>& y)
{
	detail::matrix<T, M, N> mat(x);
	detail::loop_op<M * N>::eval(detail::multiplies_assign(), //
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
inline detail::matrix<T, M, N> outerProduct(const detail::vector<T, N>& c,
		const detail::vector<T, M>& r)
{
	detail::matrix<T, M, N> mat(x);
	//	detail::loop_op<M * N>::eval(detail::multiplies_assign(), //
	//			mat.begin(), y.begin());
	return mat;
}

/// Returns a matrix that is the transpose of m. The input
/// matrix m is not modified.
template<typename T, std::size_t M, std::size_t N>
inline detail::matrix<T, M, N> transpose(const detail::matrix<T, N, M>& m)
{
	detail::matrix<T, M, N> mat(x);
	//	detail::loop_op<M * N>::eval(detail::multiplies_assign(), //
	//			mat.begin(), y.begin());
	return mat;
}

} // namespace sl
} // namespace gl

#endif /* BOOST_GLSL_MATRIX_HPP */
