/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_2_HPP
#define GLCC_DETAIL_VECTOR_2_HPP

#include <glcc/detail/vector.hpp>

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
};

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_2_HPP */
