//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_328FC462A19A11DE93A809CD55D89593
#define UUID_328FC462A19A11DE93A809CD55D89593

#include <boost/la/config.hpp>
#include <boost/la/math.hpp>
#include <boost/static_assert.hpp>

namespace
boost
	{
	namespace
	la
		{
		namespace
		la_detail
			{
			template <class T,int Dim>
			struct
			rotz_matrix_
				{
				T s, c;

				explicit
				BOOST_LA_INLINE_TRIVIAL
				rotz_matrix_( T a ):
					s(la::sin(a)),
					c(la::cos(a))
					{
					}

				template <class R>
				BOOST_LA_INLINE_TRIVIAL
				operator R() const
					{
					R r;
					assign(r,*this);
					return r;
					}
				};

			template <int Row,int Col>
			struct
			rotz_matrix_get
				{
				template <class T,int Dim>
				static
				BOOST_LA_INLINE_CRITICAL
				T
				get( rotz_matrix_<T,Dim> const & )
					{
					return T(Row==Col);
					};
				};

			template <>
			struct
			rotz_matrix_get<0,0>
				{
				template <class T,int Dim>
				static
				BOOST_LA_INLINE_CRITICAL
				T
				get( rotz_matrix_<T,Dim> const & x )
					{
					BOOST_STATIC_ASSERT(Dim>=2);
					return x.c;
					};
				};

			template <>
			struct
			rotz_matrix_get<0,1>
				{
				template <class T,int Dim>
				static
				BOOST_LA_INLINE_CRITICAL
				T
				get( rotz_matrix_<T,Dim> const & x )
					{
					BOOST_STATIC_ASSERT(Dim>=2);
					return -x.s;
					};
				};

			template <>
			struct
			rotz_matrix_get<1,0>
				{
				template <class T,int Dim>
				static
				BOOST_LA_INLINE_CRITICAL
				T
				get( rotz_matrix_<T,Dim> const & x )
					{
					BOOST_STATIC_ASSERT(Dim>=2);
					return x.s;
					};
				};

			template <>
			struct
			rotz_matrix_get<1,1>
				{
				template <class T,int Dim>
				static
				BOOST_LA_INLINE_CRITICAL
				T
				get( rotz_matrix_<T,Dim> const & x )
					{
					BOOST_STATIC_ASSERT(Dim>=2);
					return x.c;
					};
				};
			}

		template <class Matrix>
		struct matrix_traits;

		template <class T,int Dim>
		struct
		matrix_traits< la_detail::rotz_matrix_<T,Dim> >
			{
			typedef la_detail::rotz_matrix_<T,Dim> this_matrix;
			typedef T scalar_type;
			static int const rows=Dim;
			static int const cols=Dim;

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_matrix const & x )
				{
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Col>=0);
				BOOST_STATIC_ASSERT(Row<Dim);
				BOOST_STATIC_ASSERT(Col<Dim);
				return la_detail::rotz_matrix_get<Row,Col>::get(x);
				}
			};

		template <int Dim,class T>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::rotz_matrix_<T,Dim>
		rotz_matrix( T angle )
			{
			return la_detail::rotz_matrix_<T,Dim>(angle);
			}
		}
	}

#endif
