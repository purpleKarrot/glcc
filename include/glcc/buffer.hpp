/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_BUFFER_HPP
#define GLCC_BUFFER_HPP

#include <GL/gl.h>
#include <glcc/detail/scoped_bind_base.hpp>
#include <glcc/detail/macros.hpp>

namespace gl
{
namespace detail
{

class buffer_base
{
GLCC_BASE(buffer_base, Buffer, Buffers)
};

template<GLenum Target, GLenum Binding>
struct buffer_target
{
	typedef buffer_base value_type;
	typedef scoped_bind_base<buffer_target, Binding> scoped_bind;

	static inline void bind(const buffer_base& buffer)
	{
		glBindBuffer(Target, buffer.name);
	}

	static inline void data(GLsizeiptr size, const GLvoid* pdata, GLenum usage)
	{
		glBufferData(Target, size, pdata, usage);
	}

	static inline void sub_data(GLintptr offset, GLsizeiptr size,
			const GLvoid * data)
	{
		glBufferSubData(Target, offset, size, data);
	}

	static inline void get_sub_data(GLintptr offset, GLsizeiptr size,
			GLvoid * data)
	{
		glGetBufferSubData(Target, offset, size, data);
	}

	static inline void* map(GLenum access)
	{
		return glMapBuffer(Target, access);
	}

	static inline bool unmap()
	{
		return glUnmapBuffer(Target);
	}

	static inline GLint access()
	{
		GLint data;
		glGetBufferParameteriv(Target, GL_BUFFER_ACCESS, &data);
		return data;
	}

	static inline bool mapped()
	{
		GLint value;
		glGetBufferParameteriv(Target, GL_BUFFER_MAPPED, &value);
		return value == GL_TRUE;
	}

	static inline GLint size()
	{
		GLint data;
		glGetBufferParameteriv(Target, GL_BUFFER_SIZE, &data);
		return data;
	}

	static inline GLint usage()
	{
		GLint data;
		glGetBufferParameteriv(Target, GL_BUFFER_USAGE, &data);
		return data;
	}

	static inline GLvoid* map_pointer()
	{
		GLvoid * pointer;
		glGetBufferPointerv(Target, GL_BUFFER_MAP_POINTER, &pointer);
		return pointer;
	}
};

} // namespace detail

typedef detail::buffer_target<GL_ARRAY_BUFFER, //
		GL_ARRAY_BUFFER_BINDING> array_buffer;

typedef detail::buffer_target<GL_ELEMENT_ARRAY_BUFFER, //
		GL_ELEMENT_ARRAY_BUFFER_BINDING> element_array_buffer;

typedef detail::buffer_target<GL_PIXEL_PACK_BUFFER, //
		GL_PIXEL_PACK_BUFFER_BINDING> pixel_pack_buffer;

typedef detail::buffer_target<GL_PIXEL_UNPACK_BUFFER, //
		GL_PIXEL_UNPACK_BUFFER_BINDING> pixel_unpack_buffer;

typedef detail::buffer_target<GL_TRANSFORM_FEEDBACK_BUFFER, //
		GL_TRANSFORM_FEEDBACK_BUFFER_BINDING> transform_feedback_buffer;

GLCC_OBJECT(buffer)

} // namespace gl

#endif /* GLCC_BUFFER_HPP */
