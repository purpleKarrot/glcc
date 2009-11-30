//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_49E8D458B92011DEA014CFC356D89593
#define UUID_49E8D458B92011DEA014CFC356D89593

#include <boost/la/config.hpp>
#include <boost/la/vector_traits.hpp>
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
			template <int I>
			struct
			vector_access_tag
				{
				};
			}

		template <class Vector,int I>
        BOOST_LA_INLINE_TRIVIAL
		typename vector_traits<Vector>::scalar_type &
		operator|( Vector & a, la_detail::vector_access_tag<I> (*)() )
			{
			BOOST_STATIC_ASSERT(I>=0);
			BOOST_STATIC_ASSERT(I<vector_traits<Vector>::dim);
			return vector_traits<Vector>::template w<I>(a);
			}

		template <class Vector,int I>
        BOOST_LA_INLINE_TRIVIAL
		typename vector_traits<Vector>::scalar_type
		operator|( Vector const & a, la_detail::vector_access_tag<I> (*)() )
			{
			BOOST_STATIC_ASSERT(I>=0);
			BOOST_STATIC_ASSERT(I<vector_traits<Vector>::dim);
			return vector_traits<Vector>::template r<I>(a);
			}

		template <class Vector,int I>
        BOOST_LA_INLINE_TRIVIAL
		typename vector_traits<Vector>::scalar_type &
		operator|( Vector & a, la_detail::vector_access_tag<I> )
			{
			BOOST_STATIC_ASSERT(I>=0);
			BOOST_STATIC_ASSERT(I<vector_traits<Vector>::dim);
			return vector_traits<Vector>::template w<I>(a);
			}

		template <class Vector,int I>
        BOOST_LA_INLINE_TRIVIAL
		typename vector_traits<Vector>::scalar_type
		operator|( Vector const & a, la_detail::vector_access_tag<I> )
			{
			BOOST_STATIC_ASSERT(I>=0);
			BOOST_STATIC_ASSERT(I<vector_traits<Vector>::dim);
			return vector_traits<Vector>::template r<I>(a);
			}

		template <int I>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::vector_access_tag<I>
		A()
			{
			return la_detail::vector_access_tag<I>();
			}

		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<0> X() { return la_detail::vector_access_tag<0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<1> Y() { return la_detail::vector_access_tag<1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<2> Z() { return la_detail::vector_access_tag<2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<3> W() { return la_detail::vector_access_tag<3>(); }

		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<0> A0() { return la_detail::vector_access_tag<0>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<1> A1() { return la_detail::vector_access_tag<1>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<2> A2() { return la_detail::vector_access_tag<2>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<3> A3() { return la_detail::vector_access_tag<3>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<4> A4() { return la_detail::vector_access_tag<4>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<5> A5() { return la_detail::vector_access_tag<5>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<6> A6() { return la_detail::vector_access_tag<6>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<7> A7() { return la_detail::vector_access_tag<7>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<8> A8() { return la_detail::vector_access_tag<8>(); }
		BOOST_LA_INLINE_TRIVIAL la_detail::vector_access_tag<9> A9() { return la_detail::vector_access_tag<9>(); }
		}
    }

#endif
