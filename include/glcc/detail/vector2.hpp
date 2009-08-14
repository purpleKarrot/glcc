/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_2_HPP
#define GLCC_DETAIL_VECTOR_2_HPP

#include <glcc/detail/vector.hpp>
#include <glcc/detail/vector_element.hpp>

namespace gl
{
namespace detail
{

template<typename T>
class vector2: public gl::detail::vector<T, 2>
{
public:
	vector2()
	{
	}

	vector2(T val)
	{
		x() = val;
		y() = val;
	}

	vector2(T x_, T y_)
	{
		x() = x_;
		y() = y_;
	}

	template<typename U>
	vector2(const vector<U, 2>& other)
	{
		x() = other[0];
		y() = other[1];
	}

	GLCC_VECTOR_ELEMENT(x, 0)
	GLCC_VECTOR_ELEMENT(y, 1)

	GLCC_SWIZZLE_2(x, x)
	GLCC_SWIZZLE_2(x, y)
	GLCC_SWIZZLE_2(y, x)
	GLCC_SWIZZLE_2(y, y)

	GLCC_SWIZZLE_3(x, x, x)
	GLCC_SWIZZLE_3(x, x, y)
	GLCC_SWIZZLE_3(x, y, x)
	GLCC_SWIZZLE_3(x, y, y)
	GLCC_SWIZZLE_3(y, x, x)
	GLCC_SWIZZLE_3(y, x, y)
	GLCC_SWIZZLE_3(y, y, x)
	GLCC_SWIZZLE_3(y, y, y)

	GLCC_SWIZZLE_4(x, x, x, x)
	GLCC_SWIZZLE_4(x, x, x, y)
	GLCC_SWIZZLE_4(x, x, y, x)
	GLCC_SWIZZLE_4(x, x, y, y)
	GLCC_SWIZZLE_4(x, y, x, x)
	GLCC_SWIZZLE_4(x, y, x, y)
	GLCC_SWIZZLE_4(x, y, y, x)
	GLCC_SWIZZLE_4(x, y, y, y)
	GLCC_SWIZZLE_4(y, x, x, x)
	GLCC_SWIZZLE_4(y, x, x, y)
	GLCC_SWIZZLE_4(y, x, y, x)
	GLCC_SWIZZLE_4(y, x, y, y)
	GLCC_SWIZZLE_4(y, y, x, x)
	GLCC_SWIZZLE_4(y, y, x, y)
	GLCC_SWIZZLE_4(y, y, y, x)
	GLCC_SWIZZLE_4(y, y, y, y)
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_2_HPP */
