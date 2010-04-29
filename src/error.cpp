/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#include <glcc/error.hpp>

namespace gl
{
namespace detail
{

struct error_category: boost::system::error_category
{
	const char* name() const
	{
		return "OpenGL";
	}

	std::string message(int value) const
	{
		if (value == GL_NO_ERROR)
			return "No error";
		if (value == GL_INVALID_ENUM)
			return "Enum argument out of range";
		if (value == GL_INVALID_VALUE)
			return "Numeric argument out of range";
		if (value == GL_INVALID_OPERATION)
			return "Operation illegal in current state";
		if (value == GL_INVALID_FRAMEBUFFER_OPERATION)
			return "Framebuffer object is not complete";
		if (value == GL_OUT_OF_MEMORY)
			return "Not enough memory left to execute command";
		return "Unknown error";
	}
};

} // namespace detail

boost::system::error_code error()
{
	static gl::detail::error_category instance;
	return boost::system::error_code(glGetError(), instance);
}

} // namespace gl
