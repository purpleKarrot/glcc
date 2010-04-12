/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_3_HPP
#define GLCC_DETAIL_VECTOR_3_HPP

#include <slcc/detail/vector.hpp>

namespace gl
{
namespace detail
{

template<typename T>
class vector<T, 3>
{
public:
	vector()
	{
	}

	vector(T val) :
		x(val), y(val), z(val)
	{
	}

	vector(T x_, T y_, T z_) :
		x(x_), y(y_), z(z_)
	{
	}

	template<typename U>
	vector(const vector<U, 3>& other) :
		x(other.x), y(other.y), z(other.z)
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
	T x, y, z;

private:
	static T vector<T, 3>::* const mem_array[3];
};

template<typename T>
T vector<T, 3>::* const vector<T, 3>::mem_array[3] =
{ &vector<T, 3>::x, &vector<T, 3>::y, &vector<T, 3>::z };

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_3_HPP */
