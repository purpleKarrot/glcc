/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_SHADER_HPP
#define GLCC_SHADER_HPP

#include <string>
#include <glcc/detail/gl.hpp>

namespace gl
{

class shader
{
public:

	enum shader_type
	{
		vertex = GL_VERTEX_SHADER,
		fragment = GL_FRAGMENT_SHADER,
		geometry = GL_GEOMETRY_SHADER
	};

	shader(shader_type t) :
		name(glCreateShader(t))
	{
	}

	~shader()
	{
		glDeleteShader(name);
	}

	shader_type type() const
	{
		GLint t;
		glGetShaderiv(name, GL_SHADER_TYPE, &t);
		return static_cast<shader_type> (t);
	}

	void source(const char* string)
	{
		glShaderSource(name, 1, &string, 0);
	}

	void source(const std::string& string)
	{
		const GLchar* s = string.c_str();
		const GLint l = string.length();
		glShaderSource(name, 1, &s, &l);
	}

	std::string source() const
	{
		GLint length;
		glGetShaderiv(name, GL_SHADER_SOURCE_LENGTH, &length);
		std::string buffer(length, 0);
		glGetShaderSource(name, length, 0, &buffer[0]);
		return buffer;
	}

	bool compile()
	{
		GLint success;
		glCompileShader(name);
		glGetShaderiv(name, GL_COMPILE_STATUS, &success);
		return success == GL_TRUE;
	}

	std::string info_log() const
	{
		GLint length;
		glGetShaderiv(name, GL_INFO_LOG_LENGTH, &length);
		std::string buffer(length, 0);
		glGetShaderInfoLog(name, length, 0, &buffer[0]);
		return buffer;
	}

private:
	friend class program;
	GLuint name;
};

} // namespace gl

#endif /* GLCC_SHADER_HPP */
