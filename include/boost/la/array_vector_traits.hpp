//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_DEC6035EA1C211DEA5E8ECB856D89593
#define UUID_DEC6035EA1C211DEA5E8ECB856D89593

#include <boost/la/config.hpp>
#include <boost/la/deduce_vector.hpp>
#include <boost/la/detail/remove_const.hpp>
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>

namespace
boost
	{
	namespace
	la
		{
		template <class T,int M,int N>
		struct
		vector_traits<T[M][N]>
			{
			static int const dim=0;
			typedef void scalar_type;
			};

		template <class T,int Dim>
		struct
		vector_traits<T[Dim]>
			{
			typedef T this_vector[Dim];
			typedef typename la_detail::remove_const<T>::type scalar_type;
			static int const dim=Dim;

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_vector const & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<Dim);
				return x[I];
				}

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_vector & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<Dim);
				return x[I];
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int i, this_vector const & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<Dim);
				return x[i];
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int i, this_vector & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<Dim);
				return x[i];
				}
			};

		template <class T,int Dim,int D,class S>
		struct
		deduce_vector<T[Dim],D,S>
			{
			typedef vec<S,D> type;
			};

		template <class T1,class T2,int Dim,int D>
		struct
		deduce_vector2<T1[Dim],T2[Dim],D>
			{
			typedef vec<typename deduce_scalar<T1,T2>::type,D> type;
			};
		}
	}

#endif
