//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_57209366ACCF11DE9FDFA6A855D89593
#define UUID_57209366ACCF11DE9FDFA6A855D89593

#include <boost/la/config.hpp>
#include <boost/la/matrix_traits.hpp>
#include <boost/la/vector_traits.hpp>
#include <boost/la/scalar_traits.hpp>
#include <boost/la/detail/bind_oper.hpp>
#include <boost/assert.hpp>
#include <boost/static_assert.hpp>

namespace
boost
	{
	namespace
	la
		{
		template <class OriginalVector>
		struct vector_traits;

		namespace
		la_detail
			{
			struct trans_matrix_tag { };

			template <class OriginalVector>
			class
			trans_matrix_
				{
				trans_matrix_( trans_matrix_ const & );
				trans_matrix_ & operator=( trans_matrix_ const & );
				~trans_matrix_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				trans_matrix_ &
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
			pipe_return<T,trans_matrix_tag>
				{
				typedef trans_matrix_<T> type;
				};

			template <class M,int Row,int Col,bool TransCol=(Col==matrix_traits<M>::cols-1)>
			struct read_trans_matrix;

			template <class OriginalVector,int Row,int Col,bool TransCol>
			struct
			read_trans_matrix<trans_matrix_<OriginalVector>,Row,Col,TransCol>
				{
				static
				BOOST_LA_INLINE_CRITICAL
				typename matrix_traits< trans_matrix_<OriginalVector> >::scalar_type
				f( trans_matrix_<OriginalVector> const & )
					{
					return scalar_traits<typename matrix_traits< trans_matrix_<OriginalVector> >::scalar_type>::zero();
					}
				};

			template <class OriginalVector,int D>
			struct
			read_trans_matrix<trans_matrix_<OriginalVector>,D,D,false>
				{
				static
				BOOST_LA_INLINE_CRITICAL
				typename matrix_traits< trans_matrix_<OriginalVector> >::scalar_type
				f( trans_matrix_<OriginalVector> const & )
					{
					return scalar_traits<typename matrix_traits< trans_matrix_<OriginalVector> >::scalar_type>::one();
					}
				};

			template <class OriginalVector,int D>
			struct
			read_trans_matrix<trans_matrix_<OriginalVector>,D,D,true>
				{
				static
				BOOST_LA_INLINE_CRITICAL
				typename matrix_traits< trans_matrix_<OriginalVector> >::scalar_type
				f( trans_matrix_<OriginalVector> const & )
					{
					return scalar_traits<typename matrix_traits< trans_matrix_<OriginalVector> >::scalar_type>::one();
					}
				};

			template <class OriginalVector,int Row,int Col>
			struct
			read_trans_matrix<trans_matrix_<OriginalVector>,Row,Col,true>
				{
				static
				BOOST_LA_INLINE_CRITICAL
				typename matrix_traits< trans_matrix_<OriginalVector> >::scalar_type
				f( trans_matrix_<OriginalVector> const & x )
					{
					return vector_traits<OriginalVector>::template r<Row>(reinterpret_cast<OriginalVector const &>(x));
					}
				};
			}

		template <class OriginalVector>
		struct
		matrix_traits< la_detail::trans_matrix_<OriginalVector> >
			{
			typedef la_detail::trans_matrix_<OriginalVector> this_matrix;
			typedef typename vector_traits<OriginalVector>::scalar_type scalar_type;
			static int const rows=vector_traits<OriginalVector>::dim+1;
			static int const cols=vector_traits<OriginalVector>::dim+1;

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
				return la_detail::read_trans_matrix<la_detail::trans_matrix_<OriginalVector>,Row,Col>::f(x);
				}

			template <int Row,int Col>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_matrix & x )
				{
				BOOST_STATIC_ASSERT(Row>=0);
				BOOST_STATIC_ASSERT(Row<rows);
				BOOST_STATIC_ASSERT(Col==cols-1);
				BOOST_STATIC_ASSERT(Col!=Row);
				return vector_traits<OriginalVector>::template w<Row>(reinterpret_cast<OriginalVector &>(x));
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
				return
					row==col?
						scalar_traits<scalar_type>::one():
						(col==cols-1?
							vector_traits<OriginalVector>::ir(row,reinterpret_cast<OriginalVector const &>(x)):
							scalar_traits<scalar_type>::zero());
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int row, int col, this_matrix const & x )
				{
				BOOST_ASSERT(row>=0);
				BOOST_ASSERT(row<rows);
				BOOST_ASSERT(col==cols-1);
				BOOST_ASSERT(col!=row);
				return vector_traits<OriginalVector>::iw(row,reinterpret_cast<OriginalVector &>(x));
				}
			};

		BOOST_LA_INLINE_TRIVIAL
		la_detail::trans_matrix_tag
		trans_matrix()
			{
			return la_detail::trans_matrix_tag();
			}
		}
	}

#endif
