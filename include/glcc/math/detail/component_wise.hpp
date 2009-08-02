/*
 * macros.hpp
 *
 *  Created on: Jun 6, 2009
 *      Author: daniel
 */

#ifndef GLCC_MATH_DETAIL_COMPONENT_WISE_HPP
#define GLCC_MATH_DETAIL_COMPONENT_WISE_HPP

#include <glcc/detail/vector2.hpp>
#include <glcc/detail/vector3.hpp>
#include <glcc/detail/vector4.hpp>

// Type, Function, Parameter
#define GLCC_COMPONENT_WISE(T, F, P)                                           \
	T F(T P);                                                                  \
	inline gl::detail::vector2<T> F(const gl::detail::vector2<T>& P)           \
	{                                                                          \
		return gl::detail::vector2<T>(F(P.x()), F(P.y()));                     \
	}                                                                          \
	inline gl::detail::vector3<T> F(const gl::detail::vector3<T>& P)           \
	{                                                                          \
		return gl::detail::vector3<T>(F(P.x()), F(P.y()), F(P.z()));           \
	}                                                                          \
	inline gl::detail::vector4<T> F(const gl::detail::vector4<T>& P)           \
	{                                                                          \
		return gl::detail::vector4<T>(F(P.x()), F(P.y()), F(P.z()), F(P.w())); \
	}                                                                          \
	inline T F(T P)

// Type, Function, Parameter
#define GLCC_COMPONENT_WISE_T(F, P)                                            \
	template<typename T>                                                       \
	T F(T P);                                                                  \
	template<typename T>                                                       \
	inline gl::detail::vector2<T> F(const gl::detail::vector2<T>& P)           \
	{                                                                          \
		return gl::detail::vector2<T>(F(P.x()), F(P.y()));                     \
	}                                                                          \
	template<typename T>                                                       \
	inline gl::detail::vector3<T> F(const gl::detail::vector3<T>& P)           \
	{                                                                          \
		return gl::detail::vector3<T>(F(P.x()), F(P.y()), F(P.z()));           \
	}                                                                          \
	template<typename T>                                                       \
	inline gl::detail::vector4<T> F(const gl::detail::vector4<T>& P)           \
	{                                                                          \
		return gl::detail::vector4<T>(F(P.x()), F(P.y()), F(P.z()), F(P.w())); \
	}                                                                          \
	template<typename T>                                                       \
	inline T F(T P)

#define GLCC_COMPONENT_WISE_STD(F, P)                                          \
	GLCC_COMPONENT_WISE_T(F, P)                                                \
	{                                                                          \
		return std::F(P);                                                      \
	}

#endif /* GLCC_MATH_DETAIL_COMPONENT_WISE_HPP */
