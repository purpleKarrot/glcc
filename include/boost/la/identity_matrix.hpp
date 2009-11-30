//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_D6250026A17F11DEA29012BF55D89593
#define UUID_D6250026A17F11DEA29012BF55D89593

#include <boost/la/config.hpp>
#include <boost/la/deduce_matrix.hpp>
#include <boost/assert.hpp>
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
			class
			identity_matrix_
				{
				identity_matrix_( identity_matrix_ const & );
				identity_matrix_ & operator=( identity_matrix_ const & );
				~identity_matrix_();

				public:

				template <class R>
				BOOST_LA_INLINE_TRIVIAL
				operator R() const
					{
					R r;
					assign(r,*this);
					return r;
					}
				};
			}

		template <class Matrix>
		struct matrix_traits;

		template <class T,int Dim>
		struct
		matrix_traits< la_detail::identity_matrix_<T,Dim> >
			{
			typedef la_detail::identity_matrix_<T,Dim> this_matrix;
			typedef T scalar_type;
			static int const rows=Dim;
			static int const cols=Dim;

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_matrix const & x )
				{
				BOOST_ASSERT(&x==0);
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Row<Dim);
				BOOST_STATIC_ASSERT(Col>=0);
				BOOST_STATIC_ASSERT(Col<Dim);
				return scalar_type(Row==Col);
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int row, int col, this_matrix const & x )
				{
				BOOST_ASSERT(&x==0);
				BOOST_ASSERT(row>=0);
				BOOST_ASSERT(row<Dim);
				BOOST_ASSERT(col>=0);
				BOOST_ASSERT(col<Dim);
				return scalar_type(row==col);
				}
			};

		template <class T,int Dim,int R,int C,class S>
		struct
		deduce_matrix<la_detail::identity_matrix_<T,Dim>,R,C,S>
			{
			typedef mat<S,R,C> type;
			};

		template <class T,int Dim>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::identity_matrix_<T,Dim> const &
		identity_matrix()
			{
			return *(la_detail::identity_matrix_<T,Dim> const *)0;
			}
		}
	}

#endif
