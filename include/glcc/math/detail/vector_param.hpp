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

template<typename T, std::size_t D>
struct vector_param
{
	typedef typename gl::detail::vector<T, D> const& type;
};

template<typename T, std::size_t D>
struct vector_param<T&, D>
{
	typedef typename gl::detail::vector<T, D>& type;
};

} // namespace detail
} // namespace math
} // namespace gl

#endif /* GLCC_MATH_DETAIL_VECTOR_PARAM_HPP */
