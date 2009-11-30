//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_B03E4582AE3311DEB01D577856D89593
#define UUID_B03E4582AE3311DEB01D577856D89593

#include <boost/utility/enable_if.hpp>
#include <boost/la/config.hpp>
#include <boost/la/deduce_vector.hpp>
#include <boost/la/custom/matrix_mul_vector.hpp>
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
			template <int M,int N>
			struct
			matrix_mul_vector_defined
				{
				static bool const value=false;
				};
			}

		template <class A,class B>
		BOOST_LA_INLINE_OPERATIONS
		typename lazy_enable_if_c<
			is_matrix<A>::value && is_vector<B>::value &&
			matrix_traits<A>::cols==vector_traits<B>::dim &&
			!la_detail::matrix_mul_vector_defined<matrix_traits<A>::rows,matrix_traits<A>::cols>::value,
			deduce_vector2<A,B,matrix_traits<A>::rows> >::type
		operator*( A const & a, B const & b )
			{
			typedef typename deduce_vector2<A,B,matrix_traits<A>::rows>::type R;
			R r;
			for( int i=0; i<matrix_traits<A>::rows; ++i )
				{
				typedef typename vector_traits<R>::scalar_type Tr;
				Tr x(scalar_traits<Tr>::zero());
				for( int j=0; j<matrix_traits<A>::cols; ++j )
					x += matrix_traits<A>::ir(i,j,a)*vector_traits<B>::ir(j,b);
				vector_traits<R>::iw(i,r) = x;
				}
            return r;
			}
		}
	}

#endif
