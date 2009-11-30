//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_47482DD8A1C011DEA9D0B1A956D89593
#define UUID_47482DD8A1C011DEA9D0B1A956D89593

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
			struct row_matrix_tag { };

			template <class OriginalVector>
			class
			row_matrix_
				{
				row_matrix_( row_matrix_ const & );
				row_matrix_ & operator=( row_matrix_ const & );
				~row_matrix_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				row_matrix_ &
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
			pipe_return<T,row_matrix_tag>
				{
				typedef row_matrix_<T> type;
				};
			}

		template <class Matrix>
		struct matrix_traits;

		template <class OriginalVector>
		struct
		matrix_traits< la_detail::row_matrix_<OriginalVector> >
			{
			typedef la_detail::row_matrix_<OriginalVector> this_matrix;
			typedef typename vector_traits<OriginalVector>::scalar_type scalar_type;
			static int const rows=1;
			static int const cols=vector_traits<OriginalVector>::dim;

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_matrix const & x )
				{
				BOOST_STATIC_ASSERT(Row==0);
				BOOST_STATIC_ASSERT(Col>=0);
				BOOST_STATIC_ASSERT(Col<cols);
				return vector_traits<OriginalVector>::template r<Col>(reinterpret_cast<OriginalVector const &>(x));
				}

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_matrix & x )
				{
				BOOST_STATIC_ASSERT(Row==0);
				BOOST_STATIC_ASSERT(Col>=0);
				BOOST_STATIC_ASSERT(Col<cols);
				return vector_traits<OriginalVector>::template w<Col>(reinterpret_cast<OriginalVector &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int row, int col, this_matrix const & x )
				{
				BOOST_ASSERT(row==0);
				BOOST_ASSERT(col>=0);
				BOOST_ASSERT(col<cols);
				return vector_traits<OriginalVector>::ir(col,reinterpret_cast<OriginalVector const &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int row, int col, this_matrix & x )
				{
				BOOST_ASSERT(row==0);
				BOOST_ASSERT(col>=0);
				BOOST_ASSERT(col<cols);
				return vector_traits<OriginalVector>::iw(col,reinterpret_cast<OriginalVector &>(x));
				}
			};

		BOOST_LA_INLINE_TRIVIAL
		la_detail::row_matrix_tag
		row_matrix()
			{
			return la_detail::row_matrix_tag();
			}
		}
	}

#endif
