/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/detail/vector2.hpp>
#include <glcc/detail/vector3.hpp>
#include <glcc/detail/vector4.hpp>

#ifndef GLCC_MATH_DETAIL_VECTOR_PARAM_HPP
#define GLCC_MATH_DETAIL_VECTOR_PARAM_HPP

namespace gl
{
namespace math
{
namespace detail
{

template<typename T, std::size_t N>
struct vector_param
{
};

template<typename T>
struct vector_param<T, 2>
{
	typedef const typename gl::detail::vector2<T>& type;
};

template<typename T>
struct vector_param<T, 3>
{
	typedef const typename gl::detail::vector3<T>& type;
};

template<typename T>
struct vector_param<T, 4>
{
	typedef const typename gl::detail::vector4<T>& type;
};

template<typename T>
struct vector_param<T&, 2>
{
	typedef typename gl::detail::vector2<T>& type;
};

template<typename T>
struct vector_param<T&, 3>
{
	typedef typename gl::detail::vector3<T>& type;
};

template<typename T>
struct vector_param<T&, 4>
{
	typedef typename gl::detail::vector4<T>& type;
};

} // namespace detail
} // namespace math
} // namespace gl

#endif /* GLCC_MATH_DETAIL_VECTOR_PARAM_HPP */
