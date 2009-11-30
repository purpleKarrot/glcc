//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_6076F0B2B24811DE8B5FB2E555D89593
#define UUID_6076F0B2B24811DE8B5FB2E555D89593

#include <boost/utility/enable_if.hpp>
#include <boost/la/config.hpp>
#include <boost/la/deduce_vector.hpp>
#include <boost/la/custom/vector_minus_vector.hpp>

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
			vector_minus_vector_defined
				{
				static bool const value=false;
				};
			}

		template <class A,class B>
		BOOST_LA_INLINE_OPERATIONS
		typename lazy_enable_if_c<
			is_vector<A>::value && is_vector<B>::value &&
			vector_traits<A>::dim==vector_traits<B>::dim &&
			!la_detail::vector_minus_vector_defined<vector_traits<A>::dim>::value,
			deduce_vector2<A,B,vector_traits<A>::dim> >::type
		operator-( A const & a, B const & b )
			{
			typedef typename deduce_vector2<A,B,vector_traits<A>::dim>::type R;
			R r;
			for( int i=0; i!=vector_traits<A>::dim; ++i )
				vector_traits<R>::iw(i,r)=vector_traits<A>::ir(i,a)-vector_traits<B>::ir(i,b);
			return r;
			}
		}
	}

#endif
