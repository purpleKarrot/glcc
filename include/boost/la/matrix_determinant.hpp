//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_44F0A73CAD6311DEB15C0A6355D89593
#define UUID_44F0A73CAD6311DEB15C0A6355D89593

#include <boost/la/custom/matrix_determinant.hpp>
#include <boost/la/detail/determinant_impl.hpp>

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
			matrix_determinant_defined
				{
				static bool const value=false;
				};
			}

		template <class A>
		BOOST_LA_INLINE_TRIVIAL
		typename enable_if_c<
			is_matrix<A>::value &&
			matrix_traits<A>::rows==matrix_traits<A>::cols &&
			!la_detail::matrix_determinant_defined<matrix_traits<A>::rows>::value,
			typename matrix_traits<A>::scalar_type>::type
		determinant( A const & a )
			{
			return la_detail::determinant_impl(a);
			}
		}
	}

#endif
