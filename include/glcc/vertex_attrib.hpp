/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_VERTEX_ATTRIB_HPP
#define GLCC_VERTEX_ATTRIB_HPP

#include <glcc/detail/adapt_vertex.hpp>

namespace gl
{

template<typename T>
void vertex_attrib_pointer(GLuint index, bool normalized, GLsizei stride,
		const T* pointer)
{
	glVertexAttribPointer(index, size<T>::value, type<T>::value, normalized,
			stride, pointer);
}

template<std::size_t I>
struct vertex_attrib_pointer
{
	template<typename Vertex>
	static void eval(const Vertex* vertex)
	{
		typedef detail::vertex_member<Vertex, I - 1> member;

		glVertexAttribPointer(I, member::size, member::gltype,
				member::normalized, member::stride, member::pointer(vertex));

		vertex_attrib_pointer<I - 1>::eval(vertex);
	}
};

template<>
struct vertex_attrib_pointer<0>
{
	template<typename Vertex>
	static void eval(const Vertex&)
	{
	}
};

/// Specifies the value of a generic vertex attribute
//template<typename Vertex>
//void vertex_attrib(const Vertex& vertex)
//{
//	//boost::mpl::for_each(vertex, detail::vertex_attrib());
//}

/// define an array of generic vertex attribute data
template<typename Vertex>
void vertex_attrib(const Vertex* vertex)
{
	vertex_attrib_pointer<detail::vertex_size<Vertex>::value>::eval(vertex);
}

/// return the address of the specified generic vertex attribute pointer
template<typename Vertex>
void get_vertex_attrib(Vertex* vertex)
{
	//	for (int I = 0; I < detail::vertex_size<Vertex>::value; ++I)
	//	{
	//		glGetVertexAttribPointerv(I, GL_VERTEX_ATTRIB_ARRAY_POINTER,
	//				detail::vertex_member<Vertex, I>::pointer(vertex));
	//	}
}

} // namespace gl

#endif /* GLCC_VERTEX_ATTRIB_HPP */
