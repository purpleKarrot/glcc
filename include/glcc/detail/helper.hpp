/*
 * helper.hpp
 *
 *  Created on: 28.02.2009
 *      Author: daniel
 */

#ifndef HELPER_HPP_
#define HELPER_HPP_

namespace gl
{
namespace detail
{

struct assign
{
	template<typename T>
	void operator()(T& left, T right)
	{
		left = right;
	}
};

struct plus_assign
{
	template<typename T>
	void operator()(T& left, T right)
	{
		left += right;
	}
};

struct minus_assign
{
	template<typename T>
	void operator()(T& left, T right)
	{
		left -= right;
	}
};

struct multiplies_assign
{
	template<typename T>
	void operator()(T& left, T right)
	{
		left *= right;
	}
};

struct divides_assign
{
	template<typename T>
	void operator()(T& left, T right)
	{
		left /= right;
	}
};

template<std::size_t N>
struct loop_op
{
	template<typename T, typename F>
	static void eval(F f, T* left, const T* right)
	{
		f(*left, *right);
		loop_op<N - 1>::eval(f, ++left, ++right);
	}

	template<typename T, typename F>
	static void eval(F f, T* left, T right)
	{
		f(*left, right);
		loop_op<N - 1>::eval(f, ++left, right);
	}
};

template<>
struct loop_op<0>
{
	template<typename F, typename U, typename V>
	static void eval(F, U, V)
	{
	}
};

} // namespace detail
} // namespace gl

#endif /* HELPER_HPP_ */
