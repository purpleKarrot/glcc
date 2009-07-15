/*
 * extension.hpp
 *
 *  Created on: 30.06.2009
 *      Author: daniel
 */

#ifndef EXTENSION_HPP_
#define EXTENSION_HPP_

#include <glcc/detail/gl.hpp>
#include <glcc/detail/get.hpp>

class extension;
struct extensions;

class extension
{
public:
	extension(const extension& other) :
		name(other.name)
	{
	}

	const extension& operator=(const extension& other)
	{
		name = other.name;
		return *this;
	}

	const char* operator*()
	{
		return reinterpret_cast<const char*> (glGetStringi(GL_EXTENSIONS, name));
	}

	bool operator==(const extension& other)
	{
		return name == other.name;
	}

	bool operator!=(const extension& other)
	{
		return name != other.name;
	}

	bool operator<(const extension& other)
	{
		return name < other.name;
	}

	bool operator>(const extension& other)
	{
		return name > other.name;
	}

	bool operator<=(const extension& other)
	{
		return name <= other.name;
	}

	bool operator>=(const extension& other)
	{
		return name >= other.name;
	}

	extension operator++()
	{
		++name;
		return *this;
	}

private:
	extension(GLuint e) :
		name(e)
	{
	}

	friend struct extensions;

	GLuint name;
};

struct extensions
{
	static GLuint size()
	{
		return gl::detail::get<GLuint>(GL_NUM_EXTENSIONS);
	}

	const char* operator[](GLuint idx)
	{
		return *extension(idx);
	}

	static extension begin()
	{
		return extension(0);
	}

	static extension end()
	{
		return extension(size());
	}

};

#endif /* EXTENSION_HPP_ */
