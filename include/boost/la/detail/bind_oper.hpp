//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_4066AB9EA3E011DE8489536C55D89593
#define UUID_4066AB9EA3E011DE8489536C55D89593

namespace
boost
	{
	namespace
	la
		{
		namespace
		la_detail
			{
			template <class T,class Tag>
			struct
			pipe_return
				{
				};
			}

		template <class T,class Tag>
		typename la_detail::pipe_return<T,Tag>::type const &
		operator|( T const & a, Tag (*)() )
			{
			return reinterpret_cast<typename la_detail::pipe_return<T,Tag>::type const &>(a);
			}

		template <class T,class Tag>
		typename la_detail::pipe_return<T,Tag>::type const &
		operator|( T const & a, Tag )
			{
			return reinterpret_cast<typename la_detail::pipe_return<T,Tag>::type const &>(a);
			}

		template <class T,class Tag>
		typename la_detail::pipe_return<T,Tag>::type &
		operator|( T & a, Tag (*)() )
			{
			return reinterpret_cast<typename la_detail::pipe_return<T,Tag>::type &>(a);
			}

		template <class T,class Tag>
		typename la_detail::pipe_return<T,Tag>::type &
		operator|( T & a, Tag )
			{
			return reinterpret_cast<typename la_detail::pipe_return<T,Tag>::type &>(a);
			}
		}
	}

#endif
