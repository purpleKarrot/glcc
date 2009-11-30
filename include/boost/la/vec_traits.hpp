//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_57AD596EA33711DE914576BB56D89593
#define UUID_57AD596EA33711DE914576BB56D89593

#include <boost/la/config.hpp>
#include <boost/la/vec.hpp>
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>

namespace
boost
	{
	namespace
	la
		{
		template <class Vector>
		struct vector_traits;

		template <class T,int Dim>
		struct
		vector_traits< vec<T,Dim> >
			{
			typedef vec<T,Dim> this_vector;
			typedef T scalar_type;
			static int const dim=Dim;

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_vector const & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return x.a[I];
				}

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_vector & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return x.a[I];
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int i, this_vector const & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return x.a[i];
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int i, this_vector & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return x.a[i];
				}
			};
		}
	}

#endif
