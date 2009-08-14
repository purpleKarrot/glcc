/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_4_HPP
#define GLCC_DETAIL_VECTOR_4_HPP

#include <glcc/detail/vector.hpp>
#include <glcc/detail/vector_element.hpp>

namespace gl
{
namespace detail
{

template<typename T>
class vector4: public gl::detail::vector<T, 4>
{
public:
	vector4()
	{
	}

	vector4(T val)
	{
		x() = val;
		y() = val;
		z() = val;
		w() = val;
	}

	vector4(T x_, T y_, T z_, T w_)
	{
		x() = x_;
		y() = y_;
		z() = z_;
		w() = w_;
	}

	template<typename U>
	vector4(const vector<U, 4>& other)
	{
		x() = other[0];
		y() = other[1];
		z() = other[2];
		w() = other[3];
	}

	GLCC_VECTOR_ELEMENT(x, 0)
	GLCC_VECTOR_ELEMENT(y, 1)
	GLCC_VECTOR_ELEMENT(z, 2)
	GLCC_VECTOR_ELEMENT(w, 3)

	GLCC_VECTOR_ELEMENT(r, 0)
	GLCC_VECTOR_ELEMENT(g, 1)
	GLCC_VECTOR_ELEMENT(b, 2)
	GLCC_VECTOR_ELEMENT(a, 3)

	GLCC_VECTOR_ELEMENT(s, 0)
	GLCC_VECTOR_ELEMENT(t, 1)
	GLCC_VECTOR_ELEMENT(p, 2)
	GLCC_VECTOR_ELEMENT(q, 3)

	GLCC_SWIZZLE_2(x, x)
	GLCC_SWIZZLE_2(x, y)
	GLCC_SWIZZLE_2(x, z)
	GLCC_SWIZZLE_2(x, w)
	GLCC_SWIZZLE_2(y, x)
	GLCC_SWIZZLE_2(y, y)
	GLCC_SWIZZLE_2(y, z)
	GLCC_SWIZZLE_2(y, w)
	GLCC_SWIZZLE_2(z, x)
	GLCC_SWIZZLE_2(z, y)
	GLCC_SWIZZLE_2(z, z)
	GLCC_SWIZZLE_2(z, w)
	GLCC_SWIZZLE_2(w, x)
	GLCC_SWIZZLE_2(w, y)
	GLCC_SWIZZLE_2(w, z)
	GLCC_SWIZZLE_2(w, w)
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_4_HPP */
