//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_3EDF999CA1C011DEBA5C8DA956D89593
#define UUID_3EDF999CA1C011DEBA5C8DA956D89593

#include <boost/la/config.hpp>
#include <boost/la/vector_traits.hpp>
#include <boost/la/detail/bind_oper.hpp>
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
			struct col_matrix_tag { };

			template <class OriginalVector>
			class
			col_matrix_
				{
				col_matrix_( col_matrix_ const & );
				col_matrix_ & operator=( col_matrix_ const & );
				~col_matrix_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				col_matrix_ &
				operator=( T const & x )
					{
					assign(*this,x);
					return *this;
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

			template <class T>
			struct
			pipe_return<T,col_matrix_tag>
				{
				typedef col_matrix_<T> type;
				};
			}

		template <class Vector>
		struct matrix_traits;

		template <class OriginalVector>
		struct
		matrix_traits< la_detail::col_matrix_<OriginalVector> >
			{
			typedef la_detail::col_matrix_<OriginalVector> this_matrix;
			typedef typename vector_traits<OriginalVector>::scalar_type scalar_type;
			static int const rows=vector_traits<OriginalVector>::dim;
			static int const cols=1;

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_matrix const & x )
				{
				BOOST_STATIC_ASSERT(Col==0);
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Row<rows);
				return vector_traits<OriginalVector>::template r<Row>(reinterpret_cast<OriginalVector const &>(x));
				}

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_matrix & x )
				{
				BOOST_STATIC_ASSERT(Col==0);
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Row<rows);
				return vector_traits<OriginalVector>::template w<Row>(reinterpret_cast<OriginalVector &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int row, int col, this_matrix const & x )
				{
				BOOST_ASSERT(col==0);
				BOOST_ASSERT(row>=0);
				BOOST_ASSERT(row<rows);
				return vector_traits<OriginalVector>::ir(row,reinterpret_cast<OriginalVector const &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int row, int col, this_matrix & x )
				{
				BOOST_ASSERT(col==0);
				BOOST_ASSERT(row>=0);
				BOOST_ASSERT(row<rows);
				return vector_traits<OriginalVector>::iw(row,reinterpret_cast<OriginalVector &>(x));
				}
			};

		BOOST_LA_INLINE_TRIVIAL
		la_detail::col_matrix_tag
		col_matrix()
			{
			return la_detail::col_matrix_tag();
			}
		}
	}

#endif
