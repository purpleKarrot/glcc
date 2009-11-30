//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_1248A9CEA26911DE88EE9BF055D89593
#define UUID_1248A9CEA26911DE88EE9BF055D89593

#include <boost/la/config.hpp>
#include <boost/la/matrix_traits.hpp>
#include <boost/la/deduce_matrix.hpp>
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
			struct transpose_tag { };

			template <class OriginalMatrix>
			class
			transpose_
				{
				transpose_( transpose_ const & );
				transpose_ & operator=( transpose_ const & );
				~transpose_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				transpose_ &
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
			pipe_return<T,transpose_tag>
				{
				typedef transpose_<T> type;
				};
			}

		template <class OriginalMatrix>
		struct
		matrix_traits< la_detail::transpose_<OriginalMatrix> >
			{
			typedef typename matrix_traits<OriginalMatrix>::scalar_type scalar_type;
			typedef la_detail::transpose_<OriginalMatrix> this_matrix;
			static int const rows=matrix_traits<OriginalMatrix>::cols;
			static int const cols=matrix_traits<OriginalMatrix>::rows;

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_matrix const & x )
				{
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Row<rows);
				BOOST_STATIC_ASSERT(Col>=0);
				BOOST_STATIC_ASSERT(Col<cols);
				return matrix_traits<OriginalMatrix>::template r<Col,Row>(reinterpret_cast<OriginalMatrix const &>(x));
				}

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_matrix & x )
				{
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Row<rows);
				BOOST_STATIC_ASSERT(Col>=0);
				BOOST_STATIC_ASSERT(Col<cols);
				return matrix_traits<OriginalMatrix>::template w<Col,Row>(reinterpret_cast<OriginalMatrix &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int row, int col, this_matrix const & x )
				{
				BOOST_ASSERT(row>=0);
				BOOST_ASSERT(row<rows);
				BOOST_ASSERT(col>=0);
				BOOST_ASSERT(col<cols);
				return matrix_traits<OriginalMatrix>::ir(col,row,reinterpret_cast<OriginalMatrix const &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int row, int col, this_matrix & x )
				{
				BOOST_ASSERT(row>=0);
				BOOST_ASSERT(row<rows);
				BOOST_ASSERT(col>=0);
				BOOST_ASSERT(col<cols);
				return matrix_traits<OriginalMatrix>::iw(col,row,reinterpret_cast<OriginalMatrix &>(x));
				}
			};

		template <class OriginalMatrix,int R,int C,class S>
		struct
		deduce_matrix<la_detail::transpose_<OriginalMatrix>,R,C,S>
			{
			typedef mat<S,R,C> type;
			};

		BOOST_LA_INLINE_TRIVIAL
		la_detail::transpose_tag
		transpose()
			{
			return la_detail::transpose_tag();
			}
		}
	}

#endif
