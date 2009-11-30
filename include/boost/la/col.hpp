//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_5265FC7CA1C011DE9EBDFFA956D89593
#define UUID_5265FC7CA1C011DE9EBDFFA956D89593

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
			struct col_tag { };

			template <int Col,class OriginalMatrix>
			class
			col_
				{
				col_( col_ const & );
				col_ & operator=( col_ const & );
				~col_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				col_ &
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
			pipe_return<T,col_tag<Col> >
				{
				typedef col_<Col,T> type;
				};
			}

		template <class Vector>
		struct vector_traits;

		template <int Col,class OriginalMatrix>
		struct
		vector_traits< la_detail::col_<Col,OriginalMatrix> >
			{
			typedef la_detail::col_<Col,OriginalMatrix> this_vector;
			typedef typename matrix_traits<OriginalMatrix>::scalar_type scalar_type;
			static int const dim=matrix_traits<OriginalMatrix>::rows;
			BOOST_STATIC_ASSERT(Col>=0);
			BOOST_STATIC_ASSERT(Col<matrix_traits<OriginalMatrix>::cols);

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_vector const & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return matrix_traits<OriginalMatrix>::template r<I,Col>(reinterpret_cast<OriginalMatrix const &>(x));
				}

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_vector & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return matrix_traits<OriginalMatrix>::template w<I,Col>(reinterpret_cast<OriginalMatrix &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int i, this_vector const & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return matrix_traits<OriginalMatrix>::ir(i,Col,reinterpret_cast<OriginalMatrix const &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int i, this_vector & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return matrix_traits<OriginalMatrix>::iw(i,Col,reinterpret_cast<OriginalMatrix &>(x));
				}
			};

		template <int C>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::col_tag<C>
		col()
			{
			return la_detail::col_tag<C>();
			}
		}
	}

#endif
