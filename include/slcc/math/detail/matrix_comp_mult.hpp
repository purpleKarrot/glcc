/*
 * matrix_comp_mult.hpp
 *
 *  Created on: 01.12.2009
 *      Author: daniel
 */

#ifndef GLCC_MATH_DETAIL_MATRIX_COMP_MULT_HPP
#define GLCC_MATH_DETAIL_MATRIX_COMP_MULT_HPP

namespace gl
{
namespace math
{
namespace detail
{

inline gl::mat2 matrixCompMult(gl::mat2 const& x, gl::mat2 const& y)
{
	gl::mat2 r;
	r.data[0][0] = x.data[0][0] * y.data[0][0];
	r.data[0][1] = x.data[0][1] * y.data[0][1];
	r.data[1][0] = x.data[1][0] * y.data[1][0];
	r.data[1][1] = x.data[1][1] * y.data[1][1];
	return r;
}

} // namespace detail
} // namespace math
} // namespace gl

#endif /* GLCC_MATH_DETAIL_MATRIX_COMP_MULT_HPP */
