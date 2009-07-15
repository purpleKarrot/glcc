/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_VERTEX_ARRAY_HPP
#define GLCC_VERTEX_ARRAY_HPP

#include <glcc/detail/gl.hpp>
#include <glcc/detail/macros.hpp>

namespace gl
{
namespace detail
{

class vertex_array_base
{
public:
	class scoped_bind;

	void bind()
	{
		glBindVertexArray(name);
	}

GLCC_BASE(vertex_array_base, VertexArray, VertexArrays)
};

class vertex_array_base::scoped_bind: private boost::noncopyable
{
public:
	scoped_bind(vertex_array_base& array) :
		stored(get<GLuint> (GL_VERTEX_ARRAY_BINDING))
	{
		array.bind();
	}

	~scoped_bind()
	{
		stored.bind();
	}

private:
	vertex_array_base stored;
};

} // namespace detail

GLCC_OBJECT(vertex_array)

} // namespace gl

#endif /* GLCC_VERTEX_ARRAY_HPP */
