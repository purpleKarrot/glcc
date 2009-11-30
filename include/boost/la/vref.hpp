//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_6D6AC1FAA33311DEABBA9A9D56D89593
#define UUID_6D6AC1FAA33311DEABBA9A9D56D89593

#include <boost/la/config.hpp>
#include <boost/la/deduce_vector.hpp>
#include <boost/utility/enable_if.hpp>
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
			template <class T>
			class
			vref_
				{
				vref_( vref_ const & );
				vref_ & operator=( vref_ const & );
				~vref_();

				public:

				template <class R>
				BOOST_LA_INLINE_TRIVIAL
				vref_ &
				operator=( R const & x )
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
			}

		template <class Vector>
		struct vector_traits;

		template <class Vector>
		struct
		vector_traits< la_detail::vref_<Vector> >
			{
			typedef typename vector_traits<Vector>::scalar_type scalar_type;
			typedef la_detail::vref_<Vector> this_vector;
			static int const dim=vector_traits<Vector>::dim;

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_vector const & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return vector_traits<Vector>::template r<I>(reinterpret_cast<Vector const &>(x));
				}

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			w( this_vector & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return vector_traits<Vector>::template w<I>(reinterpret_cast<Vector &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int i, this_vector const & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return vector_traits<Vector>::ir(i,reinterpret_cast<Vector const &>(x));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type &
			iw( int i, this_vector & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return vector_traits<Vector>::iw(i,reinterpret_cast<Vector &>(x));
				}
			};

		template <class Vector,int D,class S>
		struct
		deduce_vector<la_detail::vref_<Vector>,D,S>
			{
			typedef vec<S,D> type;
			};

		template <class Vector>
		BOOST_LA_INLINE_TRIVIAL
		typename enable_if_c<
			is_vector<Vector>::value,
			la_detail::vref_<Vector> const &>::type
		vref( Vector const & a )
			{
			return reinterpret_cast<la_detail::vref_<Vector> const &>(a);
			}

		template <class Vector>
		BOOST_LA_INLINE_TRIVIAL
		typename enable_if_c<
			is_vector<Vector>::value,
			la_detail::vref_<Vector> &>::type
		vref( Vector & a )
			{
			return reinterpret_cast<la_detail::vref_<Vector> &>(a);
			}
		}
	}

#endif
