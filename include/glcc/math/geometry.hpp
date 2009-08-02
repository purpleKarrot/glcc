/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef BOOST_GLSL_GEOMETRY_HPP
#define BOOST_GLSL_GEOMETRY_HPP

namespace gl
{
namespace sl
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
float length(const vector<T, N>& x);

//! Returns the distance between p0 and p1.
/** i.e. length(p0 - p1) */
template<typename T, std::size_t N>
float distance(const vector<T, N>& p0, const vector<T, N>& p1);

//! Returns the dot product of x and y.
/** i.e. \f$ x[0]*y[0]+x[1]*y[1]+\ldots \f$ */
template<typename T, std::size_t N>
float dot(const vector<T, N>& x, const vector<T, N>& y);

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
vec3 cross(vec3 a, vec3 b)
{
	return vec3(a[1] * b[2] - b[1] * a[2], //
			a[2] * b[0] - b[2] * a[0], //
			a[0] * b[1] - b[0] * a[1]);
}

//! Returns a vector in the same direction as x but with a length of 1.
template<typename T, std::size_t N>
vector<T, N> normalize(const vector<T, N>& x)
{
	return x / length(x);
}

//! If dot(Nref, I) < 0 return n, otherwise return -N.
template<typename T, std::size_t N>
vector<T, N> faceforward(const vector<T, N>& n, const vector<T, N>& I,
		const vector<T, N>& Nref)
{
	return dot(Nref, I) < 0 ? n : -n;
}

//! For the incident vector i and surface orientation n,
//! returns the reflection direction.
/** n must already be normalized in order to achieve the desired result.
 */
template<typename T, std::size_t N>
vector<T, N> reflect(const vector<T, N>& i, const vector<T, N>& n)
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
vector<T, N> refract(const vector<T, N>& i, const vector<T, N>& n, float eta)
{
	float k = 1.0 - eta * eta * (1.0 - dot(n, i) * dot(n, i));
	if (k < 0.f)
		return vector<T, N> (0.f);
	else
		return eta * i - (eta * dot(n, i) + std::sqrt(k)) * n;
}

/** \} */

} // namespace sl
} // namespace gl

#endif /* BOOST_GLSL_GEOMETRY_HPP */
