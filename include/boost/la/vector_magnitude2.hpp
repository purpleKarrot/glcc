//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_F31342B0B24611DE9CA3E5D455D89593
#define UUID_F31342B0B24611DE9CA3E5D455D89593

#include <boost/la/custom/vector_magnitude2.hpp>
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
			vector_magnitude2_defined
				{
				static bool const value=false;
				};
			}

		template <class A>
		BOOST_LA_INLINE_OPERATIONS
		typename enable_if_c<
			is_vector<A>::value &&
			!la_detail::vector_magnitude2_defined<vector_traits<A>::dim>::value,
			typename vector_traits<A>::scalar_type>::type
		magnitude2( A const & a )
			{
			typedef typename vector_traits<A>::scalar_type T;
			T m(scalar_traits<T>::zero());
			for( int i=0; i!=vector_traits<A>::dim; ++i )
				{
				T x=vector_traits<A>::ir(i,a);
				m+=x*x;
				}
			return m;
			}
		}
	}

#endif
