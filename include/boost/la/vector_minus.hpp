//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_727590E8B24811DEBB692CE655D89593
#define UUID_727590E8B24811DEBB692CE655D89593

#include <boost/la/custom/vector_minus.hpp>

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
			vector_minus_defined
				{
				static bool const value=false;
				};
			}

		template <class A>
		BOOST_LA_INLINE_OPERATIONS
        typename lazy_enable_if_c<
			is_vector<A>::value &&
			!la_detail::vector_minus_defined<vector_traits<A>::dim>::value,
			deduce_vector<A> >::type
        operator-( A const & a )
            {
			typedef typename deduce_vector<A>::type R;
			R r;
			for( int i=0; i!=vector_traits<A>::dim; ++i )
				vector_traits<R>::iw(i,r)=-vector_traits<A>::ir(i,a);
			return r;
            }
        }
    }

#endif
