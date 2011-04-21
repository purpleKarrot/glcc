/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef BOOST_GL_DETAIL_GET_HPP
#define BOOST_GL_DETAIL_GET_HPP

#include <GL/gl.h>
#include <glcc/vec.hpp>

namespace gl
{
namespace detail
{

template<typename T>
inline T get(GLenum pname)
{
	GLint param;
	glGetIntegerv(pname, &param);
	return static_cast<T> (param);
}

template<>
inline int64_t get<int64_t> (GLenum pname)
{
	GLint64 param;
	glGetInteger64v(pname, &param);
	return param;
}

template<>
inline bool get<bool> (GLenum pname)
{
	GLboolean param;
	glGetBooleanv(pname, &param);
	return param;
}

template<>
inline double get<double> (GLenum pname)
{
	GLdouble param;
	glGetDoublev(pname, &param);
	return param;
}

template<>
inline float get<float> (GLenum pname)
{
	GLfloat param;
	glGetFloatv(pname, &param);
	return param;
}

template<>
inline vec4 get<vec4> (GLenum pname)
{
	vec4 param;
	glGetFloatv(pname, param.a);
	return param;
}

template<>
inline bvec4 get<bvec4> (GLenum pname)
{
	bvec4 param;
	glGetBooleanv(pname, param.a);
	return param;
}

template<>
inline const char* get<const char*> (GLenum pname)
{
	return reinterpret_cast<const char*> (glGetString(pname));
}

} // namespace detail
} // namespace gl

#endif /* BOOST_GL_DETAIL_GET_HPP */
