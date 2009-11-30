//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_1748793AAE0E11DE91888BE355D89593
#define UUID_1748793AAE0E11DE91888BE355D89593

#include <boost/la/custom/matrix_inverse.hpp>
#include <boost/la/matrix_determinant.hpp>
#include <boost/la/scalar_traits.hpp>
#include <boost/throw_exception.hpp>
#include <boost/la/matrix_mul_scalar.hpp>
#include <boost/la/transpose.hpp>
#include <boost/la/zero_determinant_error.hpp>
#include <boost/la/detail/cofactor_impl.hpp>

namespace
boost
	{
	namespace
	la
		{
		namespace
		la_detail
			{
			template <int D>
			struct
			matrix_inverse_defined
				{
				static bool const value=false;
				};
			}

		template <class A>
		BOOST_LA_INLINE_TRIVIAL
		typename lazy_enable_if_c<
			is_matrix<A>::value &&
			matrix_traits<A>::rows==matrix_traits<A>::cols &&
			!la_detail::matrix_inverse_defined<matrix_traits<A>::rows>::value,
			deduce_matrix<A> >::type
		inverse( A const & a, typename matrix_traits<A>::scalar_type det )
			{
			typedef typename matrix_traits<A>::scalar_type T;
			BOOST_ASSERT(det!=scalar_traits<T>::zero());
			T f=scalar_traits<T>::one()/det;
			return (la_detail::cofactor_impl(a)|transpose) * f;
			}

		template <class A>
		BOOST_LA_INLINE_TRIVIAL
		typename lazy_enable_if_c<
			is_matrix<A>::value &&
			matrix_traits<A>::rows==matrix_traits<A>::cols,
			deduce_matrix<A> >::type
		inverse( A const & a )
			{
			typedef typename matrix_traits<A>::scalar_type T;
			T det=determinant(a);
			if( det==scalar_traits<T>::zero() )
				BOOST_THROW_EXCEPTION(zero_determinant_error());
			return inverse(a,det);
			}
		}
	}

#endif
