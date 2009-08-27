/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_DETAIL_UNIFORM_HPP
#define GLCC_DETAIL_UNIFORM_HPP

//#include <array>
#include <boost/array.hpp>
namespace std
{
using boost::array;
}

#include <glcc/detail/vector.hpp>
#include <glcc/detail/matrix.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#define GLCC_uniform(T, A)                                                     \
	inline void uniform(GLuint location, T value)                              \
	{                                                                          \
		glUniform1##A(location, value);                                        \
	}                                                                          \
	template<std::size_t N>                                                    \
	inline void uniform(GLuint location, const std::array<T, N>& values)       \
	{                                                                          \
		glUniform1##A##v(location, N, values.data());                          \
	}

#define GLCC_vector_elements(z, N, d) , value[N]
#define GLCC_uniform_vector(T, A, D)                                           \
	inline void uniform(GLuint location, const detail::vector<T, D>& value)    \
	{                                                                          \
		glUniform##D##A(location BOOST_PP_REPEAT(D, GLCC_vector_elements, ~)); \
	}                                                                          \
	template<std::size_t N>                                                    \
	inline void uniform(GLuint location,                                       \
			const std::array<detail::vector<T, D>, N>& values)                 \
	{                                                                          \
		glUniform##D##A##v(location, N, reinterpret_cast<T*> (values.data())); \
	}

#define GLCC_uniform_matrix_s(D)                                               \
	inline void uniform(GLuint location,                                       \
			const detail::matrix<GLfloat, D, D>& value)                        \
	{                                                                          \
		glUniformMatrix##D##fv(location, 1, false,                             \
				reinterpret_cast<const GLfloat*>(&value));                     \
	}                                                                          \
	template<std::size_t S>                                                    \
	inline void uniform(GLuint location,                                       \
			const std::array<detail::matrix<GLfloat, D, D>, S>& values)        \
	{                                                                          \
		glUniformMatrix##D##fv(location, S, false,                             \
				reinterpret_cast<GLfloat*> (values.data()));                   \
	}

#define GLCC_uniform_matrix(M, N)                                              \
	inline void uniform(GLuint location,                                       \
			const detail::matrix<GLfloat, M, N>& value)                        \
	{                                                                          \
		glUniformMatrix##M##x##N##fv(location, 1, false,                       \
				reinterpret_cast<const GLfloat*>(&value));                     \
	}                                                                          \
	template<std::size_t S>                                                    \
	inline void uniform(GLuint location,                                       \
			const std::array<detail::matrix<GLfloat, M, N>, S>& values)        \
	{                                                                          \
		glUniformMatrix##M##x##N##fv(location, S, false,                       \
				reinterpret_cast<GLfloat*> (values.data()));                   \
	}

namespace gl
{
namespace detail
{

GLCC_uniform(GLfloat, f)
GLCC_uniform(GLint, i)
GLCC_uniform(GLuint, ui)

GLCC_uniform_vector(GLfloat, f, 2)
GLCC_uniform_vector(GLfloat, f, 3)
GLCC_uniform_vector(GLfloat, f, 4)

GLCC_uniform_vector(GLint, i, 2)
GLCC_uniform_vector(GLint, i, 3)
GLCC_uniform_vector(GLint, i, 4)

GLCC_uniform_vector(GLuint, ui, 2)
GLCC_uniform_vector(GLuint, ui, 3)
GLCC_uniform_vector(GLuint, ui, 4)

GLCC_uniform_matrix_s(2)
GLCC_uniform_matrix_s(3)
GLCC_uniform_matrix_s(4)

GLCC_uniform_matrix(2, 3)
GLCC_uniform_matrix(2, 4)
GLCC_uniform_matrix(3, 2)
GLCC_uniform_matrix(3, 4)
GLCC_uniform_matrix(4, 2)
GLCC_uniform_matrix(4, 3)

} // namespace detail
} // namespace gl

#undef GLCC_uniform
#undef GLCC_uniform_vector
#undef GLCC_uniform_matrix
#undef GLCC_uniform_matrix_s
#undef GLCC_vector_elements

#endif /* GLCC_DETAIL_UNIFORM_HPP */
