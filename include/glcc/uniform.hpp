/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_UNIFORM_HPP
#define GLCC_UNIFORM_HPP

#include <boost/call_traits.hpp>
#include <boost/noncopyable.hpp>
//#include <glcc/detail/uniform.hpp>

namespace gl
{

template<typename T>
class uniform: private boost::noncopyable
{
	typedef typename boost::call_traits<T>::param_type param_type;

public:
	uniform() :
		program(0), location(0)
	{
	}

	uniform(GLuint program, GLuint location) :
		program(program), location(location)
	{
	}

	uniform(GLuint program, const char* name) :
		program(program), location(glGetUniformLocation(program, name))
	{
	}

	~uniform()
	{
	}

	void assign(GLuint program, GLuint location)
	{
		this->program = program;
		this->location = location;
	}

	void assign(GLuint program, const char* name)
	{
		this->program = program;
		this->location = glGetUniformLocation(program, name);
	}

	param_type operator=(param_type value)
	{
		//detail::set_uniform(program, location, value);
		return value;
	}

	operator T()
	{
		T value;
		//detail::get_uniform(program, location, value);
		return value;
	}

private:
	GLuint program;
	GLuint location;
};

} // namespace gl

#endif /* GLCC_UNIFORM_HPP */
