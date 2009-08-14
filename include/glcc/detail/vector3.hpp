/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_3_HPP
#define GLCC_DETAIL_VECTOR_3_HPP

#include <glcc/detail/vector.hpp>
#include <glcc/detail/vector_element.hpp>

namespace gl
{
namespace detail
{

template<typename T>
class vector3: public gl::detail::vector<T, 3>
{
public:
	vector3()
	{
	}

	vector3(T val)
	{
		x() = val;
		y() = val;
		z() = val;
	}

	vector3(T x_, T y_, T z_)
	{
		x() = x_;
		y() = y_;
		z() = z_;
	}

	template<typename U>
	vector3(const vector<U, 3>& other)
	{
		x() = other[0];
		y() = other[1];
		z() = other[2];
	}

	GLCC_VECTOR_ELEMENT(x, 0)
	GLCC_VECTOR_ELEMENT(y, 1)
	GLCC_VECTOR_ELEMENT(z, 2)

	GLCC_VECTOR_ELEMENT(r, 0)
	GLCC_VECTOR_ELEMENT(g, 1)
	GLCC_VECTOR_ELEMENT(b, 2)

	GLCC_VECTOR_ELEMENT(s, 0)
	GLCC_VECTOR_ELEMENT(t, 1)
	GLCC_VECTOR_ELEMENT(p, 2)

	GLCC_SWIZZLE_2(x, x)
	GLCC_SWIZZLE_2(x, y)
	GLCC_SWIZZLE_2(x, z)
	GLCC_SWIZZLE_2(y, x)
	GLCC_SWIZZLE_2(y, y)
	GLCC_SWIZZLE_2(y, z)
	GLCC_SWIZZLE_2(z, x)
	GLCC_SWIZZLE_2(z, y)
	GLCC_SWIZZLE_2(z, z)

	GLCC_SWIZZLE_3(x, x, x)
	GLCC_SWIZZLE_3(x, x, y)
	GLCC_SWIZZLE_3(x, x, z)
	GLCC_SWIZZLE_3(x, y, x)
	GLCC_SWIZZLE_3(x, y, y)
	GLCC_SWIZZLE_3(x, y, z)
	GLCC_SWIZZLE_3(x, z, x)
	GLCC_SWIZZLE_3(x, z, y)
	GLCC_SWIZZLE_3(x, z, z)
	GLCC_SWIZZLE_3(y, x, x)
	GLCC_SWIZZLE_3(y, x, y)
	GLCC_SWIZZLE_3(y, x, z)
	GLCC_SWIZZLE_3(y, y, x)
	GLCC_SWIZZLE_3(y, y, y)
	GLCC_SWIZZLE_3(y, y, z)
	GLCC_SWIZZLE_3(y, z, x)
	GLCC_SWIZZLE_3(y, z, y)
	GLCC_SWIZZLE_3(y, z, z)
	GLCC_SWIZZLE_3(z, x, x)
	GLCC_SWIZZLE_3(z, x, y)
	GLCC_SWIZZLE_3(z, x, z)
	GLCC_SWIZZLE_3(z, y, x)
	GLCC_SWIZZLE_3(z, y, y)
	GLCC_SWIZZLE_3(z, y, z)
	GLCC_SWIZZLE_3(z, z, x)
	GLCC_SWIZZLE_3(z, z, y)
	GLCC_SWIZZLE_3(z, z, z)

	GLCC_SWIZZLE_4(x, x, x, x)
	GLCC_SWIZZLE_4(x, x, x, y)
	GLCC_SWIZZLE_4(x, x, x, z)
	GLCC_SWIZZLE_4(x, x, y, x)
	GLCC_SWIZZLE_4(x, x, y, y)
	GLCC_SWIZZLE_4(x, x, y, z)
	GLCC_SWIZZLE_4(x, x, z, x)
	GLCC_SWIZZLE_4(x, x, z, y)
	GLCC_SWIZZLE_4(x, x, z, z)
	GLCC_SWIZZLE_4(x, y, x, x)
	GLCC_SWIZZLE_4(x, y, x, y)
	GLCC_SWIZZLE_4(x, y, x, z)
	GLCC_SWIZZLE_4(x, y, y, x)
	GLCC_SWIZZLE_4(x, y, y, y)
	GLCC_SWIZZLE_4(x, y, y, z)
	GLCC_SWIZZLE_4(x, y, z, x)
	GLCC_SWIZZLE_4(x, y, z, y)
	GLCC_SWIZZLE_4(x, y, z, z)
	GLCC_SWIZZLE_4(x, z, x, x)
	GLCC_SWIZZLE_4(x, z, x, y)
	GLCC_SWIZZLE_4(x, z, x, z)
	GLCC_SWIZZLE_4(x, z, y, x)
	GLCC_SWIZZLE_4(x, z, y, y)
	GLCC_SWIZZLE_4(x, z, y, z)
	GLCC_SWIZZLE_4(x, z, z, x)
	GLCC_SWIZZLE_4(x, z, z, y)
	GLCC_SWIZZLE_4(x, z, z, z)
	GLCC_SWIZZLE_4(y, x, x, x)
	GLCC_SWIZZLE_4(y, x, x, y)
	GLCC_SWIZZLE_4(y, x, x, z)
	GLCC_SWIZZLE_4(y, x, y, x)
	GLCC_SWIZZLE_4(y, x, y, y)
	GLCC_SWIZZLE_4(y, x, y, z)
	GLCC_SWIZZLE_4(y, x, z, x)
	GLCC_SWIZZLE_4(y, x, z, y)
	GLCC_SWIZZLE_4(y, x, z, z)
	GLCC_SWIZZLE_4(y, y, x, x)
	GLCC_SWIZZLE_4(y, y, x, y)
	GLCC_SWIZZLE_4(y, y, x, z)
	GLCC_SWIZZLE_4(y, y, y, x)
	GLCC_SWIZZLE_4(y, y, y, y)
	GLCC_SWIZZLE_4(y, y, y, z)
	GLCC_SWIZZLE_4(y, y, z, x)
	GLCC_SWIZZLE_4(y, y, z, y)
	GLCC_SWIZZLE_4(y, y, z, z)
	GLCC_SWIZZLE_4(y, z, x, x)
	GLCC_SWIZZLE_4(y, z, x, y)
	GLCC_SWIZZLE_4(y, z, x, z)
	GLCC_SWIZZLE_4(y, z, y, x)
	GLCC_SWIZZLE_4(y, z, y, y)
	GLCC_SWIZZLE_4(y, z, y, z)
	GLCC_SWIZZLE_4(y, z, z, x)
	GLCC_SWIZZLE_4(y, z, z, y)
	GLCC_SWIZZLE_4(y, z, z, z)
	GLCC_SWIZZLE_4(z, x, x, x)
	GLCC_SWIZZLE_4(z, x, x, y)
	GLCC_SWIZZLE_4(z, x, x, z)
	GLCC_SWIZZLE_4(z, x, y, x)
	GLCC_SWIZZLE_4(z, x, y, y)
	GLCC_SWIZZLE_4(z, x, y, z)
	GLCC_SWIZZLE_4(z, x, z, x)
	GLCC_SWIZZLE_4(z, x, z, y)
	GLCC_SWIZZLE_4(z, x, z, z)
	GLCC_SWIZZLE_4(z, y, x, x)
	GLCC_SWIZZLE_4(z, y, x, y)
	GLCC_SWIZZLE_4(z, y, x, z)
	GLCC_SWIZZLE_4(z, y, y, x)
	GLCC_SWIZZLE_4(z, y, y, y)
	GLCC_SWIZZLE_4(z, y, y, z)
	GLCC_SWIZZLE_4(z, y, z, x)
	GLCC_SWIZZLE_4(z, y, z, y)
	GLCC_SWIZZLE_4(z, y, z, z)
	GLCC_SWIZZLE_4(z, z, x, x)
	GLCC_SWIZZLE_4(z, z, x, y)
	GLCC_SWIZZLE_4(z, z, x, z)
	GLCC_SWIZZLE_4(z, z, y, x)
	GLCC_SWIZZLE_4(z, z, y, y)
	GLCC_SWIZZLE_4(z, z, y, z)
	GLCC_SWIZZLE_4(z, z, z, x)
	GLCC_SWIZZLE_4(z, z, z, y)
	GLCC_SWIZZLE_4(z, z, z, z)
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_3_HPP */
