//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_339AB904A1C011DE9A625CA956D89593
#define UUID_339AB904A1C011DE9A625CA956D89593

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
			struct row_tag { };

			template <int Row,class OriginalMatrix>
			class
			row_
				{
				row_( row_ const & );
				row_ & operator=( row_ const & );
				~row_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				row_ &
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
			pipe_return<T,row_tag<Row> >
				{
				typedef row_<Row,T> type;
				};
			}

		template <class Vector>
		struct vector_traits;

		template <int Row,class OriginalMatrix>
		struct
		vector_traits< la_detail::row_<Row,OriginalMatrix> >
			{
			typedef la_detail::row_<Row,OriginalMatrix> this_vector;
			typedef typename matrix_traits<OriginalMatrix>::scalar_type scalar_type;
			static int const dim=matrix_traits<OriginalMatrix>::cols;
			BOOST_STATIC_ASSERT(Row>=0);
			BOOST_STATIC_ASSERT(Row<matrix_traits<OriginalMatrix>::rows);

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_vector const & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return matrix_traits<OriginalMatrix>::template r<Row,I>(reinterpret_cast<OriginalMatrix const &>(x));
				}

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_vector & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return matrix_traits<OriginalMatrix>::template w<Row,I>(reinterpret_cast<OriginalMatrix &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int i, this_vector const & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return matrix_traits<OriginalMatrix>::ir(Row,i,reinterpret_cast<OriginalMatrix const &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int i, this_vector & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return matrix_traits<OriginalMatrix>::iw(Row,i,reinterpret_cast<OriginalMatrix &>(x));
				}
			};

		template <int C>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::row_tag<C>
		row()
			{
			return la_detail::row_tag<C>();
			}
		}
	}

#endif
