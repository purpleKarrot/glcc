/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_4_HPP
#define GLCC_DETAIL_VECTOR_4_HPP

#include <glcc/detail/vector.hpp>

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
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_4_HPP */
