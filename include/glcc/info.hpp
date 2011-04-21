/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_INFO_HPP
#define GLCC_INFO_HPP

#include <GL/gl.h>
#include <glcc/detail/get.hpp>

namespace gl
{

/// Returns the company responsible for this GL implementation.
inline const char* vendor()
{
	return detail::get<const char*>(GL_VENDOR);
}

/// Returns the name of the renderer.
inline const char* renderer()
{
	return detail::get<const char*>(GL_RENDERER);
}

//!
inline int major_version()
{
	return detail::get<int>(GL_MAJOR_VERSION);
}

//!
inline int minor_version()
{
	return detail::get<int>(GL_MINOR_VERSION);
}

/// Returns a version or release number.
inline const char* version()
{
	return detail::get<const char*>(GL_VERSION);
}

/// Returns a version or release number for the shading language.
inline const char* shading_language_version()
{
	return detail::get<const char*>(GL_SHADING_LANGUAGE_VERSION);
}

} // namespace gl

#endif /* GLCC_INFO_HPP */
