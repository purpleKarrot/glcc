/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_PROGRAM_HPP
#define GLCC_PROGRAM_HPP

#include <string>
#include <glcc/shader.hpp>

namespace gl
{

class program
{
public:
	program() :
		name(glCreateProgram())
	{
	}

	~program()
	{
		glDeleteProgram(name);
	}

	void attach(gl::shader shader)
	{
		glAttachShader(name, shader.name);
	}

	void attach(gl::shader::shader_type type, const char* source)
	{
		gl::shader shader(type);
		shader.source(source);
		shader.compile();
		attach(shader);
	}

	void attach(gl::shader::shader_type type, const std::string& source)
	{
		gl::shader shader(type);
		shader.source(source);
		shader.compile();
		attach(shader);
	}

	void detach(gl::shader shader)
	{
		glDetachShader(name, shader.name);
	}

	void validate()
	{
		glValidateProgram(name);
	}

	bool validate_status()
	{
		GLint success;
		glGetProgramiv(name, GL_VALIDATE_STATUS, &success);
		return success == GL_TRUE;
	}

	void link()
	{
		glLinkProgram(name);
	}

	bool link_status()
	{
		GLint success;
		glGetProgramiv(name, GL_LINK_STATUS, &success);
		return success == GL_TRUE;
	}

	std::string info_log()
	{
		GLint length;
		glGetProgramiv(name, GL_INFO_LOG_LENGTH, &length);
		std::string buffer(length, 0);
		glGetProgramInfoLog(name, length, 0, &buffer[0]);
		return buffer;
	}

	void use()
	{
		glUseProgram(name);
	}

private:
	GLuint name;
};

} // namespace gl

#endif /* GLCC_PROGRAM_HPP */
