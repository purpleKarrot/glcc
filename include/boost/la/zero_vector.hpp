//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_F8101DE2A17F11DE976588BF55D89593
#define UUID_F8101DE2A17F11DE976588BF55D89593

#include <boost/la/config.hpp>
#include <boost/la/deduce_vector.hpp>
#include <boost/la/scalar_traits.hpp>
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
			template <class T,int Dim>
			class
			zero_vector_
				{
				zero_vector_( zero_vector_ const & );
				zero_vector_ & operator=( zero_vector_ const & );
				~zero_vector_();

				public:

				template <class R>
				BOOST_LA_INLINE_TRIVIAL
				operator R() const
					{
					R r;
					assign(r,*this);
					return r;
					}
				};
			}

		template <class Vector>
		struct vector_traits;

		template <class T,int Dim>
		struct
		vector_traits< la_detail::zero_vector_<T,Dim> >
			{
			typedef la_detail::zero_vector_<T,Dim> this_vector;
			typedef T scalar_type;
			static int const dim=Dim;

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_vector const & x )
				{
				BOOST_ASSERT(&x==0);
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<Dim);
				return scalar_traits<scalar_type>::zero();
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int i, this_vector const & x )
				{
				BOOST_ASSERT(&x==0);
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<Dim);
				return scalar_traits<scalar_type>::zero();
				}
			};

		template <class T,int Dim>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::zero_vector_<T,Dim> const &
		zero_vector()
			{
			return *(la_detail::zero_vector_<T,Dim> const *)0;
			}
		}
	}

#endif
