/**************************************************************
 * Copyright (c) 2008-2010 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_EXTENSIONS_HPP
#define GLCC_EXTENSIONS_HPP

#include <GL/gl.h>
#include <glcc/detail/get.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/range/iterator_range.hpp>

namespace gl
{

class extension_iterator: public boost::iterator_facade<extension_iterator,
		GLuint, boost::forward_traversal_tag, const char*, GLuint>
{
public:
	explicit extension_iterator(GLuint name) :
		name(name)
	{
	}

	extension_iterator(const extension_iterator& other) :
		name(other.name)
	{
	}

	const extension_iterator& operator=(const extension_iterator& other)
	{
		name = other.name;
		return *this;
	}

	void increment()
	{
		++name;
	}

	void advance(GLuint n)
	{
		name = +n;
	}

	bool equal(const extension_iterator& other) const
	{
		return name == other.name;
	}

	GLuint distance_to(extension_iterator const& other) const
	{
		return other.name - name;
	}

	const char* dereference() const
	{
		return reinterpret_cast<const char*> (glGetStringi(GL_EXTENSIONS, name));
	}

private:
	GLuint name;
};

boost::iterator_range<extension_iterator> extensions()
{
	return boost::iterator_range<extension_iterator>(extension_iterator(0),
			extension_iterator(gl::detail::get<GLuint>(GL_NUM_EXTENSIONS)));
}

} // namespace gl

#endif /* GLCC_EXTENSIONS_HPP */
