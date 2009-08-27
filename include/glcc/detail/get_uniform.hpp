/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_GET_UNIFORM_HPP
#define GLCC_DETAIL_GET_UNIFORM_HPP

//#include <glcc/detail/vector.hpp>
//#include <glcc/detail/matrix.hpp>
#include <cassert>

namespace gl
{
namespace detail
{

template<typename T>
void get_uniform(GLuint program, GLuint location, T value)
{
	assert(!"get_uniform is not yet implemented!");
}

} // namespace detail
} // namespace gl

#endif /* GLCC_DETAIL_GET_UNIFORM_HPP */
