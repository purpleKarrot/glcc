//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_FORCEINLINE
#	if defined(_MSC_VER)
#		define BOOST_LA_FORCEINLINE __forceinline
#	elif defined(__GNUC__) && __GNUC__>3
#		define BOOST_LA_FORCEINLINE inline __attribute__ ((always_inline))
#	else
#		define BOOST_LA_FORCEINLINE inline
#	endif
#endif

#ifndef BOOST_LA_INLINE
#define BOOST_LA_INLINE inline
#endif

#ifndef BOOST_LA_INLINE_TRIVIAL
#define BOOST_LA_INLINE_TRIVIAL BOOST_LA_FORCEINLINE
#endif

#ifndef BOOST_LA_INLINE_CRITICAL
#define BOOST_LA_INLINE_CRITICAL BOOST_LA_FORCEINLINE
#endif

#ifndef BOOST_LA_INLINE_OPERATIONS
#define BOOST_LA_INLINE_OPERATIONS BOOST_LA_INLINE
#endif

#ifndef BOOST_LA_INLINE_RECURSION
#define BOOST_LA_INLINE_RECURSION BOOST_LA_INLINE_OPERATIONS
#endif
