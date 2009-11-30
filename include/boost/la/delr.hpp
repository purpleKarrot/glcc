//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_15C6C808B95511DE840057A656D89593
#define UUID_15C6C808B95511DE840057A656D89593

#include <boost/la/config.hpp>
#include <boost/la/matrix_traits.hpp>
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
			template <int Row>
			struct delr_tag { };

			template <int Row,class OriginalMatrix>
			class
			delr_
				{
				delr_( delr_ const & );
				delr_ & operator=( delr_ const & );
				~delr_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				delr_ &
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

			template <class T,int Row>
			struct
			pipe_return<T,delr_tag<Row> >
				{
				typedef delr_<Row,T> type;
				};
			}

		template <int I,class OriginalMatrix>
		struct
		matrix_traits< la_detail::delr_<I,OriginalMatrix> >
			{
			typedef la_detail::delr_<I,OriginalMatrix> this_matrix;
			typedef typename matrix_traits<OriginalMatrix>::scalar_type scalar_type;
			static int const rows=matrix_traits<OriginalMatrix>::rows-1;
			static int const cols=matrix_traits<OriginalMatrix>::cols;

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
				return matrix_traits<OriginalMatrix>::template r<Row+(Row>=I),Col>(reinterpret_cast<OriginalMatrix const &>(x));
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
				return matrix_traits<OriginalMatrix>::template w<Row+(Row>=I),Col>(reinterpret_cast<OriginalMatrix &>(x));
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
				return matrix_traits<OriginalMatrix>::ir(row+(row>=I),col,reinterpret_cast<OriginalMatrix const &>(x));
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
				return matrix_traits<OriginalMatrix>::iw(row+(row>=I),col,reinterpret_cast<OriginalMatrix &>(x));
				}
			};

		template <int Row>
		la_detail::delr_tag<Row> delr() { return la_detail::delr_tag<Row>(); }
		}
	}

#endif
