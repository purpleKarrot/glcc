//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_2DBFB616A33B11DE8413405255D89593
#define UUID_2DBFB616A33B11DE8413405255D89593

#include <boost/la/custom/vector_assign.hpp>

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
			vector_assign_defined
				{
				static bool const value=false;
				};

			template <int I,int N>
			struct
			copy_vector_elements
				{
				template <class A,class B>
				static
				void
				f( A & a, B const & b )
					{
					vector_traits<A>::template w<I>(a)=vector_traits<B>::template r<I>(b);
					copy_vector_elements<I+1,N>::f(a,b);
					}
				};

			template <int N>
			struct
			copy_vector_elements<N,N>
				{
				template <class A,class B>
				static
				void
				f( A & a, B const & b )
					{
					}
				};
			}

		template <class A,class B>
		inline
		typename boost::enable_if_c<
			is_vector<A>::value && is_vector<B>::value &&
			vector_traits<A>::dim==vector_traits<B>::dim &&
			!la_detail::vector_assign_defined<vector_traits<A>::dim>::value,
			A &>::type
		assign( A & a, B const & b )
			{
			la_detail::copy_vector_elements<0,vector_traits<A>::dim>::f(a,b);
			return a;
			}
		}
	}

#endif
