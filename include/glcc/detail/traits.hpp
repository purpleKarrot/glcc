/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_TRAITS_HPP
#define GLCC_DETAIL_TRAITS_HPP

#include <GL3/gl3w.h>
#include <boost/config.hpp>

#include <boost/type_traits/is_arithmetic.hpp>
#include <boost/utility/enable_if.hpp>

namespace gl
{
namespace detail
{

#define GLCC_TRAITS_BASE(TYPE, NAME)                 \
	template<typename T, typename Enable = void> struct NAME {};             \
	template<TYPE VAL> struct NAME##_base            \
	{ BOOST_STATIC_CONSTANT(TYPE, NAME = VAL); };    \

#define GLCC_TRAITS(NAME, CC, GL)                    \
	template<> struct NAME<CC> : NAME##_base<GL> {}; \

GLCC_TRAITS_BASE(GLint, size)

template<typename T>
struct size<T, typename boost::enable_if<boost::is_arithmetic<T> >::type> : //
size_base<1>
{
};

template<typename T>
struct size<T, typename boost::enable_if<typename boost::la::is_vector<T>::value>::type> : //
size_base<boost::la::vector_traits<T>::dim>
{
};

GLCC_TRAITS_BASE(GLenum, type)
GLCC_TRAITS(type, GLbyte, GL_BYTE)
GLCC_TRAITS(type, GLubyte, GL_UNSIGNED_BYTE)
GLCC_TRAITS(type, GLshort, GL_SHORT)
GLCC_TRAITS(type, GLushort, GL_UNSIGNED_SHORT)
GLCC_TRAITS(type, GLint, GL_INT)
GLCC_TRAITS(type, GLuint, GL_UNSIGNED_INT)
GLCC_TRAITS(type, GLfloat, GL_FLOAT)
GLCC_TRAITS(type, GLdouble, GL_DOUBLE)

template<typename T>
struct type<T, typename boost::enable_if<typename boost::la::is_vector<T>::value>::type> : //
type<typename boost::la::vector_traits<T>::scalar_type>
{
};

#undef GLCC_TRAITS
#undef GLCC_TRAITS_BASE

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_TRAITS_HPP */
