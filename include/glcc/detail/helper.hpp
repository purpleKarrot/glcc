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

#define GLCC_OP_FUNCTOR(NAME, OP)         \
	struct NAME                           \
	{                                     \
		template<typename T>              \
		void operator()(T& left, T right) \
		{                                 \
			left OP right;                \
		}                                 \
	};

GLCC_OP_FUNCTOR(assign, =)
GLCC_OP_FUNCTOR(plus_assign, +=)
GLCC_OP_FUNCTOR(minus_assign, -=)
GLCC_OP_FUNCTOR(multiplies_assign, *=)
GLCC_OP_FUNCTOR(divides_assign, /=)

#undef GLCC_OP_FUNCTOR

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
