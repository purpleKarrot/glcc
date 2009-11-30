//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_8048C57EA3E711DE9FF857BA55D89593
#define UUID_8048C57EA3E711DE9FF857BA55D89593

namespace
boost
	{
	namespace
	la
		{
		template <class Vector>
		struct
		vector_traits
			{
			static int const dim=0;
			typedef void scalar_type;
			};

		template <class T>
		struct
		is_vector
			{
			static bool const value=vector_traits<T>::dim>0;
			};
		}
	}

#endif
