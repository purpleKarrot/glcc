//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_67E67D68A32F11DEA56FD18556D89593
#define UUID_67E67D68A32F11DEA56FD18556D89593

namespace
boost
	{
	namespace
	la
		{
		template <class T,int Rows,int Cols>
		struct
		mat
			{
			T a[Rows][Cols];
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
