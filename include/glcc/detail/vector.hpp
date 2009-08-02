/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_TYPES_VECTOR_HPP
#define GLCC_MATH_TYPES_VECTOR_HPP

#include <glcc/detail/vector2.hpp>
#include <glcc/detail/vector3.hpp>
#include <glcc/detail/vector4.hpp>

namespace gl
{
namespace detail
{

template<typename T, std::size_t N>
struct vector
{
};

template<typename T>
struct vector<T, 2>
{
	typedef vector2<T> type;
};

template<typename T>
struct vector<T, 3>
{
	typedef vector3<T> type;
};

template<typename T>
struct vector<T, 4>
{
	typedef vector4<T> type;
};

} // namespace detail
} // namespace gl

#endif /* GLCC_MATH_TYPES_VECTOR_HPP */
