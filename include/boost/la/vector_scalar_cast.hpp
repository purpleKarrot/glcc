//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_8A95F136B96E11DE87FE1CD855D89593
#define UUID_8A95F136B96E11DE87FE1CD855D89593

#include <boost/la/config.hpp>
#include <boost/la/vector_traits.hpp>
#include <boost/la/deduce_vector.hpp>
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
			template <class OriginalType,class Scalar>
			class
			vector_scalar_cast_
				{
				vector_scalar_cast_( vector_scalar_cast_ const & );
				vector_scalar_cast_ & operator=( vector_scalar_cast_ const & );
				~vector_scalar_cast_();

				public:

				template <class T>
				BOOST_LA_INLINE_TRIVIAL
				vector_scalar_cast_ &
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

			template <bool> struct scalar_cast_vector_filter { };
			template <> struct scalar_cast_vector_filter<true> { typedef int type; };
			}

		template <class OriginalType,class Scalar>
		struct
		vector_traits< la_detail::vector_scalar_cast_<OriginalType,Scalar> >
			{
			typedef Scalar scalar_type;
			typedef la_detail::vector_scalar_cast_<OriginalType,Scalar> this_vector;
			static int const dim=vector_traits<OriginalType>::dim;

			template <int I>
			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			r( this_vector const & x )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return scalar_type(vector_traits<OriginalType>::template r<I>(reinterpret_cast<OriginalType const &>(x)));
				}

			static
			BOOST_LA_INLINE_CRITICAL
			scalar_type
			ir( int i, this_vector const & x )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return scalar_type(vector_traits<OriginalType>::ir(i,reinterpret_cast<OriginalType const &>(x)));
				}
			};

		template <class OriginalType,class Scalar,int D,class S>
		struct
		deduce_vector<la_detail::vector_scalar_cast_<OriginalType,Scalar>,D,S>
			{
			typedef vec<S,D> type;
			};

		template <class Scalar,class T>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::vector_scalar_cast_<T,Scalar> const &
		scalar_cast( T const & x, typename la_detail::scalar_cast_vector_filter<is_vector<T>::value>::type=0 )
			{
			return reinterpret_cast<la_detail::vector_scalar_cast_<T,Scalar> const &>(x);
			}
		}
	}

#endif
