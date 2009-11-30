//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_92B1247AAE1111DE9655F2FC55D89593
#define UUID_92B1247AAE1111DE9655F2FC55D89593

#include "boost/exception/exception.hpp"
#include <exception>

namespace
boost
	{
	namespace
	la
		{
		struct
		error:
			virtual boost::exception,
			virtual std::exception
			{
			char const *
			what() const throw()
				{
				return "Boost LA error";
				}

			~error() throw()
				{
				}
			};
		}
	}

#endif
