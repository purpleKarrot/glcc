/**************************************************************
 * Copyright (c) 2008-2009 Daniel Pfeifer                     *
 *                                                            *
 * Distributed under the Boost Software License, Version 1.0. *
 **************************************************************/

#ifndef GLCC_MATH_VECTOR_HPP
#define GLCC_MATH_VECTOR_HPP

#include <glcc/detail/gl.hpp>
#include <glcc/vector.hpp>
#include <glcc/math/detail/component_wise.hpp>

namespace gl
{
namespace math
{

/**
 * \defgroup vector Vector Relational Functions (8.6)
 *
 * Relational and equality operators (<, <=, >, >=, ==, !=)
 * are defined to produce scalar Boolean results.
 * For vector results, use the following functions.
 *
 * \{
 */

//! Returns the component-wise compare of x < y.
GLCC_COMPONENT_WISE(GLboolean, lessThan, (GLfloat, x)(GLfloat, y))
{
	return x < y;
}

GLCC_COMPONENT_WISE(GLboolean, lessThan, (GLint, x)(GLint, y))
{
	return x < y;
}

GLCC_COMPONENT_WISE(GLboolean, lessThan, (GLuint, x)(GLuint, y))
{
	return x < y;
}

//! Returns the component-wise compare of x <= y.
GLCC_COMPONENT_WISE(GLboolean, lessThanEqual, (GLfloat, x)(GLfloat, y))
{
	return x <= y;
}

GLCC_COMPONENT_WISE(GLboolean, lessThanEqual, (GLint, x)(GLint, y))
{
	return x <= y;
}

GLCC_COMPONENT_WISE(GLboolean, lessThanEqual, (GLuint, x)(GLuint, y))
{
	return x <= y;
}

//! Returns the component-wise compare of x > y.
GLCC_COMPONENT_WISE(GLboolean, greaterThan, (GLfloat, x)(GLfloat, y))
{
	return x > y;
}

GLCC_COMPONENT_WISE(GLboolean, greaterThan, (GLint, x)(GLint, y))
{
	return x > y;
}

GLCC_COMPONENT_WISE(GLboolean, greaterThan, (GLuint, x)(GLuint, y))
{
	return x > y;
}

//! Returns the component-wise compare of x >= y.
GLCC_COMPONENT_WISE(GLboolean, greaterThanEqual, (GLfloat, x)(GLfloat, y))
{
	return x >= y;
}

GLCC_COMPONENT_WISE(GLboolean, greaterThanEqual, (GLint, x)(GLint, y))
{
	return x >= y;
}

GLCC_COMPONENT_WISE(GLboolean, greaterThanEqual, (GLuint, x)(GLuint, y))
{
	return x >= y;
}

//! Returns the component-wise compare of x == y.
GLCC_COMPONENT_WISE(GLboolean, equal, (GLfloat, x)(GLfloat, y))
{
	return x == y;
}

GLCC_COMPONENT_WISE(GLboolean, equal, (GLint, x)(GLint, y))
{
	return x == y;
}

GLCC_COMPONENT_WISE(GLboolean, equal, (GLuint, x)(GLuint, y))
{
	return x == y;
}

//! Returns the component-wise compare of x != y.
GLCC_COMPONENT_WISE(GLboolean, notEqual, (GLfloat, x)(GLfloat, y))
{
	return x != y;
}

GLCC_COMPONENT_WISE(GLboolean, notEqual, (GLint, x)(GLint, y))
{
	return x != y;
}

GLCC_COMPONENT_WISE(GLboolean, notEqual, (GLuint, x)(GLuint, y))
{
	return x != y;
}

//! Returns true if any component of a is true.
inline bool any(const bvec2& a)
{
	return a.x || a.y;
}

inline bool any(const bvec3& a)
{
	return a.x || a.y || a.z;
}

inline bool any(const bvec4& a)
{
	return a.x || a.y || a.z || a.w;
}

//! Returns true only if all components of a are true.
inline bool all(const bvec2& a)
{
	return a.x && a.y;
}

inline bool all(const bvec3& a)
{
	return a.x && a.y && a.z;
}

inline bool all(const bvec4& a)
{
	return a.x && a.y && a.z && a.w;
}

//! Returns the component-wise logical complement of a.
inline bvec2 operator not(bvec2 const& a)
{
	return bvec2(!a.x, !a.y);
}

inline bvec3 operator not(bvec3 const& a)
{
	return bvec3(!a.x, !a.y, !a.z);
}

inline bvec4 operator not(bvec4 const& a)
{
	return bvec4(!a.x, !a.y, !a.z, !a.w);
}

/** \} */

} // namespace math
} // namespace gl

#endif /* GLCC_MATH_VECTOR_HPP */
