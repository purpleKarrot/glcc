//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_65C5A806B95511DE99A226A756D89593
#define UUID_65C5A806B95511DE99A226A756D89593

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
			template <int Col>
			struct delc_tag { };

			template <int Col,class OriginalMatrix>
			class
			delc_
				{
				delc_( delc_ const & );
				delc_ & operator=( delc_ const & );
				~delc_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				delc_ &
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

			template <class T,int Col>
			struct
			pipe_return<T,delc_tag<Col> >
				{
				typedef delc_<Col,T> type;
				};
			}

		template <int J,class OriginalMatrix>
		struct
		matrix_traits< la_detail::delc_<J,OriginalMatrix> >
			{
			typedef la_detail::delc_<J,OriginalMatrix> this_matrix;
			typedef typename matrix_traits<OriginalMatrix>::scalar_type scalar_type;
			static int const rows=matrix_traits<OriginalMatrix>::rows;
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
				return matrix_traits<OriginalMatrix>::template r<Row,Col+(Col>=J)>(reinterpret_cast<OriginalMatrix const &>(x));
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
				return matrix_traits<OriginalMatrix>::template w<Row,Col+(Col>=J)>(reinterpret_cast<OriginalMatrix &>(x));
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
				return matrix_traits<OriginalMatrix>::ir(row,col+(col>=J),reinterpret_cast<OriginalMatrix const &>(x));
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
				return matrix_traits<OriginalMatrix>::iw(row,col+(col>=J),reinterpret_cast<OriginalMatrix &>(x));
				}
			};

		template <int Col>
		la_detail::delc_tag<Col> delc() { return la_detail::delc_tag<Col>(); }
		}
	}

#endif
