//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_14D494E4ACC511DE91E7736255D89593
#define UUID_14D494E4ACC511DE91E7736255D89593

#include <boost/la/custom/vector_make.hpp>
#include <boost/la/vector_assign.hpp>

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
			vector_make_defined
				{
				static bool const value=false;
				};
			}

		template <class R,class A>
		BOOST_LA_INLINE_TRIVIAL
		typename enable_if_c<
			is_vector<R>::value && is_vector<A>::value &&
			vector_traits<R>::dim==vector_traits<A>::dim &&
			!la_detail::vector_make_defined<vector_traits<R>::dim>::value,
			R>::type
		make( A const & a )
			{
			R r; assign(r,a);
			return r;
			}
		}
	}

#endif
