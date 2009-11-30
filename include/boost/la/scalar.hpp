//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_0B23ECEAB10E11DE8B61E7B455D89593
#define UUID_0B23ECEAB10E11DE8B61E7B455D89593

#include <boost/la/matrix_traits.hpp>
#include <boost/la/vector_traits.hpp>

namespace
boost
	{
	namespace
	la
		{
		namespace
		la_detail
			{
			template <class A,bool M=is_matrix<A>::value,bool V=is_vector<A>::value>
			struct
			scalar_impl
				{
				};

			template <class A>
			struct
			scalar_impl<A,true,false>
				{
				typedef typename matrix_traits<A>::scalar_type type;
				};

			template <class A>
			struct
			scalar_impl<A,false,true>
				{
				typedef typename vector_traits<A>::scalar_type type;
				};
			}

		template <class A>
		struct
		scalar
			{
			typedef typename la_detail::scalar_impl<A>::type type;
			};
		}
	}

#endif
