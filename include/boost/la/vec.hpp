//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_44EB56F0A33711DEB31B41BB56D89593
#define UUID_44EB56F0A33711DEB31B41BB56D89593

namespace
boost
	{
	namespace
	la
		{
		template <class T,int D>
		struct
		vec
			{
			T a[D];
			template <class R>
			operator R() const
				{
				R r;
				assign(r,*this);
				return r;
				}
			};
		}
	}

#endif
