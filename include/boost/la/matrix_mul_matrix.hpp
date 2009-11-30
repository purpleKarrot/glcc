//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_D860B386AE3011DE8FFBCB6556D89593
#define UUID_D860B386AE3011DE8FFBCB6556D89593

#include <boost/utility/enable_if.hpp>
#include <boost/la/config.hpp>
#include <boost/la/deduce_matrix.hpp>
#include <boost/la/custom/matrix_mul_matrix.hpp>
#include <boost/la/scalar_traits.hpp>

namespace
boost
	{
	namespace
	la
		{
		namespace
		la_detail
			{
			template <int M,int N,int P>
			struct
			matrix_mul_matrix_defined
				{
				static bool const value=false;
				};
			}

		template <class A,class B>
		BOOST_LA_INLINE_OPERATIONS
		typename lazy_enable_if_c<
			is_matrix<A>::value && is_matrix<B>::value &&
			matrix_traits<A>::cols==matrix_traits<B>::rows &&
			!la_detail::matrix_mul_matrix_defined<matrix_traits<A>::rows,matrix_traits<A>::cols,matrix_traits<B>::cols>::value,
			deduce_matrix2<A,B,matrix_traits<A>::rows,matrix_traits<B>::cols> >::type
		operator*( A const & a, B const & b )
			{
			typedef typename deduce_matrix2<A,B,matrix_traits<A>::rows,matrix_traits<B>::cols>::type R;
			R r;
			for( int i=0; i<matrix_traits<A>::rows; ++i )
				for( int j=0; j<matrix_traits<B>::cols; ++j )
					{
					typedef typename matrix_traits<A>::scalar_type Ta;
					Ta x(scalar_traits<Ta>::zero());
					for( int k=0; k<matrix_traits<A>::cols; ++k )
						x += matrix_traits<A>::ir(i,k,a)*matrix_traits<B>::ir(k,j,b);
					matrix_traits<R>::iw(i,j,r) = x;
					}
            return r;
			}
		}
	}

#endif
