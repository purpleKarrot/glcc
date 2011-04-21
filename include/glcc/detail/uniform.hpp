/**************************************************************
 * Copyright (c) 2008-2011 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_UNIFORM_HPP
#define GLCC_DETAIL_UNIFORM_HPP

#include <GL/gl.h>
#include <glcc/vec.hpp>
#include <glcc/mat.hpp>

#define GLCC_uniform(T, S)                                                     \
    inline void set_uniform(GLuint program, GLuint location, T value)          \
    {                                                                          \
        glProgramUniform1##S(program, location, value);                        \
    }                                                                          \
    inline void get_uniform(GLuint program, GLuint location, T& value)         \
    {                                                                          \
        glGetUniform##S##v(program, location, &value);                         \
    }                                                                          \

#define GLCC_uniform_vector(D, P, S)                                           \
	inline void uniform(GLuint prog, GLuint loc, const P##vec##D& val)         \
	{                                                                          \
        glProgramUniform##D##S##v(prog, loc, 1, val.a);                        \
	}                                                                          \
    inline void get_uniform(GLuint prog, GLuint loc, P##vec##D& val)           \
    {                                                                          \
        glGetUniform##S##v(proc, loc, val.a);                                  \
    }                                                                          \

#define GLCC_uniform_matrix(D, P, S)                                           \
	inline void uniform(GLuint prog, GLuint loc, const P##mat##D& val)         \
	{                                                                          \
		glProgramUniformMatrix##D##S##v(prog, loc, 1, false, val.a);           \
	}                                                                          \
    inline void get_uniform(GLuint prog, GLuint loc, P##mat##D& val)           \
    {                                                                          \
        glGetUniform##S##v(prog, loc, val.a);                                  \
    }                                                                          \

namespace gl
{
namespace detail
{

GLCC_uniform(GLint, i)
GLCC_uniform(GLfloat, f)
GLCC_uniform(GLdouble, d)
GLCC_uniform(GLuint, ui)

GLCC_uniform_vector(2, i, i)
GLCC_uniform_vector(3, i, i)
GLCC_uniform_vector(4, i, i)

GLCC_uniform_vector(2,  , f)
GLCC_uniform_vector(3,  , f)
GLCC_uniform_vector(4,  , f)

GLCC_uniform_vector(2, d, d)
GLCC_uniform_vector(3, d, d)
GLCC_uniform_vector(4, d, d)

GLCC_uniform_vector(2, u, ui)
GLCC_uniform_vector(3, u, ui)
GLCC_uniform_vector(4, u, ui)

GLCC_uniform_matrix(2,  , f)
GLCC_uniform_matrix(3,  , f)
GLCC_uniform_matrix(4,  , f)

GLCC_uniform_matrix(2, d, d)
GLCC_uniform_matrix(3, d, d)
GLCC_uniform_matrix(4, d, d)

GLCC_uniform_matrix(2x3,  , f)
GLCC_uniform_matrix(3x2,  , f)
GLCC_uniform_matrix(2x4,  , f)
GLCC_uniform_matrix(4x2,  , f)
GLCC_uniform_matrix(3x4,  , f)
GLCC_uniform_matrix(4x3,  , f)

GLCC_uniform_matrix(2x3, d, d)
GLCC_uniform_matrix(3x2, d, d)
GLCC_uniform_matrix(2x4, d, d)
GLCC_uniform_matrix(4x2, d, d)
GLCC_uniform_matrix(3x4, d, d)
GLCC_uniform_matrix(4x3, d, d)

} // namespace detail
} // namespace gl

#undef GLCC_uniform
#undef GLCC_uniform_vector
#undef GLCC_uniform_matrix

#endif /* GLCC_DETAIL_UNIFORM_HPP */
