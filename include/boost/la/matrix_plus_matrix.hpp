//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_4C02BAE8A17811DE9B2A9F8F55D89593
#define UUID_4C02BAE8A17811DE9B2A9F8F55D89593

#include <boost/utility/enable_if.hpp>
#include <boost/la/config.hpp>
#include <boost/la/deduce_matrix.hpp>
#include <boost/la/custom/matrix_plus_matrix.hpp>

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
			matrix_plus_matrix_defined
				{
				static bool const value=false;
				};
			}

		template <class A,class B>
		BOOST_LA_INLINE_OPERATIONS
		typename lazy_enable_if_c<
			is_matrix<A>::value && is_matrix<B>::value &&
			matrix_traits<A>::rows==matrix_traits<B>::rows &&
			matrix_traits<A>::cols==matrix_traits<B>::cols &&
			!la_detail::matrix_plus_matrix_defined<matrix_traits<A>::rows,matrix_traits<A>::cols>::value,
			deduce_matrix2<A,B,matrix_traits<A>::rows,matrix_traits<A>::cols> >::type
		operator+( A const & a, B const & b )
			{
			typedef typename deduce_matrix2<A,B,matrix_traits<A>::rows,matrix_traits<A>::cols>::type R;
			R r;
			for( int i=0; i!=matrix_traits<A>::rows; ++i )
				for( int j=0; j!=matrix_traits<A>::cols; ++j )
					matrix_traits<R>::iw(i,j,r)=matrix_traits<A>::ir(i,j,a)+matrix_traits<B>::ir(i,j,b);
			return r;
			}
		}
	}

#endif
