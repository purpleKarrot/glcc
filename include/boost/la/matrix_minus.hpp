//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_A3D4B894AD8411DE9B98703856D89593
#define UUID_A3D4B894AD8411DE9B98703856D89593

#include <boost/la/custom/matrix_minus.hpp>

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
			matrix_minus_defined
				{
				static bool const value=false;
				};
			}

		template <class A>
		BOOST_LA_INLINE_OPERATIONS
        typename lazy_enable_if_c<
			is_matrix<A>::value &&
			!la_detail::matrix_minus_defined<matrix_traits<A>::rows,matrix_traits<A>::cols>::value,
			deduce_matrix<A> >::type
        operator-( A const & a )
            {
			typedef typename deduce_matrix<A>::type R;
			R r;
			for( int i=0; i!=matrix_traits<A>::rows; ++i )
				for( int j=0; j!=matrix_traits<A>::cols; ++j )
					matrix_traits<R>::iw(i,j,r)=-matrix_traits<A>::ir(i,j,a);
			return r;
            }
        }
    }

#endif
