/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_UNIFORM_HPP
#define GLCC_UNIFORM_HPP

#include <boost/call_traits.hpp>
#include <boost/noncopyable.hpp>
#include <glcc/detail/uniform.hpp>

namespace gl
{

template<typename T>
class uniform: private boost::noncopyable
{
	typedef typename boost::call_traits<T>::param_type param_type;

public:
	uniform() :
		location(0)
	{
	}

	uniform(GLuint program, const char* name) :
		location(glGetUniformLocation(program, name))
	{
	}

	~uniform()
	{
	}

	void locate(GLuint program, const char* name)
	{
		location = glGetUniformLocation(program, name);
	}

	param_type operator=(param_type value)
	{
		detail::uniform(location, value);
		return value;
	}

	operator T()
	{
		T value;
		assert(!"Not implemented!");
		// TODO: detail::get_uniform(location, value);
		return value;
	}

private:
	GLuint location;
};

} // namespace gl

#endif /* GLCC_UNIFORM_HPP */
