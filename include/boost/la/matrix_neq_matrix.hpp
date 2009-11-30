//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_08842074B17A11DE9975A45356D89593
#define UUID_08842074B17A11DE9975A45356D89593

#include <boost/la/custom/matrix_neq_matrix.hpp>

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
			matrix_neq_matrix_defined
				{
				static bool const value=false;
				};
			}

		template <class A,class B>
		BOOST_LA_INLINE_OPERATIONS
		typename enable_if_c<
			is_matrix<A>::value && is_matrix<B>::value &&
			matrix_traits<A>::rows==matrix_traits<B>::rows &&
			matrix_traits<A>::cols==matrix_traits<B>::cols &&
			!la_detail::matrix_neq_matrix_defined<matrix_traits<A>::rows,matrix_traits<A>::cols>::value,
			bool>::type
		operator!=( A const & a, B const & b )
			{
			for( int i=0; i!=matrix_traits<A>::rows; ++i )
				for( int j=0; j!=matrix_traits<A>::cols; ++j )
					if( matrix_traits<A>::ir(i,j,a)!=matrix_traits<B>::ir(i,j,b) )
						return true;
			return false;
			}
		}
	}

#endif
