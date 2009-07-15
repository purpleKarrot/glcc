/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_QUERY_HPP
#define GLCC_QUERY_HPP

#include <glcc/detail/gl.hpp>
#include <glcc/detail/macros.hpp>

namespace gl
{
namespace detail
{

class query_base
{
	void begin(GLenum target)
	{
		glBeginQuery(target, name);
	}

	void end(GLenum target)
	{
		glEndQuery(target);
	}

	//	* GetQuery*

	// SAMPLES_PASSED
	// PRIMITIVES_GENERATED
	// TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN

	int result()
	{
		int value;
		glGetQueryObjectiv(name, GL_QUERY_RESULT, &value);
		return value;
	}

	bool result_available()
	{
		int value;
		glGetQueryObjectiv(name, GL_QUERY_RESULT_AVAILABLE, &value);
		return value;
	}

GLCC_BASE(query_base, Query, Queries)
};

} // namespace detail

GLCC_OBJECT(query)

} // namespace gl

#endif /* GLCC_QUERY_HPP */
