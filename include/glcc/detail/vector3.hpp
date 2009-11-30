/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_3_HPP
#define GLCC_DETAIL_VECTOR_3_HPP

#include <glcc/detail/vector.hpp>

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
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_3_HPP */
