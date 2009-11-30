//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_3B4D90BAAE3411DE9A62D77B56D89593
#define UUID_3B4D90BAAE3411DE9A62D77B56D89593

#include <boost/utility/enable_if.hpp>
#include <boost/la/config.hpp>
#include <boost/la/deduce_vector.hpp>
#include <boost/la/custom/vector_mul_matrix.hpp>
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
			vector_mul_matrix_defined
				{
				static bool const value=false;
				};
			}

		template <class A,class B>
		BOOST_LA_INLINE_OPERATIONS
		typename lazy_enable_if_c<
            is_vector<A>::value && is_matrix<B>::value &&
			vector_traits<A>::dim==matrix_traits<B>::rows &&
			!la_detail::vector_mul_matrix_defined<matrix_traits<B>::rows,matrix_traits<B>::cols>::value,
			deduce_vector2<A,B,matrix_traits<B>::cols> >::type
		operator*( A const & a, B const & b )
			{
			typedef typename deduce_vector2<A,B,matrix_traits<B>::cols>::type R;
			R r;
			for( int i=0; i<matrix_traits<B>::cols; ++i )
				{
				typedef typename vector_traits<R>::scalar_type Tr;
				Tr x(scalar_traits<Tr>::zero());
				for( int j=0; j<matrix_traits<B>::rows; ++j )
					x += vector_traits<A>::ir(j,a)*matrix_traits<B>::ir(j,i,b);
				vector_traits<R>::iw(i,r) = x;
				}
            return r;
			}
		}
	}

#endif
