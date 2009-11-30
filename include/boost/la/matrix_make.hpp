//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_8328668EACC311DE8A2F7C5955D89593
#define UUID_8328668EACC311DE8A2F7C5955D89593

#include <boost/la/custom/matrix_make.hpp>
#include <boost/la/matrix_assign.hpp>

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
			matrix_make_defined
				{
				static bool const value=false;
				};
			}

		template <class R,class A>
		BOOST_LA_INLINE_TRIVIAL
		typename enable_if_c<
			is_matrix<R>::value && is_matrix<A>::value &&
			matrix_traits<R>::rows==matrix_traits<A>::rows &&
			matrix_traits<R>::cols==matrix_traits<A>::cols &&
			!la_detail::matrix_make_defined<matrix_traits<A>::rows,matrix_traits<A>::cols>::value,
			R>::type
		make( A const & a )
			{
			R r; assign(r,a);
			return r;
			}
		}
	}

#endif
