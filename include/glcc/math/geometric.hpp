/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_GEOMETRIC_HPP
#define GLCC_MATH_GEOMETRIC_HPP

#include <cmath>
#include <glcc/detail/vector.hpp>
#include <boost/la/vector_dot.hpp>
#include <boost/la/vector_cross.hpp>
#include <boost/la/vector_div_scalar.hpp>
#include <boost/la/vector_magnitude.hpp>

namespace gl
{
namespace math
{

/**
 * \defgroup geometry Geometric Functions (8.4)
 *
 * These operate on vectors as vectors, not component-wise.
 *
 * \{
 */

//! Returns the length of vector x.
/** i.e. \f$ \sqrt{x[0]^2+x[1]^2+\ldots} \f$ */
template<typename T, std::size_t D>
GLfloat length(gl::detail::vector<T, D> const& x)
{
	return boost::la::magnitude(x);
}

//! Returns the distance between p0 and p1.
/** i.e. length(p0 - p1) */
template<typename T, std::size_t D>
inline GLfloat distance(gl::detail::vector<T, D> const& p0, //
		gl::detail::vector<T, D> const& p1)
{
	using namespace boost::la;
	return length(p0 - p1);
}

//! Returns the dot product of a and b.
/** i.e. \f$ x[0]*y[0]+x[1]*y[1]+\ldots \f$ */
template<typename T, std::size_t D>
inline float dot(const gl::detail::vector<T, D>& a, //
		const gl::detail::vector<T, D>& b)
{
	return boost::la::dot(a, b);
}

//! Returns the cross product of a and b.
/** i.e.
 * \f$
 * \begin{bmatrix}
 *  a[1] * b[2] - b[1] * a[2] \\
 *  a[2] * b[0] - b[2] * a[0] \\
 *  a[0] * b[1] - b[0] * a[1]
 * \end{bmatrix}
 * \f$
 */
inline vec3 cross(vec3 a, vec3 b)
{
	return boost::la::cross(a, b);
}

//! Returns a vector in the same direction as x but with a length of 1.
template<typename T, std::size_t D>
inline typename gl::detail::vector<T, D> //
normalize(const gl::detail::vector<T, D>& x)
{
	using namespace boost::la;
	return x / length(x);
}

//! If dot(Nref, I) < 0 return n, otherwise return -N.
template<typename T, std::size_t N>
inline typename gl::detail::vector<T, N> //
faceforward(typename gl::detail::vector<T, N> const& n,
		typename gl::detail::vector<T, N> const& I,
		typename gl::detail::vector<T, N> const& Nref)
{
	return dot(Nref, I) < 0 ? n : -n;
}

//! For the incident vector i and surface orientation n,
//! returns the reflection direction.
/** n must already be normalized in order to achieve the desired result.
 */
template<typename T, std::size_t N>
inline typename gl::detail::vector<T, N> //
reflect(typename gl::detail::vector<T, N> const& i, //
		typename gl::detail::vector<T, N> const& n)
{
	return i - 2 * dot(n, i) * n;
}

//! For the incident vector I and surface normal N, and the
//! ratio of indices of refraction eta, return the refraction
//! vector.
/** The input parameters for the incident vector I and the
 *  surface normal N must already be normalized to get the
 *  desired results.
 */
template<typename T, std::size_t N>
inline typename gl::detail::vector<T, N> //
refract(typename gl::detail::vector<T, N> const& i, //
		typename gl::detail::vector<T, N> const& n, float eta)
{
	float k = 1.0 - eta * eta * (1.0 - dot(n, i) * dot(n, i));
	if (k < 0.f)
		return typename gl::detail::vector<T, N>::type(0.f);
	else
		return eta * i - (eta * dot(n, i) + std::sqrt(k)) * n;
}

/** \} */

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_GEOMETRIC_HPP */
