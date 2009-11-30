//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_77C453ACA26911DEAFD066F255D89593
#define UUID_77C453ACA26911DEAFD066F255D89593

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
			struct diag_tag { };

			template <class OriginalMatrix>
			class
			diag_
				{
				diag_( diag_ const & );
				diag_ & operator=( diag_ const & );
				~diag_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				diag_ &
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
			pipe_return<T,diag_tag>
				{
				typedef diag_<T> type;
				};

			template <int X,int Y,bool Which>
			struct diag_bool_dispatch;

			template <int X,int Y>
			struct
			diag_bool_dispatch<X,Y,true>
				{
				static int const value=X;
				};

			template <int X,int Y>
			struct
			diag_bool_dispatch<X,Y,false>
				{
				static int const value=Y;
				};
			}

		template <class Vector>
		struct vector_traits;

		template <class OriginalMatrix>
		struct
		vector_traits< la_detail::diag_<OriginalMatrix> >
			{
			typedef la_detail::diag_<OriginalMatrix> this_vector;
			typedef typename matrix_traits<OriginalMatrix>::scalar_type scalar_type;
			static int const dim=la_detail::diag_bool_dispatch<
					matrix_traits<OriginalMatrix>::rows,
					matrix_traits<OriginalMatrix>::cols,
					matrix_traits<OriginalMatrix>::rows<=matrix_traits<OriginalMatrix>::cols>::value;

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_vector const & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return matrix_traits<OriginalMatrix>::template r<I,I>(reinterpret_cast<OriginalMatrix const &>(x));
				}

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_vector & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return matrix_traits<OriginalMatrix>::template w<I,I>(reinterpret_cast<OriginalMatrix &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int i, this_vector const & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return matrix_traits<OriginalMatrix>::ir(i,i,reinterpret_cast<OriginalMatrix const &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int i, this_vector & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return matrix_traits<OriginalMatrix>::iw(i,i,reinterpret_cast<OriginalMatrix &>(x));
				}
			};

		BOOST_LA_INLINE_TRIVIAL
		la_detail::diag_tag
		diag()
			{
			return la_detail::diag_tag();
			}
		}
	}

#endif
