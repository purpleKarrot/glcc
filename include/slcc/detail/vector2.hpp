/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_2_HPP
#define GLCC_DETAIL_VECTOR_2_HPP

#include <slcc/detail/vector.hpp>

namespace gl
{
namespace detail
{

template<typename T>
class vector<T, 2>
{
public:
	vector()
	{
	}

	vector(T val) :
		x(val), y(val)
	{
	}

	vector(T x_, T y_) :
		x(x_), y(y_)
	{
	}

	template<typename U>
	vector(const vector<U, 2>& other) :
		x(other.x), y(other.y)
	{
	}

public:
	T operator[](std::size_t i) const
	{
		return this->*mem_array[i];
	}

	T& operator[](std::size_t i)
	{
		return this->*mem_array[i];
	}

public:
	T x, y;

private:
	static T vector<T, 2>::* const mem_array[2];
};

template<typename T>
T vector<T, 2>::* const vector<T, 2>::mem_array[2] =
{ &vector<T, 2>::x, &vector<T, 2>::y };

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_2_HPP */
