//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_C1B803C2AE2711DEB04CC72956D89593
#define UUID_C1B803C2AE2711DEB04CC72956D89593

#include <boost/la/custom/matrix_mul_eq_matrix.hpp>
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
			template <int D>
			struct
			matrix_mul_eq_matrix_defined
				{
				static bool const value=false;
				};
			}

		template <class A,class B>
		BOOST_LA_INLINE_OPERATIONS
		typename enable_if_c<
			is_matrix<A>::value &&
			is_matrix<B>::value &&
			matrix_traits<A>::rows==matrix_traits<A>::cols &&
			matrix_traits<A>::rows==matrix_traits<B>::rows &&
			matrix_traits<A>::cols==matrix_traits<B>::cols &&
			!la_detail::matrix_mul_eq_matrix_defined<matrix_traits<A>::rows>::value,
			A &>::type
		operator*=( A & r, B const & b )
			{
			typedef typename matrix_traits<A>::scalar_type Ta;
			Ta a[matrix_traits<A>::rows][matrix_traits<A>::cols];
			for( int i=0; i<matrix_traits<A>::rows; ++i )
				for( int j=0; j<matrix_traits<B>::cols; ++j )
					a[i][j]=matrix_traits<A>::ir(i,j,r);
			for( int i=0; i<matrix_traits<A>::rows; ++i )
				for( int j=0; j<matrix_traits<B>::cols; ++j )
					{
					Ta x(scalar_traits<Ta>::zero());
					for( int k=0; k<matrix_traits<A>::cols; ++k )
						x += a[i][k]*matrix_traits<B>::ir(k,j,b);
					matrix_traits<A>::iw(i,j,r) = x;
					}
            return r;
			}
		}
	}

#endif
