//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_20D98340A3EB11DEB2180CD156D89593
#define UUID_20D98340A3EB11DEB2180CD156D89593

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
			template <int Row,int Col>
			struct delrc_tag { };

			template <int Row,int Col,class OriginalMatrix>
			class
			delrc_
				{
				delrc_( delrc_ const & );
				delrc_ & operator=( delrc_ const & );
				~delrc_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				delrc_ &
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

			template <class T,int Row,int Col>
			struct
			pipe_return<T,delrc_tag<Row,Col> >
				{
				typedef delrc_<Row,Col,T> type;
				};
			}

		template <int I,int J,class OriginalMatrix>
		struct
		matrix_traits< la_detail::delrc_<I,J,OriginalMatrix> >
			{
			typedef la_detail::delrc_<I,J,OriginalMatrix> this_matrix;
			typedef typename matrix_traits<OriginalMatrix>::scalar_type scalar_type;
			static int const rows=matrix_traits<OriginalMatrix>::rows-1;
			static int const cols=matrix_traits<OriginalMatrix>::cols-1;

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
				return matrix_traits<OriginalMatrix>::template r<Row+(Row>=I),Col+(Col>=J)>(reinterpret_cast<OriginalMatrix const &>(x));
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
				return matrix_traits<OriginalMatrix>::template w<Row+(Row>=I),Col+(Col>=J)>(reinterpret_cast<OriginalMatrix &>(x));
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
				return matrix_traits<OriginalMatrix>::ir(row+(row>=I),col+(col>=J),reinterpret_cast<OriginalMatrix const &>(x));
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
				return matrix_traits<OriginalMatrix>::iw(row+(row>=I),col+(col>=J),reinterpret_cast<OriginalMatrix &>(x));
				}
			};

		template <int Row,int Col>
		la_detail::delrc_tag<Row,Col> delrc() { return la_detail::delrc_tag<Row,Col>(); }
		}
	}

#endif
