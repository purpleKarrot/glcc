/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_GEOMETRIC_HPP
#define GLCC_MATH_GEOMETRIC_HPP

#include <glcc/detail/vector.hpp>
#include <glcc/math/detail/vector_param.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>

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
template<typename T, std::size_t N>
inline typename boost::enable_if_c<N == 2, float>::type //
length(const gl::detail::vector<T, N>& x)
{
	return std::sqrt(x[0] * x[0] + x[1] * x[1]);
}

template<typename T, std::size_t N>
inline typename boost::enable_if_c<N == 3, float>::type //
length(const gl::detail::vector<T, N>& x)
{
	return std::sqrt(x[0] * x[0] + x[1] * x[1] + x[2] * x[2]);
}

template<typename T, std::size_t N>
inline typename boost::enable_if_c<N == 4, float>::type //
length(const gl::detail::vector<T, N>& x)
{
	return std::sqrt(x[0] * x[0] + x[1] * x[1] + x[2] * x[2] + x[3] * x[3]);
}

//! Returns the distance between p0 and p1.
/** i.e. length(p0 - p1) */
template<typename T, std::size_t N>
inline float distance(const gl::detail::vector<T, N>& p0,
        const gl::detail::vector<T, N>& p1)
{
	return length(p0 - p1);
}

//! Returns the dot product of a and b.
/** i.e. \f$ x[0]*y[0]+x[1]*y[1]+\ldots \f$ */
template<typename T>
inline float dot(const gl::detail::vector2<T>& a,
        const gl::detail::vector2<T>& b)
{
	return a.x() * b.x() + a.y() * b.y();
}

template<typename T>
inline float dot(const gl::detail::vector3<T>& a,
        const gl::detail::vector3<T>& b)
{
	return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
}

template<typename T>
inline float dot(const gl::detail::vector4<T>& a,
        const gl::detail::vector4<T>& b)
{
	return a.x() * b.x() + a.y() * b.y() + a.z() * b.z() + a.w() * b.w();
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
	return vec3(a.y() * b.z() - b.y() * a.z(), //
	        a.z() * b.x() - b.z() * a.x(), //
	        a.x() * b.y() - b.x() * a.y());
}

//! Returns a vector in the same direction as x but with a length of 1.
template<typename T, std::size_t N>
inline typename gl::math::detail::vector_type<T, N>::type //
normalize(const gl::detail::vector<T, N>& x)
{
	return x / length(x);
}

//! If dot(Nref, I) < 0 return n, otherwise return -N.
template<typename T, std::size_t N>
inline typename gl::detail::vector<T, N>::type faceforward(
        const typename gl::detail::vector<T, N>::type& n,
        typename gl::detail::vector<T, N>::type& I,
        const typename gl::detail::vector<T, N>::type& Nref)
{
	return dot(Nref, I) < 0 ? n : -n;
}

//! For the incident vector i and surface orientation n,
//! returns the reflection direction.
/** n must already be normalized in order to achieve the desired result.
 */
template<typename T, std::size_t N>
inline typename gl::detail::vector<T, N>::type reflect(
        const typename gl::detail::vector<T, N>::type& i,
        const typename gl::detail::vector<T, N>::type& n)
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
inline typename gl::detail::vector<T, N>::type refract(
        const typename gl::detail::vector<T, N>::type& i,
        const typename gl::detail::vector<T, N>::type& n, float eta)
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
