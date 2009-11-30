//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_AC7E24FAB24611DE9FDAA8D255D89593
#define UUID_AC7E24FAB24611DE9FDAA8D255D89593

#include <boost/la/custom/vector_mul_scalar.hpp>

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
			vector_mul_scalar_defined
				{
				static bool const value=false;
				};
			}

		template <class A>
		BOOST_LA_INLINE_OPERATIONS
        typename lazy_enable_if_c<
			is_vector<A>::value &&
			!la_detail::vector_mul_scalar_defined<vector_traits<A>::dim>::value,
            deduce_vector<A> >::type
        operator*( A const & a, typename vector_traits<A>::scalar_type b )
            {
			typedef typename deduce_vector<A>::type R;
			R r;
			for( int i=0; i!=vector_traits<A>::dim; ++i )
				vector_traits<R>::iw(i,r)=vector_traits<A>::ir(i,a)*b;
			return r;
            }
        }
    }

#endif
