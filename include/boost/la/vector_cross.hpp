//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_297CF186B5CE11DE82D9405255D89593
#define UUID_297CF186B5CE11DE82D9405255D89593

#include <boost/utility/enable_if.hpp>
#include <boost/la/config.hpp>
#include <boost/la/deduce_vector.hpp>

namespace
boost
	{
	namespace
	la
		{
		template <class A,class B>
		BOOST_LA_INLINE_OPERATIONS
		typename lazy_enable_if_c<
			is_vector<A>::value && is_vector<B>::value &&
			vector_traits<A>::dim==3 && vector_traits<B>::dim==3,
			deduce_vector2<A,B,3> >::type
		cross( A const & a, B const & b )
			{
			typedef typename deduce_vector2<A,B,3>::type R;
			R r;
			vector_traits<R>::template w<0>(r)=
				vector_traits<A>::template r<1>(a)*vector_traits<B>::template r<2>(b)-
				vector_traits<A>::template r<2>(a)*vector_traits<B>::template r<1>(b);
			vector_traits<R>::template w<1>(r)=
				vector_traits<A>::template r<2>(a)*vector_traits<B>::template r<0>(b)-
				vector_traits<A>::template r<0>(a)*vector_traits<B>::template r<2>(b);
			vector_traits<R>::template w<2>(r)=
				vector_traits<A>::template r<0>(a)*vector_traits<B>::template r<1>(b)-
				vector_traits<A>::template r<1>(a)*vector_traits<B>::template r<0>(b);
			return r;
			}
		}
	}

#endif
