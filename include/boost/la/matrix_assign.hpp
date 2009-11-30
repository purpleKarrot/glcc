//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_90A10084A19011DEABB5838E55D89593
#define UUID_90A10084A19011DEABB5838E55D89593

#include <boost/la/custom/matrix_assign.hpp>

namespace
boost
	{
	namespace
	la
		{
		namespace
		la_detail
			{
			template <int M,int N>
			struct
			matrix_assign_defined
				{
				static bool const value=false;
				};

			template <int I,int N>
			struct
			copy_matrix_elements
				{
				template <class A,class B>
				static
				BOOST_LA_INLINE_CRITICAL
				void
				f( A & a, B const & b )
					{
					matrix_traits<A>::template w<I/matrix_traits<A>::cols,I%matrix_traits<A>::cols>(a) =
						matrix_traits<B>::template r<I/matrix_traits<B>::cols,I%matrix_traits<B>::cols>(b);
					copy_matrix_elements<I+1,N>::f(a,b);
					}
				};

			template <int N>
			struct
			copy_matrix_elements<N,N>
				{
				template <class A,class B>
				static
				BOOST_LA_INLINE_CRITICAL
				void
				f( A & a, B const & b )
					{
					}
				};
			}

		template <class A,class B>
		BOOST_LA_INLINE_TRIVIAL
		typename boost::enable_if_c<
			is_matrix<A>::value && is_matrix<B>::value &&
			matrix_traits<A>::rows==matrix_traits<B>::rows &&
			matrix_traits<A>::cols==matrix_traits<B>::cols &&
			!la_detail::matrix_assign_defined<matrix_traits<A>::rows,matrix_traits<A>::cols>::value,
			A &>::type
		assign( A & a, B const & b )
			{
			la_detail::copy_matrix_elements<0,matrix_traits<A>::rows*matrix_traits<A>::cols>::f(a,b);
			return a;
			}
		}
	}

#endif
