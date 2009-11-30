//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_FC410EE8A17B11DEA6064CA655D89593
#define UUID_FC410EE8A17B11DEA6064CA655D89593

#include <boost/la/config.hpp>
#include <boost/la/deduce_matrix.hpp>
#include <boost/la/scalar_traits.hpp>
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
			template <class T,int Rows,int Cols>
			class
			zero_matrix_
				{
				zero_matrix_( zero_matrix_ const & );
				zero_matrix_ & operator=( zero_matrix_ const & );
				~zero_matrix_();

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

		template <class T,int Rows,int Cols>
		struct
		matrix_traits< la_detail::zero_matrix_<T,Rows,Cols> >
			{
			typedef la_detail::zero_matrix_<T,Rows,Cols> this_matrix;
			typedef T scalar_type;
			static int const rows=Rows;
			static int const cols=Cols;

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_matrix const & x )
				{
				BOOST_ASSERT(&x==0);
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Row<Rows);
				BOOST_STATIC_ASSERT(Col>=0);
				BOOST_STATIC_ASSERT(Col<Cols);
				return scalar_traits<scalar_type>::zero();
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int row, int col, this_matrix const & x )
				{
				BOOST_ASSERT(&x==0);
				BOOST_ASSERT(row>=0);
				BOOST_ASSERT(row<rows);
				BOOST_ASSERT(col>=0);
				BOOST_ASSERT(col<cols);
				return scalar_traits<scalar_type>::zero();
				}
			};

		template <class T,int Rows,int Cols,int R,int C,class S>
		struct
		deduce_matrix<la_detail::zero_matrix_<T,Rows,Cols>,R,C,S>
			{
			typedef mat<S,R,C> type;
			};

		template <class T,int Rows,int Cols>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::zero_matrix_<T,Rows,Cols> const &
		zero_matrix()
			{
			return *(la_detail::zero_matrix_<T,Rows,Cols> const *)0;
			}
		}
	}

#endif
