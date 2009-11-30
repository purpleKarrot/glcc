//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_3B4919D8A41411DEB0818E4C56D89593
#define UUID_3B4919D8A41411DEB0818E4C56D89593

#include <boost/la/detail/swizzle_traits.hpp>

namespace
boost
	{
	namespace
	la
		{
		template <int A0>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::swizzle_idx<A0>
		sw() { return la_detail::swizzle_idx<A0>(); }

		template <int A0,int A1>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::swizzle_idx<A0,la_detail::swizzle_idx<A1> >
		sw() { return la_detail::swizzle_idx<A0,la_detail::swizzle_idx<A1> >(); }

		template <int A0,int A1,int A2>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::swizzle_idx<A0,la_detail::swizzle_idx<A1,la_detail::swizzle_idx<A2> > >
		sw() { return la_detail::swizzle_idx<A0,la_detail::swizzle_idx<A1,la_detail::swizzle_idx<A2> > >(); }

		template <int A0,int A1,int A2,int A3>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::swizzle_idx<A0,la_detail::swizzle_idx<A1,la_detail::swizzle_idx<A2,la_detail::swizzle_idx<A3> > > >
		sw() { return la_detail::swizzle_idx<A0,la_detail::swizzle_idx<A1,la_detail::swizzle_idx<A2,la_detail::swizzle_idx<A3> > > >(); }

		template <class A0>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::swizzle_idx<la_detail::swizzle_tag<A0>::value>
		sw() { return la_detail::swizzle_idx<la_detail::swizzle_tag<A0>::value>(); }

		template <class A0,class A1>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::swizzle_idx<la_detail::swizzle_tag<A0>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A1>::value> >
		sw() { return la_detail::swizzle_idx<la_detail::swizzle_tag<A0>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A1>::value> >(); }

		template <class A0,class A1,class A2>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::swizzle_idx<la_detail::swizzle_tag<A0>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A1>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A2>::value> > >
		sw() { return la_detail::swizzle_idx<la_detail::swizzle_tag<A0>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A1>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A2>::value> > >(); }

		template <class A0,class A1,class A2,class A3>
		BOOST_LA_INLINE_TRIVIAL
		la_detail::swizzle_idx<la_detail::swizzle_tag<A0>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A1>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A2>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A3>::value> > > >
		sw() { return la_detail::swizzle_idx<la_detail::swizzle_tag<A0>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A1>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A2>::value,la_detail::swizzle_idx<la_detail::swizzle_tag<A3>::value> > > >(); }
		}
	}

#endif
