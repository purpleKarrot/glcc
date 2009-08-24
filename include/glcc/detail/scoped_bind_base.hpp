/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_SCOPED_BIND_BASE_HPP
#define GLCC_SCOPED_BIND_BASE_HPP

#include <boost/noncopyable.hpp>
#include <glcc/detail/get.hpp>

namespace gl
{
namespace detail
{

template<typename Target, GLenum Binding>
class scoped_bind_base: private boost::noncopyable
{
	typedef typename Target::value_type value_type;

public:
	scoped_bind_base(const value_type& value) :
		stored(get<GLuint> (Binding))
	{
		Target::bind(value);
	}

	~scoped_bind_base()
	{
		Target::bind(stored);
	}

private:
	value_type stored;
};

} // namespace detail
} // namespace gl

#endif /* GLCC_SCOPED_BIND_BASE_HPP */
