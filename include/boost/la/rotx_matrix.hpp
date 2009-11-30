//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_F1FD2A20A1BC11DEA67B0F9756D89593
#define UUID_F1FD2A20A1BC11DEA67B0F9756D89593

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
			rotx_matrix_
				{
				T s, c;

				explicit
				BOOST_LA_INLINE_TRIVIAL
				rotx_matrix_( T a ):
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
			rotx_matrix_get
				{
				template <class T,int Dim>
				static
				BOOST_LA_INLINE_CRITICAL
				T
				get( rotx_matrix_<T,Dim> const & )
					{
					return T(Row==Col);
					};
				};

			template <>
			struct
			rotx_matrix_get<1,1>
				{
				template <class T,int Dim>
				static
				BOOST_LA_INLINE_CRITICAL
				T
				get( rotx_matrix_<T,Dim> const & x )
					{
					BOOST_STATIC_ASSERT(Dim>2);
					return x.c;
					};
				};

			template <>
			struct
			rotx_matrix_get<1,2>
				{
				template <class T,int Dim>
				static
				T
				BOOST_LA_INLINE_CRITICAL
				get( rotx_matrix_<T,Dim> const & x )
					{
					BOOST_STATIC_ASSERT(Dim>2);
					return -x.s;
					};
				};

			template <>
			struct
			rotx_matrix_get<2,1>
				{
				template <class T,int Dim>
				static
				T
				BOOST_LA_INLINE_CRITICAL
				get( rotx_matrix_<T,Dim> const & x )
					{
					BOOST_STATIC_ASSERT(Dim>2);
					return x.s;
					};
				};

			template <>
			struct
			rotx_matrix_get<2,2>
				{
				template <class T,int Dim>
				static
				BOOST_LA_INLINE_CRITICAL
				T
				get( rotx_matrix_<T,Dim> const & x )
					{
					BOOST_STATIC_ASSERT(Dim>2);
					return x.c;
					};
				};
			}

		template <class Matrix>
		struct matrix_traits;

		template <class T,int Dim>
		struct
		matrix_traits< la_detail::rotx_matrix_<T,Dim> >
			{
			typedef la_detail::rotx_matrix_<T,Dim> this_matrix;
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
				return la_detail::rotx_matrix_get<Row,Col>::get(x);
				}
			};

		template <int Dim,class T>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::rotx_matrix_<T,Dim>
		rotx_matrix( T angle )
			{
			return la_detail::rotx_matrix_<T,Dim>(angle);
			}
		}
	}

#endif
