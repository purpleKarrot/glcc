/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_VERTEX_ATTRIB_POINTER_HPP
#define GLCC_VERTEX_ATTRIB_POINTER_HPP

#include <glcc/detail/traits.hpp>

namespace gl
{

/// define an array of generic vertex attribute data
template<typename T>
inline void vertex_attrib_pointer(GLuint index, bool normalized,
		GLsizei stride, const T* pointer)
{
	glVertexAttribPointer(index, detail::size<T>::value,
			detail::type<T>::value, normalized, stride, pointer);
}

/// return the address of the specified generic vertex attribute pointer
template<typename Vertex>
GLvoid* get_vertex_attrib_pointer(GLuint index)
{
	GLvoid* pointer;
	glGetVertexAttribPointerv(index, GL_VERTEX_ATTRIB_ARRAY_POINTER, &pointer);
	return pointer;
}

} // namespace gl

#endif /* GLCC_VERTEX_ATTRIB_POINTER_HPP */
