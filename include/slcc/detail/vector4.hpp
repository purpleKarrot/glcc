/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_VECTOR_4_HPP
#define GLCC_DETAIL_VECTOR_4_HPP

#include <slcc/detail/vector.hpp>

namespace gl
{
namespace detail
{

template<typename T>
class vector<T, 4>
{
public:
	vector()
	{
	}

	vector(T val) :
		x(val), y(val), z(val), w(val)
	{
	}

	vector(T x_, T y_, T z_, T w_) :
		x(x_), y(y_), z(z_), w(w_)
	{
	}

	template<typename U>
	vector(const vector<U, 4>& other) :
		x(other.x), y(other.y), z(other.z), w(other.w)
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
	T x, y, z, w;

private:
	static T vector<T, 4>::* const mem_array[4];
};

template<typename T>
T vector<T, 4>::* const vector<T, 4>::mem_array[4] =
{ &vector<T, 4>::x, &vector<T, 4>::y, &vector<T, 4>::z, &vector<T, 4>::w };

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_VECTOR_4_HPP */
