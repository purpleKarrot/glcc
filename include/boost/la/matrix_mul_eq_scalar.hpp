//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_8395B1E8AE2711DE8D88D82856D89593
#define UUID_8395B1E8AE2711DE8D88D82856D89593

#include <boost/la/custom/matrix_mul_eq_scalar.hpp>

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
			matrix_mul_eq_scalar_defined
				{
				static bool const value=false;
				};
			}

		template <class A>
        BOOST_LA_INLINE_OPERATIONS
		typename enable_if_c<
			is_matrix<A>::value &&
			!la_detail::matrix_mul_eq_scalar_defined<matrix_traits<A>::rows,matrix_traits<A>::cols>::value,
            A &>::type
        operator*=( A & a, typename matrix_traits<A>::scalar_type b )
            {
			for( int i=0; i!=matrix_traits<A>::rows; ++i )
				for( int j=0; j!=matrix_traits<A>::cols; ++j )
					matrix_traits<A>::iw(i,j,a)*=b;
            return a;
            }
        }
    }

#endif
