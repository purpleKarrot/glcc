//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_AEE9F0E4B24A11DE9DEAB5F355D89593
#define UUID_AEE9F0E4B24A11DE9DEAB5F355D89593

#include <boost/la/deduce_scalar.hpp>
#include <boost/la/custom/vector_dot.hpp>
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
			vector_dot_defined
				{
				static bool const value=false;
				};
			}

		template <class A,class B>
		BOOST_LA_INLINE_OPERATIONS
		typename lazy_enable_if_c<
			is_vector<A>::value && is_vector<B>::value &&
			vector_traits<A>::dim==vector_traits<B>::dim &&
			!la_detail::vector_dot_defined<vector_traits<A>::dim>::value,
			deduce_scalar<typename vector_traits<A>::scalar_type,typename vector_traits<B>::scalar_type> >::type
		dot( A const & a, B const & b )
			{
			typedef typename deduce_scalar<typename vector_traits<A>::scalar_type,typename vector_traits<B>::scalar_type>::type T;
			T m(scalar_traits<T>::zero());
			for( int i=0; i!=vector_traits<A>::dim; ++i )
				m+=vector_traits<A>::ir(i,a)*vector_traits<B>::ir(i,b);
			return m;
			}
		}
	}

#endif
